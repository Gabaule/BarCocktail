#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <string.h>

/* Structures de boissons */

typedef struct tjuice{  // Structure définissant les jus de fruit
    char name[100]; //Nom du jus de fruit
    float stock;
} juice;

typedef struct tliqueur{  // Structure définissant les liqueurs
    char name[100]; // nom de la liqueur
    float stock;
} liqueur;

typedef struct tsquash{  // Structure définissant les sirops
    char name[100]; //nom du sirop
    float stock;
} squash;

typedef struct tsoda { // Structure définissant les sodas
    char name[100]; //nom du soda
    float stock;
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

FILE* Jus;
FILE* Sirops;
FILE* Soda;
FILE* Liqueur;
FILE* Alcool;
FILE* Alcool_Cokctail;
FILE* Sans_Alcool_Cokctail;

/* Variables globales de Taille */

int Taille_Tab_Juices = 0;
int Taille_Tab_Squashes = 0;
int Taille_Tab_Soda = 0;
int Taille_Tab_Liquors = 0;
int Taille_Tab_alcohol_drinks = 0;
int Taille_Tab_no_alcohol_drinks = 0;
int Taille_Tab_no_alcohol_cocktails = 0;
int Taille_Tab_alcohol_cocktails = 0;

/* Variables globales de Tableau*/

juice* TabJuice;
squash* TabSquash;
soda* TabSoda;
liqueur* TabLiquor;
alcohol_drink* Tab_alcohol_drink;
alcohol_cocktail* Tab_alcohol_cocktail;
noalcohol_cocktail* Tab_no_alcohol_cocktail;

/*   Fonctions Principales   */

/* Fonctions d'initialisations */

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
        scanf ("%s %f", Tabsquash[i].name, &Tabsquash[i].stock);
    }
    return Tabsquash;
    free (Tabsquash);
}

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

alcohol_drink* defineTab_alcohol_drink (int n){
    alcohol_drink* Tab_alcohol_drink = malloc (n*sizeof(alcohol_drink));
    int i;
    TabLiquor = defineTab_Liquor(n);
    for (i = 0; i<n; i++){
        puts ("Enter le nom, le stock :\n");
        scanf ("%s %f", Tab_alcohol_drink[i].name, &Tab_alcohol_drink[i].stock);
    }
    return Tab_alcohol_drink;
    free (Tab_alcohol_drink);
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

/* Fonctions D'ajout */

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

/* Fonctions de suppression */

juice* remove_juices (juice* Tab_Juices, int n2, int n, juice x){
    int i;
    int j;
    juice* Tab_Juices_rem = malloc (n2*sizeof(juice));
    if (strcmp (Tab_Juices[0].name, x.name) == 0){
        for (i = 1; i<=n; i++){
            Tab_Juices_rem[i-1] = Tab_Juices[i]; 
        }
    }
    else{
        for(i = 0; i < n; i++ ){
            Tab_Juices_rem[i] = Tab_Juices[i];
            if(strcmp(Tab_Juices[i].name, x.name) == 0){
                printf ("%s \n", Tab_Juices[i].name);
                for(j = i; j <= n; j++){
                    Tab_Juices_rem[j] = Tab_Juices[j+1];
                }
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
    if (strcmp (Tab_squash[0].name, x.name) == 0){
        for (i = 1; i<=n; i++){
            Tab_Squash_rem[i-1] = Tab_squash[i]; 
        }
    }
    else{
        for(i = 0; i < n; i++ ){
            Tab_Squash_rem[i] = Tab_squash[i];
            if(strcmp(Tab_squash[i].name, x.name) == 0){
                printf ("%s \n", Tab_squash[i].name);
                for(j = i; j <= n; j++){
                    Tab_Squash_rem[j] = Tab_squash[j+1];
                }
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
    if (strcmp (Tab_soda[0].name, x.name) == 0){
        for (i = 1; i<=n; i++){
            Tab_Soda_rem[i-1] = Tab_soda[i]; 
        }
    }
    else{
        for(i = 0; i < n; i++ ){
            Tab_Soda_rem[i] = Tab_soda[i];
            if(strcmp(Tab_soda[i].name, x.name) == 0){
                printf ("%s \n", Tab_soda[i].name);
                for(j = i; j <= n; j++){
                    Tab_Soda_rem[j] = Tab_soda[j+1];
                }
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
    if (strcmp (Tab_liquor[0].name, x.name) == 0){
        for (i = 1; i<=n; i++){
            Tab_liquor_rem[i-1] = Tab_liquor[i]; 
        }
    }
    else{
        for(i = 0; i < n; i++ ){
            Tab_liquor_rem[i] = Tab_liquor[i];
            if(strcmp(Tab_liquor[i].name, x.name) == 0){
                printf ("%s \n", Tab_liquor[i].name);
                for(j = i; j <= n; j++){
                    Tab_liquor_rem[j] = Tab_liquor[j+1];
                }
            }
        }
    }
    return Tab_liquor_rem;
    free(Tab_liquor_rem);
}

alcohol_drink* remove_acohol_drinks (alcohol_drink* Tab_alcohol_drink, int n2, int n, alcohol_drink x){
    int i;
    int j;
    alcohol_drink* Tab_alcohol_drink_rem = malloc (n2*sizeof(alcohol_drink));
    if (strcmp (Tab_alcohol_drink[0].name, x.name) == 0){
        for (i = 1; i<=n; i++){
            Tab_alcohol_drink_rem[i-1] = Tab_alcohol_drink[i]; 
        }
    }
    else{
        for(i = 0; i < n; i++ ){
            Tab_alcohol_drink_rem[i] = Tab_alcohol_drink[i];
            if(strcmp(Tab_alcohol_drink[i].name, x.name) == 0){
                printf ("%s \n", Tab_alcohol_drink[i].name);
                for(j = i; j <= n; j++){
                    Tab_alcohol_drink_rem[j] = Tab_alcohol_drink[j+1];
                }
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
    if (strcmp (Tab_alcohol_cocktail[0].name, x.name) == 0){
        for (i = 1; i<=n; i++){
            Tab_alcohol_cocktail_rem[i-1] = Tab_alcohol_cocktail[i]; 
        }
    }
    else{
        for(i = 0; i < n; i++ ){
            Tab_alcohol_cocktail_rem[i] = Tab_alcohol_cocktail[i];
            if(strcmp(Tab_alcohol_cocktail[i].name, x.name) == 0){
                printf ("%s \n", Tab_alcohol_cocktail[i].name);
                for(j = i; j <= n; j++){
                    Tab_alcohol_cocktail_rem[j] = Tab_alcohol_cocktail[j+1];
                }
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
    if (strcmp (Tab_no_alcohol_cocktail[0].name, x.name) == 0){
        for (i = 1; i<=n; i++){
            Tab_no_alcohol_cocktail_rem[i-1] = Tab_no_alcohol_cocktail[i]; 
        }
    }
    else{
        for(i = 0; i < n; i++ ){
            Tab_no_alcohol_cocktail_rem[i] = Tab_no_alcohol_cocktail[i];
            if(strcmp(Tab_alcohol_cocktail[i].name, x.name) == 0){
                printf ("%s \n", Tab_no_alcohol_cocktail[i].name);
                for(j = i; j <= n; j++){
                    Tab_no_alcohol_cocktail_rem[j] = Tab_no_alcohol_cocktail[j+1];
                }
            }
        }
    }
    return Tab_no_alcohol_cocktail_rem;
    free(Tab_no_alcohol_cocktail_rem);
}

/* Procédures d'affichage */

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

/* Procédure de sauvegarde en fichiers */

void Sauvegarde_Jus (int n, juice* Tab_Juice){
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
}

void Sauvegarde_Sirops (int n, squash* Tab_Squash){
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
}

void Sauvegarde_Soda (int n, soda* Tab_Soda){
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
}

void Sauvegarde_liqueur (int n, liqueur* Tab_Liqueur){
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
}

void Sauvegarde_alcool (int n, alcohol_drink* Tab_alcohol_drink){
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
}

void Sauvegarde_alcool_cocktail (int n, alcohol_cocktail* Tab_alcohol_cocktail){
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
}

void Sauvegarde_no_alcool_cocktail (int n, noalcohol_cocktail* Tab_no_alcohol_cocktail){
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
    return Tab_no_alcohol_cocktail;
}

void menuPrincipal()
{
    int nombre; 
    int Taille;
    puts ("\n");
    puts ("Menu general\n");
    puts ("1 : Initialiser les tableaux\n");
    puts ("2 : Ajouter matieres premieres et supprimer des matieres premieres\n");
    puts ("3 : Ajouter cocktails et supprimer cocktails\n");
    puts ("4 : Sauvegarder les coctails et matieres premieres\n");
    puts ("5 : Recuperer les matieres premieres et cocktail\n");

    printf("Entrer un nombre\n");
    scanf("%d",&nombre);

    switch(nombre){
        case 1:
            menuInitialisation ();
            break;
        case 2: 
            menuMatieresPremieres();
            break;
        break;
        case 3: 
            menuCocktail();
            break;
        case 4: 
            Sauvegarde_Jus (Taille_Tab_Juices, TabJuice);
            Sauvegarde_Sirops (Taille_Tab_Squashes, TabSquash);
            Sauvegarde_Soda (Taille_Tab_Soda, TabSoda);
            Sauvegarde_liqueur (Taille_Tab_Liquors, TabLiquor);
            Sauvegarde_alcool (Taille_Tab_alcohol_drinks, Tab_alcohol_drink);
            Sauvegarde_alcool_cocktail (Taille_Tab_alcohol_cocktails, Tab_alcohol_cocktail);
            Sauvegarde_no_alcool_cocktail (Taille_Tab_no_alcohol_cocktails, Tab_no_alcohol_cocktail);
            break;
        case 5: 
            Taille = TailleTab ();
            TabJuice = malloc (Taille*sizeof(juice));
            TabJuice = Recup_Jus (Taille, TabJuice);
            Taille_Tab_Juices = Taille;
            Taille = TailleTab ();
            TabSquash = malloc (Taille*sizeof(squash));
            TabSquash = Recup_Sirops (Taille, TabSquash);
            Taille_Tab_Squashes = Taille;
            Taille = TailleTab ();
            TabSoda = malloc (Taille*sizeof(soda));
            TabSoda = Recup_Soda (Taille, TabSoda);
            Taille_Tab_Soda = Taille;
            Taille = TailleTab ();
            Tab_alcohol_drink = malloc (Taille*sizeof(alcohol_drink));
            Tab_alcohol_drink = Recup_alcool (Taille, Tab_alcohol_drink);
            Taille_Tab_alcohol_drinks = Taille;
            Taille = TailleTab ();
            Tab_alcohol_cocktail = malloc (Taille*sizeof(alcohol_cocktail));
            Tab_alcohol_cocktail = Recup_alcool_cocktail (Taille, Tab_alcohol_cocktail);
            Taille_Tab_alcohol_cocktails = Taille;
            Taille = TailleTab ();
            Tab_no_alcohol_cocktail = malloc (Taille*sizeof(noalcohol_cocktail));
            Tab_no_alcohol_cocktail = Recup_no_alcool_cocktail (Taille, Tab_no_alcohol_cocktail);
            Taille_Tab_no_alcohol_cocktails = Taille;
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
        taille_Tab = TailleTab ();
        Taille_Tab_Juices = taille_Tab;
        TabJuice = malloc (Taille_Tab_Juices*sizeof(juice));
        TabJuice = defineTab_Juices(Taille_Tab_Juices);
        aff_juices(TabJuice, Taille_Tab_Juices);
        menuPrincipal();
        break;
    case 2:
        puts ("Initialisation des sirops \n");
        taille_Tab = TailleTab ();
        Taille_Tab_Squashes = taille_Tab;
        TabSquash = malloc (Taille_Tab_Squashes*sizeof(squash));
        TabSquash = defineTab_Squashes(Taille_Tab_Squashes);
        aff_Squashes (TabSquash, Taille_Tab_Squashes);
        menuPrincipal();
        break;
    case 3:
        puts ("Initialisation des sodas \n");
        taille_Tab = TailleTab ();
        Taille_Tab_Soda = taille_Tab;
        TabSoda = malloc (Taille_Tab_Soda*sizeof(soda));
        TabSoda = defineTab_Sodas(Taille_Tab_Soda);
        aff_Sodas (TabSoda, Taille_Tab_Soda);
        menuPrincipal();
        break;
    case 4:
        puts ("Initialisation des liqueurs \n");
        taille_Tab = TailleTab ();
        Taille_Tab_Liquors = taille_Tab;
        TabLiquor = malloc (Taille_Tab_Liquors*sizeof(liqueur));
        TabLiquor = defineTab_Liquor(Taille_Tab_Liquors);
        aff_liquor (TabLiquor, Taille_Tab_Liquors);
        menuPrincipal();
        break;
    case 5:
        puts ("Initialisation des alcohols \n");
        taille_Tab = TailleTab ();
        Taille_Tab_alcohol_drinks = taille_Tab;
        Tab_alcohol_drink = malloc (Taille_Tab_alcohol_drinks*sizeof(alcohol_drink));
        Tab_alcohol_drink = defineTab_alcohol_drink(Taille_Tab_alcohol_drinks);
        aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);
        menuPrincipal();
        break;
    case 6:
        puts ("Initialisation des cocktails avec alcool \n");
        taille_Tab = TailleTab ();
        Taille_Tab_alcohol_cocktails = taille_Tab;
        Tab_alcohol_cocktail = malloc (Taille_Tab_alcohol_cocktails*sizeof(alcohol_cocktail));
        Tab_alcohol_cocktail = defineTab_alcohol_cokctail(Taille_Tab_alcohol_cocktails);
        aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
        menuPrincipal();
        break;
    case 7:
        puts ("Initialisation des cocktails sans alcool \n");
        taille_Tab = TailleTab ();
        Taille_Tab_no_alcohol_cocktails = taille_Tab;
        Tab_no_alcohol_cocktail = malloc (Taille_Tab_no_alcohol_cocktails*sizeof(noalcohol_cocktail));
        Tab_no_alcohol_cocktail = defineTab_no_alcohol_cokctail(Taille_Tab_no_alcohol_cocktails);
        aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails);
        menuPrincipal();
        break;
    default:
        menuPrincipal();
        break;
    }
}
    

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
            Taille_tab =  TailleTab ();
            Tab_alcohol_drink = realloc (Tab_alcohol_drink, Taille_tab*sizeof(alcohol_drink));
            Tab_alcohol_drink = add_alcohol_drinks (Tab_alcohol_drink, Taille_Tab_alcohol_drinks, Taille_tab);
            Taille_Tab_alcohol_drinks = Taille_tab;
            puts("Alcool ajoute\n");
            aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);
            menuPrincipal();
            break;
        case 2: 
            
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_alcohol_drink.name);
            Tab_alcohol_drink_Copie = malloc (Taille_tab*sizeof(alcohol_drink));
            Tab_alcohol_drink_Copie = remove_acohol_drinks (Tab_alcohol_drink, Taille_Tab_alcohol_drinks, Taille_tab, x_alcohol_drink);
            Taille_Tab_alcohol_drinks = Taille_tab;
            Tab_alcohol_drink = realloc (Tab_alcohol_drink, Taille_Tab_alcohol_drinks*sizeof(juice));
            Tab_alcohol_drink = Tab_alcohol_drink_Copie;
            free(Tab_alcohol_drink_Copie);
            puts("Alcool supprime\n");
            aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);
            menuPrincipal();
            break;
        case 3: 
            Taille_tab =  TailleTab ();
            TabLiquor = realloc (TabLiquor, Taille_tab*sizeof(liqueur));
            TabLiquor = add_liquors (TabLiquor, Taille_Tab_Liquors, Taille_tab);
            Taille_Tab_Liquors = Taille_tab;
            puts("Liqueur ajoute\n");
            aff_liquor (TabLiquor, Taille_Tab_Liquors);
            menuPrincipal();
            break;
        case 4: 
            
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_liquor.name);
            TabLiquor_Copie = malloc(Taille_tab*sizeof(liqueur));
            TabLiquor_Copie = remove_liquors (TabLiquor, Taille_Tab_Liquors, Taille_tab, x_liquor);
            Taille_Tab_Liquors = Taille_tab;
            TabLiquor = realloc (TabLiquor, Taille_Tab_Liquors*sizeof(liqueur));
            TabLiquor = TabLiquor_Copie;
            free (TabLiquor_Copie);
            puts("Liqueur supprimé\n");
            aff_liquor (TabLiquor_Copie, Taille_Tab_Liquors);
            menuPrincipal();
            break;
        case 5: 
            
            Taille_tab =  TailleTab ();
            TabSquash = realloc (TabSquash, Taille_tab*sizeof(squash));
            TabSquash = add_squashes (TabSquash, Taille_Tab_Squashes, Taille_tab);
            Taille_Tab_Squashes = Taille_tab;
            puts("Sirop ajoute\n");
            aff_Squashes (TabSquash, Taille_Tab_Squashes);
            menuPrincipal();
            break;
        case 6: 
            
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_squash.name);
            TabSquash_Copie = malloc (Taille_tab*sizeof(squash));
            TabSquash_Copie = remove_squash (TabSquash, Taille_Tab_Squashes, Taille_tab, x_squash);
            Taille_Tab_Squashes = Taille_tab;
            TabSquash = realloc (TabSquash, Taille_Tab_Squashes*sizeof(squash));
            TabSquash = TabSquash_Copie;
            free(TabSquash_Copie);
            puts("Sirop supprime\n");
            aff_Squashes (TabSquash, Taille_Tab_Squashes);
            menuPrincipal();
            break;
        case 7: 
            Taille_tab =  TailleTab ();
            TabJuice = realloc (TabJuice, Taille_tab*sizeof(juice));
            TabJuice = add_Juices (TabJuice, Taille_Tab_Juices, Taille_tab);
            Taille_Tab_Juices = Taille_tab;
            puts("Jus ajoute\n");
            aff_juices(TabJuice, Taille_Tab_Juices); 
            menuPrincipal();
            break;
        case 8: 
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_juice.name);
            TabJuice_Copie = malloc (Taille_tab*sizeof(juice));
            TabJuice_Copie = remove_juices (TabJuice, Taille_Tab_Juices, Taille_tab, x_juice);
            Taille_Tab_Juices = Taille_tab;
            TabJuice = realloc (TabJuice, Taille_Tab_Juices*sizeof(juice));
            TabJuice = TabJuice_Copie;
            free(TabJuice_Copie);
            puts("Jus supprime\n");
            aff_juices(TabJuice, Taille_Tab_Juices);
            menuPrincipal();
            break;
        case 9: 
            Taille_tab =  TailleTab ();
            TabSoda = realloc (TabSoda, Taille_tab*sizeof(soda));
            TabSoda = add_sodas (TabSoda, Taille_Tab_Soda, Taille_tab);
            Taille_Tab_Soda = Taille_tab;
            puts("Soda ajoute\n");
            aff_Sodas (TabSoda, Taille_Tab_Soda);
            menuPrincipal();
            break;
        case 10: 
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur a supprimer : \n");
            scanf ("%s", x_soda.name);
            TabSoda_Copie = malloc (Taille_tab*sizeof(soda));
            TabSoda_Copie = remove_soda (TabSoda, Taille_Tab_Soda, Taille_tab, x_soda);
            Taille_Tab_Soda = Taille_tab;
            TabSoda = realloc (TabSoda, Taille_Tab_Soda*sizeof(juice));
            TabSoda = TabSoda_Copie;
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
            Taille_Tab = TailleTab();
            Tab_alcohol_cocktail = realloc (Tab_alcohol_cocktail, Taille_Tab*sizeof(alcohol_cocktail));
            Tab_alcohol_cocktail = add_alcohol_cocktails (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails, Taille_Tab);
            Taille_Tab_alcohol_cocktails = Taille_Tab;
            puts("Cocktail avec alcool ajoute\n");
            aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
            menuPrincipal();
            break;
        case 2: 
            Taille_Tab = TailleTab();
            puts ("Entrer la valeur a supprimer : ");
            scanf ("%s", x_alcohol_cocktail.name);
            Tab_alcohol_cocktail_Copie = malloc (Taille_Tab*sizeof(alcohol_cocktail));
            Tab_alcohol_cocktail_Copie = remove_acohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails, Taille_Tab, x_alcohol_cocktail);
            Taille_Tab_alcohol_cocktails = Taille_Tab;
            Tab_alcohol_cocktail = realloc (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails*sizeof (alcohol_cocktail));
            Tab_alcohol_cocktail = Tab_alcohol_cocktail_Copie;
            free (Tab_alcohol_cocktail_Copie);
            puts("Cocktail avec alcool supprime\n");
            aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
            menuPrincipal();
            break;
        case 3: 
            Taille_Tab = TailleTab();
            Tab_no_alcohol_cocktail = realloc (Tab_no_alcohol_cocktail, Taille_Tab*sizeof(noalcohol_cocktail));
            Tab_no_alcohol_cocktail = add_no_alcohol_cocktails (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails, Taille_Tab);
            Taille_Tab_no_alcohol_cocktails = Taille_Tab;
            puts("Cocktail sans alcool ajoute\n");
            aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails);
            menuPrincipal();
            break;
        case 4: 
            Taille_Tab = TailleTab();
            puts ("Entrer la valeur a supprimer : ");
            scanf ("%s", x_no_alcohol_cocktail.name);
            Tab_no_alcohol_cocktail_Copie = malloc (Taille_Tab*sizeof(noalcohol_cocktail));
            Tab_no_alcohol_cocktail_Copie = remove_no_acohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails, Taille_Tab, x_no_alcohol_cocktail);
            Taille_Tab_no_alcohol_cocktails = Taille_Tab;
            puts("Cocktail sans alcool supprime\n"); 
            Tab_no_alcohol_cocktail = realloc (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails*sizeof (noalcohol_cocktail));
            Tab_no_alcohol_cocktail = Tab_no_alcohol_cocktail_Copie;
            free (Tab_no_alcohol_cocktail_Copie);
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

int main (void){
    menuPrincipal ();
    return 0;
}
