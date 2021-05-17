CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=Projet

all : $(EXEC)

Projet : main.o menu.o initialisation.o ajout_suppression.o sauvegarde.o Menu.h TypeStruct.h Sauvegarde.h Affichage.h Ajout_Supression.h Initialisation.h
		$(CC) -o main.o menu.o initialisation.o ajout_suppression.o sauvegarde.o Menu.h TypeStruct.h Sauvegarde.h Affichage.h Ajout_Supression.h Initialisation.h $(LDFLAGS)

menu.o : Menu.c
	$(CC) -c Menu.c $(CFLAGS)

affichage.o : Affichage.c
	$(CC) -c affichage.c $(CFLAGS)

ajout_suppression.o : Ajout_Supression.c
	$(CC) -c Ajout_Supression.c $(CFLAGS)

initialisation.o : Initialisation.c
	$(CC) -c Initialisation.c $(CFLAGS)

sauvegarde.o : Sauvegarde.c
	$(CC) -c Sauvegarde.c $(CFLAGS)

main.o : Main.c
	$(CC) -c Main.c $(CFLAGS)
