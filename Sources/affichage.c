#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typestruct.h"
#include "initialisation.h"
#include "ajout_suppression.h"
#include "affichage.h"

void aff_juices (juice* Tab_Juices, int n){
    int i;
    for (i = 0; i<n; i++){
        printf (" %s |", Tab_Juices[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_Juices[i].stock);
    }
}

void aff_Squashes (squash* Tab_Squash, int n){
    int i;
    for (i = 0; i<n; i++){
        printf (" %s |", Tab_Squash[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_Squash[i].stock);
    }
}

void aff_Sodas (soda* Tab_Soda, int n){
    int i;
    for (i = 0; i<n; i++){
        printf (" %s |", Tab_Soda[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_Soda[i].stock);
    }
}

void aff_liquor (liqueur* Tab_liqueur, int n){
    int i;
    for (i = 0; i<n; i++){
        printf (" %s |", Tab_liqueur[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_liqueur[i].stock);
    }
}

void aff_no_alcohol_drink (no_alcohol_drink* Tab_no_alcohol_drink, int n){
    int i;
    for (i = 0; i<n; i++){
        printf (" %s |", Tab_no_alcohol_drink[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_no_alcohol_drink[i].stock);
    }
}

void aff_alcohol_drink (alcohol_drink* Tab_alcohol_drink, int n){
    int i;
    for (i = 0; i<n; i++){
        printf (" %s |", Tab_alcohol_drink[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_alcohol_drink[i].stock);
    }
}

void aff_alcohol_cocktail (alcohol_cocktail* Tab_alcohol_cocktail, int n){
    int i;
    for (i = 0; i<n; i++){
        printf (" %s |", Tab_alcohol_cocktail[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_alcohol_cocktail[i].degrees);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_alcohol_cocktail[i].price);
    }
}

void aff_no_alcohol_cocktail (noalcohol_cocktail* Tab_no_alcohol_cocktail, int n){
    int i;
    for (i = 0; i<n; i++){
        printf (" %s |", Tab_no_alcohol_cocktail[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_no_alcohol_cocktail[i].sugar_level);
    }
    puts ("\n");
    for (i = 0; i<n; i++){
        printf (" %f |", Tab_no_alcohol_cocktail[i].price);
    }
}


