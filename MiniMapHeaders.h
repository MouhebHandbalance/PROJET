#ifndef MiniMapHeaders_H
#define MiniMapHeaders_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
/**
* @file MiniMapHeaders.h
* @brief Les fonctions et strectures necessaires Pur la tache Minimap
* @author Mouheb
* @version 0.1
* @date Apr 01, 2022
*
* Testing program for background scrollilng
*
*/

/**
* @struct MiniMap
* @brief Strecture Minimap(Position sur ecran, espace dans la memoire)
*/
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
  TTF_Font *policetemps;
  
  char entree[100];
  time_t t1, t2;
  int secondesEcoules;
  int min, sec;
}temps;

typedef struct
{
  SDL_Surface *score;
  SDL_Rect scorePos;
  int val;
  char entree[100000];
  
  TTF_Font *policescore;
  
}score;


MiniMap initMiniMap(MiniMap m);
void MAJMinimap(SDL_Rect posJoueur, MiniMap *m,int redimensionnement);
void afficher(MiniMap m, SDL_Surface *screen);
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *screen);
void entrerNomJoueur(char nomJoueur[]);

void sauvegarder(int score,char nomjoueur[],char nomfichier[]);
void meilleur (char nomfichier[],int *score,char nomjoueur[]);

void Liberer(MiniMap *m);

#define SCREEN_W 800
#define SCREEN_H 800
#endif
