/* BOF MAIN_C
 Praktikumsversuch: Einführung in die Sprache C
 Haupt-Programm
 */

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <SDL.h>

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

        init_exit();
        int keep_going = 1;
       
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

        while (keep_going != 0)
        {

        
        /*--- Parameter über Dialog abfragen -------------------------------*/
            keep_going = param_dialog(p, c); //gibt 0 zurück wenn programm beenden, sonst 1
         
        /*--- Überprüfen der Exitbedingung ---------------------------------*/
            if (keep_going == 0)
            {
                break;
            }

        /* Initialisierung des Grafikausgabefensters */
            grafik_init_window();

        /* Erzeugen einer virtuellen Leinwand um darauf zu zeichnen: */
            grafik_create_paint_area(p.xmin, p.xmax, p.ymin, p.ymax, p.xpoints, p.ypoints);
        
        /* virtuelle Leinwand vor dem Zeichnen aktivieren */
            //grafik_lock_for_painting();

        /* Bitte ersetzen Sie folgenden Funktionsaufruf durch ihre eigene
         * Implementation der Fraktalberechnung und -anzeige. */
        
            fraktal(c, z, p);

        
         /* virtuelle Leinwand deaktivieren und im Grafikfenster ausgeben. */
        //grafik_unlock_and_show();

       
        

        
        /* ------------------------*/
        /*VOR ABSCHLUSS ENTFERNEN!!*/
            system("pause");
        /*-------------------------*/

        }
        
                
        /* Aufräumen und freigeben der benutzten Grafikressourcen */
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
