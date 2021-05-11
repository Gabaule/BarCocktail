#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <string.h>
#include "TypeStruct.h"
#include "Allocation.h"
#include "Intitialisation.h"
#include "Ajout_Supression.h"
#include "Menu.h"



int menuPrincipal()
{
    int nombre; 

    puts ("Menu général\n");
    puts ("1 : Initialiser les tableaux\n");
    puts ("2 : Ajouter matières premières\n");
    puts ("3 : Supprimer matières premières\n");
    puts ("4 : Ajouter cocktails\n");
    puts ("5 : Supprimer cocktails\n");
    puts ("6 : Afficher stock\n");
    puts ("7 : Ne pas afficher stock\n");
    puts ("8 : Afficher cocktails\n");
    puts ("9 : Ne pas afficher cocktails\n");

    printf("Entrer un nombre\n");
    scanf("%d",&nombre);

    switch(nombre){
        case 1:
            menuInitialisation ();
        case 2: 
            printf("Matières premières ajoutées\n");
            menuMatieresPremieres();
        break;
        case 3: 
            printf("Matières premières supprimées\n");
            menuMatieresPremieres();
            break;
        case 4: 
            printf("Cocktails ajoutés");
            menuCocktail();
            break;
        case 5: 
            printf("Cocktails supprimés\n");
            break;
        case 6: 
            printf("Affichage du stock\n");
            break;
        case 7: 
            printf("Pas d'affichage du stock\n");
            break;
        case 8: 
            printf("Affichage des cocktails\n");
            break;
        case 9: 
            printf("Pas d'affichage des cocktails\n");
            break;
        default: 
            break;
    }
return nombre; 
}

int menuInitialisation (){
    int n;
    int taille_Tab;
    puts ("Menu d'initialisation \n");
    puts ("1 : initialiser jus de fruits \n");
    puts ("2 : initialiser soda \n");
    puts ("3 : initialiser sirops \n");
    puts ("4 : initialiser liqueur \n");
    puts ("5 : initialiser alcool \n");
    puts ("6 : initialiser boissons sans alcools \n");
    puts ("7 : initialiser cocktails avec alcool \n");
    puts ("8 : initialiser cocktails sans alcool \n");
    puts ("9 : retour au menu principal \n");
    scanf ("%d", &n);
    switch (n)
    {
    case 1:
        puts ("Initialisation des jus de fruits \n");
        taille_Tab = TailleTab ();
        break;
    
    default:
        break;
    }
}
    

int menuMatieresPremieres()
{

    int choix = 0; 

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

            break;
        case 2: 
            printf("Alcool supprimé\n");
            break;
        case 3: 
            printf("Liqueur ajouté\n");
            break;
        case 4: 
            printf("Liqueur supprimé\n");
            break; 
        case 5: 
            printf("Sirop ajouté\n");
            break; 
        case 6: 
            printf("Sirop supprimé\n");
            break; 
        case 7: 
            printf("Jus ajouté\n");
            break; 
        case 8: 
            printf("Jus supprimé\n");
            break;
        case 9: 
            printf("Soda ajouté\n");
            break;
        case 10: 
            printf("Soda supprimé\n");
            break;
        default: 
            printf("Recommencer\n");
            break;
    }
    return choix;
}



int menuCocktail()
{
    int choix2 = 0; 

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
            break;
        case 2: 
            printf("Cocktail avec alcool supprimé\n");
            break;
        case 3: 
            printf("Cocktail sans alcool ajouté\n");
            break;
        case 4: 
            printf("Cocktail sans alcool supprimé\n");
            break; 
        default:
            printf("Recommencer\n");
            break;
    }
    return choix2; 
}