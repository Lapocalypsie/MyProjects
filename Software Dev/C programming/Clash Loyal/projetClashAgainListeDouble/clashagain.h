#ifndef CLASHAGAIN_H_INCLUDED
#define CLASHAGAIN_H_INCLUDED

#define LARGEURJEU 11
#define HAUTEURJEU 19

///********************* NOUVEAUTE ***************************
#include "zone.h"
#include "types.h"


typedef Tunite* ** TplateauJeu; //le plateau du jeu pour l'affichage (reprise du systreme du projet clashLoyal)
typedef T_listedouble ** TplateauJeuUpgrade;  ////tableau a deux dimensions de largeur 11 et hauteur 19 contenant des Tzone

TPlayer initPlayer(Tcouleur couleur);

///********************* fin NOUVEAUTE ***************************


TplateauJeuUpgrade AlloueTab2D_Tzone(int largeur, int hauteur);  //fourni dans clashagain.c
TplateauJeu AlloueTab2D(int largeur, int hauteur);
void initPlateauAvecNULL(TplateauJeu jeu,int largeur, int hauteur);
void affichePlateauConsole(TplateauJeu jeu, int largeur, int hauteur);
void initPlateauTzoneAvecNULL(TplateauJeuUpgrade jeu,int largeur, int hauteur);


Tunite *creeTour(int posx, int posy, Tcouleur couleur);
Tunite *creeTourRoi(int posx, int posy, Tcouleur couleur);


///********************* NOUVEAUTE ***************************
//void PositionnePlayerOnPlateau(TListePlayer player, TplateauJeu jeu)  //AVANT
//DEVIENT :

void PositionnePlayerOnPlateau_Upgade(TListePlayer player, TplateauJeuUpgrade jeuUpgrade);
TplateauJeu ConversionEnTplateauJeu(TplateauJeuUpgrade jeuEncours);

TListePlayer PlayerInZone(Tunite unite, TplateauJeuUpgrade JeuUpgrade);
TListePlayer sortplayerbycolorblue(TListePlayer allplayer);
TListePlayer sortplayerbycolorred(TListePlayer allplayer);
void sortplayerbyatspeed(TListePlayer allplayer);
void sortplayeratlife(TListePlayer allplayer);
bool APortee(Tunite a, Tunite b);
void MinusLife(Tunite *player1, Tunite *player2);
void supprimerUniteDeListe(TListePlayer *player1, TListePlayer *player2);
void Abletoattack(TListePlayer player1, TListePlayer player2);
void finalcombat(TListePlayer *player, TListePlayer *player2,  TplateauJeuUpgrade jeuUpgrade);
///********************* fin NOUVEAUTE ***************************


int tourRoiDetruite(TListePlayer player);
Tunite *creeArcher(int posx, int posy, Tcouleur couleur);
Tunite *creeGargouille(int posx, int posy, Tcouleur couleur);
Tunite *creeDragon(int posx, int posy, Tcouleur couleur);
Tunite *creeChevalier(int posx, int posy, Tcouleur couleur);

void supprimerUnite(TListePlayer *player, Tunite *UniteDetruite);
void AjouterUnite(TListePlayer *player, Tunite *nouvelleUnite);
int random_x();
int PosTourRoi(TListePlayer player) ;

void movep2(TListePlayer player, TListePlayer player2, TplateauJeu jeu);
void movep(TListePlayer player, TListePlayer player2, TplateauJeu jeu);
bool isunity(TListePlayer player2, int x, int y);
void displayListPlayer(TListePlayer player);
///********************* NOUVEAUTE ***************************
int AcheteUnite(TListePlayer *player, int elixir);  //achete une unité et la rajoute dans la liste des unités de player
// Attention remarquer bien l'utilisation du type Tplayer
///********************* fin NOUVEAUTE ***************************


#endif // CLASHAGAIN_H_INCLUDED
