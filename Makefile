prog:menu.o main.o
	gcc menu.o main.o -o prog -g  -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -g -lSDL -g -lSDL_image -lSDL_ttf -lSDL_mixer
menu.o:menu.c
	gcc -c menu.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer



