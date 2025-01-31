/* BOF DIALOG_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"

 Samuel Quinn Wagner, 4760211
 Nina Silvia Dröge, 4764513
 Lukas Gerbeth, 4817176
 Huu An Nguyen, 4763633

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

int param_dialog(param_t *p_in, complex_t *c_in)
{
    param_t p = *p_in;
    complex_t c = *c_in;
    int input = 0;
    int exit = 0;
    
    
    while (exit == 0)
    {
        /* Textausgabe im Terminal */
        printf("\n--------------------------------------------------------------------------\n");
        printf("Zur Parametereingabe bitte eine der Folgenden Optionen auswählen und mit [Enter] bestätigen:\n");
        printf("\n[1]: Radius zur Beschreibung es kreisförmigen Gebietes G für komplexe Zahlen \n Aktuell: radius = %f\n", p.radius);
        printf("\n[2]: Maximale Iterationszahl \n Aktuell: imax = %d\n", p.imax);
        printf("\n[3]: Fraktalvariante wählen: m für Manedelbrot, j für Juliamenge \n Aktuell: menge = % c\n", p.menge);
        printf("\n[4]: Komplexwertiges Analysegebiet wählen \n Aktuell: xmin = %f\
                                                            \n          xmax = %f\
                                                            \n          ymin = %f\
                                                            \n          ymax = %f", p.xmin, p.xmax, p.ymin, p.ymax);
        printf("\n[5]: Auflösung des Analysegebietes in x und y Richtung\
                \n Aktuell: Linien in x-Richtung: xpoints = %d \
                \n          Linien in y-Richtung: ypoints = %d\n", p.xpoints, p.ypoints);
        printf("\n[6]: Komplexe Zahl c\n Aktuell: Realteil = %f, Imaginärteil = %f\n", c.real, c.imag);
        printf("\n[8]: Programm beenden\
                \n[9]: Eingaben bestätigen und Speichern, sowie Fraktal berechnen.\
                \n--------------------------------------------------------------------------\n");

        input_int(&input);

        /* Auswertung der Nutzereingabe zur Änderung der Werte, Bestätigung, usw.*/

        switch (input)
        {
        case 1: printf("Bitte Radius Eingeben. Dezimalstellen mit [.] realisieren, z.B. x.y \n");    //Eingabe Radius.
            input_double(&p.radius);
            break;

        case 2: printf("Bitte die maximale Iterationszahl wählen. \n"); //Eingabe der maximalen Iterationszahl
            input_int(&p.imax);
            break;

        case 3: printf("Bitte Fraktalvariante wählen: Mandelbrot- oder Juliamenge (m/j) \n"); //Eingabe der Fraktalvariante mithilfe unserer get_F Funktion.
            p.menge = get_F();
            while (p.menge != julia && p.menge != mandel)
            {
                p.menge = get_F();
            }
            break;

        case 4:;            //Eingabe des Analysegebietes
            int xokay = 0;
            int yokay = 0;
            /*--- The Following is Ugly but works ----------------------*/

            while (xokay == 0) {
                printf("Bitte xmin Eingeben. Dezimalstellen mit [.] realisieren, z.B. -2.5 \n"); //Eingabe der X-Werte
                input_double(&p.xmin);
                printf("Bitte xmax Eingeben. \n");
                input_double(&p.xmax);
                if (p.xmin >= p.xmax) {                                                      //Überprüfen, ob xmin kleiner xmax ist.
                    printf("Unzulaessige Eingabe!\nxmin muss kleiner sein als xmax. \n");
                }
                else {
                    ++xokay;
                }
            }
            while (yokay == 0) {                                                                  //Eingabe der Y-Werte
                printf("Bitte ymin Eingeben. \n");
                input_double(&p.ymin);
                printf("Bitte ymax Eingeben. \n");
                input_double(&p.ymax);
                if (p.ymin >= p.ymax) {                                                      //Überprüfen, ob ymin kleiner ymax ist.
                    printf("Unzulaessige Eingabe!\nymin muss kleiner sein als ymax \n");
                }
                else {
                    ++yokay;
                }
            }
            /*-----------------------------------------------------------*/
            break;

        case 5: printf("Bitte die Anzahl der Linien in x-Richtung eingeben.\n"); //Eingabe der Anzahl der Linien bzw. Auflösung in x & y Richtung 
            input_int(&p.xpoints);
            printf("Bitte die Anzahl der Linien in y-Richtung eingeben.\n");
            input_int(&p.ypoints);
            break;

        case 6: printf("Bitte Realteil der Komplexen Zahl c eingeben. Dezimalstellen mit [.] realisieren, z.B. x.y\n"); //Eingabe der komplexen Zahl c
            input_double(&c.real);
            printf("Bitte Imaginärteil der Komplexen Zahl c eingeben. Dezimalstellen mit [.] realisieren, z.B. x.y\n");
            input_double(&c.imag);
            break;

        case 8: printf("Programm beenden? (y/n)\n");    //Überprüft, ob das Programm wirklich beendet werden soll.
            if (input_char() == 'y' || input_char() == 'Y')
            {
                printf("exiting...\n");
                return 0;                               //Übergibt 0 an Main --> auch dort Programm beenden.
            }
            else
            {
                break;
            }
            

        case 9: printf("Eingaben bestätigen? (y/n)");   //bestätigen und speichern der Eingaben
            if (input_char() == 'y' || input_char() == 'Y')
            { //Prüft, ob Eingaben Sinnhaft sind. 
                if ((p.radius > 0) && (p.imax > 0) && (p.menge == 'm' || p.menge == 'j') && (p.xmin < p.xmax)
                    && (p.ymin < p.ymax) && (p.xpoints > 0) && (p.ypoints > 0))
                {
                printf("Eingaben bestätigt...\n"); //Speichern der Eingaben für die Verwendung in main.c
                *p_in = p;
                *c_in = c;
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


fraktal_t get_F(void)  //unterfunktion zur Auswahl der Mengenart
{
    switch (input_char())
    {
    case 'm': return mandel;
        break;
    case 'M': return mandel;
        break;
    case 'j': return julia;
        break;
    case 'J': return julia;
        break;
    default: printf("Eingabe falsch. Bitte wiederholen.\n");
        return mandel;
        break;
    }    
}


/* EOF DIALOG_C */
