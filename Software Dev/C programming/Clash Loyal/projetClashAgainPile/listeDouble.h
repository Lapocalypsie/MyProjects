#ifndef LISTEDOUBLE_H_INCLUDED
#define LISTEDOUBLE_H_INCLUDED

#include <stdbool.h>
#include "types.h"
#include "utils.h"


void initListe(TListePlayer *l);
bool listeVide(TListePlayer l);


// fin de tag ligne 50

void afficheListeV1(TListePlayer l);

TListePlayer getptrLastCell(TListePlayer l);
TListePlayer getptrNextCell(TListePlayer l);

TListePlayer concat_liste(TListePlayer l1, TListePlayer l2);
Tunite* getPtrData(TListePlayer l);
void swapPtrData( TListePlayer source, TListePlayer destination );
Tunite* FindUnite (TListePlayer* player, Tunite a);
void displayListPlayer(TListePlayer player);

int getNbreCell(TListePlayer l);
int getSizeBytes(TListePlayer l); //utilisation de sizeof

#endif // LISTEDOUBLE_H_INCLUDED

