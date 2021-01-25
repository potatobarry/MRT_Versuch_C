/* BOF DIALOG_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"
 */

#ifndef DIALOG_H
#define DIALOG_H
#include "fraktal.h"


/*--- Parameter Dialog -----------------------------------------------------*/

int param_dialog(param_t *p, complex_t *c);
fraktal_t get_F();

/*--- Funktion zum einlesen des ersten Characters einer getchar() Eingabe --*/
char input_char();


#endif /* DIALOG_H */

/* EOF DIALOG_H */
/*kommentar*/