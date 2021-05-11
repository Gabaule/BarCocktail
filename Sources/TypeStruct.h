#ifndef TYPESTRUCT_H
#define TYPESTRUCT_H

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
    liqueur liquor; //les liqueur
} alcohol_drink;

typedef struct tno_alcohol_drink{  // Structure définissant les boissons non alcoolisées 
    char name[100]; //nom de la boisson sans alcool
    float stock; //stock de boissons non alcoolisées
    juice juices; //les jus de fruits
    soda sodas; //les sodas
    squash squashes; //les sirops
} no_alcohol_drink;

typedef struct talcohol_cocktail{ //Type cocktail avec alcool
    int capacity; //la capacité du contenant
    char name[100]; //le nom du cocktail
    float price; // le prix du cocktail
    float degrees; // le degrés d'alcool contenu dans le cocktail
    no_alcohol_drink no_alcohol; // les boissons non alcoolisées
    alcohol_drink alcohol; // les boissons alcoolisées
} alcohol_cocktail;

typedef struct tno_alcohol_cocktail { //Type cocktail sans alcool
    int capacity; //la capacité du contenant
    char name[100]; // le nom du cocktail
    float price; //le prix du cocktail
    float sugar_level; //La teneur en sucre du cocktail
    no_alcohol_drink no_alcohol; //les boissons nonn alcoolisées
} noalcohol_cocktail;

#endif