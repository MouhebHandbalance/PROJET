#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


typedef struct
{
  SDL_Surface *image ;
SDL_Surface *mask;
SDL_Surface *i;
  SDL_Rect   pos ;
SDL_Rect anim;
SDL_Rect  sprite ;
int num_image;//numéro image
}background;



void initback (background *bg,Mix_Music *musique);
void afficher_back(background bg,SDL_Surface *ecran);
void scrolling (background *bg,int vitesse,int d);
void initpartage (background *bg1,background *bg2,Mix_Music *musique);
void animation_startv2(SDL_Surface *screen,SDL_Surface *image);
void animer(background *bg);
int is_black(int x,int y,SDL_Surface *i);
