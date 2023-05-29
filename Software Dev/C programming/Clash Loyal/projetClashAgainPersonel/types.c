#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "types.h"

// Fonctions de comparaisons
//-------------------------------------------------------------------
bool comp_egal_AegalB (Tunite a, Tunite b){
    return (a.nom == b.nom)&&(a.cibleAttaquable == b.cibleAttaquable)
       && (a.coutEnElixir == b.coutEnElixir) && (a.degats == b.degats)
       && (a.maposition == b.maposition) && (a.peutAttaquer == b.peutAttaquer)
       && (a.pointsDeVie == b.pointsDeVie) && (a.portee == b.portee)
       && (a.posX == b.posX) && (a.posY == b.posY) && (a.vitesseAttaque == b.vitesseAttaque)
       && (a.vitessedeplacement == b.vitessedeplacement)
       &&(a.couleur == b.couleur);
}

bool comp_vitesse_asupb(Tunite a, Tunite b){
    return(a.vitesseAttaque >= b.vitesseAttaque);
}

bool comp_vie_ainfb(Tunite a, Tunite b){
    return(a.pointsDeVie < b.pointsDeVie);
}

bool comp_couleur_rouge(Tunite a, Tunite b){
    return(a.couleur == rouge && b.couleur != rouge);
}

bool comp_couleur_bleu(Tunite a, Tunite b){
    return(a.couleur == bleu && b.couleur != bleu);
}

Tcible maposition(Tunite a){
    return a.maposition;
}

bool fcompare( Tunite p1, Tunite p2, bool (*fcomp)(Tunite a, Tunite b)){
    return (fcomp( p1, p2) );
}


//Fonction de traitement de listeplayer
/*---------------------------------------------------------------------------------------*/

void initListe(TListePlayer *l){
*l=NULL;
}


bool listeVide(TListePlayer l){
    return (l==NULL);
};


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
}

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

void tri_selection_liste(TListePlayer l, bool(*fcomp)(Tunite a, Tunite b))
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


Tunite* FindUnite (TListePlayer *player, Tunite a){
    TListePlayer courant = *player;
    while( !comp_egal_AegalB(*courant->pdata, a)){
        courant= courant->suiv;
    }
    return courant->pdata;
}

void afficheUnite(Tunite c){
    printf("\n Positions sont : %d %d, nombre de points de vies : %d \n", c.posX,c.posY, c.pointsDeVie);
}

int getPosX(TListePlayer c){
    return c->pdata -> posX;
}

int getPosY(TListePlayer c){
    return c->pdata -> posY;
}

int getPosUX(Tunite c){
    return c.posX;
}

int getPosUY(Tunite c){
    return c.posY;
}
int getName(TListePlayer c){
    return c->pdata -> nom;
}

int getColor(TListePlayer c){
    return c-> pdata -> couleur;
}

int getLifepoint(TListePlayer c){
    return c->pdata->pointsDeVie;
}

int getLifepointU(Tunite c){
    return c.pointsDeVie;
}
int getattack(TListePlayer c){
    return c->pdata->peutAttaquer;
}

float getvitesseattaque(Tunite c){
 return c.vitesseAttaque;
 }

 int getdegats(Tunite c){
    return c.degats;
 }
