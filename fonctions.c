#include "headers.h"
#include "MiniMap.c"
#include "MiniMapHeaders.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void MenuPrincipal()
{                                  
                                                                       SDL_Surface *TexteOptions = NULL;                     SDL_Surface *BlackBackGround = NULL;
  SDL_Surface *screen = NULL;                                          SDL_Surface *Volume1 = NULL;                          SDL_Surface *txt = NULL; 
  SDL_Surface *Image_Background = NULL;                                SDL_Surface *Volume2 = NULL;                          SDL_Surface *txtnext = NULL;
  SDL_Surface *Image_Lantern1 = NULL;                                  SDL_Surface *Volume3 = NULL; 
  SDL_Surface *Image_Lantern2 = NULL;                                  SDL_Surface *BoutonVolume1 = NULL; 
  SDL_Surface *Image_SbouiJeu = NULL;                                  SDL_Surface *BoutonVolume2 = NULL; 
  SDL_Surface *Image_xd = NULL;                                        
  SDL_Surface *Image_PlaySurface = NULL;                               
  SDL_Surface *Image_PlayButtonBackground = NULL;                       
  SDL_Surface *Image_OptionsButtonBackground = NULL;                   
  SDL_Surface *Image_QuitButtonBackground = NULL;                       
  SDL_Surface *Texte = NULL;                                           SDL_Surface *TexteVolume = NULL;
  SDL_Surface *Play = NULL;                                            SDL_Surface *TexteBack = NULL;
  SDL_Surface *Options = NULL;                                         SDL_Surface *TexteFullScreen = NULL;
  SDL_Surface *Quit = NULL;                                            SDL_Surface *CarreauFullScreen = NULL;
  SDL_Surface *Image_ff = NULL;                                        SDL_Surface *CarreauFullScreen1 = NULL;
  
  SDL_Rect PositionPlayButtonSurEcran;                                 SDL_Rect PositionVolume1SurEcran;         SDL_Rect PositionCarreauFullScreenSurEcran;
  SDL_Rect PositionOptionsButtonSurEcran;                              SDL_Rect PositionVolume2SurEcran;
  SDL_Rect PositionQuitButtonSurEcran;                                 SDL_Rect PositionVolume3SurEcran;
  SDL_Rect PositionBGSurEcran;                                         SDL_Rect PositionBoutonVolume1SurEcran;
  SDL_Rect PositionButtonBackgroundPlaySurEcran;                       SDL_Rect PositionBoutonVolume2SurEcran;
  SDL_Rect PositionButtonBackgroundOptionsSurEcran;                    
  SDL_Rect PositionButtonBackgroundQuitSurEcran;                       
  SDL_Rect PositionTexteSurEcran;                                      
  SDL_Rect PositionLantern1SurEcran;                                   
  SDL_Rect PositionLantern2SurEcran;                               
  SDL_Rect PositionSbouiJeuSurEcran;                                   SDL_Rect PositionTexteOptionsSurEcran;           SDL_Rect PositiontxtSurEcran;
  SDL_Rect PositionffSurEcran;                                         SDL_Rect PositionTexteVolumeSurEcran;            SDL_Rect PositiontxtnextSurEcran;
                                                                       SDL_Rect PositionTexteBackSurEcran;
                                                                       SDL_Rect PositionTexteFullScreenSurEcran;
                                                                
  TTF_Font *policeTexte = NULL;                                        TTF_Font *policeTexteOptions = NULL;             TTF_Font *policetxt = NULL;
  TTF_Font *policePlayButton = NULL;                                   TTF_Font *policeTexteVolume = NULL;              TTF_Font *policetxtnext = NULL;
  TTF_Font *policeOptionsButton = NULL;                                TTF_Font *policeTexteBack = NULL; 
  TTF_Font *policeQuitButton = NULL;                                   TTF_Font *policeTexteFullScreen = NULL;
  
  SDL_bool program_launched = SDL_TRUE;
  
  SDL_Color CouleurNoire = {255, 255, 255};
  SDL_Color CouleurNoire1 = {0, 0, 0};
  SDL_Color CouleurRouge = {255, 0, 0};
  
  Mix_Music *MusicContenuMenu = NULL; 
  Mix_Chunk *SonBrefClick;
  
  SDL_Event event;
  SDL_Event event1;

int FoisDeRepetition = 1; 
int x;
int t = 0;       int redimensionnement;    char nomJoueur[10];

MiniMap m;

SDL_Rect posJoueur;
SDL_Surface *Image_fd = NULL;

temps temp;

//Creation de la fenetre
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    if(SDL_Init(SDL_INIT_VIDEO) != 0) 	
    {
       printf("Erreur : %s \n", SDL_GetError());
       SDL_FreeSurface(Texte);
       SDL_Quit();
    }
    
    /////////////////////////////////////////
    
    /////////////////////////////////////////
    
    screen = SDL_SetVideoMode(1509, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
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

Image_PlaySurface = IMG_Load("/home/mouheb/PROJET/src/Images/PlaySurface.png");
    if(Image_PlaySurface == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_Lantern1 = IMG_Load("/home/mouheb/PROJET/src/Images/Lantern1.png");
    if(Image_Lantern1 == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_Lantern2 = IMG_Load("/home/mouheb/PROJET/src/Images/Lantern2.png");
    if(Image_Lantern2 == NULL)
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
    
    Image_ff = IMG_Load("/home/mouheb/PROJET/src/Images/ff.png");
    if(Image_ff == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Volume1 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume1.png");
    if(Volume1 == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Volume2 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume2.png");
    if(Volume2 == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
   
   Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume3.png");
    if(Volume3 == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
   
   CarreauFullScreen = IMG_Load("/home/mouheb/PROJET/src/Images/hi.png");
    if(CarreauFullScreen == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    BoutonVolume1 = IMG_Load("/home/mouheb/PROJET/src/Images/BoutonVolume1.png");
    if(BoutonVolume1 == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    BoutonVolume2 = IMG_Load("/home/mouheb/PROJET/src/Images/BoutonVolume2.png");
    if(BoutonVolume2 == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    Image_fd = IMG_Load("/home/mouheb/PROJET/src/Images/SbouiJeu.png");
    if(Image_fd == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }
    
    BlackBackGround = IMG_Load("/home/mouheb/PROJET/src/Images/thumb-3d-black-texture-geometric-black-texture-black-abstraction-background-3d-abstraction-black-texture-creative-black-background.jpg");
    if(BlackBackGround == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_FreeSurface(Texte);
      SDL_Quit();
    }

    
        //Police + Texte
    policeTexte = TTF_OpenFont("paze.ttf", 80);                                            policeTexteOptions = TTF_OpenFont("f.ttf", 80);
    Texte = TTF_RenderText_Blended(policeTexte, "WELCOME", CouleurNoire);                  TexteOptions = TTF_RenderText_Blended(policeTexteOptions, "OPTIONS", CouleurNoire1);
                                                                                           policeTexteVolume = TTF_OpenFont("f.ttf", 60);
    /*Texte: Play*/                                                                        TexteVolume = TTF_RenderText_Blended(policeTexteVolume, "VOLUME", CouleurNoire1);
    policePlayButton = TTF_OpenFont("paze.ttf",40);                                        policeTexteBack = TTF_OpenFont("f.ttf", 60);
    Play = TTF_RenderText_Blended(policePlayButton, "PLAY", CouleurNoire);                 TexteBack = TTF_RenderText_Blended(policeTexteBack, "BACK", CouleurNoire1);
                                                                                           policeTexteFullScreen = TTF_OpenFont("f.ttf", 60);
    /*Texte: Options*/                                                                     TexteFullScreen = TTF_RenderText_Blended(policeTexteFullScreen, "FULL SCREEN", CouleurNoire1);
    policeOptionsButton = TTF_OpenFont("paze.ttf",40);
    Options = TTF_RenderText_Blended(policeOptionsButton, "OPTIONS", CouleurNoire);
    
    //Texte: Quit
    policeQuitButton = TTF_OpenFont("paze.ttf",40);
    Quit = TTF_RenderText_Blended(policeQuitButton, "QUIT", CouleurNoire);
    
    //Texte: Meilleuir score
    policetxt = TTF_OpenFont("f.ttf",40);
    txt = TTF_RenderText_Blended(policetxt, "!BEST SCORE!", CouleurNoire);
    
    //Texte: Next
    policetxtnext = TTF_OpenFont("f.ttf",40);
    txtnext = TTF_RenderText_Blended(policetxtnext, "NEXT", CouleurNoire);

// Boucle de l'ouverture du fenetre
     while(program_launched && t == 0)
     {
     
     
        PositionBGSurEcran.x = 0;                                                                                      
        PositionBGSurEcran.y = 0;                                                                                      
        
        PositionPlayButtonSurEcran.x = 640;          PositionButtonBackgroundPlaySurEcran.x = 556;                  PositiontxtSurEcran.x = 550;
        PositionPlayButtonSurEcran.y = 350;          PositionButtonBackgroundPlaySurEcran.y = 345;                  PositiontxtSurEcran.y = 400;
                                                                                                                   
                                                                                                                    PositiontxtnextSurEcran.x = 640;
        PositionOptionsButtonSurEcran.x = 610;       PositionButtonBackgroundOptionsSurEcran.x = 556;               PositiontxtnextSurEcran.y = 800;
        PositionOptionsButtonSurEcran.y = 410;       PositionButtonBackgroundOptionsSurEcran.y = 405;
        
        PositionQuitButtonSurEcran.x = 640;          PositionButtonBackgroundQuitSurEcran.x = 556;
        PositionQuitButtonSurEcran.y = 470;          PositionButtonBackgroundQuitSurEcran.y = 465;
        
        PositionTexteSurEcran.x = 500;
        PositionTexteSurEcran.y = 210;
        
        PositionLantern1SurEcran.x = -520;           PositionLantern2SurEcran.x = -298;
        PositionLantern1SurEcran.y = 0;              PositionLantern1SurEcran.y = 0;
        
        PositionSbouiJeuSurEcran.x = 30;
        PositionSbouiJeuSurEcran.y = 600;
        
        PositionTexteOptionsSurEcran.x = 540;
        PositionTexteOptionsSurEcran.y = 100;
        
        PositionTexteVolumeSurEcran.x = 800;
        PositionTexteVolumeSurEcran.y = 320;
        
        PositionTexteBackSurEcran.x = 1100;
        PositionTexteBackSurEcran.y = 800;
        
        PositionVolume1SurEcran.x = 1140;       //PositionVolume2SurEcran.x = ;         PositionVolume3SurEcran.x = ;
        PositionVolume1SurEcran.y = 360;        //PositionVolume2SurEcran.y = ;         PositionVolume3SurEcran.y = ;
        
        PositionTexteFullScreenSurEcran.x = 800;               PositionCarreauFullScreenSurEcran.x = 1250;
        PositionTexteFullScreenSurEcran.y = 520;               PositionCarreauFullScreenSurEcran.y = 543;
        
        PositionBoutonVolume1SurEcran.x = 760;                PositionBoutonVolume2SurEcran.x = 1070;
        PositionBoutonVolume1SurEcran.y = 365;                PositionBoutonVolume2SurEcran.y = 365;
        
        
        posJoueur.x = 50;
        posJoueur.y = 500;
        

        SDL_BlitSurface(Image_Background, NULL, screen, &PositionBGSurEcran); //Blit du fond
        SDL_BlitSurface(Texte, NULL, screen, &PositionTexteSurEcran); //Blit du texte
        SDL_BlitSurface(Image_PlayButtonBackground, NULL, screen, &PositionButtonBackgroundPlaySurEcran);
        SDL_BlitSurface(Image_OptionsButtonBackground, NULL, screen, &PositionButtonBackgroundOptionsSurEcran); 
        SDL_BlitSurface(Image_QuitButtonBackground, NULL, screen, &PositionButtonBackgroundQuitSurEcran);
        SDL_BlitSurface(Play, NULL, screen, &PositionPlayButtonSurEcran);
        SDL_BlitSurface(Options, NULL, screen, &PositionOptionsButtonSurEcran);
        SDL_BlitSurface(Quit, NULL, screen, &PositionQuitButtonSurEcran);
                
        SDL_BlitSurface(Image_Lantern1, NULL, screen, &PositionLantern1SurEcran);

        SDL_Flip(screen);

SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN:
               switch(event.key.keysym.sym)
                   {
                       case SDLK_l:
                          SDL_BlitSurface(Image_Lantern2, NULL, screen, &PositionLantern2SurEcran);
                          SDL_Flip(screen);
                       break;
                       
                       case SDLK_p:
                         t = 2;
                         break;
                         
                         case SDLK_o:
                         t++;
                         break;
                         
                         case SDLK_q:
                            program_launched = SDL_FALSE;
                            break;
                         
                         case SDLK_f:
                            SDL_WM_ToggleFullScreen(screen);
                            
                       defaut:
                          break;   
                   }
            break;
       case SDL_MOUSEMOTION://printf("%d | %d \n", event.motion.x, event.motion.y);
              
              //Bouton PLAY
                if(556 <= event.motion.x && event.motion.x<=826 && 345 <= event.motion.y && event.motion.y <=392)
               {Image_PlayButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ff.png");
                SDL_BlitSurface(Image_ff, NULL, screen, &PositionButtonBackgroundPlaySurEcran);
                
                while(FoisDeRepetition == 1) {SonBrefClick = Mix_LoadWAV("SonBrefClick.wav"); Mix_PlayChannel(-1, SonBrefClick, 0); FoisDeRepetition++;}
                policePlayButton = TTF_OpenFont("paze.ttf",40);
                Play = TTF_RenderText_Blended(policePlayButton, "PLAY", CouleurNoire1);
                 }
            else 
                  {Image_PlayButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ButtonBackground1.png");
                   SDL_BlitSurface(Image_PlayButtonBackground, NULL, screen, & PositionButtonBackgroundPlaySurEcran);
                   policePlayButton = TTF_OpenFont("paze.ttf",40);
                   Play = TTF_RenderText_Blended(policePlayButton, "PLAY", CouleurNoire);
                  }
                  //Bouton OPTIONS
               if(556 <= event.motion.x && event.motion.x<=826 && 407 <= event.motion.y && event.motion.y <=451)
               {
                 Image_OptionsButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ff.png");
                 SDL_BlitSurface(Image_OptionsButtonBackground, NULL, screen, &PositionButtonBackgroundOptionsSurEcran);
                 FoisDeRepetition--;
                 while(FoisDeRepetition == 1) {SonBrefClick = Mix_LoadWAV("SonBrefClick.wav"); Mix_PlayChannel(-1, SonBrefClick, 0); FoisDeRepetition++;}
                 policeOptionsButton = TTF_OpenFont("paze.ttf",40);
                 Options = TTF_RenderText_Blended(policeOptionsButton, "OPTIONS", CouleurNoire1);
               }
               else
               {
                 Image_OptionsButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ButtonBackground2.png");
                 SDL_BlitSurface(Image_OptionsButtonBackground, NULL, screen, & PositionButtonBackgroundOptionsSurEcran);
                 policeOptionsButton = TTF_OpenFont("paze.ttf",40);
                 Options = TTF_RenderText_Blended(policeOptionsButton, "OPTIONS", CouleurNoire);
               }
               //Bouton QUIT
               if(556 <= event.motion.x && event.motion.x<=826 && 465 <= event.motion.y && event.motion.y <=512)
               {
                 Image_QuitButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ff.png");
                 SDL_BlitSurface(Image_QuitButtonBackground, NULL, screen, & PositionButtonBackgroundQuitSurEcran);
                 FoisDeRepetition--;
                 while(FoisDeRepetition == 1) {SonBrefClick = Mix_LoadWAV("SonBrefClick.wav"); Mix_PlayChannel(-1, SonBrefClick, 0); FoisDeRepetition++;}
                 policeQuitButton = TTF_OpenFont("paze.ttf",40);
                 Quit = TTF_RenderText_Blended(policeQuitButton, "QUIT", CouleurNoire1);
               }
               else
               {
                 Image_QuitButtonBackground = IMG_Load("/home/mouheb/PROJET/src/Images/ButtonBackground3.png");
                 SDL_BlitSurface(Image_QuitButtonBackground, NULL, screen, & PositionButtonBackgroundQuitSurEcran);
                 policeQuitButton = TTF_OpenFont("paze.ttf",40);
                 Quit = TTF_RenderText_Blended(policeQuitButton, "QUIT", CouleurNoire);
               }
            break;
            
      case SDL_MOUSEBUTTONDOWN:
            if(556 <= event.button.x && event.button.x<=826 && 345 <= event.button.y && event.button.y <=392)   //Ouverture du fenetre Pour Jouer le Jeu  
               {
                 t = 2;
               }
              // Liberer(&m);
               
               
               else if(556 <= event.button.x && event.button.x<=826 && 407 <= event.button.y && event.button.y <=451) //Ouverture du fenetre Pour les Options
               {
                 t = 1;
               }
                   
                   
                   
                else if(356<=event.button.x && event.button.x<=632 && 465<=event.button.y && event.button.y<=513)   //Quitter aprés cliquer sur Bouton Quitter
                 {
                    program_launched = SDL_FALSE;
                 } 
            break;
            case SDL_QUIT:
              program_launched = SDL_FALSE;
            
            break;
            
            
        }
     
        
        while(t == 1)
        {
          while(program_launched = SDL_TRUE)
                   {
                     SDL_BlitSurface(Image_Background, NULL, screen, &PositionBGSurEcran);
                     SDL_BlitSurface(TexteOptions, NULL, screen, &PositionTexteOptionsSurEcran);
                     SDL_BlitSurface(TexteVolume, NULL, screen, &PositionTexteVolumeSurEcran);
                     SDL_BlitSurface(TexteBack, NULL, screen, &PositionTexteBackSurEcran);
                     SDL_BlitSurface(TexteFullScreen, NULL, screen, &PositionTexteFullScreenSurEcran);
                     SDL_BlitSurface(Volume3, NULL, screen, &PositionVolume1SurEcran);
                     SDL_BlitSurface(CarreauFullScreen, NULL, screen, &PositionCarreauFullScreenSurEcran);
                     SDL_BlitSurface(BoutonVolume1, NULL, screen, &PositionBoutonVolume1SurEcran);
                     SDL_BlitSurface(BoutonVolume2, NULL, screen, &PositionBoutonVolume2SurEcran);
                     SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_KEYDOWN:
                          switch(event.key.keysym.sym)
                          {
                            case SDLK_f:
                            CarreauFullScreen = IMG_Load("/home/mouheb/PROJET/src/Images/hello.png");
                            SDL_BlitSurface(CarreauFullScreen, NULL, screen, & PositionCarreauFullScreenSurEcran);
                            SDL_WM_ToggleFullScreen(screen);
                               break;
                            
                            case SDLK_b:
                               SDL_BlitSurface(Image_Background, NULL, screen, &PositionBGSurEcran); //Blit du fond
                           SDL_BlitSurface(Texte, NULL, screen, &PositionTexteSurEcran); //Blit du texte
                           SDL_BlitSurface(Image_PlayButtonBackground, NULL, screen, &PositionButtonBackgroundPlaySurEcran);
                           SDL_BlitSurface(Image_OptionsButtonBackground, NULL, screen, &PositionButtonBackgroundOptionsSurEcran); 
                           SDL_BlitSurface(Image_QuitButtonBackground, NULL, screen, &PositionButtonBackgroundQuitSurEcran);
                           SDL_BlitSurface(Play, NULL, screen, &PositionPlayButtonSurEcran);
                           SDL_BlitSurface(Options, NULL, screen, &PositionOptionsButtonSurEcran);
                           SDL_BlitSurface(Quit, NULL, screen, &PositionQuitButtonSurEcran);
                
                           SDL_BlitSurface(Image_Lantern1, NULL, screen, &PositionLantern1SurEcran);
                           

                           SDL_Flip(screen);
                            break;
                            case SDLK_LEFT: 
                               Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
                               Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume2.png");
                               break;
                            case SDLK_DOWN:
                              Mix_VolumeMusic(MIX_MAX_VOLUME / 6);
                              Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume1.png");
                              break;
                            case   SDLK_UP:
                               if(Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume2.png"))
                               {
                                 Mix_VolumeMusic(MIX_MAX_VOLUME * 1000);
                                 Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume3.png");
                               }
                               break;
                             case SDLK_RIGHT:
                                 Mix_VolumeMusic(MIX_MAX_VOLUME * 3);
                                 Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume2.png");
                               break;
                               
                          }
                          
                          
                          break;
                      case SDL_MOUSEMOTION:     //printf("%d | %d \n", event.motion.x, event.motion.y);
                      break;
                      
                      case SDL_MOUSEBUTTONDOWN:
                      //Bouton FULLSCREEN
                         if(1250 <= event.button.x && event.button.x<=1295 && 547 <= event.button.y && event.button.y <=588)
                            {
                              CarreauFullScreen = IMG_Load("/home/mouheb/PROJET/src/Images/hello.png");
                              SDL_BlitSurface(CarreauFullScreen, NULL, screen, & PositionCarreauFullScreenSurEcran);
                              SDL_WM_ToggleFullScreen(screen);
                            }
                         else
                            {
                              CarreauFullScreen = IMG_Load("/home/mouheb/PROJET/src/Images/hi.png");
                              SDL_BlitSurface(CarreauFullScreen, NULL, screen, & PositionCarreauFullScreenSurEcran);
                            }
                            
                            //Bouton BACK
                         if(1098 <= event.button.x && event.button.x<=1307 && 832 <= event.button.y && event.button.y <=889)   
                         {
                         
                           t = 0;
                           SDL_Flip(screen);
                         }
                         
                         //Boutons Volume
                         if(762 <= event.button.x && event.button.x<=792 && 365 <= event.button.y && event.button.y <=391 && event.button.button == SDL_BUTTON_LEFT)
                         {
                          
                           Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
                           Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume2.png");
                         }
                         if(762 <= event.button.x && event.button.x<=792 && 365 <= event.button.y && event.button.y <=391 && event.button.button == SDL_BUTTON_RIGHT)
                         {
                            Mix_VolumeMusic(MIX_MAX_VOLUME / 6);
                            Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume1.png");
                         }
                         
                         if(1070 <= event.button.x && event.button.x<=1098 && 365 <= event.button.y && event.button.y <=392 && event.button.button == SDL_BUTTON_LEFT)
                         {
                           Mix_VolumeMusic(MIX_MAX_VOLUME * 3);
                           Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume2.png");
                         }
                         
                         if(1070 <= event.button.x && event.button.x<=1098 && 365 <= event.button.y && event.button.y <=392 && event.button.button == SDL_BUTTON_RIGHT)
                         {
                           Mix_VolumeMusic(MIX_MAX_VOLUME * 1000);
                           Volume3 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume3.png");
                         }
                    break;
                    
                     }
                     SDL_Flip(screen);
                   }
        }
        while(t == 2) // interface best score
        {
              SDL_BlitSurface(BlackBackGround, NULL, screen, &PositionBGSurEcran);
              SDL_BlitSurface(txt, NULL, screen, &PositiontxtSurEcran);
              SDL_BlitSurface(txtnext, NULL, screen, &PositiontxtnextSurEcran);
              SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_KEYDOWN:
                          switch(event.key.keysym.sym)
                          {
                            case SDLK_n:
                               t = 3;
                            break;
                          }
                      break;    
                      case SDL_MOUSEBUTTONDOWN:
                         if(635 <= event.button.x && event.button.x<= 774&& 823 <= event.button.y && event.button.y <=859)
                         {
                           t = 3;
                         }
                      break;   
                     }  
              SDL_Flip(screen);
        }
        
        while(t == 3) //interface lvl1
        {
           while(program_launched = SDL_TRUE)
           {
             SDL_BlitSurface(Image_PlaySurface, NULL, screen, &PositionBGSurEcran);
             SDL_BlitSurface(Image_fd, NULL, screen, &posJoueur);
             MAJMinimap(posJoueur, &m, 100);
             afficher(m, screen);
             initialiser_temps(&temp);
             afficher_temps(&temp, screen);
             entrerNomJoueur(nomJoueur);
             SDL_Flip(screen);
           }
        }
        
       
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

