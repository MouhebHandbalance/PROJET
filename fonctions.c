
#include "headers.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void MenuPrincipal()
{                                  
                                                                       SDL_Surface *TexteOptions = NULL;
  SDL_Surface *screen = NULL;                                          SDL_Surface *Volume1 = NULL; 
  SDL_Surface *Image_Background = NULL;                                SDL_Surface *Volume2 = NULL; 
  SDL_Surface *Image_Lantern1 = NULL;                                  SDL_Surface *Volume3 = NULL; 
  SDL_Surface *Image_Lantern2 = NULL;                                  SDL_Surface *Volume4 = NULL; 
  SDL_Surface *Image_SbouiJeu = NULL;                                  SDL_Surface *Volume5 = NULL; 
  SDL_Surface *Image_xd = NULL;                                        SDL_Surface *Volume6 = NULL; 
  SDL_Surface *Image_PlaySurface = NULL;                               SDL_Surface *Volume7 = NULL; 
  SDL_Surface *Image_PlayButtonBackground = NULL;                      SDL_Surface *Volume8 = NULL; 
  SDL_Surface *Image_OptionsButtonBackground = NULL;                   SDL_Surface *Volume9 = NULL; 
  SDL_Surface *Image_QuitButtonBackground = NULL;                      SDL_Surface *Volume10 = NULL; 
  SDL_Surface *Texte = NULL;                                           SDL_Surface *TexteVolume = NULL;
  SDL_Surface *Play = NULL;                                            SDL_Surface *TexteBack = NULL;
  SDL_Surface *Options = NULL;
  SDL_Surface *Quit = NULL;
  SDL_Surface *Image_ff = NULL;
  
  SDL_Rect PositionPlayButtonSurEcran;                                 SDL_Rect PositionVolume1SurEcran;
  SDL_Rect PositionOptionsButtonSurEcran;                              SDL_Rect PositionVolume2SurEcran;
  SDL_Rect PositionQuitButtonSurEcran;                                 SDL_Rect PositionVolume3SurEcran;
  SDL_Rect PositionBGSurEcran;                                         SDL_Rect PositionVolume4SurEcran;
  SDL_Rect PositionButtonBackgroundPlaySurEcran;                       SDL_Rect PositionVolume5SurEcran;
  SDL_Rect PositionButtonBackgroundOptionsSurEcran;                    SDL_Rect PositionVolume6SurEcran;
  SDL_Rect PositionButtonBackgroundQuitSurEcran;                       SDL_Rect PositionVolume7SurEcran;
  SDL_Rect PositionTexteSurEcran;                                      SDL_Rect PositionVolume8SurEcran;
  SDL_Rect PositionLantern1SurEcran;                                   SDL_Rect PositionVolume9SurEcran;
  SDL_Rect PositionLantern2SurEcran;                                   SDL_Rect PositionVolume10SurEcran;
  SDL_Rect PositionSbouiJeuSurEcran;                                   SDL_Rect PositionTexteOptionsSurEcran;
  SDL_Rect PositionffSurEcran;                                         SDL_Rect PositionTexteVolumeSurEcran;
                                                                       SDL_Rect PositionTexteBackSurEcran;
                                                               
  TTF_Font *policeTexte = NULL;                                        TTF_Font *policeTexteOptions = NULL; 
  TTF_Font *policePlayButton = NULL;                                   TTF_Font *policeTexteVolume = NULL; 
  TTF_Font *policeOptionsButton = NULL;                                TTF_Font *policeTexteBack = NULL; 
  TTF_Font *policeQuitButton = NULL;
  
  SDL_bool program_launched = SDL_TRUE;
  
  SDL_Color CouleurNoire = {255, 255, 255};
  SDL_Color CouleurNoire1 = {0, 0, 0};
  SDL_Color CouleurRouge = {255, 0, 0};
  
  Mix_Music *MusicContenuMenu = NULL;
  Mix_Chunk *SonBrefClick;
  
  SDL_Event event;
  SDL_Event eventBack;

int FoisDeRepetition = 1;  
  
  
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
    
    Image_PlaySurface = IMG_Load("/home/mouheb/PROJET/src/Images/PlaySurface.jpg");
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
    
    Volume1 = IMG_Load("/home/mouheb/PROJET/src/Images/Volume10.png");
    if(Volume1 == NULL)
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
        
        PositionPlayButtonSurEcran.x = 640;          PositionButtonBackgroundPlaySurEcran.x = 556;
        PositionPlayButtonSurEcran.y = 350;          PositionButtonBackgroundPlaySurEcran.y = 345;
        
        
        PositionOptionsButtonSurEcran.x = 610;       PositionButtonBackgroundOptionsSurEcran.x = 556;
        PositionOptionsButtonSurEcran.y = 410;       PositionButtonBackgroundOptionsSurEcran.y = 405;
        
        PositionQuitButtonSurEcran.x = 640;          PositionButtonBackgroundQuitSurEcran.x = 556;
        PositionQuitButtonSurEcran.y = 470;          PositionButtonBackgroundQuitSurEcran.y = 465;
        
        PositionTexteSurEcran.x = 500;
        PositionTexteSurEcran.y = 210;
        
        PositionLantern1SurEcran.x = -520;          PositionLantern2SurEcran.x = -298;
        PositionLantern1SurEcran.y = 0;             PositionLantern1SurEcran.y = 0;
        
        PositionSbouiJeuSurEcran.x = 30;
        PositionSbouiJeuSurEcran.y = 600;
        
        PositionTexteOptionsSurEcran.x = 540;
        PositionTexteOptionsSurEcran.y = 100;
        
        PositionTexteVolumeSurEcran.x = 900;
        PositionTexteVolumeSurEcran.y = 320;
        
        PositionTexteBackSurEcran.x = 1100;
        PositionTexteBackSurEcran.y = 800;
        
        PositionVolume1SurEcran.x = 1000;
        PositionVolume1SurEcran.y = 320;
        
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
                         while(program_launched = SDL_TRUE)
                         {
                           SDL_BlitSurface(Image_PlaySurface, NULL, screen, &PositionBGSurEcran);
                           SDL_BlitSurface(Image_SbouiJeu, NULL, screen, &PositionSbouiJeuSurEcran);
                           SDL_Flip(screen);
                         }
                         break;
                         
                         case SDLK_o:
                            while(program_launched = SDL_TRUE)
                            {
                              SDL_BlitSurface(Image_Background, NULL, screen, &PositionBGSurEcran);
                              SDL_BlitSurface(TexteOptions, NULL, screen, &PositionTexteOptionsSurEcran);
                              SDL_BlitSurface(TexteVolume, NULL, screen, &PositionTexteVolumeSurEcran);
                              SDL_BlitSurface(TexteBack, NULL, screen, &PositionTexteBackSurEcran);
                              SDL_Flip(screen);
                            }
                         break;
                         
                         case SDLK_q:
                            program_launched = SDL_FALSE;
                            break;
                            
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
                 //Musique(Son Bref)
                 SonBrefClick = Mix_LoadWAV("SonBrefClick.wav");
                 Mix_PlayChannel(-1, SonBrefClick, 0);
                 while(program_launched = SDL_TRUE)
                   {
                     SDL_BlitSurface(Image_PlaySurface, NULL, screen, &PositionBGSurEcran);
                     
                     SDL_Flip(screen);
                   }
               }
               
               
               
               if(556 <= event.button.x && event.button.x<=826 && 407 <= event.button.y && event.button.y <=451) //Ouverture du fenetre Pour les Options
               {
                 while(program_launched = SDL_TRUE)
                   {
                     SDL_BlitSurface(Image_Background, NULL, screen, &PositionBGSurEcran);
                     SDL_BlitSurface(TexteOptions, NULL, screen, &PositionTexteOptionsSurEcran);
                     SDL_BlitSurface(TexteVolume, NULL, screen, &PositionTexteVolumeSurEcran);
                     SDL_BlitSurface(TexteBack, NULL, screen, &PositionTexteBackSurEcran);
                     SDL_BlitSurface(Volume1, NULL, screen, &PositionVolume1SurEcran);
                     SDL_PollEvent(&eventBack);
                     switch(event.type)
                     {
                       case SDL_KEYDOWN:
                          switch(event.key.keysym.sym)
                          {
                            case SDLK_q:
                               while(program_launched = SDL_TRUE)
                               {
                                 program_launched = SDL_FALSE;
                               }
                               break;
                          }
                     }
                     SDL_Flip(screen);
                   }
               }
                   
                   
                   
                if(356<=event.button.x && event.button.x<=632 && 465<=event.button.y && event.button.y<=513)   //Quitter aprés cliquer sur Bouton Quitter
                 {
                    program_launched = SDL_FALSE;
                 } 
            break;
            case SDL_QUIT:
              program_launched = SDL_FALSE;
            break;
            
            
        }
        //FoisDeRepetition--;
       
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

