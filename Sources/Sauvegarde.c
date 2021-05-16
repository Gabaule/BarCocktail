#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <string.h>
#include "TypeStruct.h"
#include "Intitialisation.h"
#include "Ajout_Supression.h"
#include "Sauvegarde.h"

/* Variables globales de fichiers */

FILE* Jus;
FILE* Sirops;
FILE* Soda;
FILE* Liqueur;
FILE* Alcool;
FILE* Alcool_Cokctail;
FILE* Sans_Alcool_Cokctail;

/* Fonctions principales */

/* Fonctions de sauvegarde dans un fichier */

int Sauvegarde_Jus (int n, juice* Tab_Juice){
    int i;
    Jus = fopen ("Jus.txt", "w");
    if (Jus == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fprintf (Jus, "%s %f \n", Tab_Juice[i].name, Tab_Juice[i].stock);
    }
    fclose(Jus);
    return 0;
}

int Sauvegarde_Sirops (int n, squash* Tab_Squash){
    int i;
    Sirops = fopen ("Sirops.txt", "w");
    if (Sirops == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fprintf (Sirops, "%s %f \n", Tab_Squash[i].name, Tab_Squash[i].stock);
    }
    fclose(Sirops);
    return 0;
}

int Sauvegarde_Soda (int n, soda* Tab_Soda){
    int i;
    Soda = fopen ("Soda.txt", "w");
    if (Soda == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fprintf (Soda, "%s %f \n", Tab_Soda[i].name, Tab_Soda[i].stock);
    }
    fclose(Soda);
    return 0;
}

int Sauvegarde_liqueur (int n, liqueur* Tab_Liqueur){
    int i;
    Liqueur = fopen ("Liqueur.txt", "w");
    if (Liqueur == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fprintf (Liqueur, "%s %f \n", Tab_Liqueur[i].name, Tab_Liqueur[i].stock);
    }
    fclose(Liqueur);
    return 0;
}

int Sauvegarde_alcool (int n, alcohol_drink* Tab_alcohol_drink){
    int i;
    Alcool = fopen ("Alcool.txt", "w");
    if (Alcool == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fprintf (Alcool, "%s %f \n", Tab_alcohol_drink[i].name, Tab_alcohol_drink[i].stock);
    }
    fclose(Alcool);
    return 0;
}

int Sauvegarde_alcool_cocktail (int n, alcohol_cocktail* Tab_alcohol_cocktail){
    int i;
    Alcool_Cokctail = fopen ("Alcool_Cocktail.txt", "w");
    if (Alcool_Cokctail == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fprintf (Alcool_Cokctail, "%s %f %f \n", Tab_alcohol_cocktail[i].name, Tab_alcohol_cocktail[i].degrees, Tab_alcohol_cocktail[i].price);
    }
    fclose(Alcool_Cokctail);
    return 0;
}

int Sauvegarde_no_alcool_cocktail (int n, noalcohol_cocktail* Tab_no_alcohol_cocktail){
    int i;
    Sans_Alcool_Cokctail = fopen ("Sans_Alcool_Cocktail.txt", "w");
    if (Sans_Alcool_Cokctail == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fprintf (Sans_Alcool_Cokctail, "%s %f %f \n", Tab_no_alcohol_cocktail[i].name, Tab_no_alcohol_cocktail[i].sugar_level, Tab_no_alcohol_cocktail[i].price);
    }
    fclose(Sans_Alcool_Cokctail);
    return 0;
}

/* Fonction de récupération des éléments d'un tableau de matière première depuis un fichier */

juice* Recup_Jus (int n, juice* Tab_Juice){
    int i;
    Jus = fopen ("Jus.txt", "r");
    if (Jus == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fscanf (Jus, "%s %f", Tab_Juice[i].name, &Tab_Juice[i].stock);
    }
    fclose (Jus);
    return Tab_Juice;
}

squash* Recup_Sirops (int n, squash* Tab_Sirops){
    int i;
    Sirops = fopen ("Sirops.txt", "r");
    if (Sirops == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fscanf (Sirops, "%s %f", Tab_Sirops[i].name, &Tab_Sirops[i].stock);
    }
    fclose (Sirops);
    return Tab_Sirops;
}

soda* Recup_Soda (int n, soda* Tab_Soda){
    int i;
    Soda = fopen ("Soda.txt", "r");
    if (Soda == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fscanf (Soda, "%s %f \n", Tab_Soda[i].name, &Tab_Soda[i].stock);
    }
    fclose(Soda);
    return Tab_Soda;
}

alcohol_cocktail* Recup_alcool (int n, alcohol_drink* Tab_alcohol_drink){
    int i;
    Alcool = fopen ("Alcool.txt", "r");
    if (Alcool == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fscanf (Alcool, "%s %f \n", Tab_alcohol_drink[i].name, &Tab_alcohol_drink[i].stock);
    }
    fclose(Alcool);
    return Tab_alcohol_drink;
}

alcohol_cocktail* Recup_alcool_cocktail (int n, alcohol_cocktail* Tab_alcohol_cocktail){
    int i;
    Alcool_Cokctail = fopen ("Alcool_Cocktail.txt", "r");
    if (Alcool_Cokctail == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fprintf (Alcool_Cokctail, "%s %f %f \n", Tab_alcohol_cocktail[i].name, &Tab_alcohol_cocktail[i].degrees, &Tab_alcohol_cocktail[i].price);
    }
    fclose(Alcool_Cokctail);
    return Tab_alcohol_cocktail;
}

noalcohol_cocktail* Recup_no_alcool_cocktail (int n, noalcohol_cocktail* Tab_no_alcohol_cocktail){
    int i;
    Sans_Alcool_Cokctail = fopen ("Sans_Alcool_Cocktail.txt", "r");
    if (Sans_Alcool_Cokctail == NULL){
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){
        fscanf (Sans_Alcool_Cokctail, "%s %f %f \n", Tab_no_alcohol_cocktail[i].name, &Tab_no_alcohol_cocktail[i].sugar_level, &Tab_no_alcohol_cocktail[i].price);
    }
    fclose(Sans_Alcool_Cokctail);
    return 0;
}