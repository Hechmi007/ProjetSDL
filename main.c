#include"menu.h"

int main()
{
SDL_Init(SDL_INIT_AUDIO);
int continuer=1;
int playM=0;
int x,y;
menu m;
m.interface=1;
m.selected=1;
SDL_Event event;

Mix_Chunk *effect;
Mix_Music *music;
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,4096);
music=Mix_LoadMUS("bkgMusic.mp3");
effect=Mix_LoadWAV("button-23.wav");

Mix_PlayMusic(music,-1);
int input;
InitMenu(&m);
SDL_Init(SDL_INIT_VIDEO);
m.screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

//m.background->w=1920;
//m.background->h=1080;
SDL_BlitSurface(m.background,NULL,m.screen,&m.posBack);
while(continuer)
{	

	if(m.interface==1)
	{
		aff_menu(&m);
	}
	else if(m.interface==2)
	{
		//affOption();
	}

	SDL_Flip(m.screen);
	SDL_WaitEvent(&event);
	switch(event.type)
	{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					continuer=0;
					break;
					
				case SDLK_DOWN: 
					Mix_PlayChannel(-1,effect,0);					
					input=1;
					break;
				case SDLK_UP:
					Mix_PlayChannel(-1,effect,0);					
					input=2;
					break;
				case SDLK_RETURN:
					printf("enter");
					input=3;
							
					if(input==3 && m.interface==1);//Enter
					{
						if(m.selected==1)
							printf("jouer");
							//PlayGame();
						else if(m.selected==2)
	
							printf("options");
							//ShowOptions();
		
						else if(m.selected==3)
		
							continuer=0;
		
					}
				

			}
		case SDL_MOUSEMOTION:
			x=event.motion.x;
			y=event.motion.y;
			break;
		case SDL_MOUSEBUTTONUP:
			input=4;
           		break;


	}
	if(input==1 && m.interface==1)//DOWN ARROW
	{
		if(m.selected==3)
			m.selected=1;	
		else 
			m.selected++;
	
	}
	 if(input==2 && m.interface==1)//UP ARROW
	{
		if(m.selected==1)
			m.selected=3;
		else
			m.selected--;
	}

	 /*if(input==3 && m.interface==1);//Enter
	{
		if(m.selected==1)
			printf("jouer");
			//PlayGame();
		else if(m.selected==2)
	
			printf("options");
			//ShowOptions();
		
		else if(m.selected==3)
		
			continuer=0;
		
	}*/
	if(x>m.posB1.x && x<m.posB1.x+m.button1->w   && y>m.posB1.y && y<m.posB1.y+m.button1->h)//curseur sur Button1
	{
		if(playM==0)
			Mix_PlayChannel(-1,effect,0);					
		if(m.interface==1)
		{
			m.selected=1;
			if(input==4)
				printf("jouer");
				//play()
		}
		playM=1;

	}
	
        else if(x>m.posB2.x && x<m.posB2.x+m.button2->w   && y>m.posB2.y && y<m.posB2.y+m.button2->h)//curseur sur Button1
	{
		if(playM==0)
			Mix_PlayChannel(-1,effect,0);					
		if(m.interface==1)
		{
			m.selected=2;
			if(input==4)
				m.interface=2;
		}
		playM=1;

	}

	else if(x>m.posB3.x && x<m.posB3.x+m.button3->w   && y>m.posB3.y && y<m.posB3.y+m.button3->h)//curseur sur Button1
	{
		if(playM==0)
			Mix_PlayChannel(-1,effect,0);					
		if(m.interface==1)
			{
			m.selected=3;
			if(input==4)
				continuer=0;
			}
		playM=1;
	}
	else
		playM=0;


input=0;
}
SDL_Quit;




}
