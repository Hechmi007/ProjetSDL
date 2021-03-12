#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include"menu.h"


void InitMenu(menu *m){
SDL_Color CNoir={255,255,255};
m->police = TTF_OpenFont("VT323-Regular.ttf", 80);
m->couleur = CNoir;
m->texte = TTF_RenderText_Blended(m->police, "MENU", m->couleur);
m->postxt.x=500;
m->postxt.y=200;

m->background=IMG_Load("Background.png");
m->posBack.x=0;
m->posBack.y=0;
//m->background->w=1920;
//m->background->h=1080;

m->backgroundM=IMG_Load("menubkg.png");
//m->backgroundM->h=1000;

m->posBackM.x=(m->background->w-m->backgroundM->w)/2;
m->posBackM.y=(m->background->h-m->backgroundM->h)/2;

m->button1=IMG_Load("PlayB1.png");
m->button1S=IMG_Load("PlayB2.png");
m->posB1.x=(m->background->w-m->button1->w)/2;
m->posB1.y=250;

m->button2=IMG_Load("OptionsB1.png");
m->button2S=IMG_Load("OptionsB2.png");
m->posB2.x=(m->background->w-m->button1->w)/2;
m->posB2.y=370;

m->button3=IMG_Load("QuitB1.png");
m->button3S=IMG_Load("QuitB2.png");
m->posB3.x=(m->background->w-m->button1->w)/2;
m->posB3.y=490;
}

void aff_menu(menu*m){


SDL_BlitSurface(m->backgroundM,NULL,m->screen,&m->posBackM);
SDL_BlitSurface(m->texte,NULL,m->screen,&m->postxt);

if(m->selected==1)

	SDL_BlitSurface(m->button1S,NULL,m->screen,&m->posB1);

else 

	SDL_BlitSurface(m->button1,NULL,m->screen,&m->posB1);

if(m->selected==2)
	SDL_BlitSurface(m->button2S,NULL,m->screen,&m->posB2);
else
	SDL_BlitSurface(m->button2,NULL,m->screen,&m->posB2);


if(m->selected==3)
	SDL_BlitSurface(m->button3S,NULL,m->screen,&m->posB3);

else
	SDL_BlitSurface(m->button3,NULL,m->screen,&m->posB3);

}


hama yarhim weldik




