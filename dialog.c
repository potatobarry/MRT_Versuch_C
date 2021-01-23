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
    printf("0: Radius zur Beschreibung es kreisförmigen Gebietes G für komplexe Zahlen \n");
    printf("1: Maximale Iterationszahl \n");
    printf("2: Fraktalvariante wählen \n");
    printf("3: Komplexwertiges Analysegebiet wählen \n");
    printf("4: Anzahl der Linien im Analysegebiet \n");
    printf("5: Komplexe \n");
    printf("p_radius = %f", p.radius); 
    printf( "\n");
    printf(" \n");
    printf(" \n");



    return 0;

};

/* EOF DIALOG_C */
