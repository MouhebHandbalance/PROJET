#ifndef enigme2_h
#define enigme2_h
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct enigme_
{
char* q;
char* r1;
char* r2;
char* r3;
int rj;
SDL_Surface *texte  ;
SDL_Surface *texte1 ;
SDL_Surface *texte2  ;
SDL_Surface *texte3   ;
SDL_Rect positiontexte ;
SDL_Rect positiontexte1 ;
SDL_Rect positiontexte2 ;
SDL_Rect positiontexte3 ;
}enigme;
typedef struct perso
{
int vies,score;
char* img;
}personne;
typedef struct  bg
{
char* cheimage;
}background;

void lireEnigmes(char * nom_fichier,int nbquestion,enigme* tabEnigmes);
void InitEnigme(enigme *e,char * nomfichier);
void afficherEnigme(enigme e, SDL_Surface * screen);
void sauvegarder(personne p,background b,char * nomfichier);
int cherger(personne *p, background *b,char *nomfichier);
void setrects(SDL_Rect* clip);
//void BoutonsMenuPrincipal();
#define SCREEN_W 800
#define SCREEN_H 800

#endif
