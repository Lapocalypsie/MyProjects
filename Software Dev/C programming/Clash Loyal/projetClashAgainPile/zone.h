#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED
#include <stdbool.h>

///********************* NOUVEAUTE ***************************
#include "piles.h"
///********************* NOUVEAUTE ***************************

typedef pile Tzone;


TListePlayer getAllUnitInZone(Tzone* z);


Tzone creerTzoneVide(void);
Tzone ajouterUnitedansZone(Tzone z, Tunite *u);
Tzone supprimerUnitedansZone(Tzone* z,Tunite *u);
bool UniteEstPresentedansZone(Tzone* z, Tunite *u);
bool UniteAuSolPresente(Tzone* z);
bool UniteEnVolPresente(Tzone* z);
bool estvide_zone(Tzone z) ;
Tzone affichezone(Tzone z);
/*
// et toutes les fonctions qui vous serez utiles sur/avec les Tzone?

... etc

*/

#endif // ZONE_H_INCLUDED
