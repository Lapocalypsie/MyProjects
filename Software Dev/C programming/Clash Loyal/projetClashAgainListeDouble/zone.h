#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED
#include <stdbool.h>

///********************* NOUVEAUTE ***************************
#include "piles.h"
///********************* NOUVEAUTE ***************************

typedef T_listedouble Tzone;


TListePlayer getAllUnitInZone(T_listedouble* z);

Tzone ajouterUnitedansZone(Tzone z, Tunite *u);
T_listedouble creerTzoneVide(void);
T_listedouble supprimerUnitedansZone(T_listedouble* z,Tunite *u);
Tzone ajouterUnitedansZone(Tzone z, Tunite *u);
bool UniteEstPresentedansZone(T_listedouble* z, Tunite *u);
bool UniteAuSolPresente(T_listedouble* z);
bool UniteEnVolPresente(T_listedouble* z);
bool estvide_zone(T_listedouble z);
void affichezone(Tzone z );
Tunite *tetezone(Tzone z);
/*
// et toutes les fonctions qui vous serez utiles sur/avec les Tzone?

... etc

*/

#endif // ZONE_H_INCLUDED
