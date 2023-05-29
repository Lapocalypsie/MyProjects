#include "SDL.h"
#include "clashagain.h"
#include <stdio.h>
#include <stdlib.h>

///********************* NOUVEAUTE ***************************
#include "zone.h"
#include "types.h"
///********************* NOUVEAUTE ***************************

//types utilisés:
typedef Tunite* ** TplateauJeu;
typedef Tzone ** TplateauUpgrade;


void PositionnePlayerOnPlateau_Upgade(TListePlayer player, TplateauJeuUpgrade jeuUpgrade){
    // A VOUS DE L ECRIRE
    TListePlayer courant = player;
    int x, y;
    while(!listeVide(courant)){
        x = getPosX(courant);
        y = getPosY(courant);
        jeuUpgrade[x][y] = ajouterUnitedansZone(jeuUpgrade[x][y], getPtrData(courant));
        courant = getptrNextCell(courant);
    }
}

TplateauJeu ConversionEnTplateauJeu(TplateauJeuUpgrade jeuEncours){
    // A VOUS DE L ECRIRE
    TplateauJeu copy = AlloueTab2D(LARGEURJEU,HAUTEURJEU);
    initPlateauAvecNULL(copy,LARGEURJEU,HAUTEURJEU);

    for(int i =0; i <LARGEURJEU; i++){
        for(int j=0; j<HAUTEURJEU; j++){
            if(!estvide_zone(jeuEncours[i][j]) && copy[i][j] == NULL){
                copy[i][j] = tetezone(jeuEncours[i][j]);
                //printf("test conversion : ajout unite sur plateau  i: %d j: %d \n", i,j);
            }else{
                copy[i][j] = NULL;
            }
        }
    }
//    for(int i =0; i <LARGEURJEU; i++){
//        for(int j=0; j<HAUTEURJEU; j++){
//                if(copy[i][j] != NULL){
//                    printf("Les positions du joueurs sont : %d %d \n", copy[i][j]->posX, copy[i][j]->posY);
//        }
//        }
//    }
    return copy;
}

TPlayer initPlayer(Tcouleur couleur){
    TPlayer p;
    //A VOUS DE COMPLETER
    p.couleurJoueur = couleur;
    p.elixir = 4;
    p.listeU = NULL;
    return p;
}

TplateauJeuUpgrade AlloueTab2D_Tzone(int largeur, int hauteur){
    TplateauJeuUpgrade jeu;
    jeu = (Tzone**)malloc(sizeof(Tzone*)*largeur);
    for (int i=0;i<largeur;i++){
        jeu[i] = (Tzone*)malloc(sizeof(Tzone)*hauteur);
    }
    return jeu;  //tab2D contenant des pointeurs
}


TplateauJeu AlloueTab2D(int largeur, int hauteur){
    TplateauJeu jeu;
    jeu = (Tunite***)malloc(sizeof(Tunite**)*largeur);
    for (int i=0;i<largeur;i++){
        jeu[i] = (Tunite**)malloc(sizeof(Tunite*)*hauteur);
    }
    return jeu;  //tab2D contenant des pointeurs
}
void initPlateauTzoneAvecNULL(TplateauJeuUpgrade jeu,int largeur, int hauteur){
    for (int i=0;i<largeur;i++){
        for (int j=0;j<hauteur;j++){
            jeu[i][j] = creerTzoneVide();
        }
    }
}
void initPlateauAvecNULL(TplateauJeu jeu,int largeur, int hauteur){
    for (int i=0;i<largeur;i++){
        for (int j=0;j<hauteur;j++){
            jeu[i][j] = NULL;
        }
    }

    //POUR LA DEMO D'AFFICHAGE UNIQUEMENT, A SUPPRIMER
    //(les tours ici ne sont pas liées aux listes des unités de vos joueurs)
//    jeu[5][3]=creeTour(5,3);
//    jeu[5][1]=creeTourRoi(5,1);
//    jeu[5][15]=creeTour(5,15);
//    jeu[5][17]=creeTourRoi(5,17);
    //FIN DEMO AFFICHAGE
}

void affichePlateauConsole(TplateauJeu jeu, int largeur, int hauteur){
    //pour un affichage sur la console, en relation avec enum TuniteDuJeu
    const char* InitialeUnite[6]={"T", "R", "A", "C", "D", "G"};

    printf("\n");
    for (int j=0;j<hauteur;j++){
        for (int i=0;i<largeur;i++){
                // A ne pas donner aux etudiants
            if (jeu[i][j] != NULL){
                    printf("%s",InitialeUnite[jeu[i][j]->nom]);
            }
            else printf(" ");  //cad pas d'unité sur cette case
        }
        printf("\n");
    }
}

Tunite *creeTour(int posx, int posy, Tcouleur couleur){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    nouv->nom = tour;
    nouv->cibleAttaquable = solEtAir;
    nouv->maposition = sol;
    nouv->pointsDeVie = 50;
    nouv->vitesseAttaque = 0.5;
    nouv->degats = 100;
    nouv->portee = 3;
    nouv->vitessedeplacement = 0;
    nouv->posX = posx;
    nouv->posY = posy;
    nouv->peutAttaquer = 1;
    nouv->coutEnElixir = 0;
    nouv->couleur = couleur;
    return nouv;
}
Tunite *creeTourRoi(int posx, int posy, Tcouleur couleur){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    nouv->nom = tourRoi;
    nouv->cibleAttaquable = solEtAir;
    nouv->maposition = sol;
    nouv->pointsDeVie = 80;
    nouv->vitesseAttaque = 0.5;
    nouv->degats = 120;
    nouv->portee = 4;
    nouv->vitessedeplacement = 0;
    nouv->posX = posx;
    nouv->posY = posy;
    nouv->peutAttaquer = 1;
    nouv->coutEnElixir = 0;
    nouv->couleur = couleur;
    return nouv;
}

Tunite *creeArcher(int posx, int posy, Tcouleur couleur){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    nouv->nom = archer;
    nouv->cibleAttaquable = solEtAir;
    nouv->maposition = sol;
    nouv->pointsDeVie = 80;
    nouv->vitesseAttaque = 0.7;
    nouv->degats = 1200;
    nouv->portee = 3;
    nouv->vitessedeplacement = 1.0;
    nouv->posX = posx;
    nouv->posY = posy;
    nouv->peutAttaquer = 1;
    nouv->coutEnElixir = 2;
    nouv->couleur = couleur;
    return nouv;
}

Tunite *creeGargouille(int posx, int posy, Tcouleur couleur){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    nouv->nom = gargouille;
    nouv->cibleAttaquable = solEtAir;
    nouv->maposition = air;
    nouv->pointsDeVie = 80;
    nouv->vitesseAttaque = 0.6;
    nouv->degats = 90;
    nouv->portee = 1;
    nouv->vitessedeplacement = 3.0;
    nouv->posX = posx;
    nouv->posY = posy;
    nouv->peutAttaquer = 1;
    nouv->coutEnElixir = 1;
    nouv->couleur = couleur;
    return nouv;
}

Tunite *creeDragon(int posx, int posy, Tcouleur couleur){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    nouv->nom = dragon;
    nouv->cibleAttaquable = solEtAir;
    nouv->maposition = air;
    nouv->pointsDeVie = 200;
    nouv->vitesseAttaque = 1.1;
    nouv->degats = 70;
    nouv->portee = 2;
    nouv->vitessedeplacement = 2.0;
    nouv->posX = posx;
    nouv->posY = posy;
    nouv->peutAttaquer = 1;
    nouv->coutEnElixir = 3;
    nouv->couleur = couleur;
    return nouv;
}
Tunite *creeChevalier(int posx, int posy, Tcouleur couleur){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    nouv->nom = chevalier;
    nouv->cibleAttaquable = sol;
    nouv->maposition = sol;
    nouv->pointsDeVie = 40;
    nouv->vitesseAttaque = 1.5;
    nouv->degats = 250;
    nouv->portee = 1;
    nouv->vitessedeplacement = 2.0;
    nouv->posX = posx;
    nouv->posY = posy;
    nouv->peutAttaquer = 1;
    nouv->coutEnElixir = 4;
    nouv->couleur = couleur;
    return nouv;
}


int tourRoiDetruite(TListePlayer player){
    TListePlayer current = player;
    int check = 0;
    while(!listeVide(current)){
        if(getName(current) == 1){
            check = 1;
            break;
        }else current = getptrNextCell(current);
    }
    return check;
}

void AjouterUnite(TListePlayer *player, Tunite *nouvelleUnite){
    struct T_cell *newp = malloc(sizeof(struct T_cell));
    if (listeVide(*player))
    {
        newp->suiv =NULL;
        newp ->pdata = nouvelleUnite;
        *player = newp;
        //printf("ajout d'une unité \n");
    }
    else
    {   newp -> suiv = *player;
        newp -> pdata = nouvelleUnite;
        *player = newp;
        //printf("ajout d'une unité \n");
    }
}

void supprimerUnite(TListePlayer *player, Tunite *UniteDetruite) {
    struct T_cell *adetruire = NULL;
    struct T_cell *tmp = *player;

    if(!listeVide(tmp)){
      if( getPtrData(tmp) == UniteDetruite){
        adetruire = tmp;
        tmp = getptrNextCell(tmp);
        free(getPtrData(adetruire));
        free(adetruire);
        *player = tmp;
     } else {
        while(getPtrData(getptrNextCell(tmp)) != UniteDetruite){
            tmp = getptrNextCell(tmp);
        }
        adetruire = getptrNextCell(tmp);
        tmp -> suiv = tmp -> suiv -> suiv;
        free(getPtrData(adetruire));
        free(adetruire);
    }
  }
}

int random_x(){
    int a = rand()%8;
    switch(a){
        case 0 : return  1;
        break;
        case 1 : return 2;
        break;
        case 2 : return 3;
        break;
        case 3: return 4;
        break ;
        case 4: return 6;
        break;
        case 5 : return 7;
        break;
        case 6 : return 8;
        break;
        case 7 : return 9;
    }
}
int PosTourRoi(TListePlayer player) {
    TListePlayer tmp = player;
    while(getName(tmp)!= tourRoi){
        tmp = getptrNextCell(tmp);
    }
    int posY = getPosY(tmp);
    return posY;
}

int AcheteUnite(TListePlayer *player, int elixir){
    int elexircost1, posplayer = PosTourRoi(*player);
    int randplay = rand()%2, randtroop1 = rand()%4;

    switch(randtroop1){
        case 1 : elexircost1 = 4 ;
        break; // on attribue la valeur de l'elexir du chevalier a elexirPlayer1
        case 2 : elexircost1 = 2 ; // on attribue la valeur de l'elexir de l'archer a elexirPlayer1
        break;
        case 3 : elexircost1 = 3 ; // on attribue la valeur de l'elexir du dragon a elexirPlayer1
        break;
        default : elexircost1 = 1 ; // on attribue la valeur de l'elexir du gargouille a elexirPlayer1
    }
    if(randplay == 1 && elixir >= elexircost1){
        if (posplayer == 1){
            switch(elexircost1){
                case 4 :  AjouterUnite(player, creeChevalier(random_x(),3, rouge));
                break; // on attribue la valeur de l'elexir du chevalier a elexirPlayer1
                case 2 : AjouterUnite(player,creeArcher(random_x(),3, rouge));  // on attribue la valeur de l'elexir de l'archer a elexirPlayer1
                break;
                case 3 : AjouterUnite(player,creeDragon(random_x(),3, rouge)); // on attribue la valeur de l'elexir du dragon a elexirPlayer1
                break;
                default : AjouterUnite(player,creeGargouille(random_x(),3, rouge)) ; // on attribue la valeur de l'elexir du gargouille a elexirPlayer1
            } elixir = elixir - elexircost1;
        } else{
            switch(elexircost1){
                case 4 : AjouterUnite(player, creeChevalier(random_x(),15, bleu));
                break; // on attribue la valeur de l'elexir du chevalier a elexirPlayer1
                case 2 : AjouterUnite(player,creeArcher(random_x(),15, bleu));  // on attribue la valeur de l'elexir de l'archer a elexirPlayer1
                break;
                case 3 : AjouterUnite(player, creeDragon(random_x(),15, bleu)); // on attribue la valeur de l'elexir du dragon a elexirPlayer1
                break;
                default: AjouterUnite(player,creeGargouille(random_x(),15, bleu)) ; // on attribue la valeur de l'elexir du gargouille a elexirPlayer1
            }
            elixir = elixir - elexircost1;
        }
    }
    return elixir;

}

TListePlayer PlayerInZone(Tunite unite, TplateauJeuUpgrade JeuUpgrade){

    int posX = getPosUX(unite), posY = getPosUY(unite);
    TListePlayer finallist = getAllUnitInZone(&JeuUpgrade[posX][posY]);
    TListePlayer liste1,liste2,liste3,liste4;
    initListe(&liste1);initListe(&liste2);initListe(&liste3);initListe(&liste4);

    for(int i= 0; i<5; i++){
        for(int j = 0; j<4; j++){
            if((i ==0 && j == 0)){
                    ;
            }else {
                if( (posX-i)>=0 && (posX + i)<LARGEURJEU && (posY-j)>=0 && (posY+j)<HAUTEURJEU){
                liste1 = concat_liste(liste1, getAllUnitInZone(&JeuUpgrade[posX+i][posY+j]));
                liste2 = concat_liste(liste2, getAllUnitInZone(&JeuUpgrade[posX-i][posY-j]));
                }
            }
        }
    }
    for(int i = 1; i<=4; i++){
        for(int j=1; j<=4; j++){
            if( (posX-i)>=1 && (posX + i)<LARGEURJEU && (posY-j)>=1 && (posY+j)<HAUTEURJEU){
                liste3 = concat_liste(liste3, getAllUnitInZone(&JeuUpgrade[posX-i][posY+j]));
                liste4 = concat_liste(liste4, getAllUnitInZone(&JeuUpgrade[posX+i][posY-j]));
            }
        }
    }

    liste2 = concat_liste(liste2,liste1);
    liste3 = concat_liste(liste3,liste2);
    liste4 = concat_liste(liste4, liste3);
    finallist = concat_liste(finallist,liste4);
    printf("Tplayerinzone : On display allplayer apres le concat \n");
    displayListPlayer(finallist);
    return finallist;
}

TListePlayer sortplayerbycolorblue(TListePlayer allplayer){
    TListePlayer bleu;
    initListe(&bleu);
    bleu = allplayer;
    tri_selection_liste(bleu, comp_couleur_bleu);

    TListePlayer finale;
    initListe(&finale);

    while(!(listeVide(bleu))){
        if (getColor(bleu) == 0){
            AjouterUnite(&finale,getPtrData(bleu));
        }
     bleu = getptrNextCell(bleu);
    }
    return finale;
}

TListePlayer sortplayerbycolorred(TListePlayer allplayer){
    TListePlayer rouges;
    initListe(&rouges);
    rouges = allplayer;
    tri_selection_liste(rouges, comp_couleur_rouge);
    TListePlayer finale;
    initListe(&finale);
    while(!listeVide(rouges)){
        if(getColor(rouges) == 1){
            AjouterUnite(&finale,getPtrData(rouges));
        }
        rouges = getptrNextCell(rouges);
    }
    return finale;
}

void sortplayerbyatspeed(TListePlayer allplayer){
    tri_selection_liste(allplayer, comp_vitesse_asupb);
}

void sortplayeratlife(TListePlayer allplayer){
    tri_selection_liste(allplayer, comp_vie_ainfb);
}

bool APortee(Tunite a, Tunite b){
    int portee_a = a.portee;
    int x_a = getPosUX(a);
    int y_a = getPosUY(a);
    int x_b = getPosUX(b);
    int y_b = getPosUY(b);
    return ((x_b >= x_a-portee_a && x_b <= x_a + portee_a) && (y_b <= y_a+portee_a && y_b >= y_a-portee_a));
}

void displayListPlayer(TListePlayer player){
    while(!listeVide(player)){
        printf("%d %d vitesse : %f, points de vie %d : ", getPosX(player), getPosY(player), getvitesseattaque(*getPtrData(player)), getLifepoint(player));
        printf("\n");
        player=getptrNextCell(player);
    }
}

void MinusLife(Tunite *player1, Tunite *player2){
    if(getLifepointU(*player1)< getdegats(*player2)){
        player1 -> pointsDeVie = 0;
    }else{
        player1->pointsDeVie = getLifepointU(*player1) - getdegats(*player2);
        }
    player2->peutAttaquer = 0;
}

void supprimerUniteDeListe(TListePlayer *player1, TListePlayer *player2){
    printf("Affiche liste A \n");
    displayListPlayer(*player1);
    printf("Affiche liste B \n");
    displayListPlayer(*player2);

    TListePlayer current = *player1;
    TListePlayer current2 = *player2;

    while(!listeVide(current)){
        if(getLifepoint(current)<=0){
            supprimerUnite(player1,getPtrData(current));
        }
        current = getptrNextCell(current) ;
    }

    while(!listeVide(current2)){
        if (getLifepoint(current2)<=0){
            supprimerUnite(player2,getPtrData(current2));
        }
        current2 = getptrNextCell(current2);
    }
    printf("Affiche liste A apres supp \n");
    displayListPlayer(*player1);
    printf("Affiche liste B apres supp \n ");
    displayListPlayer(*player2);
}

void Abletoattack(TListePlayer player1, TListePlayer player2){
    while(player1 != NULL){
        player1->pdata->peutAttaquer = 1 ;
        player1 = getptrNextCell(player1);
    }
    while(player2 != NULL){
        player2->pdata->peutAttaquer = 1;
        player2 = getptrNextCell(player2);
    }
}
void finalcombat(TListePlayer *player, TListePlayer *player2,  TplateauJeuUpgrade jeuUpgrade){
    TListePlayer current = *player;
    printf("liste 1 \n");
    displayListPlayer(*player);
    printf("liste 2\n");
    displayListPlayer(*player2);

    while (!listeVide(current)){
        supprimerUniteDeListe(player,player2);
        combat(current, *player2, *(getPtrData(current)),jeuUpgrade);
        current = getptrNextCell(current);
    }
}

void combat(TListePlayer player, TListePlayer player2, Tunite togather, TplateauJeuUpgrade jeuUpgrade) {
        printf("entree dans la fonction combat\n\n");
        TListePlayer Allplayer;
        initListe(&Allplayer);
        Allplayer = PlayerInZone(togather,jeuUpgrade);
        printf("fin display Allplayer ");
        TListePlayer blue = sortplayerbycolorblue(Allplayer);
        TListePlayer bluelife = blue;
        sortplayeratlife(bluelife);
        TListePlayer red = sortplayerbycolorred(Allplayer);
        sortplayerbyatspeed(red);
        while(!listeVide(red)){
            while(!listeVide(bluelife)){
                if(APortee(*getPtrData(red), *getPtrData(bluelife))&& (getattack(red) != 0) && getLifepoint(red)>0){

                    if(comp_vitesse_asupb(*getPtrData(red), *getPtrData(bluelife))){
                        MinusLife(getPtrData(bluelife),getPtrData(red));
                        printf("MinusLife 1 \n");
                        if(APortee(*(getPtrData(bluelife)), *(getPtrData(red)))&& (getattack(bluelife)!=0) && getLifepoint(bluelife)>0){
                            MinusLife(getPtrData(red),getPtrData(bluelife));
                            printf("MinusLife 2 \n");
                        }
                    }
                    else if(!comp_vitesse_asupb(*getPtrData(red), *getPtrData(bluelife))){
                            if(APortee(*getPtrData(bluelife), *getPtrData(red))&&(getattack(bluelife)!=0) && getLifepoint(bluelife)>0){
                                MinusLife(getPtrData(red),getPtrData(bluelife));
                                printf("MinusLife 3 \n");
                            }
                            if(getLifepoint(red)> 0){
                                MinusLife(getPtrData(bluelife),getPtrData(red));
                                printf("MinusLife 4 \n");
                                if(getLifepoint(bluelife)<=0){
                                printf("Unite Supprime rouge moins rapide que bleu \n");
                                }
                            }
                    }
                }else if(!APortee(*(getPtrData(red)), *(getPtrData(bluelife))) && APortee(*(getPtrData(bluelife)),*(getPtrData(red)))){
                        MinusLife(getPtrData(red),getPtrData(bluelife));
                        printf("MinusLife 5");
                    }
                bluelife = getptrNextCell(bluelife);
            }
            red = getptrNextCell(red);
        }
        printf("sortie de la fonction combat\n\n");
}



bool isunity(TListePlayer player2, int x, int y){
    int result = 0;
    TListePlayer current = player2;
    while (!listeVide(current)){
        int checkx = getPosX(current);
        int checky = getPosY(current);
        if (checkx == x && checky == y){
            result = 1;
        }
        current = getptrNextCell(current);
    }
    if (result ==1){
        return true;
    } else return false;
}

void movep(TListePlayer player, TListePlayer player2, TplateauJeu jeu){
    TListePlayer current = player;

    while(!listeVide(current))
    {
        int x = getPosX(current);
        int y = getPosY(current);

        if((getName(current)) == 1 || (getName(current)) == 0){
            current = getptrNextCell(current);
        }else{
            if(isunity(player2,x+1,y) || isunity(player2,x-1,y) || isunity(player2,x,y+1)|| isunity(player2,x,y-1)){
                current = getptrNextCell(current);
            }
            else if( y ==8 && x>5 && jeu[x-1][y] == NULL){
                current -> pdata -> posX = x-1;
                current = getptrNextCell(current);
            } else if( y == 8 && x<5 && jeu[x+1][y]==NULL){
                current -> pdata -> posX = x+1;
                current = getptrNextCell(current);
            } else if (jeu[x][y+1] == NULL){
                current -> pdata -> posX = x;
                current -> pdata -> posY = y+1;
                current = getptrNextCell(current);
            } else if(x>5 && jeu[x-1][y] ==NULL){
                current -> pdata -> posX = x-1;
                current -> pdata -> posY = y;
                current = getptrNextCell(current);
            } else if(x<5 && jeu[x+1][y] ==NULL){
                current -> pdata -> posX = x+1;
                current -> pdata -> posY = y;
                current = getptrNextCell(current);
            } else{
                current = getptrNextCell(current);
            }
        }
    }
}

void movep2(TListePlayer player, TListePlayer player2, TplateauJeu jeu)
{
    TListePlayer current = player;

    while(current != NULL)
    {
        int x = getPosX(current);
        int y = getPosY(current);

        if((getName(current)) == 1 || (getName(current)) == 0){
            current = getptrNextCell(current);
        }else{
            if(isunity(player2,x+1,y) || isunity(player2,x-1,y) || isunity(player2,x,y+1)|| isunity(player2,x,y-1)){
                current = getptrNextCell(current);
            }
            else if( y ==10 && x>5 && jeu[x-1][y] == NULL){
                current -> pdata -> posX = x-1;
                current -> pdata -> posY = y;
                current = getptrNextCell(current);
            } else if( y == 10 && x<5 && jeu[x+1][y]==NULL){
                current -> pdata -> posX = x+1;
                current -> pdata -> posY = y;
                current = getptrNextCell(current);
            } else if (jeu[x][y-1] == NULL){
                current -> pdata -> posX = x;
                current -> pdata -> posY = y-1;
                current = getptrNextCell(current);
            }else if(x>5 && jeu[x-1][y] ==NULL){
                current -> pdata -> posX = x-1;
                current -> pdata -> posY = y;
                current = getptrNextCell(current);
            }else if(x<5 && jeu[x+1][y] ==NULL){
                current -> pdata -> posX = x+1;
                current -> pdata -> posY = y;
                current = getptrNextCell(current);
            }else{
                current = getptrNextCell(current);
            }
        }
    }
}
