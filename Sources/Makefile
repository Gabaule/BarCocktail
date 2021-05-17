CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=Projet

all : $(EXEC)

Projet : main.o menu.o initialisation.o ajout_suppression.o sauvegarde.o affichage.o typestruct.h menu.h sauvegarde.h affichage.h ajout_suppression.h initialisation.h affichage.h
		$(CC) -o main.o menu.o initialisation.o ajout_suppression.o sauvegarde.o affichage.o typestruct.h menu.h sauvegarde.h affichage.h ajout_suppression.h initialisation.h affichage.h $(LDFLAGS)

menu.o : menu.c
	$(CC) -c menu.c $(CFLAGS)

affichage.o : affichage.c
	$(CC) -c affichage.c $(CFLAGS)

ajout_suppression.o : ajout_suppression.c
	$(CC) -c ajout_suppression.c $(CFLAGS)

initialisation.o : initialisation.c
	$(CC) -c initialisation.c $(CFLAGS)

sauvegarde.o : sauvegarde.c
	$(CC) -c sauvegarde.c $(CFLAGS)

main.o : main.c
	$(CC) -c main.c $(CFLAGS)
