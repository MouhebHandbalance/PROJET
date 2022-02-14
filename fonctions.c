#include "headers.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void MenuPrincipal()
{
  SDL_Surface *screen = NULL;
  SDL_Surface *Image_Background = NULL;
  SDL_Surface *Image_SbouiSoleil = NULL;
  SDL_Surface *Image_SbouiJeu = NULL;
  SDL_Surface *Image_xd = NULL;
  SDL_Surface *Image_PlaySurface = NULL;
  SDL_Surface *Image_PlayButtonBackground = NULL;
  SDL_Surface *Image_OptionsButtonBackground = NULL;
  SDL_Surface *Image_QuitButtonBackground = NULL;
  SDL_Surface *Texte = NULL;
  SDL_Surface *Play = NULL;
  SDL_Surface *Options = NULL;
  SDL_Surface *Quit = NULL;
  
  SDL_Rect PositionPlayButtonSurEcran;
  SDL_Rect PositionOptionsButtonSurEcran;
  SDL_Rect PositionQuitButtonSurEcran;
  SDL_Rect PositionBGSurEcran;
  SDL_Rect PositionButtonBackgroundPlaySurEcran;
  SDL_Rect PositionButtonBackgroundOptionsSurEcran;
  SDL_Rect PositionButtonBackgroundQuitSurEcran;
  SDL_Rect PositionTexteSurEcran;
  SDL_Rect PositionSbouiSoleilSurEcran;
  SDL_Rect PositionSbouiJeuSurEcran;
  
  TTF_Font *policeTexte = NULL;
  TTF_Font *policePlayButton = NULL;
  TTF_Font *policeOptionsButton = NULL;
  TTF_Font *policeQuitButton = NULL;
  
  SDL_bool program_launched = SDL_TRUE;
  
  SDL_Color CouleurNoire = {0, 0, 0};
  Mix_Music *MusicContenuMenu = NULL;
  Mix_Chunk *SonBrefClick;
  
  SDL_Event event;
    SDL_Event event1;
  
  
  
    //Creation de la fenetre
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
       printf("Erreur : %s \n", SDL_GetError());
       SDL_FreeSurface(Texte);
       SDL_Quit();
    }
    
    /////////////////////////////////////////
    
    /////////////////////////////////////////
    
    screen = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(screen == NULL)
    {
       printf("Erreur : %s \n", SDL_GetError());
       SDL_FreeSurface(Texte);
       SDL_Quit();
    }
    
    //Musique(Son Continu)
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
      {
        printf("%s", Mix_GetError());
      }
      MusicContenuMenu = Mix_LoadMUS("MusicContenuMenu.mp3"); //Load music
      Mix_PlayMusic(MusicContenuMenu, -1); //Play music 
      
      
    
    
    
    //Insertion de l'image du Background Principal
    Image_Background = IMG_Load("/home/mouheb/PROJET/src/Images/BackgroundPrincipal.jpg");
    if(Image_Background == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_xd = IMG_Load("/home/mouheb/PROJET/src/Images/xd.jpg");
    if(Image_xd == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    
    //Insertion de Cadre des Boutons Du Menu Principal
    Image_PlayButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ButtonBackground1.png");
    if(Image_PlayButtonBackground == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_OptionsButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ButtonBackground2.png");
    if(Image_OptionsButtonBackground == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_QuitButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ButtonBackground3.png");
    if(Image_QuitButtonBackground == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_PlaySurface = IMG_Load("/home/mouheb/PROJET/src/Images/PlaySurface.jpg");
    if(Image_PlaySurface == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_SbouiSoleil = IMG_Load("/home/mouheb/PROJET/src/Images/SbouiSoleil.png");
    if(Image_SbouiSoleil == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_SbouiJeu = IMG_Load("/home/mouheb/PROJET/src/Images/SbouiJeu.png");
    if(Image_SbouiJeu == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
        //Police + Texte
    policeTexte = TTF_OpenFont("paze.ttf", 60);
    Texte = TTF_RenderText_Blended(policeTexte, "WELCOME", CouleurNoire);
    
    //Texte: Play
    policePlayButton = TTF_OpenFont("paze.ttf",40);
    Play = TTF_RenderText_Blended(policePlayButton, "PLAY", CouleurNoire);
    
    //Texte: Options
    policeOptionsButton = TTF_OpenFont("paze.ttf",40);
    Options = TTF_RenderText_Blended(policeOptionsButton, "OPTIONS", CouleurNoire);
    
    //Texte: Quit
    policeQuitButton = TTF_OpenFont("paze.ttf",40);
    Quit = TTF_RenderText_Blended(policeQuitButton, "QUIT", CouleurNoire);
    
        
     // Boucle de l'ouverture du fenetre
     while(program_launched)
     {
        PositionBGSurEcran.x = 0;
        PositionBGSurEcran.y = 0;
        
        PositionPlayButtonSurEcran.x = 430;          PositionButtonBackgroundPlaySurEcran.x = 356;
        PositionPlayButtonSurEcran.y = 350;          PositionButtonBackgroundPlaySurEcran.y = 345;
        
        
        PositionOptionsButtonSurEcran.x = 390;       PositionButtonBackgroundOptionsSurEcran.x = 356;
        PositionOptionsButtonSurEcran.y = 410;       PositionButtonBackgroundOptionsSurEcran.y = 405;
        
        PositionQuitButtonSurEcran.x = 430;          PositionButtonBackgroundQuitSurEcran.x = 356;
        PositionQuitButtonSurEcran.y = 470;          PositionButtonBackgroundQuitSurEcran.y = 465;
        
        PositionTexteSurEcran.x = 331;
        PositionTexteSurEcran.y = 210;
        
        PositionSbouiSoleilSurEcran.x = 731;
        PositionSbouiSoleilSurEcran.y = 30;
        
        PositionSbouiJeuSurEcran.x = 30;
        PositionSbouiJeuSurEcran.y = 600;
        
        
        SDL_BlitSurface(Image_Background, NULL, screen, &PositionBGSurEcran); //Blit du fond
        SDL_BlitSurface(Texte, NULL, screen, &PositionTexteSurEcran); //Blit du texte
        SDL_BlitSurface(Image_PlayButtonBackground, NULL, screen, &PositionButtonBackgroundPlaySurEcran);
        SDL_BlitSurface(Image_OptionsButtonBackground, NULL, screen, &PositionButtonBackgroundOptionsSurEcran); 
        SDL_BlitSurface(Image_QuitButtonBackground, NULL, screen, &PositionButtonBackgroundQuitSurEcran);
        SDL_BlitSurface(Play, NULL, screen, &PositionPlayButtonSurEcran);
        SDL_BlitSurface(Options, NULL, screen, &PositionOptionsButtonSurEcran);
        SDL_BlitSurface(Quit, NULL, screen, &PositionQuitButtonSurEcran);
        SDL_BlitSurface(Image_SbouiSoleil, NULL, screen, &PositionSbouiSoleilSurEcran);
        SDL_Flip(screen);
      
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
               switch(event.key.keysym.sym)
                   {
                       case SDLK_b:
                          //Musique(Son Bref)
                          SonBrefClick = Mix_LoadWAV("SonBrefClick.wav");
                          Mix_PlayChannel(-1, SonBrefClick, 0);
                       break;
                        
                       defaut:
                          break;   
                   }
            break;
            case SDL_MOUSEMOTION:
               if (356 < event.motion.x<632 && 345 < event.motion.y< 392)
               {Image_PlayButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ButtonBackground4.png");}
               /*if (356 < event.motion.x< 632 && 405 < event.motion.y < 450)
               {Image_OptionsButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/xd.jpg");}
               if(356 < event.motion.x< 632 && 465 < event.motion.y < 513)
               {Image_QuitButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/xd.jpg");}*/
            break;
            case SDL_MOUSEBUTTONDOWN:
            if(356 < event.motion.x<632 && 345 < event.motion.y < 392)       //Ouverture du fenetre Pour Jouer le Jeu  
               {
                 //Musique(Son Bref)
                 SonBrefClick = Mix_LoadWAV("SonBrefClick.wav");
                 Mix_PlayChannel(-1, SonBrefClick, 0);
                 while(program_launched = SDL_TRUE)
                   {
                     SDL_BlitSurface(Image_PlaySurface, NULL, screen, &PositionBGSurEcran);
                     SDL_BlitSurface(Image_SbouiJeu, NULL, screen, &PositionSbouiJeuSurEcran);
                     SDL_Flip(screen);
                     
                     
                     event = event1;
                     switch(event1.type)
                     {
                       case SDL_QUIT:
              program_launched = SDL_FALSE;
              break;
                     }
                   }
               }
               
               
               
               
               else if(356<=event.button.x<=632 && 405<=event.button.y<=450) //Ouverture du fenetre Pour les Options
               {
                 while(program_launched = SDL_TRUE)
                   {
                     SDL_BlitSurface(Image_xd, NULL, screen, &PositionBGSurEcran);
                     SDL_Flip(screen);
                   }
               }
                   
                   
                   
                   
               else if(356<=event.button.x<=632 && 465<=event.button.y<=513)  //Quitter aprés cliquer sur Bouton Quitter
                 {
                    program_launched = SDL_FALSE;
                 } 
            break;
            case SDL_QUIT:
              program_launched = SDL_FALSE;
            break;
            
            
        }
        //if(event.type == SDL_QUIT) program_launched = SDL_FALSE;
      }     

   TTF_CloseFont(policeTexte);
   TTF_CloseFont(policePlayButton);
   TTF_CloseFont(policeOptionsButton);
   TTF_CloseFont(policeQuitButton);
   TTF_Quit();
   Mix_FreeMusic(MusicContenuMenu);
   Mix_FreeChunk(SonBrefClick);
   SDL_FreeSurface(Texte);
   SDL_FreeSurface(Play);
   SDL_FreeSurface(Options);
   SDL_FreeSurface(Quit);
   SDL_Quit();
}

//////////////////////////////////////////////////////////////////////////////////////


