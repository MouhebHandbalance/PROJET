#include "enigme2.h"


void SDL_ExitWithError(const char *message);


int main(int argc, char *argv[])
{

int contenu=1;
char * nomfichier="/home/nafaa/enigme2/enigme.txt";
enigme * e=malloc(sizeof(enigme));





  do
{ SDL_Surface *screen = NULL; 
 screen = SDL_SetVideoMode(1200, 680, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

 afficherEnigme(*e, screen);
  InitEnigme(e, nomfichier);
 contenu=contenu+1;
 SDL_Flip(screen); 
  return 0;
}
while(contenu!=3);
}


