#include "enigme2.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void InitEnigme(enigme* e,char * nomfichier)
{
int d;


//lireEnigmes(nomfichier,3,tabEnigmes);
char* reponsejuste=NULL;
SDL_Color policeRouge = {255, 0,0} ;

FILE * fichier=fopen(nomfichier,"r");
int i;
size_t len = 0;
ssize_t read;

TTF_Font *police = NULL ;
police = TTF_OpenFont("Condensed.ttf",40);  
d = rand()%3;
for(i=0;i<=d;i++)
{
reponsejuste=NULL;
read = getline(&(e->q), &len, fichier);

read = getline(&(e->r1), &len, fichier);
read = getline(&(e->r2), &len, fichier);
read = getline(&(e->r3), &len, fichier);
read = getline(&reponsejuste, &len, fichier);
e->rj=atoi(reponsejuste);

e->texte = TTF_RenderText_Blended(police,e->q,policeRouge);
e->positiontexte.x = 50;
e->positiontexte.y = 50;


e->texte1 = TTF_RenderText_Blended(police,e->r1,policeRouge);
e->positiontexte1.x = 50;
e->positiontexte1.y = 150;



e->texte2 = TTF_RenderText_Blended(police,e->r2,policeRouge);
e->positiontexte2.x = 50;
e->positiontexte2.y = 250;

e->texte3 = TTF_RenderText_Blended(police,e->r3,policeRouge);
e->positiontexte3.x= 50;
e->positiontexte3.y = 350;
}
TTF_CloseFont(police);
fclose(fichier);

}

void afficherEnigme(enigme e, SDL_Surface * screen)
{  


int frame=0;
int n=0,answer;
SDL_Surface *horse = NULL;
SDL_Rect PositionH;
SDL_Rect rects[11];
PositionH.x=0;
PositionH.y=0;
SDL_Surface* T=NULL;

char * nomfichier="/home/nafaa/enigme2/enigme.txt";
 SDL_Surface *Image_Background = NULL; 
   SDL_Rect PositionBGSurEcran; 
       SDL_Init(SDL_INIT_VIDEO );
     TTF_Init();

//Creation de la fenetre
    SDL_Init(SDL_INIT_VIDEO );
    TTF_Init();
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
       printf("Erreur : %s \n", SDL_GetError());
       SDL_FreeSurface(T);
       SDL_Quit();
    }
    
  /////////////////////////////////////////
    
    /////////////////////////////////////////
    
    screen = SDL_SetVideoMode(1200, 680, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(screen == NULL) {
       printf("Erreur : %s \n", SDL_GetError());
       SDL_FreeSurface(T);
       SDL_Quit();
    }
    


  
    PositionBGSurEcran.x = 0;                                                                                      
    PositionBGSurEcran.y = 0;  

  
    Image_Background = IMG_Load("bl.png");
    if(Image_Background == NULL) {
       printf("Erreur : %s \n", SDL_GetError());
       SDL_FreeSurface(T);
       
       SDL_Quit();
    }
 /*  horse= IMG_Load("low.png");
      if(horse == NULL)
      {
       printf("Erreur : %s \n", SDL_GetError());
       SDL_FreeSurface(T);
       
       SDL_Quit();
    }*/
   	InitEnigme(&e,nomfichier);
  
  	answer=0;
  	setrects(rects);
  while(answer==0)
  // affiche l'énigme
    { SDL_BlitSurface(Image_Background, NULL, screen, &PositionBGSurEcran); //Blit du fond
     SDL_BlitSurface(e.texte,NULL,screen,&e.positiontexte);
     SDL_BlitSurface(e.texte1,NULL,screen,&e.positiontexte1);
     SDL_BlitSurface(e.texte2,NULL,screen,&e.positiontexte2);
     SDL_BlitSurface(e.texte3,NULL,screen,&e.positiontexte3);
     SDL_BlitSurface(horse,&rects[frame],screen,&PositionH);
       frame++;
	if(frame==11)
		frame=0;
       SDL_Flip(screen); 
       
       

do
{
  scanf("%d",&answer);
  }
  
while((answer !=1 ) && (answer != 2) && (answer != 3));
}
if(e.rj==answer)
{n=n+1;}

printf("%d",n);
SDL_FreeSurface(e.texte);
SDL_FreeSurface(e.texte1);
SDL_FreeSurface(e.texte2);
SDL_FreeSurface(e.texte3);
SDL_FreeSurface(Image_Background);
SDL_Flip(screen);
TTF_Quit();
   
}


 /*
 * Sauvegarde le fichier
 * @param[in] personne
 * @param[in] background
 * @param[in] nomfichier
 */   
  void sauvegarder(personne p,background b,char *nomfichier) {
  	FILE* fp=NULL;
  	fp=fopen(nomfichier,"w+");
  	fprintf(fp,"%d\n%d\n%s\n",p.score,p.vies,p.img);
    	fprintf(fp,"%s\n",b.cheimage);
	fclose(fp);
}

int charger(personne *p, background *b,char *nomfichier)
{
FILE* fp=NULL;
size_t len = 0;
ssize_t read;
char* temp=NULL;

    fp=fopen(nomfichier,"r");
read = getline(&(temp), &len, fp);
p->score=atoi(temp);
read = getline(&(temp), &len, fp);
p->vies=atoi(temp);
read = getline(&(p->img), &len, fp);
read = getline(&(b->cheimage), &len, fp);
fclose(fp);
}


void setrects(SDL_Rect* clip)
{
        clip[0].x = 0;
        clip[0].y = 0;
        clip[0].w = 78;
        clip[0].h = 68;
        
        clip[1].x = 78;
        clip[1].y = 0;
        clip[1].w = 78;
        clip[1].h = 68;
        
        clip[2].x = 166;
        clip[2].y = 0;
        clip[2].w = 78;
        clip[2].h = 68;
        
        clip[3].x = 257;
        clip[3].y = 0;
        clip[3].w = 78;
        clip[3].h = 68;
        
        clip[4].x = 353;
        clip[4].y = 0;
        clip[4].w = 78;
        clip[4].h = 68;
        
        clip[5].x = 443;
        clip[5].y = 0;
        clip[5].w = 78;
        clip[5].h = 68;
        
        clip[6].x = 530;
        clip[6].y = 0;
        clip[6].w = 78;
        clip[6].h = 68;
        
        clip[7].x = 613;
        clip[7].y = 0;
        clip[7].w = 78;
        clip[7].h = 68;
        
        clip[8].x = 699;
        clip[8].y = 0;
        clip[8].w = 78;
        clip[8].h = 68;
        
        clip[9].x = 734;
        clip[9].y = 0;
        clip[9].w = 78;
        clip[9].h = 68;
        
        clip[10].x = 851;
        clip[10].y = 0;
        clip[10].w = 78;
        clip[10].h = 68;      
}













