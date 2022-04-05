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
  t->min = ((t->secondesEcoules /60)%60);
  t->sec = ((t->secondesEcoules /60)%60);
  int millisecondes = SDL_GetTicks()%60;
  sprintf(t->entree, "%02d:%02d:02d", t->min, t->sec, millisecondes);
  t->texte = TTF_RenderText_Blended(t->policetemps, t->entree, CouleurNoire);
  SDL_BlitSurface(t->texte, NULL, screen, &(t->texteSurEcran));
}
/*----------------------------------------------------------*/
void entrerNomJoueur(char nomJoueur[])
{
  SDL_Event event;
  
  SDL_PollEvent(&event);
  switch(event.type)
    { 
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
       {
         case SDLK_a:
            printf("a \n"); 
       }
      break;                    
    }
}
/*----------------------------------------------------------*/
void sauvegarder(int score, char nomJoueur[], char nomFichier[])
{
  FILE *f = NULL;
  nomFichier = "Sauvegardage";
  f = fopen(nomFichier, "w");
  fprintf(f,"%d %s", score, nomJoueur);
  fclose(f);
}
/*----------------------------------------------------------*/
void meilleur(char nomJoueur[], char nomFichier[], int *score)
{
  FILE *f = NULL;
}
/*----------------------------------------------------------*/
void Liberer(MiniMap * m)
{
  free(m);
}
/*---------------------------------------------------------*/
