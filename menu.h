#ifndef HEADER_FILE
#define HEADER_FILE
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

typedef struct{
int selected;
int interface;
SDL_Surface *screen;

SDL_Surface *background;
SDL_Rect posBack;

SDL_Surface *backgroundM;
SDL_Rect posBackM;

SDL_Surface *button1;
SDL_Surface *button1S;
SDL_Rect posB1;

SDL_Surface *button2;
SDL_Surface *button2S;
SDL_Rect posB2;

SDL_Surface *button3;
SDL_Surface *button3S;
SDL_Rect posB3;


SDL_Surface *texte;
SDL_Rect postxt;
TTF_Font *police ;
SDL_Color couleur ;
}menu;


void InitMenu(menu *m);
void aff_menu(menu*m);










#endif

