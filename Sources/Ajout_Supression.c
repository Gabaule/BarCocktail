#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TypeStruct.h"
#include "Intitialisation.h"
#include "Ajout_Supression.h"

juice* add_Juices (juice* Tab_Juice, int n, int n2){
    int i = 0;
    juice* Tab_Juice_add = malloc (n2*sizeof(juice));
    while (i<n){
        Tab_Juice_add[i] = Tab_Juice[i];
        i++;
    }
    while (i<n2){
        puts ("Entrer le nom et le stock des jus de fruits a ajouter");
        scanf ("%s %f", Tab_Juice_add[i].name, &Tab_Juice_add[i].stock);
        i++;
    }
    return Tab_Juice_add; 
    free (Tab_Juice_add);
}

squash* add_squashes (squash* Tab_squash, int n, int n2){
    int i = 0;
    squash* Tab_squash_add = malloc (n2*sizeof(squash));
    while (i<n){
        Tab_squash_add[i] = Tab_squash[i];
        i++;
    }
    while (i<n2){
        puts ("Entrer le nom et le stock des sirops a ajouter");
        scanf ("%s %f", Tab_squash_add[i].name, &Tab_squash_add[i].stock);
        i++;
    }
    return Tab_squash_add; 
    free (Tab_squash_add);
}

liqueur* add_liquors (liqueur* Tab_liquor, int n, int n2){
    int i = 0;
    liqueur* Tab_liquor_add = malloc (n2*sizeof(squash));
    while (i<n){
        Tab_liquor_add[i] = Tab_liquor[i];
        i++;
    }
    while (i<n2){
        puts ("Entrer le nom et le stock des liqueurs a ajouter");
        scanf ("%s %f", Tab_liquor_add[i].name, &Tab_liquor_add[i].stock);
        i++;
    }
    return Tab_liquor_add; 
    free (Tab_liquor_add);
}

soda* add_sodas (soda* Tab_soda, int n, int n2){
    int i = 0;
    soda* Tab_soda_add = malloc (n2*sizeof(soda));
    while (i<n){
        Tab_soda_add[i] = Tab_soda[i];
        i++;
    }
    while (i<n2){
        puts ("Entrer le nom et le stock des sodas a ajouter");
        scanf ("%s %f", Tab_soda_add[i].name, &Tab_soda_add[i].stock);
        i++;
    }
    return Tab_soda_add; 
    free (Tab_soda_add);
}

alcohol_drink* add_alcohol_drinks (alcohol_drink* Tab_alcohol_drink, int n, int n2){
    int i = 0;
    alcohol_drink* Tab_alcohol_drink_add = malloc (n2*sizeof(alcohol_drink));
    while (i<n){
        Tab_alcohol_drink_add[i] = Tab_alcohol_drink[i];
        i++;
    }
    while (i<n2){
        puts ("Entrer le nom et le stock des alcools a ajouter");
        scanf ("%s %f", Tab_alcohol_drink_add[i].name, &Tab_alcohol_drink_add[i].stock);
        i++;
    }  
    return Tab_alcohol_drink_add; 
    free (Tab_alcohol_drink_add);
}

no_alcohol_drink* add_no_alcohol_drinks (no_alcohol_drink* Tab_no_alcohol_drink, int n, int n2){
    int i = 0;
    no_alcohol_drink* Tab_no_alcohol_drink_add = malloc (n2*sizeof(no_alcohol_drink));
    while (i<n){
        Tab_no_alcohol_drink_add[i] = Tab_no_alcohol_drink[i];
        i++;
    }
    while (i<n2){
        puts ("Entrer le nom et le stock des alcools a ajouter");
        scanf ("%s %f", Tab_no_alcohol_drink_add[i].name, &Tab_no_alcohol_drink_add[i].stock);
        i++;
    } 
    return Tab_no_alcohol_drink_add;
    free (Tab_no_alcohol_drink_add);
}

alcohol_cocktail* add_alcohol_cocktails (alcohol_cocktail* Tab_alcohol_cocktail, int n , int n2){
    int i = 0;
    alcohol_cocktail* Tab_alcohol_cocktail_add = malloc (n2*sizeof(alcohol_cocktail));
    while (i<n){
        Tab_alcohol_cocktail_add[i] = Tab_alcohol_cocktail[i];
        i++;
    }
    while (i<n2){
        puts ("Entrer le nom et le stock des alcools a ajouter");
        scanf ("%s %f %f", Tab_alcohol_cocktail_add[i].name, &Tab_alcohol_cocktail_add[i].degrees, &Tab_alcohol_cocktail_add[i].price);
        i++;
    } 
    return Tab_alcohol_cocktail_add;
    free (Tab_alcohol_cocktail_add);
}

noalcohol_cocktail* add_no_alcohol_cocktails (noalcohol_cocktail* Tab_no_alcohol_cocktail, int n , int n2){
    int i = 0;
    noalcohol_cocktail* Tab_no_alcohol_cocktail_add = malloc (n2*sizeof(noalcohol_cocktail));
    while (i<n){
        Tab_no_alcohol_cocktail_add[i] = Tab_no_alcohol_cocktail[i];
        i++;
    }
    while (i<n2){
        puts ("Entrer le nom et le stock des alcools a ajouter");
        scanf ("%s %f %f", Tab_no_alcohol_cocktail_add[i].name, &Tab_no_alcohol_cocktail_add[i].sugar_level, &Tab_no_alcohol_cocktail_add[i].price);
        i++;
    }
    return Tab_no_alcohol_cocktail_add;
    free (Tab_no_alcohol_cocktail_add);   
}

juice* remove_juices (juice* Tab_Juices,int n2, int n, juice x){
    int i;
    int j;
    juice* Tab_Juices_rem = malloc (n2*sizeof(juice));
    for(i = 0; i < n; i++ ){
         if(strcmp(Tab_Juices[i].name, x.name) == 0){
            printf ("%s \n", Tab_Juices[i].name);
            for(j=i; j < n; j++){
                Tab_Juices_rem[j] = Tab_Juices[j+1];
            }
         }
    }
    return Tab_Juices_rem;
    free(Tab_Juices_rem);
}

squash* remove_squash (squash* Tab_squash,int n2, int n, squash x){
    int i;
    int j;
    squash* Tab_Squash_rem = malloc (n2*sizeof(squash));
    for(i = 0; i < n; i++ ){
         if(strcmp(Tab_squash[i].name, x.name) == 0){
            for(j=i; j < n; j++){
                Tab_Squash_rem[j] = Tab_squash[j+1];
            }
         }
    }
    return Tab_Squash_rem;
    free(Tab_Squash_rem);
}

soda* remove_soda (soda* Tab_soda,int n2, int n, soda x){
    int i;
    int j;
    soda* Tab_Soda_rem = malloc (n2*sizeof(soda));
    for(i = 0; i < n; i++ ){
         if(strcmp(Tab_soda[i].name, x.name) == 0){
            for(j=i; j < n; j++){
                Tab_Soda_rem[j] = Tab_soda[j+1];
            }
         }
    }
    return Tab_Soda_rem;
    free(Tab_Soda_rem);
}

liqueur* remove_liquors (liqueur* Tab_liquor, int n2, int n, liqueur x){
    int i;
    int j;
    liqueur* Tab_liquor_rem = malloc (n2*sizeof(liqueur));
    for(i = 0; i < n; i++ ){
         if(strcmp(Tab_liquor[i].name, x.name) == 0){
            for(j=i; j < n; j++){
                Tab_liquor_rem[j] = Tab_liquor[j+1];
            }
         }
    }
    return Tab_liquor_rem;
    free(Tab_liquor_rem);
}

no_alcohol_drink* remove_no_acohol_drinks (no_alcohol_drink* Tab_no_alcohol_drink, int n2, int n, no_alcohol_drink x){
    int i;
    int j;
    no_alcohol_drink* Tab_no_alcohol_drink_rem = malloc (n2*sizeof(no_alcohol_drink));
    for(i = 0; i < n; i++ ){
         if(strcmp(Tab_no_alcohol_drink[i].name, x.name) == 0){
            for(j=i; j < n; j++){
                Tab_no_alcohol_drink_rem[j] = Tab_no_alcohol_drink[j+1];
            }
         }
    }
    return Tab_no_alcohol_drink_rem;
    free(Tab_no_alcohol_drink_rem);
}

alcohol_drink* remove_acohol_drinks (alcohol_drink* Tab_alcohol_drink, int n2, int n, alcohol_drink x){
    int i;
    int j;
    alcohol_drink* Tab_alcohol_drink_rem = malloc (n2*sizeof(alcohol_drink));
    for(i = 0; i < n; i++ ){
         if(strcmp(Tab_alcohol_drink[i].name, x.name) == 0){
            for(j=i; j < n; j++){
                Tab_alcohol_drink_rem[j] = Tab_alcohol_drink[j+1];
            }
         }
    }
    return Tab_alcohol_drink_rem;
    free(Tab_alcohol_drink_rem);
}

alcohol_cocktail* remove_acohol_cocktail (alcohol_cocktail* Tab_alcohol_cocktail, int n2, int n, alcohol_cocktail x){
    int i;
    int j;
    alcohol_cocktail* Tab_alcohol_cocktail_rem = malloc (n2*sizeof(alcohol_cocktail));
    for(i = 0; i < n; i++ ){
         if(strcmp(Tab_alcohol_cocktail[i].name, x.name) == 0){
            for(j=i; j < n; j++){
                Tab_alcohol_cocktail_rem[j] = Tab_alcohol_cocktail[j+1];
            }
         }
    }
    return Tab_alcohol_cocktail_rem;
    free(Tab_alcohol_cocktail_rem);
}


noalcohol_cocktail* remove_no_acohol_cocktail (noalcohol_cocktail* Tab_no_alcohol_cocktail, int n2, int n, noalcohol_cocktail x){
    int i;
    int j;
    noalcohol_cocktail* Tab_no_alcohol_cocktail_rem = malloc (n2*sizeof(noalcohol_cocktail));
    for(i = 0; i < n; i++ ){
         if(strcmp(Tab_no_alcohol_cocktail[i].name, x.name) == 0){
            for(j=i; j < n; j++){
                Tab_no_alcohol_cocktail_rem[j] = Tab_no_alcohol_cocktail[j+1];
            }
         }
    }
    return Tab_no_alcohol_cocktail_rem;
    free(Tab_no_alcohol_cocktail_rem);
}