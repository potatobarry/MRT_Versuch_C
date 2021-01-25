/* BOF FRAKTAL_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#include "fraktal.h"
#include "graphic.h"



/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
int get_itera(complex_t c, complex_t z, param_t param){ /*wir brauchen den eingabeparameter param, damit wir die bedingungen für die while schleife haben*/
	int itera = 0;
	double a = c.real;
	double b = c.imag;
	double xnew = z.real;
	double ynew = z.imag;
	double xzero, yzero;
	while (((xnew * xnew) + (ynew * ynew) < (param.radius * param.radius)) && (itera < param.imax)) { /*prüft ob, die komlexe zahl innerhalb der menge liegt und dass wir die max. iterationszahl nicht überschreiten*/
		xzero = xnew;
		yzero = ynew;
		xnew = (xzero * xzero) - (yzero * yzero) + a; /*berechnung des neuen fraktals durch umstellung der fraktalformel*/
		ynew = 2 * xzero * yzero + b;
	    itera++;
	} return itera;
	/*berechnung des fraktals innerhalb der get_itera-methode, weil in den ietrationen mit z(i+1) weitergerechnet wird*/
}

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
color_name_t get_color_value(int i, int imax) {
	color_name_t colorname = Black;
	int colorvalue = i % 31 + 1; /*begrenzung der iterationen auf max. anzahl von farbwerten*/
	if(i >= imax){
		return colorname = Black; /*ausgabe schwarz, wenn imax überschritten wird*/
	}
	else{ /*zuordnung der farben zu iterationsanzahl*/
		switch(colorvalue){
			case 1: colorname = Valhalla;
			break;
			case 2: colorname = Loulou;
			break;
			case 3: colorname = Oiled_Cedar;
			break;
			case 4: colorname = Rope;
			break;
			case 5: colorname = Tahiti_Gold;
			break;
			case 6: colorname = Twine;
			break;
			case 7: colorname = Pancho;
			break;
			case 8: colorname = Golden_Fizz;
			break;
			case 9: colorname = Atlantis;
			break;
			case 10: colorname = Christi;
			break;
			case 11: colorname = Elf_Green;
			break;
			case 12: colorname = Dell;
			break;
			case 13: colorname = Verdigris;
			break;
			case 14: colorname = Opal;
			break;
			case 15: colorname = Deep_Koamaru;
			break;
			case 16: colorname = Venice_Blue;
			break;
			case 17: colorname = Royal_Blue;
			break;
			case 18: colorname = Cornflower;
			break;
			case 19: colorname = Viking;
			break;
			case 20: colorname = Light_Steel_Blu;
			break;
			case 21: colorname = White;
			break;
			case 22: colorname = Heather;
			break;
			case 23: colorname = Topaz;
			break;
			case 24: colorname = Dim_Gray;
			break;
			case 25: colorname = Smokey_Ash;
			break;
			case 26: colorname = Clairvoyant;
			break;
			case 27: colorname = Brown;
			break;
			case 28: colorname = Mandy;
			break;
			case 29: colorname = Plum;
			break;
			case 30: colorname = Rainforest;
			break;
			case 31: colorname = Stinger;
			break;
		}
		return colorname;
	}
}


/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/
void fraktal(complex_t c, complex_t z, param_t param){
	double xmid = (param.xmax - param.xmin) / param.xpoints; /*berechnung des koordinatenursprungs*/
	double ymid = (param.ymax - param.ymin) / param.ypoints;
	double x, y;
	complex_t zvar, cvar;
	int i = 0;
	color_name_t colorname;
	for(x = param.xmin; x < param.xmax; x = x + xmid){ /*grenzen des feldes*/
		for(y = param.ymin; y < param.ymax; y = y + ymid){
			if(param.menge == mandel){
				printf("Varying cvar.\n");						//debug output. Delete before final?
				cvar.real = x; /*bei mandel wird c variiert*/
				cvar.imag = y;
				i = get_itera(cvar, z, param);					//debug output. Delete before final?
				printf("cvar.real: %f, cvar.imag: %f.\n", cvar.real, cvar.imag);
			}
			else {
				printf("Varying zvar.\n");						//debug output. Delete before final?
				zvar.real = x; /*bei julia wird z variiert*/
				zvar.imag = y;
				i = get_itera(c, zvar, param);
				printf("cvar.real: %f, cvar.imag: %f.\n", zvar.real, zvar.imag); //debug output. Delete before final?
			}
			colorname = get_color_value(i, param.imax);
			grafik_lock_for_painting();
			grafik_unlock_and_show();
			grafik_paint_point(x, y, colorname);
		}
	}
};

/* EOF FRAKTAL_C */
