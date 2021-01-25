/* BOF DIALOG_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"
 */

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>


/*--- Definitionen ---------------------------------------------------------*/

enum bool {FALSE, TRUE};


/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char input_char(void)
{
        char s[80];
        fgets(s,sizeof(s), stdin);
        
        return s[0];
        
}

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void input_double(double *value)
{
        char *endptr;
        char s[80];
        fgets(s,sizeof(s), stdin);
        
        if (s[0]!=10) *value=strtod (s, &endptr);
}


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void input_int(int *value)
{
        char s[80];
        fgets(s,sizeof(s), stdin);
        if (s[0]!=10) *value=atoi (s);
}


/*--- Parameter Dialog -----------------------------------------------------*/

int param_dialog(param_t p, complex_t c)
{
    param_t p_in = p;
    complex_t c_in =c;
    int input = 0;
    int exit = 0;
    
    
    while (exit == 0)
    {
        printf("\n--------------------------------------------------------------------------\n");
        printf("Zur Parametereingabe bitte eine der Folgenden Optionen auswählen und mit [Enter] bestätigen:\n");
        printf("\n[1]: Radius zur Beschreibung es kreisförmigen Gebietes G für komplexe Zahlen \n Aktuell: radius = %f\n", p_in.radius);
        printf("\n[2]: Maximale Iterationszahl \n Aktuell: imax = %d\n", p_in.imax);
        printf("\n[3]: Fraktalvariante wählen: m für Manedelbrot, j für Juliamenge \n Aktuell: menge = % c\n", p_in.menge);
        printf("\n[4]: Komplexwertiges Analysegebiet wählen \n Aktuell: xmin = %f\
                                                            \n          xmax = %f\
                                                            \n          ymin = %f\
                                                            \n          ymax = %f", p_in.xmin, p_in.xmax, p_in.ymin, p_in.ymax);
        printf("\n[5]: Anzahl der Linien im Analysegebiet \n Aktuell: Linien in x-Richtung: xpoints = %d \n          Linien in y-Richtung: ypoints = %d\n", p_in.xpoints, p_in.ypoints);
        printf("\n[6]: Komplexe Zahl c\n Aktuell: Realteil = %f, Imaginärteil = %f\n", c_in.real, c_in.imag);
        printf("\n[8]: Programm beenden\
                \n[9]: Eingaben bestätigen und Speichern\
                \n--------------------------------------------------------------------------\n");

        input_int(&input);

        switch (input)
        {
        case 1: printf("Bitte Radius Eingeben. Dezimalstellen mit [.] realisieren, z.B. x.y \n");    //Eingabe Radius.
            input_double(&p_in.radius);
            break;
        case 2: printf("Bitte die maximale Iterationszahl wählen. \n"); //Eingabe der maximalen Iterationszahl
            input_int(&p_in.imax);
            break;
        case 3: printf("Bitte Fraktalvariante wählen: Mandelbrot- oder Juliamenge (m/j) \n"); //Eingabe der Fraktalvariante mithilfe unserer get_F Funktion.
            p_in.menge = get_F();
            while (p_in.menge != julia && p_in.menge != mandel)
            {
                p_in.menge = get_F();
            }
            break;
        case 4:             //Eingabe des Analysegebietes
            int xokay = 0;
            int yokay = 0;
            while (xokay == 0) {
                printf("Bitte xmin Eingeben. Dezimalstellen mit [.] realisieren, z.B. x.y \n"); //Eingabe des X-Werte
                input_double(&p_in.xmin);
                printf("Bitte xmax Eingeben. \n");
                input_double(&p_in.xmax);
                if (p_in.xmin > p_in.xmax) {                                                      //überprüfe ob xmin kleiner xmax ist
                    printf("Unzulaessige Eingabe!\nxmin muss kleiner sein als xmax \n");
                }
                else {
                    ++xokay;
                }
            }
            while (yokay == 0) {                                                                  //Eingabe des Y-Werte
                printf("Bitte ymin Eingeben. \n");
                input_double(&p_in.ymin);
                printf("Bitte ymax Eingeben. \n");
                input_double(&p_in.ymax);
                if (p_in.ymin > p_in.ymax) {                                                      //überprüfe ob ymin kleiner ymax ist
                    printf("Unzulaessige Eingabe!\nymin muss kleiner sein als ymax \n");
                }
                else {
                    ++yokay;
                }
            }
            break;
        case 5: printf("Bitte die Anzahl der Linien in x-Richtung eingeben.\n"); //Eingebe der Anzahl der Linien in x & y Richtung 
            input_int(&p_in.xpoints);
            printf("Bitte die Anzahl der Linien in y-Richtung eingeben.\n");
            input_int(&p_in.ypoints);
            break;
        case 6: printf("Bitte Realteil der Komplexen Zahl c eingeben. Dezimalstellen mit [.] realisieren, z.B. x.y\n"); //Eingabe der komplexen Zahl
            input_double(&c_in.real);
            printf("Bitte Imaginärteil der Komplexen Zahl c eingeben. Dezimalstellen mit [.] realisieren, z.B. x.y\n");
            input_double(&c_in.imag);
            break;
        case 8: printf("Programm beenden? (y/n)\n");    //Überprüft, ob Programm wirklich beendet werden soll.
            if (input_char() == 'y' || input_char() == 'Y')
            {
                printf("exiting...\n");
                return 0;                               //Übergibt 0 an Main --> auch dort Programm gezielt beenden.
            }
            break;
        case 9: printf("Eingaben bestätigen? (y/n)");   //bestätigen und speichern der Eingaben
            if (input_char() == 'y' || input_char() == 'Y')
            { //Prüft, ob Eingaben Sinnhaft sind. 
                if ((p_in.radius > 0) && (p_in.imax > 0) && (p_in.menge == 'm' || p_in.menge == 'j') && (p_in.xmin < p_in.xmax)
                    && (p_in.ymin < p_in.ymax) && (p_in.xpoints > 0) && (p_in.ypoints > 0))
                {
                printf("Eingaben bestätigt...\n"); //Setzten der eingegebenen p und c Variablen auf Eingaben.
                p = p_in;
                c = c_in;
                exit = 1;   //Bedingung zum verlassen der while Schleife
                }
                else
                {
                    printf("Eingaben bitte überprüfen.\n");
                }
            }
            break;
        default: printf("\n*********************************************************************\
                         \nEingabe nicht erkannt: Bitte Entsprechende Zahl von 1 ... 9 eingeben!\
                         \n*********************************************************************\n");
            break;
        }

       
    }

     return 1;

};


fraktal_t get_F(void)
{
    switch (input_char())
    {
    case 'm': return mandel;
        break;
    case 'j': return julia;
        break;
    default: printf("Eingabe falsch. Bitte wiederholen.\n");
        break;
    }    
}


/* EOF DIALOG_C */
