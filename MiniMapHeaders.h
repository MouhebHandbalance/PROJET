#ifndef MiniMapHeaders_H
#define MiniMapHeaders_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
  SDL_Surface *ImageMiniature;
  SDL_Rect PositionMiniMapSurEcran;
  SDL_Surface *ImagePesonnage;
  SDL_Rect PositionPesonnageSurMiniMap;
}MiniMap;

MiniMap initMiniMap(MiniMap m);
void MAJMinimap(SDL_Rect posJoueur, MiniMap *m, SDL_Rect camera, int redimensionnement);
void afficher(MiniMap m, SDL_Surface *screen);
void Liberer(MiniMap *m);

#define SCREEN_W 800
#define SCREEN_H 800

#endif
