#ifndef AFFICHAGE_H
#define AFFICHAGE_H

/* Prototype des fonctions de sauvegarde */

/* Prototypes de fonctions de récupérations dans un fichier */

juice* Recup_Jus (int n, juice* Tab_Juice);
squash* Recup_Sirops (int n, squash* Tab_Sirops);
soda* Recup_Soda (int n, soda* Tab_Soda);
alcohol_drink* Recup_alcool (int n, alcohol_drink* Tab_alcohol_drink);
alcohol_cocktail* Recup_alcool_cocktail (int n, alcohol_cocktail* Tab_alcohol_cocktail);
noalcohol_cocktail* Recup_no_alcool_cocktail (int n, noalcohol_cocktail* Tab_no_alcohol_cocktail);

#endif