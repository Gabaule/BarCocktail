#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TypeStruct.h"
#include "Allocation.h"


juice* Realloc_Juices_add (juice* Tabjuice, int n2, int n){
    juice* Tabjuice_Copie = malloc (n2*sizeof(juice));
    int i;
    for (i = 0; i<n; i++){
        Tabjuice_Copie[i] = Tabjuice[i];
    }
    return Tabjuice_Copie;
    free (Tabjuice);
    free(Tabjuice_Copie);
}

soda* Realloc_Soda_add (soda* Tabsoda, int n2, int n){
    soda* Tabsoda_Copie = malloc (n2*sizeof(soda));
    int i;
    for (i = 0; i<n; i++){
        Tabsoda_Copie[i] = Tabsoda[i];
    }
    return Tabsoda_Copie;
    free (Tabsoda);
    free(Tabsoda_Copie);
}

squash* Realloc_squash_add (squash* Tabsquash, int n2, int n){
    squash* Tabsquash_Copie = malloc (n2*sizeof(squash));
    int i;
    for (i = 0; i<n; i++){
        Tabsquash_Copie[i] = Tabsquash[i];
    }
    return Tabsquash_Copie;
    free (Tabsquash);
    free(Tabsquash_Copie);
}

liqueur* Realloc_liquor_add (liqueur* Tabliqueur, int n2, int n){
    liqueur* Tabliqueur_Copie = malloc (n2*sizeof(liqueur));
    int i;
    for (i = 0; i<n; i++){
        Tabliqueur_Copie[i] = Tabliqueur[i];
    }
    return Tabliqueur_Copie;
    free (Tabliqueur);
    free(Tabliqueur_Copie);
}

no_alcohol_drink* Realloc_no_alcohol_drink_add (no_alcohol_drink* Tab_no_alochol_drink, int n2, int n){
    no_alcohol_drink* Tab_no_alochol_drink_Copie = malloc (n2*sizeof(no_alcohol_drink));
    int i;
    for (i = 0; i<n; i++){
        Tab_no_alochol_drink_Copie[i] = Tab_no_alochol_drink[i];
    }
    return Tab_no_alochol_drink_Copie;
    free (Tab_no_alochol_drink);
    free(Tab_no_alochol_drink_Copie);
}

alcohol_drink* Realloc_alcohol_drink_add (alcohol_drink* Tab_alochol_drink, int n2, int n){
    alcohol_drink* Tab_alochol_drink_Copie = malloc (n2*sizeof(alcohol_drink));
    int i;
    for (i = 0; i<n; i++){
        Tab_alochol_drink_Copie[i] = Tab_alochol_drink[i];
    }
    return Tab_alochol_drink_Copie;
    free (Tab_alochol_drink);
    free(Tab_alochol_drink_Copie);
}

alcohol_cocktail* Realloc_alcohol_cocktail_add (alcohol_cocktail* Tab_alochol_cocktail, int n2, int n){
    alcohol_cocktail* Tab_alochol_cocktail_Copie = malloc (n2*sizeof(alcohol_cocktail));
    int i;
    for (i = 0; i<n; i++){
        Tab_alochol_cocktail_Copie[i] = Tab_alochol_cocktail[i];
    }
    return Tab_alochol_cocktail_Copie;
    free (Tab_alochol_cocktail);
    free(Tab_alochol_cocktail_Copie);
}

noalcohol_cocktail* Realloc_no_alcohol_cocktail_add (noalcohol_cocktail* Tab_no_alochol_cocktail, int n2, int n){
    noalcohol_cocktail* Tab_no_alochol_cocktail_Copie = malloc (n2*sizeof(noalcohol_cocktail));
    int i;
    for (i = 0; i<n; i++){
        Tab_no_alochol_cocktail_Copie[i] = Tab_no_alochol_cocktail[i];
    }
    return Tab_no_alochol_cocktail_Copie;
    free (Tab_no_alochol_cocktail);
    free(Tab_no_alochol_cocktail_Copie);
}
