prog:fonctions.o main.o 
	gcc fonctions.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c 
	gcc -c main.c 
fonctions.o:fonctions.c 
	gcc -c fonctions.c 
headers.o:headers.h
	gcc -c headers.h
