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
    double x = 2.4;

    printf("-------------------------------------------------------------------------- \n");
    printf("Zur Parametereingabe bitte eine der Folgenden Optionen auswählen: \n\n");
    printf("0: Radius zur Beschreibung es kreisförmigen Gebietes G für komplexe Zahlen \n Aktuell: p_radius = %f", p.radius);
    printf("\n1: Maximale Iterationszahl \n Aktuell: imax = %d", p.imax);
    printf("\n2: Fraktalvariante wählen: 0 für Manedelbrot, 1 für Juliamenge \n Aktuell: menge = % f", p.radius);
    printf("\n3: Komplexwertiges Analysegebiet wählen \n Aktuell: p_radius = % f", p.radius);
    printf("\n4: Anzahl der Linien im Analysegebiet \n Aktuell: p_radius = % f", p.radius);
    printf("\n5: Komplexe \n");
    
    printf( "\n");
    printf(" \n");
    printf(" \n");



    return 0;

};

/* EOF DIALOG_C */
