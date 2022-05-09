#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void TicTacToe(SDL_Surface *screen)
{
  SDL_Surface *tictactoe = NULL;
  SDL_Surface *BlackBackGround = NULL;
  SDL_Surface *tictactoetxt = NULL;
  SDL_Surface *you = NULL;
  SDL_Surface *computer = NULL;
  SDL_Surface *x = NULL;
  SDL_Surface *o = NULL;
  
  SDL_Rect PositionttictactoeSurEcran;
  SDL_Rect PositionBGSurEcran;
  SDL_Rect PositiontictactoetxtSurEcran;
  SDL_Rect PositionyouSurEcran;
  SDL_Rect PositioncomputerSurEcran;
  SDL_Rect PositionxSurEcran;
  SDL_Rect PositionoSurEcran;
  
  SDL_Color CouleurNoire = {255, 255, 255};
  TTF_Font *policetxtnext = NULL;
  
  int continuer = 1, m = 0;
  int millisecondes;
  
   SDL_Event event;
  
  PositionBGSurEcran.x = 0;   PositionBGSurEcran.y = 0;
  PositionttictactoeSurEcran.x = 440; PositionttictactoeSurEcran.y = 150;
  PositiontictactoetxtSurEcran.x = 640;  PositiontictactoetxtSurEcran.y = 20;
  PositionyouSurEcran.x = 60;  PositionyouSurEcran.y = 700;
  PositioncomputerSurEcran.x = 60; PositioncomputerSurEcran.y = 760;
  
  
  
  tictactoe = IMG_Load("/home/yassine/PROJET/src/Images/TicTacToe.png");
    if(tictactoe == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      
      SDL_Quit();
    }
    
    BlackBackGround = IMG_Load("/home/yassine/PROJET/src/Images/thumb-3d-black-texture-geometric-black-texture-black-abstraction-background-3d-abstraction-black-texture-creative-black-background.jpg");
    if(BlackBackGround == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_Quit();
    }
    
    x = IMG_Load("/home/yassine/PROJET/src/Images/Xchose.png");
    if(x == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_Quit();
    }
    
    o = IMG_Load("/home/yassine/PROJET/src/Images/Ochose.png");
    if(o == NULL)
    {
      printf("Erreur : %s \n", SDL_GetError());
      SDL_Quit();
    }
    
    policetxtnext = TTF_OpenFont("f.ttf",40);
  tictactoetxt = TTF_RenderText_Blended(policetxtnext, "!TIC-TAC-TOE!", CouleurNoire);
  policetxtnext = TTF_OpenFont("f.ttf",40);
  
   policetxtnext = TTF_OpenFont("f.ttf",40);
  you = TTF_RenderText_Blended(policetxtnext, "YOU: X", CouleurNoire);
  policetxtnext = TTF_OpenFont("f.ttf",40);
  
  policetxtnext = TTF_OpenFont("f.ttf",40);
  computer = TTF_RenderText_Blended(policetxtnext, "COMPUTER: O", CouleurNoire);
  policetxtnext = TTF_OpenFont("f.ttf",40);
    
    while(continuer == 1)
    {
      SDL_BlitSurface(BlackBackGround, NULL, screen, &PositionBGSurEcran);
      SDL_BlitSurface(tictactoe, NULL, screen, &PositionttictactoeSurEcran);
      SDL_BlitSurface(tictactoetxt, NULL, screen, &PositiontictactoetxtSurEcran);
      SDL_BlitSurface(you, NULL, screen, &PositionyouSurEcran);
      SDL_BlitSurface(computer, NULL, screen, &PositioncomputerSurEcran);
      SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(483 <= event.button.x && event.button.x<= 666&& 293<= event.button.y && event.button.y <=487)
                         {
                           m = 1;
                         }
                        
                     }
                     
      SDL_Flip(screen);
      
      if(m == 1)
      {
        while(m == 1 && continuer)
        {
          PositionxSurEcran.x = 545; PositionxSurEcran.y = 347;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 733;  PositionoSurEcran.y = 355;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(475 <= event.button.x && event.button.x<= 666&& 525<= event.button.y && event.button.y <=693)
                         {
                           m = 2;
                         }
                         else if(475 <= event.button.x && event.button.x<= 666&& 729<= event.button.y && event.button.y <=915)
                         {
                           m = 23;
                         }
                         else if(689 <= event.button.x && event.button.x<= 879 && 510<= event.button.y && event.button.y <=701)
                         {
                           m = 44;
                         }
                         else if(689 <= event.button.x && event.button.x<= 880 && 724<= event.button.y && event.button.y <=918)
                         {
                           m = 65;
                         }
                        
                        else if(898 <= event.button.x && event.button.x<= 1086 && 724<= event.button.y && event.button.y <=909)
                         {
                           m = 88;
                         }
                        break;
                     }
        SDL_Flip(screen);
        }
         while(m == 88 && continuer)
        {
          PositionxSurEcran.x = 955; PositionxSurEcran.y = 786;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 713;  PositionoSurEcran.y = 563;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(897 <= event.button.x && event.button.x<= 1097 && 511<= event.button.y && event.button.y <= 705)
                         {
                           m = 89;
                         }
                         else if(691 <= event.button.x && event.button.x<= 878 && 729<= event.button.y && event.button.y <= 915)
                         {
                           m = 90;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1082 && 300<= event.button.y && event.button.y <= 490)
                         {
                           m = 91;
                         }
                         else if(474 <= event.button.x && event.button.x<= 667 && 729<= event.button.y && event.button.y <= 917)
                         {
                           m = 92;
                         }
                         else if(474 <= event.button.x && event.button.x<= 669 && 514<= event.button.y && event.button.y <= 705)
                         {
                           m = 93;
                         }
                        break;
                      break;
                        case SDL_MOUSEMOTION: printf("%d | %d \n", event.motion.x, event.motion.y);   
                     }
        SDL_Flip(screen);
        }
        while(m == 89 && continuer)
        {
          PositionxSurEcran.x = 940; PositionxSurEcran.y = 548;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 728;  PositionoSurEcran.y = 774;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 91 && continuer)
        {
          PositionxSurEcran.x = 942; PositionxSurEcran.y = 330;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 725;  PositionoSurEcran.y = 777;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 90 && continuer)
        {
          PositionxSurEcran.x = 722; PositionxSurEcran.y = 770;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 520;  PositionoSurEcran.y = 770;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(900 <= event.button.x && event.button.x<= 1093 && 296<= event.button.y && event.button.y <= 484)
                         {
                           m = 94;
                         }
                         if(900 <= event.button.x && event.button.x<= 1093 && 514<= event.button.y && event.button.y <= 703)
                         {
                           m = 95;
                         }
                         if(474 <= event.button.x && event.button.x<= 663 && 515<= event.button.y && event.button.y <= 700)
                         {
                           m = 96;
                         }
                     }    
        }
        while(m == 92 && continuer)
        {
          PositionxSurEcran.x = 511; PositionxSurEcran.y = 769;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 726;  PositionoSurEcran.y = 773;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 93 && continuer)
        {
          PositionxSurEcran.x = 511; PositionxSurEcran.y = 544;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 728;  PositionoSurEcran.y = 774;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        
        
        while(m == 94 && continuer)
        {
          PositionxSurEcran.x = 942; PositionxSurEcran.y = 343;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 940;  PositionoSurEcran.y = 560;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 95 && continuer)
        {
          PositionxSurEcran.x = 941; PositionxSurEcran.y = 556;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 941;  PositionoSurEcran.y = 326;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 96 && continuer)
        {
          PositionxSurEcran.x = 516; PositionxSurEcran.y = 547;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 947;  PositionoSurEcran.y = 331;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        
        
        
        
        while(m == 65 && continuer)
        {
          PositionxSurEcran.x = 732; PositionxSurEcran.y = 772;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 517;  PositionoSurEcran.y = 553;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(471 <= event.button.x && event.button.x<= 664 && 724<= event.button.y && event.button.y <= 914)
                         {
                           m = 66;
                         }
                         else if(690 <= event.button.x && event.button.x<= 878 && 508<= event.button.y && event.button.y <= 702)
                         {
                           m = 67;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1082 && 727<= event.button.y && event.button.y <= 909)
                         {
                           m = 68;
                         }
                         else if(867 <= event.button.x && event.button.x<= 1094 && 510<= event.button.y && event.button.y <= 701)
                         {
                           m = 69;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1094 && 300<= event.button.y && event.button.y <= 489)
                         {
                           m = 70;
                         }
                        break;
                      break;
                        case SDL_MOUSEMOTION: printf("%d | %d \n", event.motion.x, event.motion.y);   
                     }
        SDL_Flip(screen);
        }
        while(m == 70 && continuer)
        {
          PositionxSurEcran.x = 941; PositionxSurEcran.y = 340;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 735;  PositionoSurEcran.y = 559;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(898 <= event.button.x && event.button.x<= 1091 && 511<= event.button.y && event.button.y <= 703)
                         {
                           m = 85;
                         }
                         else if(899 <= event.button.x && event.button.x<= 1079 && 726<= event.button.y && event.button.y <= 897)
                         {
                           m = 86;
                         }
                         else if(474 <= event.button.x && event.button.x<= 665 && 728<= event.button.y && event.button.y <= 915)
                         {
                           m = 87;
                         }
                     }    
        }
        while(m == 85 && continuer)
        {
          PositionxSurEcran.x = 942; PositionxSurEcran.y = 552;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 949;  PositionoSurEcran.y = 771;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 86 && continuer)
        {
          PositionxSurEcran.x = 946; PositionxSurEcran.y = 772;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 945;  PositionoSurEcran.y = 558;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 87 && continuer)
        {
          PositionxSurEcran.x = 517; PositionxSurEcran.y = 768;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 941;  PositionoSurEcran.y = 557;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 69 && continuer)
        {
          PositionxSurEcran.x = 941; PositionxSurEcran.y = 558;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 937;  PositionoSurEcran.y = 328;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(690 <= event.button.x && event.button.x<= 875 && 511<= event.button.y && event.button.y <= 703)
                         {
                           m = 81;
                         }
                         else if(899 <= event.button.x && event.button.x<= 1079 && 726<= event.button.y && event.button.y <= 897)
                         {
                           m = 82;
                         }
                         else if(474 <= event.button.x && event.button.x<= 665 && 728<= event.button.y && event.button.y <= 915)
                         {
                           m = 84;
                         }
                     }    
        }
        while(m == 68 && continuer)
        {
          PositionxSurEcran.x = 938; PositionxSurEcran.y = 768;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 511;  PositionoSurEcran.y = 762;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(691 <= event.button.x && event.button.x<= 650 && 511<= event.button.y && event.button.y <= 618)
                         {
                           m = 77;
                         }
                         else if(898 <= event.button.x && event.button.x<= 1095 && 511<= event.button.y && event.button.y <= 702)
                         {
                           m = 78;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1093 && 296<= event.button.y && event.button.y <= 488)
                         {
                           m = 79;
                         }
                     }    
        }
        while(m == 81 && continuer)
        {
          PositionxSurEcran.x = 726; PositionxSurEcran.y = 552;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 934;  PositionoSurEcran.y = 764;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 84 && continuer)
        {
          PositionxSurEcran.x = 525; PositionxSurEcran.y = 766;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 947;  PositionoSurEcran.y = 777;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 82 && continuer)
        {
          PositionxSurEcran.x = 949; PositionxSurEcran.y = 782;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 730;  PositionoSurEcran.y = 556;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(473 <= event.button.x && event.button.x<= 667 && 726<= event.button.y && event.button.y <= 914)
                         {
                           m = 83;
                         }
                     }    
        }
        while(m == 83 && continuer)
        {
          PositionxSurEcran.x = 508; PositionxSurEcran.y = 767;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 77 && continuer)
        {
          PositionxSurEcran.x = 731; PositionxSurEcran.y = 552;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 78 && continuer)
        {
          PositionxSurEcran.x = 943; PositionxSurEcran.y = 549;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 735;  PositionoSurEcran.y = 555;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 79 && continuer)
        {
          PositionxSurEcran.x = 936; PositionxSurEcran.y = 327;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 938;  PositionoSurEcran.y = 553;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(688 <= event.button.x && event.button.x<= 878 && 512<= event.button.y && event.button.y <= 699)
                         {
                           m = 80;
                         }
                     }    
        }
        while(m == 80 && continuer)
        {
          PositionxSurEcran.x = 722; PositionxSurEcran.y = 549;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 67 && continuer)
        {
          PositionxSurEcran.x = 729; PositionxSurEcran.y = 556;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 950;  PositionoSurEcran.y = 332;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(901 <= event.button.x && event.button.x<= 1076 && 728<= event.button.y && event.button.y <= 915)
                         {
                           m = 74;
                         }
                         else if(898 <= event.button.x && event.button.x<= 1095 && 511<= event.button.y && event.button.y <= 702)
                         {
                           m = 75;
                         }
                         else if(474 <= event.button.x && event.button.x<= 668 && 725<= event.button.y && event.button.y <= 915)
                         {
                           m = 76;
                         }
                     }    
        }
        while(m == 74 && continuer)
        {
          PositionxSurEcran.x = 942; PositionxSurEcran.y = 770;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 75 && continuer)
        {
          PositionxSurEcran.x = 950; PositionxSurEcran.y = 562;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 947;  PositionoSurEcran.y = 778;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 76 && continuer)
        {
          PositionxSurEcran.x = 518; PositionxSurEcran.y = 772;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 945;  PositionoSurEcran.y = 767;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 66 && continuer)
        {
          PositionxSurEcran.x = 519; PositionxSurEcran.y = 770;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 950;  PositionoSurEcran.y = 772;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(689 <= event.button.x && event.button.x<= 878 && 509<= event.button.y && event.button.y <= 703)
                         {
                           m = 71;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1095 && 513<= event.button.y && event.button.y <= 702)
                         {
                           m = 72;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1095 && 294<= event.button.y && event.button.y <= 485)
                         {
                           m = 73;
                         }
                     }    
        }
        
        while(m == 71 && continuer)
        {
          PositionxSurEcran.x = 730; PositionxSurEcran.y = 552;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 943;  PositionoSurEcran.y = 331;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 72 && continuer)
        {
          PositionxSurEcran.x = 945; PositionxSurEcran.y = 565;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 938;  PositionoSurEcran.y = 327;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 73 && continuer)
        {
          PositionxSurEcran.x = 934; PositionxSurEcran.y = 333;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 731;  PositionoSurEcran.y = 554;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 44 && continuer)
        {
          PositionxSurEcran.x = 739; PositionxSurEcran.y = 567;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 949;  PositionoSurEcran.y = 784;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(472 <= event.button.x && event.button.x<= 664 && 729<= event.button.y && event.button.y <= 914)
                         {
                           m = 45;
                         }
                         else if(473 <= event.button.x && event.button.x<= 666 && 514<= event.button.y && event.button.y <= 704)
                         {
                           m = 46;
                         }
                         else if(692 <= event.button.x && event.button.x<= 876 && 727<= event.button.y && event.button.y <= 916)
                         {
                           m = 47;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1094 && 512<= event.button.y && event.button.y <= 701)
                         {
                           m = 48;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1094 && 300<= event.button.y && event.button.y <= 489)
                         {
                           m = 49;
                         }
                        break;
                      break;
                        case SDL_MOUSEMOTION: printf("%d | %d \n", event.motion.x, event.motion.y);   
                     }
        SDL_Flip(screen);
        }
        while(m == 49 && continuer)
        {
          PositionxSurEcran.x = 947; PositionxSurEcran.y = 333;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 519;  PositionoSurEcran.y = 771;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(899 <= event.button.x && event.button.x<= 1094 && 511<= event.button.y && event.button.y <= 702)
                         {
                           m = 62;
                         }
                         else if(472 <= event.button.x && event.button.x<= 668 && 510<= event.button.y && event.button.y <= 701)
                         {
                           m = 63;
                         }
                         else if(688 <= event.button.x && event.button.x<= 880 && 725<= event.button.y && event.button.y <= 912)
                         {
                           m = 64;
                         }
                     }    
        }
        while(m == 62 && continuer)
        {
          PositionxSurEcran.x = 943; PositionxSurEcran.y = 558;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 511;  PositionoSurEcran.y = 551;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 63 && continuer)
        {
          PositionxSurEcran.x = 502; PositionxSurEcran.y = 544;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 950;  PositionoSurEcran.y = 561;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 64 && continuer)
        {
          PositionxSurEcran.x = 729; PositionxSurEcran.y = 769;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 956;  PositionoSurEcran.y = 564;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 48 && continuer)
        {
          PositionxSurEcran.x = 957; PositionxSurEcran.y = 567;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 522;  PositionoSurEcran.y = 556;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(473 <= event.button.x && event.button.x<= 666 && 726<= event.button.y && event.button.y <= 916)
                         {
                           m = 59;
                         }
                         else if(691 <= event.button.x && event.button.x<= 880 && 729<= event.button.y && event.button.y <= 913)
                         {
                           m = 60;
                         }
                         else if(898 <= event.button.x && event.button.x<= 1094 && 294<= event.button.y && event.button.y <= 487)
                         {
                           m = 61;
                         }
                     }    
        }
        while(m == 59 && continuer)
        {
          PositionxSurEcran.x = 522; PositionxSurEcran.y = 773;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 950;  PositionoSurEcran.y = 330;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 60 && continuer)
        {
          PositionxSurEcran.x = 730; PositionxSurEcran.y = 776;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 940;  PositionoSurEcran.y = 325;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 61 && continuer)
        {
          PositionxSurEcran.x = 946; PositionxSurEcran.y = 327;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 520;  PositionoSurEcran.y = 774;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 47 && continuer)
        {
          PositionxSurEcran.x = 738; PositionxSurEcran.y = 776;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 951;  PositionoSurEcran.y = 559;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(900 <= event.button.x && event.button.x<= 1095 && 294<= event.button.y && event.button.y <= 490)
                         {
                           m = 56;
                         }
                         else if(473 <= event.button.x && event.button.x<= 668 && 728<= event.button.y && event.button.y <= 916)
                         {
                           m = 57;
                         }
                         else if(476 <= event.button.x && event.button.x<= 668 && 514<= event.button.y && event.button.y <= 703)
                         {
                           m = 58;
                         }
                     }    
        }
        while(m == 56 && continuer)
        {
          PositionxSurEcran.x = 946; PositionxSurEcran.y = 335;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 532;  PositionoSurEcran.y = 770;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 57 && continuer)
        {
          PositionxSurEcran.x = 521; PositionxSurEcran.y = 779;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 940;  PositionoSurEcran.y = 333;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 58 && continuer)
        {
          PositionxSurEcran.x = 517; PositionxSurEcran.y = 548;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 947;  PositionoSurEcran.y = 342;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 46 && continuer)
        {
          PositionxSurEcran.x = 527; PositionxSurEcran.y = 547;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 949;  PositionoSurEcran.y = 563;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(474 <= event.button.x && event.button.x<= 667 && 726<= event.button.y && event.button.y <= 915)
                         {
                           m = 53;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1096 && 295<= event.button.y && event.button.y <= 490)
                         {
                           m = 54;
                         }
                         else if(689 <= event.button.x && event.button.x<= 878 && 725<= event.button.y && event.button.y <= 914)
                         {
                           m = 55;
                         }
                     }    
        }
        while(m == 53 && continuer)
        {
          PositionxSurEcran.x = 510; PositionxSurEcran.y = 773;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 54 && continuer)
        {
          PositionxSurEcran.x = 950; PositionxSurEcran.y = 343;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 532;  PositionoSurEcran.y = 770;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 55 && continuer)
        {
          PositionxSurEcran.x = 743; PositionxSurEcran.y = 775;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 944;  PositionoSurEcran.y = 334;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 45 && continuer)
        {
          PositionxSurEcran.x = 527; PositionxSurEcran.y = 776;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 517;  PositionoSurEcran.y = 550;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(900 <= event.button.x && event.button.x<= 1095 && 294<= event.button.y && event.button.y <= 489)
                         {
                           m = 50;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1095 && 512<= event.button.y && event.button.y <= 704)
                         {
                           m = 51;
                         }
                         else if(689 <= event.button.x && event.button.x<= 881 && 725<= event.button.y && event.button.y <= 914)
                         {
                           m = 52;
                         }
                     }    
        }
        
        while(m == 50 && continuer)
        {
          PositionxSurEcran.x = 936; PositionxSurEcran.y = 331;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 51 && continuer)
        {
          PositionxSurEcran.x = 937; PositionxSurEcran.y = 556;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 933;  PositionoSurEcran.y = 329;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 52 && continuer)
        {
          PositionxSurEcran.x = 730; PositionxSurEcran.y = 771;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 940;  PositionoSurEcran.y = 336;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 23 && continuer)
        {
          PositionxSurEcran.x = 537; PositionxSurEcran.y = 783;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 533;  PositionoSurEcran.y = 558;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(902 <= event.button.x && event.button.x<= 1079 && 729<= event.button.y && event.button.y <= 914)
                         {
                           m = 24;
                         }
                         else if(907 <= event.button.x && event.button.x<= 1093 && 295<= event.button.y && event.button.y <= 487)
                         {
                           m = 25;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1095 && 511<= event.button.y && event.button.y <= 701)
                         {
                           m = 26;
                         }
                         else if(690 <= event.button.x && event.button.x<= 877 && 512<= event.button.y && event.button.y <= 701)
                         {
                           m = 27;
                         }
                         else if(692 <= event.button.x && event.button.x<= 873 && 731<= event.button.y && event.button.y <= 912)
                         {
                           m = 28;
                         }
                        break;
                      break;
                        case SDL_MOUSEMOTION: printf("%d | %d \n", event.motion.x, event.motion.y);   
                     }
        SDL_Flip(screen);
        }
        while(m == 28 && continuer)
        {
          PositionxSurEcran.x = 739; PositionxSurEcran.y = 779;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 947;  PositionoSurEcran.y = 785;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(691 <= event.button.x && event.button.x<= 879 && 512<= event.button.y && event.button.y <= 700)
                         {
                           m = 41;
                         }
                         else if(900 <= event.button.x && event.button.x<= 1095 && 512<= event.button.y && event.button.y <= 704)
                         {
                           m = 42;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1095 && 300<= event.button.y && event.button.y <= 489)
                         {
                           m = 43;
                         }
                     }    
        }
        
        while(m == 41 && continuer)
        {
          PositionxSurEcran.x = 734; PositionxSurEcran.y = 558;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 936;  PositionoSurEcran.y = 338;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 42 && continuer)
        {
          PositionxSurEcran.x = 946; PositionxSurEcran.y = 569;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 734;  PositionoSurEcran.y = 562;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 43 && continuer)
        {
          PositionxSurEcran.x = 943; PositionxSurEcran.y = 332;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 732;  PositionoSurEcran.y = 562;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        
        while(m == 27 && continuer)
        {
          PositionxSurEcran.x = 951; PositionxSurEcran.y = 566;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 746;  PositionoSurEcran.y = 561;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(899 <= event.button.x && event.button.x<= 1076 && 727<= event.button.y && event.button.y <= 904)
                         {
                           m = 38;
                         }
                         else if(690 <= event.button.x && event.button.x<= 874 && 726<= event.button.y && event.button.y <= 914)
                         {
                           m = 39;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1095 && 511<= event.button.y && event.button.y <= 700)
                         {
                           m = 40;
                         }
                     }    
        }
        
        while(m == 38 && continuer)
        {
          PositionxSurEcran.x = 954; PositionxSurEcran.y = 782;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 39 && continuer)
        {
          PositionxSurEcran.x = 740; PositionxSurEcran.y = 782;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 951;  PositionoSurEcran.y = 786;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 40 && continuer)
        {
          PositionxSurEcran.x = 952; PositionxSurEcran.y = 569;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 951;  PositionoSurEcran.y = 786;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 26 && continuer)
        {
          PositionxSurEcran.x = 951; PositionxSurEcran.y = 566;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 746;  PositionoSurEcran.y = 561;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(694 <= event.button.x && event.button.x<= 873 && 726<= event.button.y && event.button.y <= 917)
                         {
                           m = 35;
                         }
                         else if(902 <= event.button.x && event.button.x<= 1072 && 726<= event.button.y && event.button.y <= 914)
                         {
                           m = 36;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1095 && 300<= event.button.y && event.button.y <= 486)
                         {
                           m = 37;
                         }
                     }    
        }
        while(m == 35 && continuer)
        {
          PositionxSurEcran.x = 740; PositionxSurEcran.y = 782;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 951;  PositionoSurEcran.y = 786;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 36 && continuer)
        {
          PositionxSurEcran.x = 948; PositionxSurEcran.y = 783;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 731;  PositionoSurEcran.y = 770;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 37 && continuer)
        {
          PositionxSurEcran.x = 946; PositionxSurEcran.y = 337;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 736;  PositionoSurEcran.y = 777;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 25 && continuer)
        {
          PositionxSurEcran.x = 954; PositionxSurEcran.y = 343;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 734;  PositionoSurEcran.y = 567;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(694 <= event.button.x && event.button.x<= 873 && 732<= event.button.y && event.button.y <= 917)
                         {
                           m = 32;
                         }
                         else if(906 <= event.button.x && event.button.x<= 1085 && 726<= event.button.y && event.button.y <= 911)
                         {
                           m = 33;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1095 && 512<= event.button.y && event.button.y <= 701)
                         {
                           m = 34;
                         }
                     }    
        }
        while(m == 32 && continuer)
        {
          PositionxSurEcran.x = 749; PositionxSurEcran.y = 777;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 947;  PositionoSurEcran.y = 565;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 33 && continuer)
        {
          PositionxSurEcran.x = 948; PositionxSurEcran.y = 783;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 740;  PositionoSurEcran.y = 787;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 34 && continuer)
        {
          PositionxSurEcran.x = 952; PositionxSurEcran.y = 569;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 739;  PositionoSurEcran.y = 785;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        } 
        while(m == 24 && continuer)
        {
          PositionxSurEcran.x = 944; PositionxSurEcran.y = 780;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 747;  PositionoSurEcran.y = 791;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(694 <= event.button.x && event.button.x<= 873 && 512<= event.button.y && event.button.y <= 700)
                         {
                           m = 29;
                         }
                         else if(906 <= event.button.x && event.button.x<= 1096 && 517<= event.button.y && event.button.y <= 701)
                         {
                           m = 30;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1095 && 296<= event.button.y && event.button.y <= 482)
                         {
                           m = 31;
                         }
                     }    
        }
        while(m == 29 && continuer)
        {
          PositionxSurEcran.x = 735; PositionxSurEcran.y = 560;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 30 && continuer)
        {
          PositionxSurEcran.x = 937; PositionxSurEcran.y = 558;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 731;  PositionoSurEcran.y = 567;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 31 && continuer)
        {
          PositionxSurEcran.x = 943; PositionxSurEcran.y = 328;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 730;  PositionoSurEcran.y = 560;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        } 
        while(m == 2 && continuer)
        {
          PositionxSurEcran.x = 500; PositionxSurEcran.y = 550;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 529;  PositionoSurEcran.y = 788;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(695 <= event.button.x && event.button.x<= 870 && 517<= event.button.y && event.button.y <= 695)
                         {
                           m = 3;
                         }
                         else if(907 <= event.button.x && event.button.x<= 1072 && 733<= event.button.y && event.button.y <= 905)
                         {
                           m = 7;
                         }
                         else if(907 <= event.button.x && event.button.x<= 1082 && 517<= event.button.y && event.button.y <= 692)
                         {
                           m = 9;
                         }
                         else if(700 <= event.button.x && event.button.x<= 868 && 733<= event.button.y && event.button.y <= 903)
                         {
                           m = 15;
                         }
                         else if(903 <= event.button.x && event.button.x<= 1091 && 300<= event.button.y && event.button.y <= 485)
                         {
                           m = 19;
                         }
                        break;
                      break;
                        case SDL_MOUSEMOTION: printf("%d | %d \n", event.motion.x, event.motion.y);   
                     }
        SDL_Flip(screen);
        }
        while(m == 19 && continuer)
        {
          PositionxSurEcran.x = 944; PositionxSurEcran.y = 321;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 734;  PositionoSurEcran.y = 555;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(694 <= event.button.x && event.button.x<= 868 && 730<= event.button.y && event.button.y <= 912)
                         {
                           m = 20;
                         }
                         else if(906 <= event.button.x && event.button.x<= 1091 && 517<= event.button.y && event.button.y <= 701)
                         {
                           m = 21;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1077 && 729<= event.button.y && event.button.y <= 914)
                         {
                           m = 22;
                         }
                     }    
        } 
        while(m == 22 && continuer)
        {
          PositionxSurEcran.x = 954; PositionxSurEcran.y = 782;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 739;  PositionoSurEcran.y = 787;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 21 && continuer)
        {
          PositionxSurEcran.x = 954; PositionxSurEcran.y = 567;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 739;  PositionoSurEcran.y = 787;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 20 && continuer)
        {
          PositionxSurEcran.x = 737; PositionxSurEcran.y = 780;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 959;  PositionoSurEcran.y = 790;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }  
        while(m == 15 && continuer)
        {
          PositionxSurEcran.x = 731; PositionxSurEcran.y = 771;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 734;  PositionoSurEcran.y = 555;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(907 <= event.button.x && event.button.x<= 1085 && 300<= event.button.y && event.button.y <= 474)
                         {
                           m = 16;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1085 && 511<= event.button.y && event.button.y <= 704)
                         {
                           m = 17;
                         }
                         else if(901 <= event.button.x && event.button.x<= 1085 && 731<= event.button.y && event.button.y <= 916)
                         {
                           m = 18;
                         }
                     }    
        }  
        while(m == 18 && continuer)
        {
          PositionxSurEcran.x = 950; PositionxSurEcran.y = 790;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 948;  PositionoSurEcran.y = 336;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 17 && continuer)
        {
          PositionxSurEcran.x = 950; PositionxSurEcran.y = 571;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 948;  PositionoSurEcran.y = 336;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }  
        while(m == 16 && continuer)
        {
          PositionxSurEcran.x = 943; PositionxSurEcran.y = 333;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 939;  PositionoSurEcran.y = 569;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }  
        while(m == 9 && continuer)
        {
          PositionxSurEcran.x = 950; PositionxSurEcran.y = 569;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 723;  PositionoSurEcran.y = 555;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(924 <= event.button.x && event.button.x<= 1085 && 305<= event.button.y && event.button.y <= 474)
                         {
                           m = 10;
                         }
                         else if(700 <= event.button.x && event.button.x<= 864 && 738<= event.button.y && event.button.y <= 904)
                         {
                          m = 11;
                         }
                         else if(913 <= event.button.x && event.button.x<= 1074 && 739<= event.button.y && event.button.y <= 904)
                         {
                          m = 12;
                         }
                        break;
                        case SDL_MOUSEMOTION: printf("%d | %d \n", event.motion.x, event.motion.y);  
                     }    
        } 
        while(m == 12 && continuer)
        {
          PositionxSurEcran.x = 950; PositionxSurEcran.y = 791;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 948;  PositionoSurEcran.y = 337;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 11 && continuer)
        {
          PositionxSurEcran.x = 733; PositionxSurEcran.y = 774;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 948;  PositionoSurEcran.y = 337;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 10 && continuer)
        {
          PositionxSurEcran.x = 950; PositionxSurEcran.y = 354;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 739;  PositionoSurEcran.y = 779;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 7 && continuer)
        {
          PositionxSurEcran.x = 946; PositionxSurEcran.y = 783;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 728;  PositionoSurEcran.y = 562;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(695 <= event.button.x && event.button.x<= 863 && 736<= event.button.y && event.button.y <= 908)
                         {
                           m = 8;
                         }
                         else if(906 <= event.button.x && event.button.x<= 1085 && 517<= event.button.y && event.button.y <= 692)
                         {
                           m = 13;
                         }
                         else if(911 <= event.button.x && event.button.x<= 1082 && 303<= event.button.y && event.button.y <= 479)
                         {
                           m = 14;
                         }
                       break;
                     }    
        } 
        while(m == 14 && continuer)
        {
          PositionxSurEcran.x = 951; PositionxSurEcran.y = 343;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 744;  PositionoSurEcran.y = 778;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        } 
        while(m == 13 && continuer)
        {
          PositionxSurEcran.x = 956; PositionxSurEcran.y = 574;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 744;  PositionoSurEcran.y = 778;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        } 
        while(m == 8 && continuer)
        {
          PositionxSurEcran.x = 742; PositionxSurEcran.y = 785;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 936;  PositionoSurEcran.y = 337;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 3 && continuer)
        {
          PositionxSurEcran.x = 737; PositionxSurEcran.y = 567;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 950;  PositionoSurEcran.y = 792;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_PollEvent(&event);
                     switch(event.type)
                     {
                       case SDL_MOUSEBUTTONDOWN:
                         if(910 <= event.button.x && event.button.x<= 1082 && 523<= event.button.y && event.button.y <= 694)
                         {
                           m = 4;
                         }
                         else if(692 <= event.button.x && event.button.x<= 872 && 731<= event.button.y && event.button.y <= 909)
                         {
                           m = 5;
                         }
                         else if(910 <= event.button.x && event.button.x<= 1088 && 300<= event.button.y && event.button.y <= 475)
                         {
                           m = 6;
                         }
                         
                        break;
                        case SDL_MOUSEMOTION: printf("%d | %d \n", event.motion.x, event.motion.y);
                     }
         SDL_Flip(screen);            
        } 
        while(m == 4 && continuer)
        {
          PositionxSurEcran.x = 940; PositionxSurEcran.y = 569;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }  
        while(m == 5 && continuer)
        {
          PositionxSurEcran.x = 739; PositionxSurEcran.y = 791;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 940;  PositionoSurEcran.y = 342;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
        while(m == 6 && continuer)
        {
          PositionxSurEcran.x = 931; PositionxSurEcran.y = 341;
          SDL_BlitSurface(x, NULL, screen, &PositionxSurEcran);
          PositionoSurEcran.x = 716;  PositionoSurEcran.y = 767;
          SDL_BlitSurface(o, NULL, screen, &PositionoSurEcran);
          SDL_Flip(screen);
          SDL_Delay(2000);
          continuer = 0;
        }
      }
    }
    
}


