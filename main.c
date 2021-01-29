/* BOF MAIN_C
 Praktikumsversuch: Einführung in die Sprache C
 Haupt-Programm

 Samuel Quinn Wagner, 4760211
 Nina Silvia Dröge, 4764513
 Lukas Gerbeth, 4817176
 Huu An Nguyen, 4763633

 */

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>
//#include <io.h>
#include <SDL2/SDL.h>


// Forwarddeklaration der später definierten Hilfsfunktionen:
void goodbye_msg(void);
static void init_exit(void);


/* Hauptprogramm, Einstiegspunkt für eigene Programmierlösung.
 * Kommentarzeichen vor Funktionsaufrufen entfernen und
 * Programmrahmen ausfüllen.
 */ 
int main (int argc, char* args[])
{
        /*--- Variablendeklaration -----------------------------------------*/
       
        param_t   p = { 0 };
        complex_t c = { 0 };
        complex_t z = { 0 };
    
        /*--- Initialwerte -------------------------------------------------*/
                      
        p.menge   = mandel;
        p.radius  =      2;
        p.xmin    =     -2;
        p.xmax    =      2;
        p.ymin    =     -2;
        p.ymax    =      2;
        p.imax    =     75;
        p.xpoints =    400;
        p.ypoints =    300;

        c.real = 0.4;
        c.imag = 0.4;

        /*--- Hauptprogramm ------------------------------------------------*/
        /*--- Parameter über Dialog abfragen -------------------------------*/
        while (param_dialog(&p, &c))  //Pointer Übergeben Adresse an param_dialog,
                       //nicht nur den Wert, damit die Eingaben zurückgegeben werden können.
        {        
        /* Initialisierung des Grafikausgabefensters */
            printf("Calling grafik_init_window.\n");
            grafik_init_window();

        /* Erzeugen einer virtuellen Leinwand um darauf zu zeichnen: */
            printf("Calling grafik_create_paint_area.\n");
            grafik_create_paint_area(p.xmin, p.xmax, p.ymin, p.ymax, p.xpoints, p.ypoints);
             
        /*--- Fraktal Berechnung -------------------------------------------*/
            printf("Calling fraktal.\n");
            fraktal(c, z, p);
                
        /* ------------------------*/
        /*VOR ABSCHLUSS ENTFERNEN!!*/
            printf("Calling system: pause.\n");
            system("pause");
        /*-------------------------*/

        }       
                
        /* Aufräumen und Freigeben der benutzten Grafikressourcen */
        grafik_close_window();
        return 0;
}


// -- Hilfsfunktionen ---
static void init_exit(void)
{
        if(atexit(goodbye_msg)){
                fprintf(stderr, "Fehler bei Registrierung der Exitfunktion\n");
                exit(-1);
        }
}

void goodbye_msg(void)
{
        printf("MRT1, V3, Programm beendet.\n");
}

/* EOF MAIN_C */
