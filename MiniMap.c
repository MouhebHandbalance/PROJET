#include "MiniMapHeaders.h"

MiniMap initMiniMap(MiniMap m)
{
  m.ImageMiniature = NULL;
  
  return m;
}
/*----------------------------------------------------------*/
void MAJMinimap(SDL_Rect posJoueur, MiniMap *m, int redimensionnement)
{
  m->PositionPesonnageSurMiniMap.x = posJoueur.x + redimensionnement;
  m->PositionPesonnageSurMiniMap.y = posJoueur.y + redimensionnement;
}
/*----------------------------------------------------------*/
void afficher(MiniMap m, SDL_Surface *screen)
{
  m = initMiniMap(m);
  m.PositionMiniMapSurEcran.x = 32;
  m.PositionMiniMapSurEcran.y = 20;
  
  m.ImageMiniature = IMG_Load("/home/mouheb/PROJET/src/Images/MiniMapLVL1.png");
  if(m.ImageMiniature == NULL)
  {
   printf("Erreur : %s \n", SDL_GetError());
   SDL_Quit();
  }
  SDL_BlitSurface(m.ImageMiniature, NULL, screen, &m.PositionMiniMapSurEcran);
  
}
/*----------------------------------------------------------*/
void initialiser_temps(temps *t)
{
  t->texte = NULL;
  t->texteSurEcran.x = 1000;
  t->texteSurEcran.y = 20;
  t->policetemps = NULL;
  t->policetemps = TTF_OpenFont("f.ttf", 40);
  strcpy(t->entree,"");
  (t->secondesEcoules) = 0;
  time(&(t->t1));
}
/*----------------------------------------------------------*/
void afficher_temps(temps *t, SDL_Surface *screen)
{
  SDL_Color CouleurNoire = {0, 0, 0};
  
  time(&(t->t2));
  t->secondesEcoules = t->t2 - t->t1;
  t->sec = ((t->secondesEcoules/60) %60);
  t->min = ((t->secondesEcoules)%60);
  
  int millisecondes = SDL_GetTicks()%60;
  sprintf(t->entree, "%02d:%02d:%02d", t->min, t->sec, millisecondes);
  t->texte = TTF_RenderText_Blended(t->policetemps, t->entree, CouleurNoire);
  SDL_BlitSurface(t->texte, NULL, screen, &(t->texteSurEcran));
}
/*----------------------------------------------------------*/
void sauvegarder(int score,char nomjoueur[],char nomfichier[])
{
  FILE *f = NULL;
  f = fopen(nomfichier, "a");
  fprintf(f, "%s %d \n", nomjoueur, score);
  fclose(f);
}
/*----------------------------------------------------------*/
void meilleur (char nomfichier[],int *score,char nomjoueur[])
{
  char nomx[10];
  int max = 0;
  FILE *f = NULL;

  f = fopen(nomfichier, "r");
  while(fscanf(f,"%s %d\n",nomjoueur,score) != EOF)
  {
    if(*score > max)
    {
      max = *score;
      strcpy(nomx, nomjoueur);
    }
    *score = max;
    strcpy(nomx, nomjoueur);
    
  }
  fclose(f);
}
/*----------------------------------------------------------*/

void Liberer(MiniMap * m)
{
  free(m);
}
/*---------------------------------------------------------*/
