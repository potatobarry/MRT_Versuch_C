/* BOF FRAKTAL_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#include "fraktal.h"
#include "graphic.h"



/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
int get_itera(complex_t c, complex_t z, param_t param){ /*Wir brauchen den Eingabeparameter param, damit wir die Bedingungen für die While-schleife haben*/
	int itera = 0;
	double a = c.real;
	double b = c.imag;
	double xnew = z.real;
	double ynew = z.imag;
	double xzero, yzero;
	while (((xnew * xnew) + (ynew * ynew) < (param.radius * param.radius)) && (itera < param.imax)) 
	{ /*Prüft, ob die komplexe Zahl innerhalb der Menge liegt und dass die max. Iterationszahl nicht überschritten wird*/
		xzero = xnew;
		yzero = ynew;
		xnew = (xzero * xzero) - (yzero * yzero) + a; /*Berechnung des neuen Fraktals durch Umstellung der Fraktalformel*/
		ynew = 2 * xzero * yzero + b;
	    itera++;
	} 
	return itera;
	/*Berechnung des Fraktals innerhalb der get_itera-methode, weil in den Iterationen mit z(i+1) weitergerechnet wird*/
}

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
color_name_t get_color_value(int i, int imax) {
	color_name_t colorname;
	int colorvalue = i % 31 + 1; /*begrenzung der iterationen auf max. anzahl von farbwerten*/
	if(i >= imax){
		return colorname = Black; /*ausgabe schwarz, wenn imax überschritten wird*/
	}
	else
	{ /*zuordnung der farben zu iterationsanzahl*/
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
			default: colorname = Black;
				break;
		}
		return colorname;
	}
}


/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/
void fraktal(complex_t c, complex_t z, param_t p){
	double xstep = (p.xmax - p.xmin) / p.xpoints; /*Berechnung der Schrittgröße*/
	double ystep = (p.ymax - p.ymin) / p.ypoints;
	double x, y;
	complex_t zvar, cvar;
	int i = 0;
	color_name_t colorname;
		
	for(x = p.xmin; x < p.xmax; x = x + xstep){ /*Grenzen des Feldes*/
		for(y = p.ymin; y < p.ymax; y = y + ystep){
			if(p.menge == mandel){
				printf("Varying cvar.\n");						//debug output. Delete before final?
				cvar.real = x; /*bei Mandel wird c variiert*/
				cvar.imag = y;
				i = get_itera(cvar, z, p);					//debug output. Delete before final?
				printf("cvar.real: %f, cvar.imag: %f.\n", cvar.real, cvar.imag);
			}
			else {
				printf("Varying zvar.\n");						//debug output. Delete before final?
				zvar.real = x; /*bei Julia wird z variiert*/
				zvar.imag = y;
				i = get_itera(c, zvar, p);
				printf("cvar.real: %f, cvar.imag: %f.\n", zvar.real, zvar.imag); //debug output. Delete before final?
			}
			printf("Painting point y\n");

			colorname = get_color_value(i, p.imax);
					
			printf("Painting point x\n");
			grafik_lock_for_painting();
			grafik_paint_point(x, y, colorname);
			grafik_unlock_and_show();
		}
		
	}
};

/* EOF FRAKTAL_C */
