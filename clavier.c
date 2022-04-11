#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
int clavierd(SDL_Surface *screen, char rep[])
{   SDL_Surface *image,*a,*z,*e,*r,*t,*y,*u,*i,*o,*p,*q,*s,*d,*f,*g,*h,*j,*k,*l,*m,*w,*x,*c,*v,*b,*n,*ok,*texte,*delete;
    SDL_Rect 					   			         postionimage,posa,posz,pose,posr,post,posy,posu,posi,poso,posp,posq,poss,
	posd,posf,posg,posh,posj,posk,posl,posm,posw,posx,posc,posv,posb,posn,posok,position_text={100,100},posdelete;
    SDL_Event event;
    int done=1;
    
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255,255,255};// couleur de texte(blanche)
    TTF_Init();

    strcpy(rep,"");
        
    image=IMG_Load("/home/mouheb/PROJET/src/Images/thumb-3d-black-texture-geometric-black-texture-black-abstraction-background-3d-abstraction-black-texture-creative-black-background.jpg");
    postionimage.x=0;
    postionimage.y=0;
	delete=IMG_Load("/home/mouheb/PROJET/src/Images/DELETE.png");
	a=IMG_Load("/home/mouheb/PROJET/src/Images/A.png");
	z=IMG_Load("/home/mouheb/PROJET/src/Images/Z.png");
	e=IMG_Load("/home/mouheb/PROJET/src/Images/E.png");
	r=IMG_Load("/home/mouheb/PROJET/src/Images/R.png");
	t=IMG_Load("/home/mouheb/PROJET/src/Images/T.png");
	y=IMG_Load("/home/mouheb/PROJET/src/Images/Y.png");
	u=IMG_Load("/home/mouheb/PROJET/src/Images/U.png");
	i=IMG_Load("/home/mouheb/PROJET/src/Images/I.png");
	o=IMG_Load("/home/mouheb/PROJET/src/Images/O.png");
	p=IMG_Load("/home/mouheb/PROJET/src/Images/P.png");
	q=IMG_Load("/home/mouheb/PROJET/src/Images/Q.png");
	s=IMG_Load("/home/mouheb/PROJET/src/Images/S.png");
	d=IMG_Load("/home/mouheb/PROJET/src/Images/D.png");
	f=IMG_Load("/home/mouheb/PROJET/src/Images/F.png");
	g=IMG_Load("/home/mouheb/PROJET/src/Images/G.png");
	h=IMG_Load("/home/mouheb/PROJET/src/Images/H.png");
	j=IMG_Load("/home/mouheb/PROJET/src/Images/J.png");
	k=IMG_Load("/home/mouheb/PROJET/src/Images/K.png");
	l=IMG_Load("/home/mouheb/PROJET/src/Images/L.png");
	m=IMG_Load("/home/mouheb/PROJET/src/Images/M.png");
	w=IMG_Load("/home/mouheb/PROJET/src/Images/W.png");
	x=IMG_Load("/home/mouheb/PROJET/src/Images/X.png");	
	c=IMG_Load("/home/mouheb/PROJET/src/Images/C.png");
	v=IMG_Load("/home/mouheb/PROJET/src/Images/V.png");
	b=IMG_Load("/home/mouheb/PROJET/src/Images/B.png");
	n=IMG_Load("/home/mouheb/PROJET/src/Images/N.png");
	ok=IMG_Load("/home/mouheb/PROJET/src/Images/OK.png");	
	posa.x=250;
	posa.y=50;
	posz.x=300;
	posz.y=50;
	pose.x=350;
	pose.y=50;
	posr.x=400;
	posr.y=50;
	post.x=450;
	post.y=50;
	posy.x=500;
	posy.y=50;
	posu.x=550;
	posu.y=50;
	posi.x=600;
	posi.y=50;
	poso.x=650;
	poso.y=50;
	posp.x=700;
	posp.y=50;
	posq.x=250;
	posq.y=100;
	poss.x=300;
	poss.y=100;
	posd.x=350;
	posd.y=100;
	posf.x=400;
	posf.y=100;
	posg.x=450;
	posg.y=100;
	posh.x=500;
	posh.y=100;
	posj.x=550;
	posj.y=100;
	posk.x=600;
	posk.y=100;
	posl.x=650;
	posl.y=100;
	posm.x=700;
	posm.y=100;
	posw.x=350;
	posw.y=150;
	posx.x=400;
	posx.y=150;
	posc.x=450;
	posc.y=150;
	posv.x=500;
	posv.y=150;
	posb.x=550;
	posb.y=150;
	posn.x=600;
	posn.y=150;
	posok.x=650;
	posok.y=150;
	posdelete.x=300;
	posdelete.y=150;
	//pos.x=50;
	//pos.y=250;

	police = TTF_OpenFont("f.ttf", 30);
	

       SDL_BlitSurface(image, NULL,screen,&postionimage);
	SDL_BlitSurface(a,NULL,screen,&posa);
	SDL_BlitSurface(z,NULL,screen,&posz);
	SDL_BlitSurface(e,NULL,screen,&pose);
	SDL_BlitSurface(r,NULL,screen,&posr);
	SDL_BlitSurface(t,NULL,screen,&post);
	SDL_BlitSurface(y,NULL,screen,&posy);
	SDL_BlitSurface(u,NULL,screen,&posu);
	SDL_BlitSurface(i,NULL,screen,&posi);
	SDL_BlitSurface(o,NULL,screen,&poso);
	SDL_BlitSurface(p,NULL,screen,&posp);
	SDL_BlitSurface(q,NULL,screen,&posq);
	SDL_BlitSurface(s,NULL,screen,&poss);
	SDL_BlitSurface(d,NULL,screen,&posd);
	SDL_BlitSurface(f,NULL,screen,&posf);
	SDL_BlitSurface(g,NULL,screen,&posg);
	SDL_BlitSurface(h,NULL,screen,&posh);
	SDL_BlitSurface(j,NULL,screen,&posj);
	SDL_BlitSurface(k,NULL,screen,&posk);
	SDL_BlitSurface(l,NULL,screen,&posl);
	SDL_BlitSurface(m,NULL,screen,&posm);
	SDL_BlitSurface(w,NULL,screen,&posw);
	SDL_BlitSurface(x,NULL,screen,&posx);
	SDL_BlitSurface(c,NULL,screen,&posc);
	SDL_BlitSurface(v,NULL,screen,&posv);
	SDL_BlitSurface(b,NULL,screen,&posb);
	SDL_BlitSurface(n,NULL,screen,&posn);
    SDL_BlitSurface(ok,NULL,screen,&posok);
	 SDL_BlitSurface(delete,NULL,screen,&posdelete);
	SDL_Flip(screen);


    while(done)
    {  
	
    
     SDL_WaitEvent(&event);
     switch(event.type)

     {  case SDL_QUIT: 
			done=0;
			SDL_Quit();
                         break;
	
	case SDL_MOUSEBUTTONDOWN :
            
            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posa.x+a->w&&event.button.x>posa.x)&&      
   (event.button.y<posa.y+a->h&&event.button.y>posa.y))

            {
	strcat(rep,"a");
		}
		
		 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posz.x+z->w&&event.button.x>posz.x)&&
(event.button.y<posz.y+z->h&&event.button.y>posz.y))

            {	strcat(rep,"z");

		}
	 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<pose.x+e->w&&event.button.x>pose.x)&&
(event.button.y<pose.y+e->h&&event.button.y>pose.y))

            {	strcat(rep,"e");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posr.x+r->w&&event.button.x>posr.x)&&
(event.button.y<posr.y+r->h&&event.button.y>posr.y))

            {	strcat(rep,"r");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<post.x+t->w&&event.button.x>post.x)&&
(event.button.y<post.y+t->h&&event.button.y>post.y))

            {	strcat(rep,"t");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posy.x+y->w&&event.button.x>posy.x)&&
(event.button.y<posy.y+y->h&&event.button.y>posy.y))

            {	strcat(rep,"y");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posu.x+u->w&&event.button.x>posu.x)&&
(event.button.y<posu.y+u->h&&event.button.y>posu.y))

            {	strcat(rep,"u");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posi.x+i->w&&event.button.x>posi.x)&&
(event.button.y<posi.y+i->h&&event.button.y>posi.y))

            {	strcat(rep,"i");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<poso.x+o->w&&event.button.x>poso.x)&&
(event.button.y<poso.y+o->h&&event.button.y>poso.y))

            {	strcat(rep,"o");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posp.x+p->w&&event.button.x>posp.x)&&
(event.button.y<posp.y+p->h&&event.button.y>posp.y))

            {	strcat(rep,"p");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posq.x+q->w&&event.button.x>posq.x)&&
(event.button.y<posq.y+q->h&&event.button.y>posq.y))

            {	strcat(rep,"q");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<poss.x+s->w&&event.button.x>poss.x)&&
(event.button.y<poss.y+z->h&&event.button.y>poss.y))

            {	strcat(rep,"s");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posd.x+d->w&&event.button.x>posd.x)&&
(event.button.y<posd.y+d->h&&event.button.y>posd.y))

            {	strcat(rep,"d");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posf.x+f->w&&event.button.x>posf.x)&&
(event.button.y<posf.y+f->h&&event.button.y>posf.y))

            {	strcat(rep,"f");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posg.x+g->w&&event.button.x>posg.x)&&
(event.button.y<posg.y+g->h&&event.button.y>posg.y))

            {	strcat(rep,"g");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posh.x+h->w&&event.button.x>posh.x)&&
(event.button.y<posh.y+h->h&&event.button.y>posh.y))

            {	strcat(rep,"h");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posj.x+j->w&&event.button.x>posj.x)&&
(event.button.y<posj.y+j->h&&event.button.y>posj.y))

            {	strcat(rep,"j");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posk.x+k->w&&event.button.x>posk.x)&&
(event.button.y<posk.y+k->h&&event.button.y>posk.y))

            {	strcat(rep,"k");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posl.x+l->w&&event.button.x>posl.x)&&
(event.button.y<posl.y+l->h&&event.button.y>posl.y))

            {	strcat(rep,"l");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posm.x+m->w&&event.button.x>posm.x)&&
(event.button.y<posm.y+m->h&&event.button.y>posm.y))

            {	strcat(rep,"m");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posw.x+w->w&&event.button.x>posw.x)&&
(event.button.y<posw.y+w->h&&event.button.y>posw.y))

            {	strcat(rep,"w");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posx.x+x->w&&event.button.x>posx.x)&&
(event.button.y<posx.y+x->h&&event.button.y>posx.y))

            {	strcat(rep,"x");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posc.x+c->w&&event.button.x>posc.x)&&
(event.button.y<posc.y+c->h&&event.button.y>posc.y))

            {	strcat(rep,"c");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posv.x+v->w&&event.button.x>posv.x)&&
(event.button.y<posv.y+v->h&&event.button.y>posv.y))

            {	strcat(rep,"v");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posb.x+b->w&&event.button.x>posb.x)&&
(event.button.y<posb.y+b->h&&event.button.y>posb.y))

            {	strcat(rep,"b");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posn.x+n->w&&event.button.x>posn.x)&&
(event.button.y<posn.y+n->h&&event.button.y>posn.y))

            {	strcat(rep,"n");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posok.x+ok->w&&event.button.x>posok.x)&&
(event.button.y<posok.y+ok->h&&event.button.y>posok.y))

            {
		
		done = 0;
	}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posdelete.x+delete->w&&event.button.x>posdelete.x)&&
(event.button.y<posdelete.y+delete->h&&event.button.y>posdelete.y))

            {
		rep[strlen(rep)-1] = '\0';

	    }
	    break;
	   case SDL_KEYDOWN:
                          switch(event.key.keysym.sym)
                          {
                            case SDLK_a:
                               done = 0;
                            break;
                          }
                          break; 
      
     }  
       texte = TTF_RenderText_Blended(police, rep, couleurBlanche);	
	SDL_BlitSurface(image, NULL,screen,&postionimage); 
       SDL_BlitSurface(a,NULL,screen,&posa);
	SDL_BlitSurface(z,NULL,screen,&posz);
	SDL_BlitSurface(e,NULL,screen,&pose);
	SDL_BlitSurface(r,NULL,screen,&posr);
	SDL_BlitSurface(t,NULL,screen,&post);
	SDL_BlitSurface(y,NULL,screen,&posy);
	SDL_BlitSurface(u,NULL,screen,&posu);
	SDL_BlitSurface(i,NULL,screen,&posi);
	SDL_BlitSurface(o,NULL,screen,&poso);
	SDL_BlitSurface(p,NULL,screen,&posp);
	SDL_BlitSurface(q,NULL,screen,&posq);
	SDL_BlitSurface(s,NULL,screen,&poss);
	SDL_BlitSurface(d,NULL,screen,&posd);
	SDL_BlitSurface(f,NULL,screen,&posf);
	SDL_BlitSurface(g,NULL,screen,&posg);
	SDL_BlitSurface(h,NULL,screen,&posh);
	SDL_BlitSurface(j,NULL,screen,&posj);
	SDL_BlitSurface(k,NULL,screen,&posk);
	SDL_BlitSurface(l,NULL,screen,&posl);
	SDL_BlitSurface(m,NULL,screen,&posm);
	SDL_BlitSurface(w,NULL,screen,&posw);
	SDL_BlitSurface(x,NULL,screen,&posx);
	SDL_BlitSurface(c,NULL,screen,&posc);
	SDL_BlitSurface(v,NULL,screen,&posv);
	SDL_BlitSurface(b,NULL,screen,&posb);
	SDL_BlitSurface(n,NULL,screen,&posn);
	SDL_BlitSurface(ok,NULL,screen,&posok);
	SDL_BlitSurface(texte, NULL,screen,&position_text);
	SDL_BlitSurface(delete,NULL,screen,&posdelete);
        SDL_Flip(screen);

	
    }
    printf("%s",rep);

    return 0;
}
