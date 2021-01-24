/* BOF FRAKTAL_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */


#ifndef FRAKTAL_H
#define FRAKTAL_H

/*--- Datentypvereinbarungen -----------------------------------------------*/
typedef enum{
    mandel = 'm', julia = 'j'
}fraktal_t; /*fraktal_t außerhalb param_t definiert, damit wir in fraktal() auf dessen elemente zugreifen können*/

typedef struct
{
    double radius;
    int imax;
    fraktal_t menge;
    double xmin, xmax, ymin, ymax;
    int xpoints, ypoints;
} param_t;

typedef struct 
{
    double real;
    double imag;
} complex_t;

/*--- Fraktal analysieren und grafisch darstellen --------------------------*/

int get_itera(complex_t c, complex_t z, param_t param);

#include "graphic.h" /*eingebunden, damit wir mit dem datentyp des rückgabewertes arbeiten können*/
color_name_t get_color_value(int i, int imax); /*datentyp zum selben wie vom enum geändert*/

void fraktal(complex_t c, complex_t z);

#endif /* FRAKTAL_H */
/* EOF FRAKTAL_H */