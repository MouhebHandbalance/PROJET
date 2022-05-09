/**
* @file enigmes.c
* @brief Testing Program.
* @author mouheb Ben Mabrouk
* @version 1.0
* @date Apr 20, 2022
*
* Testing program for random puzzle
*
*/

/**

* @file enigmes.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "enigmesheader.h"
/**
* @brief To initialize the puzzle e .
* @param e the puzzle
* @param nomfichier the file name
* @return Nothing
*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitEnigme(enigme* e, char *nomfichier)
{

FILE* fichier = NULL;
fichier = fopen("/home/mouheb/enigme/fichier.txt","r+");
if (fichier==NULL)
{
printf("Impossible d'ouvrir le fichier Results.txt");
}

else
{
fprintf(fichier,"/home/mouheb/enigme/picEnig/seaweed.jpeg /home/mouheb/enigme/picEnig/fishy.jpeg /home/mouheb/enigme/picEnig/worm.jpg /home/mouheb/enigme/picEnig/bone.png 1 3 4 2\n");
fprintf(fichier,"/home/mouheb/enigme/picEnig/seaweed.jpeg /home/mouheb/enigme/picEnig/fishy.jpeg /home/mouheb/enigme/picEnig/bone.png /home/mouheb/enigme/picEnig/worm.jpg 1 3 2 4\n");
fprintf(fichier,"/home/mouheb/enigme/picEnig/fishy.jpeg /home/mouheb/enigme/picEnig/seaweed.jpeg /home/mouheb/enigme/picEnig/worm.jpg /home/mouheb/enigme/picEnig/bone.png 3 1 4 2\n");
fprintf(fichier,"/home/mouheb/enigme/picEnig/fishy.jpeg /home/mouheb/enigme/picEnig/seaweed.jpeg /home/mouheb/enigme/picEnig/bone.png /home/mouheb/enigme/picEnig/worm.jpg 3 1 2 4\n");
}
fclose(fichier);

e->PositionBGSurEcran.x=0;
e->PositionBGSurEcran.y=0;
SDL_Surface *Image_Background = NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
* @brief To generate the puzzle e randomly.
* @param e the puzzle
* @param screen the surface
* @param alea the int
* @param image the random image
* @return Nothing
*/
void generate_afficher (SDL_Surface *screen  , char image [],enigme *e,int *alea)
{

	int test=*alea ;
       srand(time(NULL));
do
{
 *alea = 1+ rand()%4;
}while(*alea==test) ; 

 sprintf(image ,"%d.png",*alea);
 e->Image_Background = IMG_Load(image);
 SDL_BlitSurface(e->Image_Background,NULL,screen,&(e->PositionBGSurEcran)) ;
  SDL_Flip(screen) ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
* @brief To show the puzzle e .
* @param e the puzzle
* @param screen the surface
* @return Nothing
*/
void afficherEnigme(enigme e, SDL_Surface *screen, int t)
{
char nomfichier;
int frame=0;
SDL_bool program_launched = SDL_TRUE;
SDL_Surface *P1 = NULL;	SDL_Rect PositionP1;		
SDL_Surface *P2 = NULL;	SDL_Rect PositionP2;
SDL_Surface *P3 = NULL;	SDL_Rect PositionP3;
SDL_Surface *P4 = NULL;	SDL_Rect PositionP4;	
SDL_Surface *PicBone = NULL;		SDL_Rect PositionPicBone;	
SDL_Surface *PicSeaweed = NULL;	SDL_Rect PositionPicSeaweed;
SDL_Surface *PicWorm = NULL;		SDL_Rect PositionPicWorm;
SDL_Surface *PicFishy = NULL;		SDL_Rect PositionPicFishy;
TTF_Font *policeA = NULL;	SDL_Rect PositionA;	SDL_Surface *A = NULL;
TTF_Font *policeB = NULL;	SDL_Rect PositionB;	SDL_Surface *B = NULL;
TTF_Font *policeC = NULL;	SDL_Rect PositionC;	SDL_Surface *C = NULL;
TTF_Font *policeD = NULL;	SDL_Rect PositionD;	SDL_Surface *D = NULL;
TTF_Font *policeX = NULL;	SDL_Rect PositionX;	SDL_Surface *X = NULL;
TTF_Font *policeY = NULL;	SDL_Rect PositionY;	SDL_Surface *Y = NULL;
TTF_Font *policeW = NULL;	SDL_Rect PositionW;	SDL_Surface *W = NULL;
TTF_Font *policeZ = NULL;	SDL_Rect PositionZ;	SDL_Surface *Z = NULL;
TTF_Font *policeWON = NULL;	SDL_Surface *won = NULL;	SDL_Rect PositionWON;	
TTF_Font *policeLOST = NULL;	SDL_Surface *lost = NULL;	SDL_Rect PositionLOST;
SDL_Surface *horse = NULL;	SDL_Rect PositionH;
SDL_Surface *target= NULL;	SDL_Rect PositionTarget;
SDL_Rect rects[11];
SDL_Event event;
SDL_Color couleur = {0,0,255};	SDL_Color red = {255,0,0};	SDL_Color green = {0,255,0};
InitEnigme(&e,&nomfichier);
e.Image_Background = IMG_Load("/home/mouheb/enigme/src/Images/bg.jpg");
SDL_BlitSurface(e.Image_Background, NULL, screen, &e.PositionBGSurEcran);
P1 = IMG_Load("/home/mouheb/enigme/picEnig/fish.jpg");
P2 = IMG_Load("/home/mouheb/enigme/picEnig/catt.jpg");
P3 = IMG_Load("/home/mouheb/enigme/picEnig/dogg.jpg");
P4 = IMG_Load("/home/mouheb/enigme/picEnig/eagl.png");
PicFishy = IMG_Load("/home/mouheb/enigme/picEnig/1.png");
PicSeaweed = IMG_Load("/home/mouheb/enigme/picEnig/2.jpg");
PicWorm = IMG_Load("/home/mouheb/enigme/picEnig/3.jpg");
PicBone = IMG_Load("/home/mouheb/enigme/picEnig/4.jpg");
horse=SDL_DisplayFormat(SDL_LoadBMP("/home/mouheb/enigme/picEnig/low.bmp"));
target=IMG_Load("/home/mouheb/enigme/pic/targett.png");
won = IMG_Load("/home/mouheb/enigme/picEnig/win.jpg");
lost = IMG_Load("/home/mouheb/enigme/picEnig/lost.jpg");
setrects(rects);
/*A*/policeA = TTF_OpenFont("paze.ttf",25);				/*X*/policeX = TTF_OpenFont("paze.ttf",25);
A = TTF_RenderText_Blended (policeA,"PRESS[A]",couleur);		X = TTF_RenderText_Blended (policeA,"PRESS[X]",couleur);
/*B*/policeB = TTF_OpenFont("paze.ttf",25);				/*Y*/policeY = TTF_OpenFont("paze.ttf",25);
B = TTF_RenderText_Blended (policeB,"PRESS[B]",couleur);		Y = TTF_RenderText_Blended (policeB,"PRESS[Y]",couleur);
/*C*/policeC = TTF_OpenFont("paze.ttf",25);				/*W*/policeW = TTF_OpenFont("paze.ttf",25);
C = TTF_RenderText_Blended (policeC,"PRESS[C]",couleur);		W = TTF_RenderText_Blended (policeB,"PRESS[W]",couleur);
/*D*/policeD = TTF_OpenFont("paze.ttf",25);				/*Z*/policeZ = TTF_OpenFont("paze.ttf",25);
D = TTF_RenderText_Blended (policeD,"PRESS[D]",couleur);		Z = TTF_RenderText_Blended (policeB,"PRESS[Z]",couleur);
/*WON*/policeWON = TTF_OpenFont("paze.ttf",400);			/*LOST*/policeLOST = TTF_OpenFont("paze.ttf",400);
won = TTF_RenderText_Blended (policeD,"YOU WIN!",green);		lost = TTF_RenderText_Blended (policeB,"GAME OVER!",red);
        PositionP1.x=2;	PositionP3.x=800;
        PositionP1.y=80;	PositionP3.y=80;
        
        PositionP2.x=450;	PositionP4.x=1221;
        PositionP2.y=80;	PositionP4.y=80;
        
        PositionPicSeaweed.x = 874;      PositionPicBone.x = 526;       	                                                                               
        PositionPicSeaweed.y = 580;	  PositionPicBone.y = 580; 
        
        PositionPicWorm.x = 1100;       PositionPicFishy.x = 58;       	                                                                               
        PositionPicWorm.y = 460;	 PositionPicFishy.y = 530;
        
        PositionA.x=152;	PositionC.x=870;							
        PositionA.y=500;	PositionC.y=500;
        
        PositionB.x=520;	PositionD.x=1291;				
        PositionB.y=500;	PositionD.y=500;
        
        PositionX.x=152;	PositionW.x=870;							
        PositionX.y=840;	PositionW.y=840;
        
        PositionY.x=520;	PositionZ.x=1291;				
        PositionY.y=840;	PositionZ.y=840;
        
        PositionH.x=0;
        PositionH.y=0;
        PositionH.h=68;
        PositionH.w=936;
while(program_launched)
	{   
	SDL_BlitSurface(P1, NULL, screen, &PositionP1);
	SDL_BlitSurface(P2, NULL, screen, &PositionP2);
	SDL_BlitSurface(P3, NULL, screen, &PositionP3);
	SDL_BlitSurface(P4, NULL, screen, &PositionP4);
	SDL_BlitSurface(PicSeaweed, NULL, screen, &PositionPicSeaweed);
	SDL_BlitSurface(PicWorm, NULL, screen, &PositionPicWorm);
	SDL_BlitSurface(PicBone, NULL, screen, &PositionPicBone);
	SDL_BlitSurface(PicFishy, NULL, screen, &PositionPicFishy);
	SDL_BlitSurface(horse,&rects[frame], screen, &PositionH);
	frame++;
	if(frame==11)
		frame=0;
	SDL_BlitSurface(A, NULL, screen, &PositionA);		SDL_BlitSurface(X, NULL, screen, &PositionX);
	SDL_BlitSurface(B, NULL, screen, &PositionB);		SDL_BlitSurface(Y, NULL, screen, &PositionY);
	SDL_BlitSurface(C, NULL, screen, &PositionC);		SDL_BlitSurface(W, NULL, screen, &PositionW);
	SDL_BlitSurface(D, NULL, screen, &PositionD);		SDL_BlitSurface(Z, NULL, screen, &PositionZ);
	SDL_Flip(screen);
	SDL_PollEvent(&event);
        switch(event.type)
                     {
                      case SDL_KEYDOWN:
                          switch(event.key.keysym.sym)
                            {	while(program_launched)
                            		{
                                	case SDLK_a:
                                		while(program_launched)
                                		{
                                    		PositionTarget.x=292;
        			     		PositionTarget.y=498;
                                   		 SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                   		 SDL_PollEvent(&event);
                                  		  switch(event.type)
                                  		  {
                                      		 case SDL_KEYDOWN:
                                      		 switch(event.key.keysym.sym)
                                       		 {
                                         		   while(program_launched)
                                         		   {
                                          		 	case SDLK_x:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=307;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_y:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=680;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_w:
                                           		 	  PositionWON.x=655;		PositionTarget.x=1036;
                                           		  	  PositionWON.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(won, NULL, screen,&PositionWON);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_z:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=1466;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                                         }
                                       		 }
                                       		 break;
                                   		 }
                                   		 SDL_Flip(screen);
                                   		}
                                		break;
                                	case SDLK_b:
                                		while(program_launched)
                                		{
                                    		PositionTarget.x=683;
        			     		PositionTarget.y=498;
                                   		 SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                    		SDL_PollEvent(&event);
                                  		  switch(event.type)
                                  		  {
                                      		 case SDL_KEYDOWN:
                                      		 switch(event.key.keysym.sym)
                                       		 {
                                         		   while(program_launched)
                                         		   {
                                          		 	case SDLK_x:
                                           		 	  PositionWON.x=655;		PositionTarget.x=307;
                                           		  	  PositionWON.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(won, NULL, screen,&PositionWON);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_y:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=680;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_w:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=1036;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_z:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=1466;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                                         }
                                       		 }
                                       		 break;
                                   		 }
                                   		 SDL_Flip(screen);
                                   		}
                                	break;
                                	case SDLK_c:
                                		  while(program_launched)
                                		  {
                                  		  PositionTarget.x=1039;
        			    		  PositionTarget.y=498;
                                  		  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                  		  SDL_PollEvent(&event);
                                  		  switch(event.type)
                                  		  {
                                      		 case SDL_KEYDOWN:
                                      		 switch(event.key.keysym.sym)
                                       		 {
                                         		   while(program_launched)
                                         		   {
                                          		 	case SDLK_x:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=307;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_y:
                                           		 	  PositionWON.x=655;		PositionTarget.x=680;
                                           		  	  PositionWON.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(won, NULL, screen,&PositionWON);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_w:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=1036;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_z:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=1466;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                                         }
                                       		 }
                                       		 break;
                                   		 }
                                   		 SDL_Flip(screen);
                                   		}
                              	break;
                               	case SDLK_d:
                               		  while(program_launched)
                               		  {
                                  		  PositionTarget.x=1445;
        			   		  PositionTarget.y=498;
                                  		  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                  		  SDL_PollEvent(&event);
                                  		  switch(event.type)
                                  		  {
                                      		 case SDL_KEYDOWN:
                                      		 switch(event.key.keysym.sym)
                                       		 {
                                         		   while(program_launched)
                                         		   {
                                          		 	case SDLK_x:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=307;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_y:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=680;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                           			case SDLK_w:
                                           		 	  PositionLOST.x=655;		PositionTarget.x=1036;
                                           		  	  PositionLOST.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(lost, NULL, screen,&PositionLOST);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			 t = 1;
                                           			break;
                                           			case SDLK_z:
                                           		 	  PositionWON.x=655;		PositionTarget.x=1466;
                                           		  	  PositionWON.y=20;		PositionTarget.y=838;
                                           		  	  SDL_BlitSurface(won, NULL, screen,&PositionWON);
                                           		  	  SDL_BlitSurface(target, NULL, screen,&PositionTarget);
                                           			  SDL_Flip(screen);
                                           			  SDL_Delay(2000);
                                           			  t = 1;
                                           			break;
                                                         }
                                       		 }
                                       		 break;
                                   		 }
                                   		 SDL_Flip(screen);
                                   		}
                             	        break;
                     	     		}
                     	     }
                     	     break;
		     }
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
* @brief To give the horse positions.
* @param clip the position
* @return Nothing
*/
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
