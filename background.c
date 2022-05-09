#include "background.h"


Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    switch(bpp) {
    case 1:
        return *p;
    case 2:
        return *(Uint16 *)p;
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
    case 4:return *(Uint32 *)p; default:return 0;
    }
}
int is_black(int x,int y,SDL_Surface *i)
{
if(getpixel(i,x,y)==-16777216)return 1;return 0;//valeur de la couleur noir
}

//////////////////////////////////////////////////////////////
void initback (background *bg,Mix_Music *musique){
  bg->image = IMG_Load("/home/mouheb/PROJET/src/Images/PlaySurface.png");
bg->i = IMG_Load("/home/mouheb/PROJET/src/Images/sprite.jpeg");
//bg->mask = IMG_Load("background/mask.png");
  if (bg->image==NULL)
  	{
  	printf("Unable to load background : %s\n" , IMG_GetError());
    }
  bg->pos.x = 0;
  bg->pos.y = 0;
  bg->anim.x = 0;
  bg->anim.y = 0;
  bg->sprite.w = bg->i->w/5;
  bg->sprite.h = bg->i->h/3;
  bg->num_image=0;
  Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //Mettre le volume à la moitié
  //Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1);


}
//////////////////////////////////////////////////////////////


void animer(background *bg)
{
bg->anim.x+=5;
SDL_Delay(15);
bg->anim.y=0;
bg->num_image++;
if(bg->num_image==14)bg->num_image=0;
bg->sprite.x=(bg->num_image%5)*bg->sprite.w;
bg->sprite.y=(bg->num_image/5)*bg->sprite.h+20;
if(bg->anim.x>1500) bg->anim.x=-200;
}

//////////////////////////////////////////////////////////////
void afficher_back(background bg,SDL_Surface *ecran){
bg.image = IMG_Load("/home/mouheb/PROJET/src/Images/PlaySurface.png");
  SDL_BlitSurface (bg.image,NULL,ecran,&bg.pos);
  SDL_BlitSurface (bg.i,&bg.sprite,ecran,&bg.anim);



}
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////

void scrolling (background *bg,int vitesse,int d){
if(d==1) bg->pos.x+=vitesse; 
else bg->pos.x+=vitesse;
if(bg->pos.x>0) bg->pos.x=0;
if(bg->pos.x<-268) bg->pos.x=-268;
}

/*void animation_startv2(SDL_Surface *screen,SDL_Surface *image)
{//animation début
SDL_Rect pos1;pos1.x=screen->w;pos1.y=0;
SDL_Rect sprite1;sprite1.x=screen->w/2;sprite1.y=0;sprite1.w=screen->w;sprite1.h=screen->h;
SDL_Rect sprite2;sprite2.w=0;sprite2.x=0;sprite2.y=0;sprite2.h=screen->h;
SDL_Delay(500);
while(pos1.x>screen->w/2)
{sprite2.w+=10;
SDL_BlitSurface(image,&sprite1,screen,&pos1);
SDL_BlitSurface(image,&sprite2,screen,NULL);
pos1.x-=10;SDL_Flip(screen);
SDL_Delay((100+pos1.x-screen->w/2)/10);
}
}

//////////////////////////////////////////////////////////////
*/void initpartage (background *bg1,background *bg2,Mix_Music *musique)
{
  bg1->image = IMG_Load("background/LVL1.partage.png");
  bg2->image = IMG_Load("background/LVL1.partage.png");

  if ((bg1->image==NULL)||(bg2->image==NULL))
  	{
  	printf("Unable to load partage background : %s\n" , IMG_GetError());
    }

  bg1->pos.x = 0;
  bg1->pos.y = 0;
  bg2->pos.x = 0;
  bg2->pos.y = 125;
  Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //Mettre le volume à la moitié
  //Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1);
}
