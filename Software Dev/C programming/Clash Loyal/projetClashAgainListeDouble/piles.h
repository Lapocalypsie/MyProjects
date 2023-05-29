#ifndef LISTEDOUBLE_H_INCLUDED
#define LISTEDOUBLE_H_INCLUDED

#include <stdbool.h>
#include "types.h"
#include "utils.h"

typedef struct T_cellzone{
    struct T_cell *suiv;
    struct T_cell *prec;
    Tunite *pdata;              //attention à faire un malloc sur ce champ avant de s'en servir
}T_cellulezone;

typedef T_cellulezone *T_listedouble;

void initListelistedouble(T_listedouble *l);
bool listeVidedouble( T_listedouble l);


// fin de tag ligne 50

//void afficheListeV1( T_listedouble l);
//Pour "AfficheListeV1" Vous avez le droit de lire directement dans la structure de données
//Utile pour afficher et debuguer les fonctions ci-dessous

T_listedouble ajoutEnTete(T_listedouble l, Tunite mydata);//Bien mettre à NULL les champs suiv et prec non utilisés s'il y en a
T_listedouble ajoutEnFin(T_listedouble l, Tunite mydata);
T_listedouble ajoutEnN(T_listedouble l, int pos, Tunite mydata);

T_listedouble suppEnTete(T_listedouble l);
T_listedouble suppEnFin(T_listedouble l);
T_listedouble suppEnN(T_listedouble l, Tunite unite);

T_listedouble getptrFirstCell(T_listedouble l);
T_listedouble getptrLastCelldouble(T_listedouble l);
T_listedouble getptrNextCelldouble(T_listedouble l);
T_listedouble getptrPrevCell(T_listedouble l);

Tunite* getPtrDatadouble(T_listedouble l);
void swapPtrDatadouble( T_listedouble source, T_listedouble destination );

int getNbreCelldouble(T_listedouble l);
int getSizeBytesdouble(T_listedouble l); //utilisation de sizeof

T_listedouble creatNewListeFromFusion(T_listedouble l1, T_listedouble l2); //on souhaite CREER une nouvelle liste sans modifier l1 et l2
T_listedouble addBehind(T_listedouble debut, T_listedouble suite);

T_listedouble findCell(T_listedouble l, Tunite data);
int getOccurences(T_listedouble l, Tunite data);  //nbre de fois que data est présent dans toute la liste l1

void afficheListeV2( T_listedouble l);
//Pour "AfficheListeV2", vous devez utiliser uniquement les fonctions écrites ci-dessus (interdiction de passer directement par les champs ptr de la SD)

/*début de tag ligne 16 */

// étape 2 : tableau

//T_listedouble createnewlist(int a); // je crée une liste avec valeurs aléatoires
//void AfficheTab(int tab[], int taille);
//int* ListtoTab(T_listedouble l, int taille);
//int* ListtoTabfree(T_listedouble l, int taille);
//T_listedouble TabtoList(int tab[], int taille);
//int* TabtoListfree(T_listedouble l, int taille);
//void tri_selection(int *tableau /*ou int tab[]*/, int taille);
//T_listedouble trie_liste_via_tableau(T_listedouble l);

#endif // LISTEDOUBLE_H_INCLUDED

