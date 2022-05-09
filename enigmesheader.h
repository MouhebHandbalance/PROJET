#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h> 
#include "SDL/SDL_ttf.h"

/**
* @struct enigme
* @brief struct for puzzle
*/

typedef struct
{
  SDL_Surface *Image_Background; /*!<Surface.*/
  SDL_Rect PositionBGSurEcran; /*!<Position du background.*/
  SDL_Surface *images[6];



}enigme;

void InitEnigme(enigme *e, char *nomfichier);
void generate_afficher (SDL_Surface *screen  , char image [],enigme *e,int *alea);
void afficherEnigme(enigme e, SDL_Surface *screen, int t);
void setrects(SDL_Rect* clip);

