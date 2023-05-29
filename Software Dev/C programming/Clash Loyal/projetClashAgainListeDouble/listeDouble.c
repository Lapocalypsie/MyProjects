#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "listeDouble.h"
#include "types.h"

void initListe(TListePlayer *l){
*l=NULL;
}


bool listeVide(TListePlayer l){
    return (l==NULL);
};

void afficheListeV1(TListePlayer l){
    TListePlayer courant = l;
    while (courant!=NULL){
        //printf(" %d ",*(courant->pdata));
        printf("valeur: %p \n",*(courant->pdata));
        courant=courant->suiv;
    }
    printf("\n");
};
/*---------------------------------------------------------------------------------------*/

TListePlayer getptrLastCell(TListePlayer l)
{
    TListePlayer courant = l;

    if (listeVide(courant)) {
        //if (DEBUG) printf("Erreur getptrLastCell liste vide");
    }
    else {
        while(courant->suiv != NULL){
            courant=courant->suiv;
        }
    }
    return courant;
};

TListePlayer getptrNextCell(TListePlayer l)
{
    TListePlayer courant = l;

    if (listeVide(courant)) {
        //if (DEBUG) printf("Erreur getptrNextCell liste vide");
    }
    else {
        courant=courant->suiv;
    }
    return courant;
};

Tunite* getPtrData(TListePlayer l)
{
    if (listeVide(l)) {
        //if (DEBUG) printf("Erreur getPtrData liste vide");
        return NULL;  // fera planter le main
    }
    else return l->pdata;  // ptr sur notre entier stocké
};

void swapPtrData( TListePlayer source, TListePlayer destination )
{
    if (listeVide(source)||listeVide(destination)){
            //if (DEBUG) printf("Erreur swapPtrData ptr = NULL");
    }
    else {  //swap
    int* tmp = source->pdata;
    source->pdata = destination->pdata;
    destination->pdata = tmp;
    }
};

void tri_selection_liste(TListePlayer l, bool(*fcomp)(Tunite A, Tunite B))
{
    TListePlayer courant = l, toswap;
    TListePlayer plus_petit;

    while(!listeVide(courant))
    {
        plus_petit = courant;
        toswap = plus_petit;
        while(!(listeVide(toswap)))
        {
            if(fcomp(*(getPtrData(toswap)),*(getPtrData(plus_petit))))
            {
                swapPtrData(toswap,courant);
            }
            toswap = getptrNextCell(toswap);
        }
        courant = getptrNextCell(courant);
    }
}

TListePlayer concat_liste(TListePlayer player1, TListePlayer player2){
    TListePlayer courant2 = player2;

    while(courant2 !=NULL){
        AjouterUnite(&player1, courant2->pdata);
        courant2 = courant2->suiv;
    }
    return player1;
}


Tunite* FindUnite (TListePlayer* player, Tunite a){
    TListePlayer courant = *player;
    while( !comp_egal_AegalB(*courant->pdata, a)){
        courant= courant->suiv;
    }
    return courant->pdata;
}

void displayListPlayer(TListePlayer player){
    while(player != NULL){
        printf("%d %d ", player->pdata->posX, player->pdata->posY);
        printf("\n");
        player=player->suiv;
    }
}

/*---------------------------------------------------------------------------------------*/
