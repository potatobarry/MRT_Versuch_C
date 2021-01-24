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
        
        /*--- Parameter über Dialog abfragen -------------------------------*/
       
        param_dialog(p, c);

        /* Initialisierung des Grafikausgabefensters */
        //grafik_init_window();

        /* Erzeugen einer virtuellen Leinwand um darauf zu zeichnen: */
        //grafik_create_paint_area(x_min, x_max, y_min, y_max, x_points, y_points);
        
        /* virtuelle Leinwand vor dem Zeichnen aktivieren */
        //grafik_lock_for_painting();

        /* Bitte ersetzen Sie folgenden Funktionsaufruf durch ihre eigene
         * Implementation der Fraktalberechnung und -anzeige. */
        //farb_demonstration();
        
        
         /* virtuelle Leinwand deaktivieren und im Grafikfenster ausgeben. */
        //grafik_unlock_and_show();

        /* Aufrufen von InputChar() um das Programm nach dem öffnen der
         Graphik anzuhalten. Erst wenn in der Konsole eine Taste gedrückt
         wird, schließt sich das Fenster wieder. */
        

         /* Aufräumen und freigeben der benutzten Grafikressourcen */
        //grafik_close_window();
        
        /* ------------------------*/
        /*VOR ABSCHLUSS ENTFERNEN!!*/
        
        system("pause");
        
        /*---------------------------*/
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
