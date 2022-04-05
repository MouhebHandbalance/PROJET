#ifndef MiniMapHeaders_H
#define MiniMapHeaders_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
  SDL_Surface *ImageMiniature;
  SDL_Rect PositionMiniMapSurEcran;
  SDL_Surface *ImagePesonnage;
  SDL_Rect PositionPesonnageSurMiniMap;
}MiniMap;


typedef struct
{
  SDL_Surface *texte;
  SDL_Rect texteSurEcran;
  SDL_Surface *policetemps;
  TTF_Font *policeTexte;
  
  char entree[100];
  time_t t1, t2;
  int secondesEcoules;
  int min, sec;
}temps;

MiniMap initMiniMap(MiniMap m);
void MAJMinimap(SDL_Rect posJoueur, MiniMap *m,int redimensionnement);
void afficher(MiniMap m, SDL_Surface *screen);
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *screen);
void entrerNomJoueur(char nomJoueur[]);
void sauvegarder(int score, char nomJoueur[], char nomFichier[]);
void meilleur(char nomJoueur[], char nomFichier[], int *score);
void Liberer(MiniMap *m);

#define SCREEN_W 800
#define SCREEN_H 800
#endif
