/* BOF DIALOG_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"

 Samuel Quinn Wagner, 4760211
 Nina Silvia Dröge, 4764513
 Lukas Gerbeth, 4817176
 Huu An Nguyen, 4763633

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