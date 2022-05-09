#ifndef tictactoe_H
#define tictactoe_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct{
SDL_Surface *pos1;
SDL_Rect pos2;
}symboleO;


typedef struct{
SDL_Surface *pos1;
SDL_Rect pos2;
}symboleX;


typedef struct{
SDL_rect Position;
TTF_Font *front;
SDL_Surface * SurfaceTexte;
SDL_Color texteColor;
char Texte [3]
}score;

int turns;

int joueur;

int tabsuivi[9];


void initialiserTic (tic * t) ;
void afficherTic(int tabsuivi[],SDL_Surface* ecran);
int atilganer(int tabsuivi[]);
void Resultat (int tabsuivi[],SDL_Surface* ecran);
void liberer( tic t);
int minmax(int tabsuivi[9],int joueur);
void calcul_coup(int tabsuivi[9]);
#endif

