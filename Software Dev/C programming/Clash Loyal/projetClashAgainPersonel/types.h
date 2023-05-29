#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED
#include <stdbool.h>
#include "utils.h"


typedef enum{tour, tourRoi, archer, chevalier, dragon, gargouille} TuniteDuJeu;
typedef enum{sol, solEtAir, air } Tcible;
typedef enum{bleu, rouge} Tcouleur;

typedef struct {
    TuniteDuJeu nom;
    Tcible cibleAttaquable;	//indique la position des unités que l’on peut attaquer
    Tcible maposition;		//indique soit « air » soit « sol », utile pour savoir
                            //qui peut nous attaquer
    int pointsDeVie;
    float vitesseAttaque;	//en seconde, plus c’est petit plus c’est rapide
    int degats;
    int portee ;			//en mètre, distance sur laquelle on peut atteindre une
                            //cible

    float vitessedeplacement;	//en m/s
    int posX, posY;			//position sur le plateau de jeu
    int peutAttaquer;		//permet de gérer le fait que chaque unité attaque une
                            //seule fois par tour ;
                            //0 = a déjà attaqué, 1 = peut attaquer ce tour-ci
                            // à remettre à 1 au début de chaque tour
    int coutEnElixir;
    Tcouleur couleur;
} Tunite;

typedef struct T_cell{
    struct T_cell *suiv;
    Tunite *pdata; //pointeur vers une unité
} *TListePlayer;


///********************* NOUVEAUTE ***************************


typedef struct {
    TListePlayer listeU;  //la liste des unités du joueur
    int elixir;
    Tcouleur couleurJoueur;
} TPlayer;

///********************* fin NOUVEAUTE ***************************

bool comp_egal_AegalB (Tunite a, Tunite b);
bool comp_vitesse_asupb(Tunite a, Tunite b);
bool comp_vie_ainfb(Tunite a, Tunite b);
bool comp_couleur_rouge(Tunite a, Tunite b);
bool comp_couleur_bleu(Tunite a, Tunite b);
Tcible maposition(Tunite a);
bool fcompare( Tunite p1, Tunite p2, bool(*fcomp)(Tunite a, Tunite b));

void initListe(TListePlayer *l);
bool listeVide(TListePlayer l);

TListePlayer getptrLastCell(TListePlayer l);
TListePlayer getptrNextCell(TListePlayer l);
Tunite* getPtrData(TListePlayer l);
void swapPtrData( TListePlayer source, TListePlayer destination );

void tri_selection_liste(TListePlayer l, bool(*fcomp)(Tunite a, Tunite b));
TListePlayer concat_liste(TListePlayer l1, TListePlayer l2);
Tunite* FindUnite (TListePlayer* player, Tunite a);

void afficheUnite(Tunite c);
int getPosX(TListePlayer c);
int getPosY(TListePlayer c);
int getPosUX(Tunite c);
int getPosUY(Tunite c);
int getColor(TListePlayer c);
int getLifepoint(TListePlayer c);
int getLifepointU(Tunite c);
int getattack(TListePlayer c);
float getvitesseattaque(Tunite c);
int getdegats(Tunite c);



#endif // TYPES_H_INCLUDED
