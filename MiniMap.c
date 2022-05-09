#include "MiniMapHeaders.h"
/**
* @file MiniMap.c
* @brief Tache Minimap: AFFICHAGE DU MINIMAP, MANIPULATION DU TEMPS, MANIPULATION DU SCORE ET MEILLEUR SCORE
* @author yassine
* @version 0.1
* @date Apr 01, 2022
*/

/**
* @brief initialiser le Minimap
* @param m Le minimap
* @return Nothing
*/
MiniMap initMiniMap(MiniMap m)
{
  m.ImageMiniature = NULL;
  
  return m;
}
/*----------------------------------------------------------*/
/**
* @brief Redimentionner le Minimap
* @param posJoueur Position du joueur sur minimap
* @param *m Pointeur sur minimap
* @param redimentionnement redimentionnement map et personnage
* @return Nothing
*/
void MAJMinimap(SDL_Rect posJoueur, MiniMap *m, int redimensionnement)
{
  m->PositionPesonnageSurMiniMap.x = posJoueur.x + redimensionnement;
  m->PositionPesonnageSurMiniMap.y = posJoueur.y + redimensionnement;
}
/*----------------------------------------------------------*/
/**
* @brief affichager du Minimap sur l'ecran
* @param m Le minimap a afficher
* @param screen La fenetre ou le minimap sera afficher
* @return Nothing
*/
void afficher(MiniMap m, SDL_Surface *screen)
{
  m = initMiniMap(m);
  m.PositionMiniMapSurEcran.x = 32;
  m.PositionMiniMapSurEcran.y = 20;
  
  m.ImageMiniature = IMG_Load("/home/yassine/PROJET/src/Images/MiniMapLVL1.png");
  if(m.ImageMiniature == NULL)
  {
   printf("Erreur : %s \n", SDL_GetError());
   SDL_Quit();
  }
  SDL_BlitSurface(m.ImageMiniature, NULL, screen, &m.PositionMiniMapSurEcran);
  
}
/*----------------------------------------------------------*/
/**
* @brief initialisation du temps 
* @param *t pointeur sur temps
* @return Nothing
*/
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
/**
* @brief affichage du temps sur l'ecran
* @param *t pointeur sur temps pour pouvoir calculer le temps ecoulés
* @param screen La fenetre ou le minimap sera afficher
* @return Nothing
*/
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
/**
* @brief sauvegardage du score du Joueur
* @param score le Score a sauvegarder
* @param nomjoueur[] le nom du Joueur a sauvegarder
* @param nomjoueur[] le nom du Fichier ou on va sauvegarder le score
* @return Nothing
*/
void sauvegarder(int score,char nomjoueur[],char nomfichier[])
{
  FILE *f = NULL;
  f = fopen(nomfichier, "a");
  fprintf(f, "%s %d \n", nomjoueur, score);
  fclose(f);
}
/*----------------------------------------------------------*/
/**
* @brief Meilleur score
* @param score le meuilleur Score
* @param nomjoueur[] le nom du Joueur qui a le meilleur score
* @param nomjoueur[] le nom du Fichier ou on va sauvegarder le score
* @return Nothing
*/
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
/**
* @brief Liberation du minimap de la memoire
* @param *m le pointeur sur le minimap a liberer
* @return Nothing
*/
void Liberer(MiniMap * m)
{
  free(m);
}
/*---------------------------------------------------------*/
