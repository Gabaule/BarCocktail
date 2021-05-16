#ifndef AJOUT_SUPPRESSION_H
#define AJOUT_SUPPRESSION_H


/* Prototype des fonctions d'ajout*/

juice* add_Juices (juice* Tab_Juice, int n, int n2);
squash* add_squashes (squash* Tab_squash, int n, int n2);
liqueur* add_liquors (liqueur* Tab_liquor, int n, int n2);
soda* add_sodas (soda* Tab_soda, int n, int n2);
alcohol_drink* add_alcohol_drinks (alcohol_drink* Tab_alcohol_drink, int n, int n2);
no_alcohol_drink* add_no_alcohol_drinks (no_alcohol_drink* Tab_no_alcohol_drink, int n, int n2);
alcohol_cocktail* add_alcohol_cocktails (alcohol_cocktail* Tab_alcohol_cocktail, int n , int n2);
noalcohol_cocktail* add_no_alcohol_cocktails (noalcohol_cocktail* Tab_no_alcohol_cocktail, int n , int n2);

/*Prototype des fonctions de suppression*/

juice* remove_juices (juice* Tab_Juices,int n2, int n, juice x);
squash* remove_squash (squash* Tab_squash,int n2, int n, squash x);
soda* remove_soda (soda* Tab_soda,int n2, int n, soda x);
liqueur* remove_liquors (liqueur* Tab_liquor, int n2, int n, liqueur x);
no_alcohol_drink* remove_no_acohol_drinks (no_alcohol_drink* Tab_no_alcohol_drink, int n2, int n, no_alcohol_drink x);
alcohol_drink* remove_acohol_drinks (alcohol_drink* Tab_alcohol_drink, int n2, int n, alcohol_drink x);
alcohol_cocktail* remove_acohol_cocktail (alcohol_cocktail* Tab_alcohol_cocktail, int n2, int n, alcohol_cocktail x);
noalcohol_cocktail* remove_no_acohol_cocktail (noalcohol_cocktail* Tab_no_alcohol_cocktail, int n2, int n, noalcohol_cocktail x);

#endif