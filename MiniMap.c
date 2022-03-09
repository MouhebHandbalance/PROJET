#include "MiniMapHeaders.h"

MiniMap initMiniMap(MiniMap m)
{
  m.ImageMiniature = NULL;
  
  return m;
}
/*----------------------------------------------------------*/
void MAJMinimap(SDL_Rect posJoueur, MiniMap *m, SDL_Rect camera, int redimensionnement)
{
  m->PositionPesonnageSurMiniMap.x = posJoueur.x * redimensionnement/100;
  m->PositionPesonnageSurMiniMap.y = posJoueur.y * redimensionnement/100;
}
/*----------------------------------------------------------*/
void afficher(MiniMap m, SDL_Surface *screen)
{
  m = initMiniMap(m);
  m.PositionMiniMapSurEcran.x = 32;
  m.PositionMiniMapSurEcran.y = 720;
  
  m.ImageMiniature = IMG_Load("/home/mouheb/PROJET/src/Images/MiniMapLVL1.png");
  if(m.ImageMiniature == NULL)
  {
   printf("Erreur : %s \n", SDL_GetError());
   SDL_Quit();
  }
  SDL_BlitSurface(m.ImageMiniature, NULL, screen, &m.PositionMiniMapSurEcran);
  
}
/*----------------------------------------------------------*/
void Liberer(MiniMap * m)
{
  free(m);
}
/*---------------------------------------------------------*/
