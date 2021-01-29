/* BOF GRAPHIC_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Grafische Darstellung"

 Samuel Quinn Wagner, 4760211
 Nina Silvia Dröge, 4764513
 Lukas Gerbeth, 4817176
 Huu An Nguyen, 4763633

 */

#ifndef GRAFIK__H
#define GRAFIK__H

/** dieses Programmmodul benutzt die Grafikbibliothek `libSDL2`
 * Homepage: https://www.libsdl.org
 *
 * zum Installieren der benötigten Dateien innerhalb der MRT-VM,
 * folgenden Kommandozeilenbefehl nutzen:
  sudo apt-get install libsdl2-dev
 */
#include <SDL2/SDL.h>

/*--- Typdefinitionen ------------------------------------------------------*/

/** Farbnamen der 32 vorgegebenen Farben
 */
typedef enum { Black = 0,
               Valhalla,
               Loulou,
               Oiled_Cedar,
               Rope,
               Tahiti_Gold,
               Twine,
               Pancho,
               Golden_Fizz,
               Atlantis,
               Christi,
               Elf_Green,
               Dell,
               Verdigris,
               Opal,
               Deep_Koamaru,
               Venice_Blue,
               Royal_Blue,
               Cornflower,
               Viking,
               Light_Steel_Blu,
               White,
               Heather,
               Topaz,
               Dim_Gray,
               Smokey_Ash,
               Clairvoyant,
               Brown,
               Mandy,
               Plum,
               Rainforest,
               Stinger
} color_name_t;


/*--------------------------------------------------------------------------*/
/*    Funktionen                                                            */
/*--------------------------------------------------------------------------*/

/*--- Grafik initialisieren und schließen ----------------------------------*/

/** Initialisiere das Grafikfenster zum Start des Programms.
 */
void grafik_init_window(void);

/** Schließe das Grafikfenster und beende SDL.
 * wird auch im Fehlerfall ausgeführt.
 */
void grafik_close_window(void);

/** erzeugt neuen Speicherbereich zum Zeichnen.
 * entfernt den alten Speicherbereich aus dem RAM vor dem Neuanlegen
 * Benutze diese Funktion um die Auflösung oder die Bereichsgrenzen zu ändern
 */
void grafik_create_paint_area(const double x_min, const double x_max,
                       const double y_min, const double y_max,
                       const unsigned x_points, const unsigned y_points);


/*--- Ausgabefenster sperren und entsperren --------------------------------*/

/** Ausgabefenster sperren um zu zeichnen.
*/
void grafik_lock_for_painting();

/** Ausgabefenster entsperren und gepufferte Daten ausgeben.
*/
void grafik_unlock_and_show();

/*--- Zeichenfunktionen ----------------------------------------------------*/

/** setze einen einzelnen Grafikpunkt.
 * and den Koordinaten der Berechnung, 
 * die Umrechnung in Bildschirmpixel erfolgt automatisch.
 * Angebe des Farbwertes mittels der oben definierten Farbnamen.
 */
int grafik_paint_point(double x, double y,
                       color_name_t colorname);


/*--- Hilfsfunktion für den Einstieg in die Praktikumsaufgabe --------------*/

// Demonstrationsfunktion, bitte nicht im eigenen Projekt verwenden.
void farb_demonstration(void);

#endif /* GRAFIK__H */
/* EOF GRAFIK__H */
