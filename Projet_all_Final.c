#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <string.h>

/* Structures de boissons */

typedef struct tjuice{  // Structure définissant les jus de fruit
    char name[100]; //Nom du jus de fruit
    float stock; // Stock du jus
} juice;

typedef struct tliqueur{  // Structure définissant les liqueurs
    char name[100]; // nom de la liqueur
    float stock; //Stock des liqueurs
} liqueur;

typedef struct tsquash{  // Structure définissant les sirops
    char name[100]; //nom du sirop
    float stock; // Stock des sirops
} squash;

typedef struct tsoda { // Structure définissant les sodas
    char name[100]; //nom du soda
    float stock; // Stock des sodas
} soda;

typedef struct talcohol_drink{  // Structure définissant les boissons alcoolisées 
    char name[100]; // nom de l'alcool
    float stock; //stock d'alcool
} alcohol_drink;

typedef struct talcohol_cocktail{ //Type cocktail avec alcool
    int capacity; //la capacité du contenant
    char name[100]; //le nom du cocktail
    float price; // le prix du cocktail
    float degrees; // le degrés d'alcool contenu dans le cocktail
} alcohol_cocktail;

typedef struct tno_alcohol_cocktail { //Type cocktail sans alcool
    int capacity; //la capacité du contenant
    char name[100]; // le nom du cocktail
    float price; //le prix du cocktail
    float sugar_level; //La teneur en sucre du cocktail
} noalcohol_cocktail;

/* Variables globales fichiers*/

FILE* Jus; // Fichier de jus
FILE* Sirops; // Fichier de sirops
FILE* Soda; // Fichier de sodas
FILE* Liqueur; // Fichier de liqueur
FILE* Alcool; // Fichier d'alcool
FILE* Alcool_Cokctail; // Fichier de cocktail avec alcool
FILE* Sans_Alcool_Cokctail; // Fichier de cocktail sans alcool

/* Variables globales de Taille */

int Taille_Tab_Juices = 0; // Taille du tableaux de jus
int Taille_Tab_Squashes = 0; // Taille du tableaux de sirops
int Taille_Tab_Soda = 0; // Taille du tableaux de sodas
int Taille_Tab_Liquors = 0; // Taille du tableaux de liqueurs
int Taille_Tab_alcohol_drinks = 0; // Taille du tableaux d'alcool
int Taille_Tab_no_alcohol_cocktails = 0; // Taille du tableaux de cocktails sans alcool
int Taille_Tab_alcohol_cocktails = 0; // Taille du tableaux de cocktails avec alcool

/* Variables globales de Tableau*/

juice* TabJuice; // Tabelaux de jus
squash* TabSquash; // Tabelaux de sirops
soda* TabSoda; // Tabelaux de sodas
liqueur* TabLiquor; // Tabelaux de liqueurs
alcohol_drink* Tab_alcohol_drink; // Tabelaux d'alcool
alcohol_cocktail* Tab_alcohol_cocktail; // Tabelaux de cocktail avec alcool
noalcohol_cocktail* Tab_no_alcohol_cocktail; // Tabelaux de cocktail sans alcool

/*   Fonctions Principales   */

/* Fonctions d'initialisations */

int TailleTab (){ // Fonction pour la taille des tableaux
    int n;
    puts ("\n Entrer la taille du tableau");
    scanf ("%d", &n);
    return n;
}

/* Fonction d'initialisation des jus de fruits (qui prend en paramètre la taille du tableau) */

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

/* Fonction d'initialisation des sirops (qui prend en paramètre la taille du tableau) */

squash* defineTab_Squashes (int n){
    squash* Tabsquash = malloc (n*sizeof(squash));
    int i;
    puts ("Entrer nom et le stock de chaque sirops :");
    for (i = 0; i<n; i++){
        scanf ("%s %f", Tabsquash[i].name, &Tabsquash[i].stock);
    }
    return Tabsquash;
    free (Tabsquash);
}

/* Fonction d'initialisation des sodas (qui prend en paramètre la taille du tableau) */

soda* defineTab_Sodas (int n){
    soda* TabSoda = malloc (n*sizeof(soda));
    int i;
        puts ("Entrer nom et le stock de chaque sodas :");
    for (i = 0; i<n; i++){
        scanf ("%s %f", TabSoda[i].name, &TabSoda[i].stock);
    }
    return TabSoda;
    free (TabSoda);
}

/* Fonction d'initialisation des liqueurs (qui prend en paramètre la taille du tableau) */

liqueur* defineTab_Liquor(int n){
    liqueur* TabLiquor = malloc (n*sizeof(liqueur));
    int i;
    puts ("Entrer nom et stock de chaque liqueurs :");
    for (i = 0; i<n; i++){
        scanf ("%s %f", TabLiquor[i].name, &TabLiquor[i].stock);
    }
    return TabLiquor;
    free (TabLiquor);
}

/* Fonction d'initialisation des alcools (qui prend en paramètre la taille du tableau) */

alcohol_drink* defineTab_alcohol_drink (int n){
    alcohol_drink* Tab_alcohol_drink = malloc (n*sizeof(alcohol_drink));
    int i;
    for (i = 0; i<n; i++){
        puts ("Enter le nom, le stock :\n");
        scanf ("%s %f", Tab_alcohol_drink[i].name, &Tab_alcohol_drink[i].stock);
    }
    return Tab_alcohol_drink;
    free (Tab_alcohol_drink);
}

/* Fonction d'initialisation des cocktails avec alcool (qui prend en paramètre la taille du tableau) */

alcohol_cocktail* defineTab_alcohol_cokctail (int n){
    alcohol_cocktail* Tab_Alcohol_cocktail = malloc (n*sizeof (alcohol_cocktail));
    int i;
    for (i = 0; i<n; i++){
        puts ("Entrer le nom, le degres d'alcool et le prix du cocktail");
        scanf ("%s %f %f", Tab_Alcohol_cocktail[i].name, &Tab_Alcohol_cocktail[i].degrees, &Tab_Alcohol_cocktail[i].price);
    }
    return Tab_Alcohol_cocktail;
    free (Tab_Alcohol_cocktail);
}

/* Fonction d'initialisation des cocktails sans alcool (qui prend en paramètre la taille du tableau) */

noalcohol_cocktail* defineTab_no_alcohol_cokctail (int n){
    noalcohol_cocktail* Tab_no_alcohol_cocktail = malloc (n*sizeof (noalcohol_cocktail));
    int i;
    for (i = 0; i<n; i++){
        puts ("Entrer le nom, la teneur en sucre et le prix du cocktail");
        scanf ("%s %f %f", Tab_no_alcohol_cocktail[i].name, &Tab_no_alcohol_cocktail[i].sugar_level, &Tab_no_alcohol_cocktail[i].price);
    }
    return Tab_no_alcohol_cocktail;
    free (Tab_no_alcohol_cocktail);
}

/* Fonctions d'ajout */

/* Fonction d'ajout des jus de fruits (qui prend en paramètre l'ancien tableau, la taille de l'ancien tableau et la taille du nouveau tableau) */

juice* add_Juices (juice* Tab_Juice, int n, int n2){
    int i = 0;
    juice* Tab_Juice_add = malloc (n2*sizeof(juice)); // réallocation mémoire pour un tableaux plus grand
    while (i<n){ //ajout des éléments déjà existant dans le nouveau tableau
        Tab_Juice_add[i] = Tab_Juice[i]; 
        i++;
    }
    while (i<n2){ //ajout des éléments entré par l'utilisateur dans le nouveau tableau
        puts ("Entrer le nom et le stock des jus de fruits a ajouter");
        scanf ("%s %f", Tab_Juice_add[i].name, &Tab_Juice_add[i].stock); 
        i++;
    }
    return Tab_Juice_add; 
    free (Tab_Juice_add);
}

/* Fonction d'ajout des sirops (qui prend en paramètre l'ancien tableau, la taille de l'ancien tableau et la taille du nouveau tableau) */

squash* add_squashes (squash* Tab_squash, int n, int n2){
    int i = 0;
    squash* Tab_squash_add = malloc (n2*sizeof(squash)); // réallocation mémoire pour un tableaux plus grand
    while (i<n){ //ajout des éléments déjà existant dans le nouveau tableau
        Tab_squash_add[i] = Tab_squash[i];
        i++;
    }
    while (i<n2){ //ajout des éléments entré par l'utilisateur dans le nouveau tableau
        puts ("Entrer le nom et le stock des sirops a ajouter");
        scanf ("%s %f", Tab_squash_add[i].name, &Tab_squash_add[i].stock);
        i++;
    }
    return Tab_squash_add; 
    free (Tab_squash_add);
}

/* Fonction d'ajout des liqueurs (qui prend en paramètre l'ancien tableau, la taille de l'ancien tableau et la taille du nouveau tableau) */

liqueur* add_liquors (liqueur* Tab_liquor, int n, int n2){
    int i = 0;
    liqueur* Tab_liquor_add = malloc (n2*sizeof(squash)); // réallocation mémoire pour un tableaux plus grand
    while (i<n){ //ajout des éléments déjà existant dans le nouveau tableau
        Tab_liquor_add[i] = Tab_liquor[i];
        i++;
    }
    while (i<n2){ //ajout des éléments entré par l'utilisateur dans le nouveau tableau
        puts ("Entrer le nom et le stock des liqueurs a ajouter");
        scanf ("%s %f", Tab_liquor_add[i].name, &Tab_liquor_add[i].stock);
        i++;
    }
    return Tab_liquor_add; 
    free (Tab_liquor_add);
}

/* Fonction d'ajout des sodas (qui prend en paramètre l'ancien tableau, la taille de l'ancien tableau et la taille du nouveau tableau) */

soda* add_sodas (soda* Tab_soda, int n, int n2){
    int i = 0;
    soda* Tab_soda_add = malloc (n2*sizeof(soda)); // réallocation mémoire pour un tableaux plus grand
    while (i<n){ //ajout des éléments déjà existant dans le nouveau tableau
        Tab_soda_add[i] = Tab_soda[i];
        i++;
    }
    while (i<n2){ //ajout des éléments entré par l'utilisateur dans le nouveau tableau
        puts ("Entrer le nom et le stock des sodas a ajouter");
        scanf ("%s %f", Tab_soda_add[i].name, &Tab_soda_add[i].stock);
        i++;
    }
    return Tab_soda_add; 
    free (Tab_soda_add);
}

/* Fonction d'ajout des alcools (qui prend en paramètre l'ancien tableau, la taille de l'ancien tableau et la taille du nouveau tableau) */

alcohol_drink* add_alcohol_drinks (alcohol_drink* Tab_alcohol_drink, int n, int n2){
    int i = 0;
    alcohol_drink* Tab_alcohol_drink_add = malloc (n2*sizeof(alcohol_drink)); // réallocation mémoire pour un tableaux plus grand
    while (i<n){ //ajout des éléments déjà existant dans le nouveau tableau
        Tab_alcohol_drink_add[i] = Tab_alcohol_drink[i];
        i++;
    }
    while (i<n2){ //ajout des éléments entré par l'utilisateur dans le nouveau tableau
        puts ("Entrer le nom et le stock des alcools a ajouter");
        scanf ("%s %f", Tab_alcohol_drink_add[i].name, &Tab_alcohol_drink_add[i].stock);
        i++;
    }  
    return Tab_alcohol_drink_add; 
    free (Tab_alcohol_drink_add);
}

/* Fonction d'ajout des cocktails avec alcool (qui prend en paramètre l'ancien tableau, la taille de l'ancien tableau et la taille du nouveau tableau) */

alcohol_cocktail* add_alcohol_cocktails (alcohol_cocktail* Tab_alcohol_cocktail, int n , int n2){
    int i = 0;
    alcohol_cocktail* Tab_alcohol_cocktail_add = malloc (n2*sizeof(alcohol_cocktail)); // réallocation mémoire pour un tableaux plus grand
    while (i<n){ //ajout des éléments déjà existant dans le nouveau tableau
        Tab_alcohol_cocktail_add[i] = Tab_alcohol_cocktail[i];
        i++;
    }
    while (i<n2){ //ajout des éléments entré par l'utilisateur dans le nouveau tableau
        puts ("Entrer le nom et le stock des alcools a ajouter");
        scanf ("%s %f %f", Tab_alcohol_cocktail_add[i].name, &Tab_alcohol_cocktail_add[i].degrees, &Tab_alcohol_cocktail_add[i].price);
        i++;
    } 
    return Tab_alcohol_cocktail_add;
    free (Tab_alcohol_cocktail_add);
}

/* Fonction d'ajout des cocktail sans alcool (qui prend en paramètre l'ancien tableau, la taille de l'ancien tableau et la taille du nouveau tableau) */

noalcohol_cocktail* add_no_alcohol_cocktails (noalcohol_cocktail* Tab_no_alcohol_cocktail, int n , int n2){
    int i = 0;
    noalcohol_cocktail* Tab_no_alcohol_cocktail_add = malloc (n2*sizeof(noalcohol_cocktail)); // réallocation mémoire pour un tableaux plus grand
    while (i<n){ //ajout des éléments déjà existant dans le nouveau tableau
        Tab_no_alcohol_cocktail_add[i] = Tab_no_alcohol_cocktail[i];
        i++;
    }
    while (i<n2){ //ajout des éléments entré par l'utilisateur dans le nouveau tableau
        puts ("Entrer le nom et le stock des alcools a ajouter");
        scanf ("%s %f %f", Tab_no_alcohol_cocktail_add[i].name, &Tab_no_alcohol_cocktail_add[i].sugar_level, &Tab_no_alcohol_cocktail_add[i].price);
        i++;
    }
    return Tab_no_alcohol_cocktail_add;
    free (Tab_no_alcohol_cocktail_add);   
}

/* Fonctions de suppression */

/* Fonction de suppression de jus de fruits (qui prend en paramètre l'ancien tableaux, la nouvelle taille, l'ancienne taille et la valeur à supprimer) */

juice* remove_juices (juice* Tab_Juices, int n2, int n, juice x){
    int i;
    int j;
    juice* Tab_Juices_rem = malloc (n2*sizeof(juice)); // allocation mémoire du nouveau tableau
    if (strcmp (Tab_Juices[0].name, x.name) == 0){ // Test de la première position
        for (i = 1; i<=n; i++){ // i = 1 car on supprime Tab_no_alcohol_cocktail[0]
            Tab_Juices_rem[i-1] = Tab_Juices[i]; 
        }
    }
    else{ // La valeur n'est pas la première du tableau
        for(i = 0; i < n; i++ ){ // On recherche la valeur dans le tableau
            Tab_Juices_rem[i] = Tab_Juices[i];
            if(strcmp(Tab_Juices[i].name, x.name) == 0){
                printf ("%s \n", Tab_Juices[i].name);
                for(j = i; j < n; j++){ // On a trouvé la valeur et on avance
                    Tab_Juices_rem[j] = Tab_Juices[j+1];
                }
            }
        }
    }
    return Tab_Juices_rem;
    free(Tab_Juices_rem);
}

/* Fonction de suppression de sirops (qui prend en paramètre l'ancien tableaux, la nouvelle taille, l'ancienne taille et la valeur à supprimer) */

squash* remove_squash (squash* Tab_squash,int n2, int n, squash x){
    int i;
    int j;
    squash* Tab_Squash_rem = malloc (n2*sizeof(squash)); // allocation mémoire du nouveau tableau
    if (strcmp (Tab_squash[0].name, x.name) == 0){ // Test de la première position
        for (i = 1; i<n; i++){ // i = 1 car on supprime Tab_no_alcohol_cocktail[0]
            Tab_Squash_rem[i-1] = Tab_squash[i]; 
        }
    }
    else{ // La valeur n'est pas la première du tableau
        for(i = 0; i < n; i++ ){ // On recherche la valeur dans le tableau
            Tab_Squash_rem[i] = Tab_squash[i];
            if(strcmp(Tab_squash[i].name, x.name) == 0){
                printf ("%s \n", Tab_squash[i].name);
                for(j = i; j <= n; j++){ // On a trouvé la valeur et on avance
                    Tab_Squash_rem[j] = Tab_squash[j+1];
                }
            }
        }
    }
    return Tab_Squash_rem;
    free(Tab_Squash_rem);
}

/* Fonction de suppression de soda (qui prend en paramètre l'ancien tableaux, la nouvelle taille, l'ancienne taille et la valeur à supprimer) */

soda* remove_soda (soda* Tab_soda,int n2, int n, soda x){
    int i;
    int j;
    soda* Tab_Soda_rem = malloc (n2*sizeof(soda)); // allocation mémoire du nouveau tableau
    if (strcmp (Tab_soda[0].name, x.name) == 0){ // Test de la première position
        for (i = 1; i<=n; i++){ // i = 1 car on supprime Tab_no_alcohol_cocktail[0]
            Tab_Soda_rem[i-1] = Tab_soda[i]; 
        }
    }
    else{ // La valeur n'est pas la première du tableau
        for(i = 0; i < n; i++ ){ // On recherche la valeur dans le tableau
            Tab_Soda_rem[i] = Tab_soda[i];
            if(strcmp(Tab_soda[i].name, x.name) == 0){
                printf ("%s \n", Tab_soda[i].name);
                for(j = i; j <= n; j++){ // On a trouvé la valeur et on avance
                    Tab_Soda_rem[j] = Tab_soda[j+1];
                }
            }
        }
    }
    return Tab_Soda_rem;
    free(Tab_Soda_rem);
}

/* Fonction de suppression de liqueurs (qui prend en paramètre l'ancien tableaux, la nouvelle taille, l'ancienne taille et la valeur à supprimer) */

liqueur* remove_liquors (liqueur* Tab_liquor, int n2, int n, liqueur x){
    int i;
    int j;
    liqueur* Tab_liquor_rem = malloc (n2*sizeof(liqueur)); // allocation mémoire du nouveau tableau
    if (strcmp (Tab_liquor[0].name, x.name) == 0){ // Test de la première position
        for (i = 1; i<=n; i++){ // i = 1 car on supprime Tab_no_alcohol_cocktail[0]
            Tab_liquor_rem[i-1] = Tab_liquor[i]; 
        }
    }
    else{ // La valeur n'est pas la première du tableau
        for(i = 0; i < n; i++ ){ // On recherche la valeur dans le tableau
            Tab_liquor_rem[i] = Tab_liquor[i];
            if(strcmp(Tab_liquor[i].name, x.name) == 0){
                printf ("%s \n", Tab_liquor[i].name);
                for(j = i; j <= n; j++){ // On a trouvé la valeur et on avance
                    Tab_liquor_rem[j] = Tab_liquor[j+1];
                }
            }
        }
    }
    return Tab_liquor_rem;
    free(Tab_liquor_rem);
}

/* Fonction de suppression d'alcool (qui prend en paramètre l'ancien tableaux, la nouvelle taille, l'ancienne taille et la valeur à supprimer) */

alcohol_drink* remove_acohol_drinks (alcohol_drink* Tab_alcohol_drink, int n2, int n, alcohol_drink x){
    int i;
    int j;
    alcohol_drink* Tab_alcohol_drink_rem = malloc (n2*sizeof(alcohol_drink)); // allocation mémoire du nouveau tableau
    if (strcmp (Tab_alcohol_drink[0].name, x.name) == 0){ // Test de la première position
        for (i = 1; i<=n; i++){ // i = 1 car on supprime Tab_no_alcohol_cocktail[0]
            Tab_alcohol_drink_rem[i-1] = Tab_alcohol_drink[i]; 
        }
    }
    else{ // La valeur n'est pas la première du tableau
        for(i = 0; i < n; i++ ){ // On recherche la valeur dans le tableau
            Tab_alcohol_drink_rem[i] = Tab_alcohol_drink[i];
            if(strcmp(Tab_alcohol_drink[i].name, x.name) == 0){
                printf ("%s \n", Tab_alcohol_drink[i].name);
                for(j = i; j <= n; j++){ // On a trouvé la valeur et on avance
                    Tab_alcohol_drink_rem[j] = Tab_alcohol_drink[j+1];
                }
            }
        }
    }
    return Tab_alcohol_drink_rem;
    free(Tab_alcohol_drink_rem);
}

/* Fonction de suppression de cocktail avec alcool (qui prend en paramètre l'ancien tableaux, la nouvelle taille, l'ancienne taille et la valeur à supprimer) */

alcohol_cocktail* remove_acohol_cocktail (alcohol_cocktail* Tab_alcohol_cocktail, int n2, int n, alcohol_cocktail x){
    int i;
    int j;
    alcohol_cocktail* Tab_alcohol_cocktail_rem = malloc (n2*sizeof(alcohol_cocktail)); // allocation mémoire du nouveau tableau
    if (strcmp (Tab_alcohol_cocktail[0].name, x.name) == 0){ // Test de la première position
        for (i = 1; i<=n; i++){ // i = 1 car on supprime Tab_no_alcohol_cocktail[0]
            Tab_alcohol_cocktail_rem[i-1] = Tab_alcohol_cocktail[i]; 
        }
    }
    else{ // La valeur n'est pas la première du tableau
        for(i = 0; i < n; i++ ){ // On recherche la valeur dans le tableau
            Tab_alcohol_cocktail_rem[i] = Tab_alcohol_cocktail[i];
            if(strcmp(Tab_alcohol_cocktail[i].name, x.name) == 0){
                printf ("%s \n", Tab_alcohol_cocktail[i].name);
                for(j = i; j < n; j++){ // On a trouvé la valeur et on avance
                    Tab_alcohol_cocktail_rem[j] = Tab_alcohol_cocktail[j+1];
                }
            }
        }
    }
    return Tab_alcohol_cocktail_rem;
    free(Tab_alcohol_cocktail_rem);
}

/* Fonction de suppression de cocktail sans alcool (qui prend en paramètre l'ancien tableaux, la nouvelle taille, l'ancienne taille et la valeur à supprimer) */

noalcohol_cocktail* remove_no_acohol_cocktail (noalcohol_cocktail* Tab_no_alcohol_cocktail, int n2, int n, noalcohol_cocktail x){
    int i;
    int j;
    noalcohol_cocktail* Tab_no_alcohol_cocktail_rem = malloc (n2*sizeof(noalcohol_cocktail)); // allocation mémoire du nouveau tableau 
    if (strcmp (Tab_no_alcohol_cocktail[0].name, x.name) == 0){ // Test de la première position
        for (i = 1; i<=n; i++){ // i = 1 car on supprime Tab_no_alcohol_cocktail[0]
            Tab_no_alcohol_cocktail_rem[i-1] = Tab_no_alcohol_cocktail[i]; 
        }
    }
    else{ // La valeur n'est pas la première du tableau
        for(i = 0; i < n; i++ ){ // On recherche la valeur dans le tableau
            Tab_no_alcohol_cocktail_rem[i] = Tab_no_alcohol_cocktail[i];
            if(strcmp(Tab_alcohol_cocktail[i].name, x.name) == 0){
                printf ("%s \n", Tab_no_alcohol_cocktail[i].name);
                for(j = i; j <= n; j++){ // On a trouvé la valeur et on avance
                    Tab_no_alcohol_cocktail_rem[j] = Tab_no_alcohol_cocktail[j+1]; 
                }
            }
        }
    }
    return Tab_no_alcohol_cocktail_rem;
    free(Tab_no_alcohol_cocktail_rem);
}

/* Procédures d'affichage */

/* Procédure d'affichage des jus de fruits (qui prend en paramère le tableau et la taille du tableau) */

void aff_juices (juice* Tab_Juices, int n){
    int i;
    for (i = 0; i<n; i++){ // Affichage des noms sous forme de tableau (avec des cases)
        printf (" %s |", Tab_Juices[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des stocks sous forme de tableau (avec des cases)
        printf (" %f |", Tab_Juices[i].stock);
    }
}

/* Procédure d'affichage des sirops (qui prend en paramère le tableau et la taille du tableau) */

void aff_Squashes (squash* Tab_Squash, int n){
    int i;
    for (i = 0; i<n; i++){ // Affichage des noms sous forme de tableau (avec des cases)
        printf (" %s |", Tab_Squash[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des stocks sous forme de tableau (avec des cases)
        printf (" %f |", Tab_Squash[i].stock);
    }
}

/* Procédure d'affichage des sodas (qui prend en paramère le tableau et la taille du tableau) */

void aff_Sodas (soda* Tab_Soda, int n){
    int i;
    for (i = 0; i<n; i++){ // Affichage des noms sous forme de tableau (avec des cases)
        printf (" %s |", Tab_Soda[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des stocks sous forme de tableau (avec des cases)
        printf (" %f |", Tab_Soda[i].stock);
    }
}

/* Procédure d'affichage des liqueurs (qui prend en paramère le tableau et la taille du tableau) */

void aff_liquor (liqueur* Tab_liqueur, int n){
    int i;
    for (i = 0; i<n; i++){ // Affichage des noms sous forme de tableau (avec des cases)
        printf (" %s |", Tab_liqueur[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des stocks sous forme de tableau (avec des cases)
        printf (" %f |", Tab_liqueur[i].stock);
    }
}

/* Procédure d'affichage des alcools (qui prend en paramère le tableau et la taille du tableau) */

void aff_alcohol_drink (alcohol_drink* Tab_alcohol_drink, int n){
    int i;
    for (i = 0; i<n; i++){ // Affichage des noms sous forme de tableau (avec des cases)
        printf (" %s |", Tab_alcohol_drink[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des stocks sous forme de tableau (avec des cases)
        printf (" %f |", Tab_alcohol_drink[i].stock);
    }
}

/* Procédure d'affichage des cocktails avec alcool (qui prend en paramère le tableau et la taille du tableau) */

void aff_alcohol_cocktail (alcohol_cocktail* Tab_alcohol_cocktail, int n){
    int i;
    for (i = 0; i<n; i++){ // Affichage des noms sous forme de tableau (avec des cases)
        printf (" %s |", Tab_alcohol_cocktail[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des degrés d'alcool sous forme de tableau (avec des cases)
        printf (" %f |", Tab_alcohol_cocktail[i].degrees);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des prix sous forme de tableau (avec des cases)
        printf (" %f |", Tab_alcohol_cocktail[i].price);
    }
}

/* Procédure d'affichage des cocktails sans alcool (qui prend en paramère le tableau et la taille du tableau) */

void aff_no_alcohol_cocktail (noalcohol_cocktail* Tab_no_alcohol_cocktail, int n){
    int i;
    for (i = 0; i<n; i++){ // Affichage des noms sous forme de tableau (avec des cases)
        printf (" %s |", Tab_no_alcohol_cocktail[i].name);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des niveaux de sucre sous forme de tableau (avec des cases)
        printf (" %f |", Tab_no_alcohol_cocktail[i].sugar_level);
    }
    puts ("\n");
    for (i = 0; i<n; i++){ // Affichage des prix sous forme de tableau (avec des cases)
        printf (" %f |", Tab_no_alcohol_cocktail[i].price);
    }
}

/* Procédure de sauvegarde en fichiers */

/* Procédure de sauvegarde des jus de fruits (qui prend en paramètre la taille du tableau et le tableau à sauvegarder) */

void Sauvegarde_Jus (int n, juice* Tab_Juice){
    int i;
    Jus = fopen ("Jus.txt", "w"); // Ouverture du fichier en écriture
    if (Jus == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ecriture dans le fichier
        fprintf (Jus, "%s %f \n", Tab_Juice[i].name, Tab_Juice[i].stock);
    }
    fclose(Jus); // Fermeture du fichier
}

/* Procédure de sauvegarde des sirops (qui prend en paramètre la taille du tableau et le tableau à sauvegarder) */

void Sauvegarde_Sirops (int n, squash* Tab_Squash){
    int i;
    Sirops = fopen ("Sirops.txt", "w"); // Ouverture du fichier en écriture
    if (Sirops == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ecriture dans le fichier
        fprintf (Sirops, "%s %f \n", Tab_Squash[i].name, Tab_Squash[i].stock);
    }
    fclose(Sirops); // Fermeture du fichier
}

/* Procédure de sauvegarde des sodas (qui prend en paramètre la taille du tableau et le tableau à sauvegarder) */

void Sauvegarde_Soda (int n, soda* Tab_Soda){
    int i;
    Soda = fopen ("Soda.txt", "w"); // Ouverture du fichier en écriture
    if (Soda == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ecriture dans le fichier
        fprintf (Soda, "%s %f \n", Tab_Soda[i].name, Tab_Soda[i].stock);
    }
    fclose(Soda); // Fermeture du fichier
}

/* Procédure de sauvegarde des liqueurs (qui prend en paramètre la taille du tableau et le tableau à sauvegarder) */

void Sauvegarde_liqueur (int n, liqueur* Tab_Liqueur){
    int i;
    Liqueur = fopen ("Liqueur.txt", "w"); // Ouverture du fichier en écriture
    if (Liqueur == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ecriture dans le fichier
        fprintf (Liqueur, "%s %f \n", Tab_Liqueur[i].name, Tab_Liqueur[i].stock);
    }
    fclose(Liqueur); // Fermeture du fichier
}

/* Procédure de sauvegarde des jalcools (qui prend en paramètre la taille du tableau et le tableau à sauvegarder) */

void Sauvegarde_alcool (int n, alcohol_drink* Tab_alcohol_drink){
    int i;
    Alcool = fopen ("Alcool.txt", "w"); // Ouverture du fichier en écriture
    if (Alcool == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ecriture dans le fichier
        fprintf (Alcool, "%s %f \n", Tab_alcohol_drink[i].name, Tab_alcohol_drink[i].stock);
    }
    fclose(Alcool); // Fermeture du fichier
}

/* Procédure de sauvegarde des cocktails avec alcool (qui prend en paramètre la taille du tableau et le tableau à sauvegarder) */

void Sauvegarde_alcool_cocktail (int n, alcohol_cocktail* Tab_alcohol_cocktail){
    int i;
    Alcool_Cokctail = fopen ("Alcool_Cocktail.txt", "w"); // Ouverture du fichier en écriture
    if (Alcool_Cokctail == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ecriture dans le fichier
        fprintf (Alcool_Cokctail, "%s %f %f \n", Tab_alcohol_cocktail[i].name, Tab_alcohol_cocktail[i].degrees, Tab_alcohol_cocktail[i].price);
    }
    fclose(Alcool_Cokctail); // Fermeture du fichier
}

/* Procédure de sauvegarde des cocktails sans alcool (qui prend en paramètre la taille du tableau et le tableau à sauvegarder) */

void Sauvegarde_no_alcool_cocktail (int n, noalcohol_cocktail* Tab_no_alcohol_cocktail){
    int i;
    Sans_Alcool_Cokctail = fopen ("Sans_Alcool_Cocktail.txt", "w"); // Ouverture du fichier en écriture
    if (Sans_Alcool_Cokctail == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ecriture dans le fichier
        fprintf (Sans_Alcool_Cokctail, "%s %f %f \n", Tab_no_alcohol_cocktail[i].name, Tab_no_alcohol_cocktail[i].sugar_level, Tab_no_alcohol_cocktail[i].price);
    }
    fclose(Sans_Alcool_Cokctail); // Fermeture du fichier
}

/* Fonction de récupération des éléments d'un tableau de matière première depuis un fichier */

/* Fonction de récupération des jus de fruits (qui prend en paramètre la taille du tableau et le tableau à remplir) */

juice* Recup_Jus (int n, juice* Tab_Juice){
    int i;
    Jus = fopen ("Jus.txt", "r"); // Ouverture du fichier en lecture
    if (Jus == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ajout dans le tableau les éléments du fichier
        fscanf (Jus, "%s %f", Tab_Juice[i].name, &Tab_Juice[i].stock);
    }
    fclose (Jus); // Fermeture du fichier
    return Tab_Juice;
}

/* Fonction de récupération des sirops (qui prend en paramètre la taille du tableau et le tableau à remplir) */

squash* Recup_Sirops (int n, squash* Tab_Sirops){
    int i;
    Sirops = fopen ("Sirops.txt", "r"); // Ouverture du fichier en lecture
    if (Sirops == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ajout dans le tableau les éléments du fichier
        fscanf (Sirops, "%s %f", Tab_Sirops[i].name, &Tab_Sirops[i].stock);
    }
    fclose (Sirops); // Fermeture du fichier
    return Tab_Sirops;
}

/* Fonction de récupération des sodas (qui prend en paramètre la taille du tableau et le tableau à remplir) */

soda* Recup_Soda (int n, soda* Tab_Soda){
    int i;
    Soda = fopen ("Soda.txt", "r"); // Ouverture du fichier en lecture
    if (Soda == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ajout dans le tableau les éléments du fichier
        fscanf (Soda, "%s %f \n", Tab_Soda[i].name, &Tab_Soda[i].stock);
    }
    fclose(Soda); // Fermeture du fichier
    return Tab_Soda;
}

/* Fonction de récupération des alcools (qui prend en paramètre la taille du tableau et le tableau à remplir) */

alcohol_drink* Recup_alcool (int n, alcohol_drink* Tab_alcohol_drink){
    int i;
    Alcool = fopen ("Alcool.txt", "r"); // Ouverture du fichier en lecture
    if (Alcool == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ajout dans le tableau les éléments du fichier
        fscanf (Alcool, "%s %f \n", Tab_alcohol_drink[i].name, &Tab_alcohol_drink[i].stock);
    }
    fclose(Alcool); // Fermeture du fichier
    return Tab_alcohol_drink;
}

/* Fonction de récupération des cocktails avec alcool (qui prend en paramètre la taille du tableau et le tableau à remplir) */

alcohol_cocktail* Recup_alcool_cocktail (int n, alcohol_cocktail* Tab_alcohol_cocktail){
    int i;
    Alcool_Cokctail = fopen ("Alcool_Cocktail.txt", "r"); // Ouverture du fichier en lecture
    if (Alcool_Cokctail == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ajout dans le tableau les éléments du fichier
        fscanf (Alcool_Cokctail, "%s %f %f \n", Tab_alcohol_cocktail[i].name, &Tab_alcohol_cocktail[i].degrees, &Tab_alcohol_cocktail[i].price);
    }
    fclose(Alcool_Cokctail); // Fermeture du fichier
    return Tab_alcohol_cocktail;
}

/* Fonction de récupération des cocktails sans alcool (qui prend en paramètre la taille du tableau et le tableau à remplir) */

noalcohol_cocktail* Recup_no_alcool_cocktail (int n, noalcohol_cocktail* Tab_no_alcohol_cocktail){
    int i;
    Sans_Alcool_Cokctail = fopen ("Sans_Alcool_Cocktail.txt", "r"); // Ouverture du fichier en lecture
    if (Sans_Alcool_Cokctail == NULL){ // Si le fichier n'existe pas
        puts ("Erreur");
        exit (1);
    }
    for (i = 0; i<n; i++){ // Ajout dans le tableau les éléments du fichier
        fscanf (Sans_Alcool_Cokctail, "%s %f %f \n", Tab_no_alcohol_cocktail[i].name, &Tab_no_alcohol_cocktail[i].sugar_level, &Tab_no_alcohol_cocktail[i].price);
    }
    fclose(Sans_Alcool_Cokctail); // Fermeture du fichier
    return Tab_no_alcohol_cocktail;
}

/* Procédure de menus */

/* Menu d'initialisation */

void menuInitialisation(){
    int n;
    int taille_Tab;
    puts ("\n");
    puts ("Menu d'initialisation \n");
    puts ("1 : initialiser jus de fruits \n");
    puts ("2 : initialiser sirops \n");
    puts ("3 : initialiser sodas \n");
    puts ("4 : initialiser liqueur \n");
    puts ("5 : initialiser alcool \n");
    puts ("6 : initialiser cocktails avec alcool \n");
    puts ("7 : initialiser cocktails sans alcool \n");
    scanf ("%d", &n);
    switch (n)
    {
    case 1:
        puts ("Initialisation des jus de fruits \n");
        taille_Tab = TailleTab (); // Taille du tableau
        Taille_Tab_Juices = taille_Tab; // Taille mise dans la variable globale
        TabJuice = malloc (Taille_Tab_Juices*sizeof(juice)); // Allocation mémoire
        TabJuice = defineTab_Juices(Taille_Tab_Juices); 
        aff_juices(TabJuice, Taille_Tab_Juices);
        menuPrincipal();
        break;
    case 2:
        puts ("Initialisation des sirops \n");
        taille_Tab = TailleTab (); // Taille du tableau
        Taille_Tab_Squashes = taille_Tab; // Taille mise dans la variable globale
        TabSquash = malloc (Taille_Tab_Squashes*sizeof(squash)); // Allocation mémoire
        TabSquash = defineTab_Squashes(Taille_Tab_Squashes);
        aff_Squashes (TabSquash, Taille_Tab_Squashes);
        menuPrincipal();
        break;
    case 3:
        puts ("Initialisation des sodas \n");
        taille_Tab = TailleTab (); // Taille du tableau
        Taille_Tab_Soda = taille_Tab; // Taille mise dans la variable globale
        TabSoda = malloc (Taille_Tab_Soda*sizeof(soda)); // Allocation mémoire
        TabSoda = defineTab_Sodas(Taille_Tab_Soda);
        aff_Sodas (TabSoda, Taille_Tab_Soda);
        menuPrincipal();
        break;
    case 4:
        puts ("Initialisation des liqueurs \n");
        taille_Tab = TailleTab (); // Taille du tableau
        Taille_Tab_Liquors = taille_Tab; // Taille mise dans la variable globale
        TabLiquor = malloc (Taille_Tab_Liquors*sizeof(liqueur)); // Allocation mémoire
        TabLiquor = defineTab_Liquor(Taille_Tab_Liquors);
        aff_liquor (TabLiquor, Taille_Tab_Liquors);
        menuPrincipal();
        break;
    case 5:
        puts ("Initialisation des alcohols \n");
        taille_Tab = TailleTab (); // Taille du tableau
        Taille_Tab_alcohol_drinks = taille_Tab; // Taille mise dans la variable globale
        Tab_alcohol_drink = malloc (Taille_Tab_alcohol_drinks*sizeof(alcohol_drink)); // Allocation mémoire
        Tab_alcohol_drink = defineTab_alcohol_drink(Taille_Tab_alcohol_drinks);
        aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);
        menuPrincipal();
        break;
    case 6:
        puts ("Initialisation des cocktails avec alcool \n");
        taille_Tab = TailleTab (); // Taille du tableau
        Taille_Tab_alcohol_cocktails = taille_Tab; // Taille mise dans la variable globale
        Tab_alcohol_cocktail = malloc (Taille_Tab_alcohol_cocktails*sizeof(alcohol_cocktail)); // Allocation mémoire
        Tab_alcohol_cocktail = defineTab_alcohol_cokctail(Taille_Tab_alcohol_cocktails);
        aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
        menuPrincipal();
        break;
    case 7:
        puts ("Initialisation des cocktails sans alcool \n");
        taille_Tab = TailleTab (); // Taille du tableau
        Taille_Tab_no_alcohol_cocktails = taille_Tab; // Taille mise dans la variable globale
        Tab_no_alcohol_cocktail = malloc (Taille_Tab_no_alcohol_cocktails*sizeof(noalcohol_cocktail)); // Allocation mémoire
        Tab_no_alcohol_cocktail = defineTab_no_alcohol_cokctail(Taille_Tab_no_alcohol_cocktails);
        aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails);
        menuPrincipal();
        break;
    default:
        menuPrincipal();
        break;
    }
}

/* Menu d'ajout et de suppression des matières premières */   

void menuMatieresPremieres()
{

    int choix = 0; 
    int Taille_tab;
    juice x_juice;
    squash x_squash;
    soda x_soda;
    liqueur x_liquor;
    alcohol_drink x_alcohol_drink;
    juice* TabJuice_Copie;
    squash* TabSquash_Copie;
    soda* TabSoda_Copie;
    liqueur* TabLiquor_Copie;
    alcohol_drink* Tab_alcohol_drink_Copie;
    printf("Menu des matieres premieres\n");
    printf("1 : Ajouter alcool\n");
    printf("2 : Supprimer alcool\n");
    printf("3 : Ajouter liqueur\n");
    printf("4 : Supprimer liqueur\n");
    printf("5 : Ajouter sirop\n");
    printf("6 : Supprimer sirop\n");
    printf("7 : Ajouter jus\n");
    printf("8 : Supprimer jus\n");
    printf("9 : Ajouter soda\n");
    printf("10 : Supprimer soda\n");

    printf("Faire votre choix\n\n");
    scanf("%d", &choix);

    switch(choix){
        case 1: 
            Taille_tab =  TailleTab (); // Taille du tableau
            Tab_alcohol_drink = realloc (Tab_alcohol_drink, Taille_tab*sizeof(alcohol_drink)); // Réallocation mémoire
            Tab_alcohol_drink = add_alcohol_drinks (Tab_alcohol_drink, Taille_Tab_alcohol_drinks, Taille_tab);
            Taille_Tab_alcohol_drinks = Taille_tab; // Taille mise dans la variable globale
            puts("Alcool ajoute\n");
            aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);
            menuPrincipal();
            break;
        case 2:
            Taille_tab =  TailleTab (); // Taille du tableau
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_alcohol_drink.name);
            Tab_alcohol_drink_Copie = malloc (Taille_tab*sizeof(alcohol_drink)); // Allocation mémoire du tableau de suppression
            Tab_alcohol_drink_Copie = remove_acohol_drinks (Tab_alcohol_drink, Taille_Tab_alcohol_drinks, Taille_tab, x_alcohol_drink);
            Taille_Tab_alcohol_drinks = Taille_tab; // Taille mise dans la variable globale
            Tab_alcohol_drink = realloc (Tab_alcohol_drink, Taille_Tab_alcohol_drinks*sizeof(juice)); // Réallocation mémoire
            for (int i = 0; i<Taille_tab; i++){ // Mise dans le nouveau Tableau réalloué les valeurs du tableau de copie
                Tab_alcohol_drink[i] = Tab_alcohol_drink_Copie[i];
            }
            free(Tab_alcohol_drink_Copie);
            puts("Alcool supprime\n");
            aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);
            menuPrincipal();
            break;
        case 3: 
            Taille_tab =  TailleTab (); // Taille du tableau
            TabLiquor = realloc (TabLiquor, Taille_tab*sizeof(liqueur)); // Réallocation mémoire
            TabLiquor = add_liquors (TabLiquor, Taille_Tab_Liquors, Taille_tab);
            Taille_Tab_Liquors = Taille_tab; // Taille mise dans la variable globale
            puts("Liqueur ajoute\n");
            aff_liquor (TabLiquor, Taille_Tab_Liquors);
            menuPrincipal();
            break;
        case 4: 
            Taille_tab =  TailleTab (); // Taille du tableau
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_liquor.name);
            TabLiquor_Copie = malloc(Taille_tab*sizeof(liqueur)); // Allocation mémoire du tableau de suppression
            TabLiquor_Copie = remove_liquors (TabLiquor, Taille_Tab_Liquors, Taille_tab, x_liquor);
            Taille_Tab_Liquors = Taille_tab; // Taille mise dans la variable globale
            TabLiquor = realloc (TabLiquor, Taille_Tab_Liquors*sizeof(liqueur)); // Réallocation mémoire
            for (int i = 0; i<Taille_tab; i++){ // Mise dans le nouveau Tableau réalloué les valeurs du tableau de copie
                TabLiquor[i] = TabLiquor_Copie[i];
            }
            free (TabLiquor_Copie);
            puts("Liqueur supprimé\n");
            aff_liquor (TabLiquor_Copie, Taille_Tab_Liquors);
            menuPrincipal();
            break;
        case 5: 
            Taille_tab =  TailleTab (); // Taille du tableau
            TabSquash = realloc (TabSquash, Taille_tab*sizeof(squash)); // Réallocation mémoire
            TabSquash = add_squashes (TabSquash, Taille_Tab_Squashes, Taille_tab);
            Taille_Tab_Squashes = Taille_tab; // Taille mise dans la variable globale
            puts("Sirop ajoute\n");
            aff_Squashes (TabSquash, Taille_Tab_Squashes);
            menuPrincipal();
            break;
        case 6: 
            Taille_tab =  TailleTab (); // Taille du tableau
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_squash.name);
            TabSquash_Copie = malloc (Taille_tab*sizeof(squash)); // Allocation mémoire du tableau de suppression
            TabSquash_Copie = remove_squash (TabSquash, Taille_Tab_Squashes, Taille_tab, x_squash);
            Taille_Tab_Squashes = Taille_tab; // Taille mise dans la variable globale
            TabSquash = realloc (TabSquash, Taille_Tab_Squashes*sizeof(squash)); // Réallocation mémoire
            for (int i = 0; i<Taille_tab; i++){ // Mise dans le nouveau Tableau réalloué les valeurs du tableau de copie
                TabSquash[i] = TabSquash_Copie[i];
            }
            free(TabSquash_Copie);
            puts("Sirop supprime\n");
            aff_Squashes (TabSquash, Taille_Tab_Squashes);
            menuPrincipal();
            break;
        case 7: 
            Taille_tab =  TailleTab (); // Taille du tableau
            TabJuice = realloc (TabJuice, Taille_tab*sizeof(juice)); // Réallocation mémoire
            TabJuice = add_Juices (TabJuice, Taille_Tab_Juices, Taille_tab);
            Taille_Tab_Juices = Taille_tab; // Taille mise dans la variable globale
            puts("Jus ajoute\n");
            aff_juices(TabJuice, Taille_Tab_Juices); 
            menuPrincipal();
            break;
        case 8: 
            Taille_tab =  TailleTab (); // Taille du tableau
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_juice.name);
            TabJuice_Copie = malloc (Taille_tab*sizeof(juice)); // Allocation mémoire du tableau de suppression
            TabJuice_Copie = remove_juices (TabJuice, Taille_Tab_Juices, Taille_tab, x_juice);
            Taille_Tab_Juices = Taille_tab; // Taille mise dans la variable globale
            TabJuice =  realloc (TabJuice, Taille_Tab_Juices*sizeof(juice)); // Réallocation mémoire
            for (int i = 0; i<Taille_tab; i++){ // Mise dans le nouveau Tableau réalloué les valeurs du tableau de copie
                TabJuice[i] = TabJuice_Copie[i];
            }
            free(TabJuice_Copie);
            puts("Jus supprime\n");
            aff_juices(TabJuice, Taille_Tab_Juices);
            menuPrincipal();
            break;
        case 9: 
            Taille_tab =  TailleTab (); // Taille du tableau
            TabSoda = realloc (TabSoda, Taille_tab*sizeof(soda)); // Réallocation mémoire
            TabSoda = add_sodas (TabSoda, Taille_Tab_Soda, Taille_tab);
            Taille_Tab_Soda = Taille_tab; // Taille mise dans la variable globale
            puts("Soda ajoute\n");
            aff_Sodas (TabSoda, Taille_Tab_Soda);
            menuPrincipal();
            break;
        case 10: 
            Taille_tab =  TailleTab (); // Taille du tableau
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_soda.name);
            TabSoda_Copie = malloc (Taille_tab*sizeof(soda)); // Allocation mémoire du tableau de suppression
            TabSoda_Copie = remove_soda (TabSoda, Taille_Tab_Soda, Taille_tab, x_soda);
            Taille_Tab_Soda = Taille_tab; // Taille mise dans la variable globale
            TabSoda = realloc (TabSoda, Taille_Tab_Soda*sizeof(juice)); // Réallocation mémoire
            for (int i = 0; i<Taille_tab; i++){ // Mise dans le nouveau Tableau réalloué les valeurs du tableau de copie
                TabSoda[i] = TabSoda_Copie[i];
            }
            free(TabSoda_Copie);
            puts("Soda supprime\n");
            aff_Sodas (TabSoda, Taille_Tab_Soda);
            menuPrincipal();
            break;
        default: 
            puts("Retour au menu principal\n");
            menuPrincipal();
            break;
    }
}

/* Menu d'ajout et de suppression des cocktails */

void menuCocktail()
{
    int choix2 = 0;
    int Taille_Tab;
    noalcohol_cocktail x_no_alcohol_cocktail;
    alcohol_cocktail x_alcohol_cocktail;
    noalcohol_cocktail* Tab_no_alcohol_cocktail_Copie;
    alcohol_cocktail* Tab_alcohol_cocktail_Copie;
    puts ("\n");
    printf("Menu des cocktails\n");
    printf("1 : Ajouter cocktail avec alcool\n");
    printf("2 : Supprimer cocktail avec alcool\n");
    printf("3 : Ajouter cocktail sans alcool\n");
    printf("4 : Supprimer cocktail sans alcool\n");

    printf("Faire votre choix\n\n");
    scanf("%d", &choix2);

    switch(choix2){
        case 1: 
            Taille_Tab = TailleTab(); // Taille du tableau
            Tab_alcohol_cocktail = realloc (Tab_alcohol_cocktail, Taille_Tab*sizeof(alcohol_cocktail)); // Réallocation mémoire
            Tab_alcohol_cocktail = add_alcohol_cocktails (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails, Taille_Tab);
            Taille_Tab_alcohol_cocktails = Taille_Tab; // Taille mise dans la variable globale
            puts("Cocktail avec alcool ajoute\n");
            aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
            menuPrincipal();
            break;
        case 2: 
            Taille_Tab = TailleTab(); // Taille du tableau
            puts ("Entrer la valeur a supprimer : ");
            scanf ("%s", x_alcohol_cocktail.name);
            Tab_alcohol_cocktail_Copie = malloc (Taille_Tab*sizeof(alcohol_cocktail)); // Allocation mémoire du tableau de suppression
            Tab_alcohol_cocktail_Copie = remove_acohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails, Taille_Tab, x_alcohol_cocktail);
            Taille_Tab_alcohol_cocktails = Taille_Tab; // Taille mise dans la variable globale
            Tab_alcohol_cocktail = realloc (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails*sizeof (alcohol_cocktail)); // Réallocation mémoire
            for (int i = 0; i<Taille_Tab; i++){ // Mise dans le nouveau Tableau réalloué les valeurs du tableau de copie
                Tab_alcohol_cocktail[i] = Tab_alcohol_cocktail_Copie[i];
            }
            free (Tab_alcohol_cocktail_Copie);
            puts("Cocktail avec alcool supprime\n");
            aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
            menuPrincipal();
            break;
        case 3: 
            Taille_Tab = TailleTab(); // Taille du tableau
            Tab_no_alcohol_cocktail = realloc (Tab_no_alcohol_cocktail, Taille_Tab*sizeof(noalcohol_cocktail)); // Réallocation mémoire
            Tab_no_alcohol_cocktail = add_no_alcohol_cocktails (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails, Taille_Tab);
            Taille_Tab_no_alcohol_cocktails = Taille_Tab; // Taille mise dans la variable globale
            puts("Cocktail sans alcool ajoute\n");
            aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails);
            menuPrincipal();
            break;
        case 4: 
            Taille_Tab = TailleTab(); // Taille du tableau
            puts ("Entrer la valeur a supprimer : ");
            scanf ("%s", x_no_alcohol_cocktail.name);
            Tab_no_alcohol_cocktail_Copie = malloc (Taille_Tab*sizeof(noalcohol_cocktail)); // Allocation mémoire du tableau de suppression
            Tab_no_alcohol_cocktail_Copie = remove_no_acohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails, Taille_Tab, x_no_alcohol_cocktail);
            Taille_Tab_no_alcohol_cocktails = Taille_Tab; // Taille mise dans la variable globale
            Tab_no_alcohol_cocktail = realloc (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails*sizeof (noalcohol_cocktail)); // Réallocation mémoire
            for (int i = 0; i<Taille_Tab; i++){ // Mise dans le nouveau Tableau réalloué les valeurs du tableau de copie
                Tab_no_alcohol_cocktail[i] = Tab_no_alcohol_cocktail_Copie[i];
            }
            free (Tab_no_alcohol_cocktail_Copie);
            puts("Cocktail sans alcool supprime\n"); 
            aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails);
            menuPrincipal();
            break;
        default:
            printf("Retour au menu principal\n");
            free (Tab_alcohol_cocktail_Copie);
            free (Tab_no_alcohol_cocktail_Copie);
            menuPrincipal();
            break;
    }
}

/* Menu Principal */

void menuPrincipal()
{
    int nombre; 
    int Taille;
    puts ("\n");
    puts ("Menu general\n");
    puts ("1 : Initialiser les tableaux\n");
    puts ("2 : Ajouter/supprimer des matieres premieres\n");
    puts ("3 : Ajouter/supprimer cocktails\n");
    puts ("4 : Sauvegarder les coctails et matieres premieres\n");
    puts ("5 : Recuperer les matieres premieres et cocktail\n");

    printf("Entrer un nombre\n");
    scanf("%d",&nombre);

    switch(nombre){
        case 1:
            menuInitialisation (); // Appel du menu d'initialisation
            break;
        case 2: 
            menuMatieresPremieres(); // Appel du menu d'ajout et de suppression de matières premières
            break;
        break;
        case 3: 
            menuCocktail(); // Appel du menu d'ajout et de suppression de cocktails
            break;
        case 4: 
            Sauvegarde_Jus (Taille_Tab_Juices, TabJuice); // Appel procédure de sauvegarde de jus de fruits
            Sauvegarde_Sirops (Taille_Tab_Squashes, TabSquash); // Appel procédure de sauvegarde de sirops
            Sauvegarde_Soda (Taille_Tab_Soda, TabSoda); // Appel procédure de sauvegarde de sodas
            Sauvegarde_liqueur (Taille_Tab_Liquors, TabLiquor); // Appel procédure de sauvegarde de liqueur
            Sauvegarde_alcool (Taille_Tab_alcohol_drinks, Tab_alcohol_drink); // Appel procédure de sauvegarde d'alcool
            Sauvegarde_alcool_cocktail (Taille_Tab_alcohol_cocktails, Tab_alcohol_cocktail); // Appel procédure de sauvegarde de cocktail avec alcool
            Sauvegarde_no_alcool_cocktail (Taille_Tab_no_alcohol_cocktails, Tab_no_alcohol_cocktail); // Appel procédure de sauvegarde de cocktail sans alcool
            break;
        case 5: 
            Taille = TailleTab (); // Taille du tableau
            TabJuice = malloc (Taille*sizeof(juice)); // Allocation mémoire
            TabJuice = Recup_Jus (Taille, TabJuice); // Appel fonction de récupération
            Taille_Tab_Juices = Taille; // Taille mise dans la variable globale
            Taille = TailleTab (); // Taille du tableau
            TabSquash = malloc (Taille*sizeof(squash)); // Allocation mémoire
            TabSquash = Recup_Sirops (Taille, TabSquash); // Appel fonction de récupération
            Taille_Tab_Squashes = Taille; // Taille mise dans la variable globale
            Taille = TailleTab (); // Taille du tableau
            TabSoda = malloc (Taille*sizeof(soda)); // Allocation mémoire
            TabSoda = Recup_Soda (Taille, TabSoda); // Appel fonction de récupération
            Taille_Tab_Soda = Taille; // Taille mise dans la variable globale
            Taille = TailleTab (); // Taille du tableau
            Tab_alcohol_drink = malloc (Taille*sizeof(alcohol_drink)); // Allocation mémoire
            Tab_alcohol_drink = Recup_alcool (Taille, Tab_alcohol_drink); // Appel fonction de récupération
            Taille_Tab_alcohol_drinks = Taille; // Taille mise dans la variable globale
            Taille = TailleTab (); // Taille du tableau
            Tab_alcohol_cocktail = malloc (Taille*sizeof(alcohol_cocktail)); // Allocation mémoire
            Tab_alcohol_cocktail = Recup_alcool_cocktail (Taille, Tab_alcohol_cocktail); // Appel fonction de récupération
            Taille_Tab_alcohol_cocktails = Taille; // Taille mise dans la variable globale
            Taille = TailleTab (); // Taille du tableau
            Tab_no_alcohol_cocktail = malloc (Taille*sizeof(noalcohol_cocktail)); // Allocation mémoire
            Tab_no_alcohol_cocktail = Recup_no_alcool_cocktail (Taille, Tab_no_alcohol_cocktail); // Appel fonction de récupération
            Taille_Tab_no_alcohol_cocktails = Taille; // Taille mise dans la variable globale
            aff_juices (TabJuice, Taille_Tab_Juices);
            puts ("\n");
            aff_Squashes (TabSquash, Taille_Tab_Squashes);
            puts ("\n");
            aff_Sodas (TabSoda, Taille_Tab_Soda);
            puts ("\n");
            aff_liquor (TabLiquor, Taille_Tab_Liquors);
            puts ("\n");
            aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);
            puts ("\n");
            aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
            puts ("\n");
            aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails);
            puts ("\n");
            break;
        default:
            free (TabJuice);
            free (TabLiquor);
            free (TabSoda);
            free (TabSquash);
            free (Tab_alcohol_drink);
            free (Tab_alcohol_cocktail);
            free (Tab_no_alcohol_cocktail);
            break;
    }
}



int main (void){
    menuPrincipal ();
    return 0;
}
