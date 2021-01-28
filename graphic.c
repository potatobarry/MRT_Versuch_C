/* BOF GRAPHIC_C
 * Praktikumsversuch: Einführung in die Sprache C
 * Programm-Modul "Grafische Darstellung"
 *
 * vorgegebene Funktionalität zur Erleichterung der Grafikausgabe.
 * 
 * Samuel Quinn Wagner, 4760211
 * Nina Silvia Dröge, 4764513
 * Lukas Gerbeth, 4817176
 * Huu An Nguyen, 4763633
 *
 */

#include "graphic.h"
#include <stdio.h>
#include <stdlib.h>
#include <io.h>


/** interne Definitionen.
 * static ⇒ alle Variablen nur in diesem Modul sichbar
 */

// Fenstergröße
static const int WIN_WIDTH=800;
static const int WIN_HEIGHT=600;

// Grafikausgabe SDL-Ressourcen
static SDL_Window *win = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

// Anzahl vorgegebener Farbwerte
#define NUM_COLORS 32

/** Zuordnungstabelle Farb-Namen ⇒ RGB-Wert.
 Quelle der Namen und Farbwerte:
 http://pixeljoint.com/forum/forum_posts.asp?TID=16247 
 */
static const unsigned char rgb_vals[NUM_COLORS][3] = {
        { /*Black*/                0,       0,       0 },
        { /*Valhalla*/            34,      32,      52 },
        { /*Loulou*/              69,      40,      60 },
        { /*Oiled Cedar*/        102,      57,      49 },
        { /*Rope*/               143,      86,      59 },
        { /*Tahiti Gold*/        223,     113,      38 },
        { /*Twine*/              217,     160,     102 },
        { /*Pancho*/             238,     195,     154 },
        { /*Golden Fizz*/        251,     242,      54 },
        { /*Atlantis*/           153,     229,      80 },
        { /*Christi*/            106,     190,      48 },
        { /*Elf Green*/           55,     148,     110 },
        { /*Dell*/                75,     105,      47 },
        { /*Verdigris*/           82,      75,      36 },
        { /*Opal*/                50,      60,      57 },
        { /*Deep Koamaru*/        63,      63,     116 },
        { /*Venice Blue*/         48,      96,     130 },
        { /*Royal Blue*/          91,     110,     225 },
        { /*Cornflower*/          99,     155,     255 },
        { /*Viking*/              95,     205,     228 },
        { /*Light Steel Blue*/   203,     219,     252 },
        { /*White*/              255,     255,     255 },
        { /*Heather*/            155,     173,     183 },
        { /*Topaz*/              132,     126,     135 },
        { /*Dim Gray*/           105,     106,     106 },
        { /*Smokey Ash*/          89,      86,      82 },
        { /*Clairvoyant*/        118,      66,     138 },
        { /*Brown*/              172,      50,      50 },
        { /*Mandy*/              217,      87,      99 },
        { /*Plum*/               215,     123,     186 },
        { /*Rainforest*/         143,     151,      74 },
        { /*Stinger*/            138,     111,      48 }
};

static double xmin = 0, ymin = 0, deltax = 0, deltay = 0;
static double xres = 0, yres = 0;

/*
* Grafikausgabe initialisieren.
*/
void grafik_init_window(void)
{
        if(SDL_Init(SDL_INIT_VIDEO) < 0){
                fprintf(stderr, "%s: SDL_Init failed: %s\n",
                        __FUNCTION__,
                        SDL_GetError());
                exit(-1);
        }
        
        if(atexit(grafik_close_window)){
                fprintf(stderr,
                        "%s: Fehler bei Registrierung der Exitfunktion\n",
                        __FUNCTION__);
                exit(-1);
        }
        
        win = SDL_CreateWindow("MRT1-V3-Grafik",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               WIN_WIDTH,
                               WIN_HEIGHT,
                               0);
        if(!win){
                fprintf(stderr, "%s: SDL_CreateWindow failed: %s",
                        __FUNCTION__,
                        SDL_GetError());
                exit(-1);
        }
        
        renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_TARGETTEXTURE);
        if(!renderer){
                fprintf(stderr, "%s: SDL_CreateRenderer failed: %s",
                        __FUNCTION__,
                        SDL_GetError());
                exit(-1);
        }

}

// initialisiere die Textur zum bemalen
void grafik_create_paint_area(const double x_min, const double x_max,
                     const double y_min, const double y_max,
                     const unsigned x_points, const unsigned y_points)
{
        if(!renderer){
                fprintf(stderr, "%s: Renderer not initialized",
                        __FUNCTION__);
                return;
        }
        
        if(texture)
                SDL_DestroyTexture(texture);
        
        texture = SDL_CreateTexture(renderer,
                                    SDL_PIXELFORMAT_RGB888,
                                    SDL_TEXTUREACCESS_TARGET,
                                    x_points,
                                    y_points);
        if(!texture){
                fprintf(stderr, "%s: SDL_CreateTexture failed: %s",
                        __FUNCTION__,
                        SDL_GetError());
                exit(-1);
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, WIN_WIDTH, WIN_HEIGHT);
        
        SDL_SetRenderTarget(renderer, texture);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        
        xmin = x_min;
        ymin = y_min;
        xres = x_points;
        yres = y_points;
        deltax = x_max - x_min;
        deltay = y_max - y_min;
}



/*
* einzelnen Farbpunkt setzen.
 */
int grafik_paint_point(double x, double y,
                       color_name_t colorname)
{
        Uint32 xp;
        Uint32 yp;
        xp = round(((x - xmin) / deltax) * xres);
        yp = round(((y - ymin) / deltay) * yres);
        
        if ((colorname < 0) || (colorname >= NUM_COLORS)){
                printf("color reset");
                colorname = 6;
        }        

        if(!texture){
                fprintf(stderr, "%s: Texture not initialized.",
                        __FUNCTION__);
                return 0;
        }

        SDL_SetRenderDrawColor(renderer,
                               rgb_vals[colorname][0],
                               rgb_vals[colorname][1],
                               rgb_vals[colorname][2],
                               255 /*opaque*/);
        SDL_RenderDrawPoint(renderer, xp, yp);
        
        return 1;
}


/*
* Ausgabefenster sperren um zu zeichnen.
*/
void grafik_lock_for_painting(void)
{
        if(!renderer || !texture){
                fprintf(stderr, "%s: Grafik not initialized.",
                        __FUNCTION__);
                return;
        }
        SDL_SetRenderTarget(renderer, texture);
}


/*
* Ausgabefenster entsperren und gepufferte Daten ausgeben.
*/
void grafik_unlock_and_show(void)
{
        if(!renderer || !texture){
                fprintf(stderr, "%s: Grafik not initialized.",
                        __FUNCTION__);
                return;
        }
        
        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
}


/*
* Grafikfenster schließen und aufräumen.
*/
void grafik_close_window(void) {
        if(texture)
                SDL_DestroyTexture(texture);
        texture=NULL;
        
        if(renderer)
                SDL_DestroyRenderer(renderer);
        renderer=NULL;
        if(win)
                SDL_DestroyWindow(win);
        win=NULL;
        SDL_Quit();
}


// Demonstration der Nutzung der vorgegebene Grafikfunktionen
// diese Funktion bitte nicht im eigenen Projekt nutzen.
void farb_demonstration(void)
{
    printf("help");
   
   
    grafik_create_paint_area(-2, 2, -2, 2, 100, 32);

    // Bildschirm muss zum Setzen von Pixeln gesperrt sein
    grafik_lock_for_painting();

    // zeichne jeweils eine Linie in einer eigenen Farbe
    int cn = 0;
    for (double j = -2; j < 2; j = j + 0.125) {
        cn = (cn + 1) % 32;
        for (double i = -2; i < 2; i = i + 0.04) {
            grafik_paint_point(i, j, cn);
        }
    }

    grafik_unlock_and_show(); // Alle Änderungen auf Bildschirm ausgeben

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
        "MRT 1 - V3 - Information",
        "              MRT 1 - V3 - Farbdemonstration\n\n"
        "Den Dialog bitte schließen, um das Programm zu beenden.\n"
        "     (Das Grafikfenster wird nicht aktualisiert.)",
        NULL);
              
}


/* EOF GRAFIC_C */
