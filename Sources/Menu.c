#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <string.h>
#include "TypeStruct.h"
#include "Intitialisation.h"
#include "Ajout_Supression.h"
#include "Affichage.h"
#include "Menu.h"

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
no_alcohol_drink* Tab_no_alcohol_drink;
alcohol_cocktail* Tab_alcohol_cocktail;
noalcohol_cocktail* Tab_no_alcohol_cocktail;

void menuPrincipal()
{
    int nombre; 
    puts ("Menu général\n");
    puts ("1 : Initialiser les tableaux\n");
    puts ("2 : Ajouter matières premières et supprimer des matières premières\n");
    puts ("3 : Ajouter cocktails et supprimer cocktails\n");
    puts ("4 : Afficher matières premières et leurs stocks\n");
    puts ("5 : Afficher cocktails\n");

    printf("Entrer un nombre\n");
    scanf("%d",&nombre);

    switch(nombre){
        case 1:
            menuInitialisation ();
        case 2: 
            menuMatieresPremieres();
        break;
        case 3: 
            menuCocktail();
        case 4: 
            menuAffichageMatieres();
        case 5: 
            menuAffichageCocktail();
            printf("Pas d'affichage du stock\n");
        default:
            free (TabJuice);
            free (TabLiquor);
            free (TabSoda);
            free (TabSquash);
            free (Tab_alcohol_drink);
            free (Tab_no_alcohol_drink);
            free (Tab_alcohol_cocktail);
            free (Tab_no_alcohol_cocktail); 
            break;
    }
}

void menuInitialisation(){
    int n;
    int taille_Tab;
    puts ("Menu d'initialisation \n");
    puts ("1 : initialiser jus de fruits \n");
    puts ("2 : initialiser sirops \n");
    puts ("3 : initialiser sodas \n");
    puts ("4 : initialiser liqueur \n");
    puts ("5 : initialiser alcool \n");
    puts ("6 : initialiser boissons sans alcools \n");
    puts ("7 : initialiser cocktails avec alcool \n");
    puts ("8 : initialiser cocktails sans alcool \n");
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
    case 2:
        puts ("Initialisation des sirops \n");
        taille_Tab = TailleTab ();
        Taille_Tab_Squashes = taille_Tab;
        TabSquash = malloc (Taille_Tab_Squashes*sizeof(squash));
        TabSquash = defineTab_Squashes(Taille_Tab_Squashes);
        aff_Squashes (TabSquash, Taille_Tab_Squashes);
    case 3:
        puts ("Initialisation des sodas \n");
        taille_Tab = TailleTab ();
        Taille_Tab_Soda = taille_Tab;
        TabSoda = malloc (Taille_Tab_Soda*sizeof(soda));
        TabSoda = defineTab_Sodas(Taille_Tab_Soda);
        aff_Sodas (TabSoda, Taille_Tab_Soda);
    case 4:
        puts ("Initialisation des liqueurs \n");
        taille_Tab = TailleTab ();
        Taille_Tab_Liquors = taille_Tab;
        TabLiquor = malloc (Taille_Tab_Liquors*sizeof(liqueur));
        TabLiquor = defineTab_Liquor(Taille_Tab_Liquors);
        aff_liquor (TabLiquor, Taille_Tab_Liquors);
    case 5:
        puts ("Initialisation des alcohols \n");
        taille_Tab = TailleTab ();
        Taille_Tab_alcohol_drinks = taille_Tab;
        Tab_alcohol_drink = malloc (Taille_Tab_alcohol_drinks*sizeof(alcohol_drink));
        Tab_alcohol_drink = defineTab_alcohol_drink(Taille_Tab_alcohol_drinks);
        aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);  
    case 6:
        puts ("Initialisation des boissons sans alcools \n");
        taille_Tab = TailleTab ();
        Taille_Tab_no_alcohol_drinks = taille_Tab;
        Tab_no_alcohol_drink = malloc (Taille_Tab_no_alcohol_drinks*sizeof(no_alcohol_drink));
        Tab_no_alcohol_drink = defineTab_no_alcohol_drink(Taille_Tab_no_alcohol_drinks);
        aff_no_alcohol_drink (Tab_no_alcohol_drink, Taille_Tab_alcohol_drinks);
    case 7:
        puts ("Initialisation des cocktails avec alcool \n");
        taille_Tab = TailleTab ();
        Taille_Tab_alcohol_cocktails = taille_Tab;
        Tab_alcohol_cocktail = malloc (Taille_Tab_alcohol_cocktails*sizeof(alcohol_cocktail));
        Tab_alcohol_cocktail = defineTab_alcohol_cokctail(Taille_Tab_alcohol_cocktails);
        aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
    case 8:
        puts ("Initialisation des cocktails sans alcool \n");
        taille_Tab = TailleTab ();
        Taille_Tab_no_alcohol_cocktails = taille_Tab;
        Tab_no_alcohol_cocktail = malloc (Taille_Tab_no_alcohol_cocktails*sizeof(noalcohol_cocktail));
        Tab_no_alcohol_cocktail = defineTab_no_alcohol_cokctail(Taille_Tab_no_alcohol_cocktails);
        aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails);
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
    printf("Menu des matières premières\n");
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
            printf("Alcool ajouté\n");
            Taille_tab =  TailleTab ();
            Tab_alcohol_drink = realloc (Tab_alcohol_drink, Taille_tab*sizeof(alcohol_drink));
            Tab_alcohol_drink = add_alcohol_drinks (Tab_alcohol_drink, Taille_Tab_alcohol_drinks, Taille_tab);
            Taille_Tab_alcohol_drinks = Taille_tab;
            aff_alcohol_drink (Tab_alcohol_drink, Taille_Tab_alcohol_drinks);
        case 2: 
            printf("Alcool supprimé\n");
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur à supprimer : \n");
            scanf ("%s", x_alcohol_drink.name);
            Tab_alcohol_drink_Copie = malloc (Taille_tab*sizeof(alcohol_drink));
            Tab_alcohol_drink_Copie = remove_acohol_drinks (Tab_alcohol_drink, Taille_Tab_alcohol_drinks, Taille_tab, x_alcohol_drink);
            Taille_Tab_alcohol_drinks = Taille_tab;
            aff_alcohol_drink (Tab_alcohol_drink_Copie, Taille_Tab_alcohol_drinks);
        case 3: 
            printf("Liqueur ajouté\n");
            Taille_tab =  TailleTab ();
            TabLiquor = realloc (TabLiquor, Taille_tab*sizeof(liqueur));
            TabLiquor = add_liquors (TabLiquor, Taille_Tab_Liquors, Taille_tab);
            Taille_Tab_Liquors = Taille_tab;
            aff_liquor (TabLiquor, Taille_Tab_Liquors);
        case 4: 
            printf("Liqueur supprimé\n");
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur à supprimer : \n");
            scanf ("%s", x_liquor.name);
            TabLiquor_Copie = malloc(Taille_tab*sizeof(liqueur));
            TabLiquor_Copie = remove_liquors (TabLiquor, Taille_Tab_Liquors, Taille_tab, x_liquor);
            Taille_Tab_Liquors = Taille_tab;
            aff_liquor (TabLiquor_Copie, Taille_Tab_Liquors);
        case 5: 
            printf("Sirop ajouté\n");
            Taille_tab =  TailleTab ();
            TabSquash = realloc (TabSquash, Taille_tab*sizeof(squash));
            TabSquash = add_squashes (TabSquash, Taille_Tab_Squashes, Taille_tab);
            Taille_Tab_Squashes = Taille_tab;
            aff_Squashes (TabSquash, Taille_Tab_Squashes);
        case 6: 
            printf("Sirop supprimé\n");
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur à supprimer : \n");
            scanf ("%s", x_squash.name);
            TabSquash_Copie = malloc (Taille_tab*sizeof(squash));
            TabSquash_Copie = remove_squash (TabSquash, Taille_Tab_Squashes, Taille_tab, x_squash);
            Taille_Tab_Squashes = Taille_tab;
            aff_Squashes (TabSquash_Copie, Taille_Tab_Squashes);
        case 7: 
            printf("Jus ajouté\n");
            Taille_tab =  TailleTab ();
            TabJuice = realloc (TabJuice, Taille_tab*sizeof(juice));
            TabJuice = add_Juices (TabJuice, Taille_Tab_Juices, Taille_tab);
            Taille_Tab_Juices = Taille_tab;
            aff_juices(TabJuice, Taille_Tab_Juices); 
        case 8: 
            printf("Jus supprimé\n");
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur à supprimer : \n");
            scanf ("%s", x_juice.name);
            TabJuice_Copie = malloc (Taille_tab*sizeof(juice));
            TabJuice_Copie = remove_juices (TabJuice, Taille_Tab_Juices, Taille_tab, x_juice);
            Taille_Tab_Juices = Taille_tab;
            aff_juices(TabJuice_Copie, Taille_Tab_Juices);
        case 9: 
            printf("Soda ajouté\n");
            Taille_tab =  TailleTab ();
            TabSoda = realloc (TabSoda, Taille_tab*sizeof(soda));
            TabSoda = add_sodas (TabSoda, Taille_Tab_Soda, Taille_tab);
            Taille_Tab_Soda = Taille_tab;
            aff_Sodas (TabSoda, Taille_Tab_Soda);
        case 10: 
            printf("Soda supprimé\n");
            Taille_tab =  TailleTab ();
            puts ("Entrer la valeur à supprimer : \n");
            scanf ("%s", x_soda.name);
            TabSoda_Copie = malloc (Taille_tab*sizeof(soda));
            TabSoda_Copie = remove_soda (TabSoda, Taille_Tab_Soda, Taille_tab, x_soda);
            Taille_Tab_Soda = Taille_tab;
            aff_Sodas (TabSoda, Taille_Tab_Soda);
        default: 
            puts("Retour au menu principal\n");
            menuPrincipal();
            free(Tab_alcohol_drink_Copie);
            free(TabJuice_Copie);
            free(TabLiquor_Copie);
            free (TabSquash_Copie);
            free(TabSoda_Copie);
    }
    return choix;
}



void menuCocktail()
{
    int choix2 = 0;
    int Taille_Tab;
    noalcohol_cocktail x_no_alcohol_cocktail;
    alcohol_cocktail x_alcohol_cocktail;
    noalcohol_cocktail* Tab_no_alcohol_cocktail_Copie;
    alcohol_cocktail* Tab_alcohol_cocktail_Copie;

    printf("Menu des cocktails\n");
    printf("1 : Ajouter cocktail avec alcool\n");
    printf("2 : Supprimer cocktail avec alcool\n");
    printf("3 : Ajouter cocktail sans alcool\n");
    printf("4 : Supprimer cocktail sans alcool\n");

    printf("Faire votre choix\n\n");
    scanf("%d", &choix2);

    switch(choix2){
        case 1: 
            printf("Cocktail avec alcool ajouté\n");
            Taille_Tab = TailleTab();
            Tab_alcohol_cocktail = realloc (Tab_alcohol_cocktail, Taille_Tab*sizeof(alcohol_cocktail));
            Tab_alcohol_cocktail = add_alcohol_cocktails (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails, Taille_Tab);
            Taille_Tab_alcohol_cocktails = Taille_Tab;
            aff_alcohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails);
        case 2: 
            printf("Cocktail avec alcool supprimé\n");
            Taille_Tab = TailleTab();
            puts ("Entrer la valeur a supprimer : ");
            scanf ("%s", x_alcohol_cocktail.name);
            Tab_alcohol_cocktail_Copie = malloc (Taille_Tab*sizeof(alcohol_cocktail));
            Tab_alcohol_cocktail_Copie = remove_acohol_cocktail (Tab_alcohol_cocktail, Taille_Tab_alcohol_cocktails, Taille_Tab, x_alcohol_cocktail);
            Taille_Tab_alcohol_cocktails = Taille_Tab;
            aff_alcohol_cocktail (Tab_alcohol_cocktail_Copie, Taille_Tab_alcohol_cocktails);
        case 3: 
            printf("Cocktail sans alcool ajouté\n");
            Taille_Tab = TailleTab();
            Tab_no_alcohol_cocktail = realloc (Tab_no_alcohol_cocktail, Taille_Tab*sizeof(noalcohol_cocktail));
            Tab_no_alcohol_cocktail = add_no_alcohol_cocktails (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails, Taille_Tab);
            Taille_Tab_no_alcohol_cocktails = Taille_Tab;
            aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails);
        case 4: 
            printf("Cocktail sans alcool supprimé\n");
            Taille_Tab = TailleTab();
            puts ("Entrer la valeur a supprimer : ");
            scanf ("%s", x_no_alcohol_cocktail.name);
            Tab_no_alcohol_cocktail_Copie = malloc (Taille_Tab*sizeof(noalcohol_cocktail));
            Tab_no_alcohol_cocktail_Copie = remove_no_acohol_cocktail (Tab_no_alcohol_cocktail, Taille_Tab_no_alcohol_cocktails, Taille_Tab, x_no_alcohol_cocktail);
            Taille_Tab_no_alcohol_cocktails = Taille_Tab; 
            aff_no_alcohol_cocktail (Tab_no_alcohol_cocktail_Copie, Taille_Tab_no_alcohol_cocktails);
        default:
            printf("Retour au menu principal\n");
            menuPrincipal();
    }
}