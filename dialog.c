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
        printf("Zur Parametereingabe bitte eine der Folgenden Optionen auswählen und mit [Enter] bestätigen: \n\n");
        printf("1: Radius zur Beschreibung es kreisförmigen Gebietes G für komplexe Zahlen \n Aktuell: radius = %f", p_in.radius);
        printf("\n2: Maximale Iterationszahl \n Aktuell: imax = %d", p_in.imax);
        printf("\n3: Fraktalvariante wählen: m für Manedelbrot, j für Juliamenge \n Aktuell: menge = % c", p_in.menge);
        printf("\n4: Komplexwertiges Analysegebiet wählen \n Aktuell: xmin = %f, xmax = %f, ymin = %f, ymax = %f", p_in.xmin, p_in.xmax, p_in.ymin, p_in.ymax);
        printf("\n5: Anzahl der Linien im Analysegebiet \n Aktuell: Linien in x-Richtung: xpoints = %d \n          Linien in y-Richtung: ypoints = %d", p_in.xpoints, p_in.ypoints);
        printf("\n6: Komplexe Zahl c\n Aktuell: Realteil = %f, Imaginärteil = %f", c_in.real, c_in.imag);
        printf("\n\n9: Eingaben bestätigen und Speichern");
        printf("\n0: Programm beenden");
        printf("\n--------------------------------------------------------------------------\n");

        input_int(&input);

        switch (input)
        {
        case 0: printf("Programm beenden? (y/n)\n");    //Überprüft, ob Programm wirklich beendet werden soll.
            char leave = input_char();
            
            if (leave == 'y')
            {
                printf("exiting...\n");
                return 1;                               //Übergibt 1 an Main --> auch dort Programm gezielt beenden.
            }
            break;
        case 1: printf("Bitte Radius Eingeben. \n");
            input_double(&p_in.radius);
            break;
        case 2: printf("Bitte die maximale Iterationszahl wählen. \n");
            input_int(&p_in.imax);
            break;
        case 3: printf("Bitte Fraktalvariante wählen: Mandelbrot- oder Juliamenge (m/j) \n");
            p_in.menge = get_F();
            while (p_in.menge != julia && p_in.menge != mandel)
            {
                p_in.menge = get_F();
            }
            break;
        case 4: printf("Bitte ");
        default: printf("\n*******\nEingabe nicht erkannt: Bitte Enstrechende Zahl von 0 ... 9 eingeben!\n");
            break;
        }

       
    }

     return 0;

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
