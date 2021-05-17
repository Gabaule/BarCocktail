#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TypeStruct.h"

#include "Initialisation.h"

int TailleTab (){
    int n;
    puts ("\n Entrer la taille du tableau");
    scanf ("%d", &n);
    return n;
}

juice* defineTab_Juices (int n){
    juice* TabJuice = malloc (n*sizeof(juice));
    int i;
        puts ("Entrer nom et le stock de chaque jus :");
    for (i = 0; i<n; i++){
        scanf ("%s %f", TabJuice[i].name, &TabJuice[i].stock);
    }
    return TabJuice;
    free (TabJuice);
}

squash* defineTab_Squashes (int n){
    squash* Tabsquash = malloc (n*sizeof(squash));
    int i;
    puts ("Entrer nom et le stock de chaque sirops :");
    for (i = 0; i<n; i++){
        scanf ("%s %f", Tabsquash[i].name, Tabsquash[i].stock);
    }
    return Tabsquash;
    free (Tabsquash);
}

soda* defineTab_Sodas (int n){
    soda* TabSoda = malloc (n*sizeof(soda));
    int i;
        puts ("Entrer nom et le stock de chaque sodas :");
    for (i = 0; i<n; i++){
        scanf ("%s %f", TabSoda[i].name, TabSoda[i].stock);
    }
    return TabSoda;
    free (TabSoda);
}

liqueur* defineTab_Liquor(int n){
    liqueur* TabLiquor = malloc (n*sizeof(liqueur));
    int i;
    puts ("Entrer nom et stock de chaque liqueurs :");
    for (i = 0; i<n; i++){
        scanf ("%s", TabLiquor[i].name, TabLiquor[i].stock);
    }
    return TabLiquor;
    free (TabLiquor);
}

alcohol_drink* defineTab_alcohol_drink (int n){
    alcohol_drink* Tab_alcohol_drink = malloc (n*sizeof(alcohol_drink));
    liqueur* TabLiquor = malloc (n*sizeof(liqueur));
    int i;
    TabLiquor = defineTab_Liquor(n);
    for (i = 0; i<n; i++){
        puts ("Enter le nom, le stock :\n");
        scanf ("%s %f", Tab_alcohol_drink[i].name, &Tab_alcohol_drink[i].stock);
        Tab_alcohol_drink[i].liquor = TabLiquor[i];
    }
    return Tab_alcohol_drink;
    free (Tab_alcohol_drink);
    free (TabLiquor);
}

no_alcohol_drink* defineTab_no_alcohol_drink (int n){
    no_alcohol_drink* Tab_no_alcohol_drink = malloc (n*sizeof(alcohol_drink));
    juice* TabJuices = malloc (n*sizeof(juice));
    soda* TabSoda = malloc (n*sizeof(soda));
    squash* Tabsquash = malloc (n*sizeof(squash));
    int i;
    TabJuices = defineTab_Juices(n);
    TabSoda = defineTab_Sodas(n);
    Tabsquash = defineTab_Squashes(n);
    for (i = 0; i<n; i++){
        puts ("Enter le nom, le stock\n");
        scanf ("%s %f", Tab_no_alcohol_drink[i].name, &Tab_no_alcohol_drink[i].stock);
        Tab_no_alcohol_drink[i].juices = TabJuices[i];
        Tab_no_alcohol_drink[i].sodas = TabSoda[i];
        Tab_no_alcohol_drink[i].squashes = Tabsquash[i];
    }
    return Tab_no_alcohol_drink;
    free (Tab_no_alcohol_drink);
    free (TabJuices);
    free (TabSoda);
    free (Tabsquash);
}

alcohol_cocktail* defineTab_alcohol_cokctail (int n){
    alcohol_cocktail* Tab_Alcohol_cocktail = malloc (n*sizeof (alcohol_cocktail));
    int i;
    for (i = 0; i<n; i++){
        puts ("Entrer le nom et le degrés du cocktail");
        scanf ("%s %f %f", Tab_Alcohol_cocktail[i].name, &Tab_Alcohol_cocktail[i].degrees, &Tab_Alcohol_cocktail[i].price);
    }
    return Tab_Alcohol_cocktail;
    free (Tab_Alcohol_cocktail);
}

noalcohol_cocktail* defineTab_no_alcohol_cokctail (int n){
    noalcohol_cocktail* Tab_no_alcohol_cocktail = malloc (n*sizeof (noalcohol_cocktail));
    int i;
    for (i = 0; i<n; i++){
        puts ("Entrer le nom et le degrés du cocktail");
        scanf ("%s %f %f", Tab_no_alcohol_cocktail[i].name, &Tab_no_alcohol_cocktail[i].sugar_level, &Tab_no_alcohol_cocktail[i].price);
    }
    return Tab_no_alcohol_cocktail;
    free (Tab_no_alcohol_cocktail);
}