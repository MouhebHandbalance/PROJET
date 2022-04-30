DEBUT //initialisation des ressources
Tant que (continuer)
             Affichage de l’écran
           Récupérer les inputs des périphériques
           Ecouter événement
           Si (niveau==”Jeu”)
     	Si (collision avec obstacle) 
                               niveau="Énigme"
                        Fin Si
            Fin Si
           Si (niveau=="Énigme")
	Si (temps < durée Énigme et réponse juste)
     	      score ++;
	Sinon   
   	      score --;
	Fin Si
      Fin Si
Fin tant que
//libération des ressources
FIN
while(n=1)
{
void SDL_ExitWithError(const char *message);


int main(int argc, char *argv[])
{

int contenu=1;
char * nomfichier="/home/nafaa/enigme2/enigme.txt";
enigme * e=malloc(sizeof(enigme));





  do
{ SDL_Surface *screen = NULL; 
 screen = SDL_SetVideoMode(1509, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
 switch event
 {case 
