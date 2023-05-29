#include "zone.h"
#include "types.h"
#include "clashagain.h"


// a vous de coder les fonctions citées dans zone.h
// + celles que vous pourriez inventer pour MANIPULER UN TZONE.

TListePlayer getAllUnitInZone(Tzone* z){
    TListePlayer l;
    initListe(&l);
    pile pileA = creerPileVide();

    while(!estvide_zone(*z)){
        AjouterUnite(&l,tetePile(*z));
        pileA = empiler(pileA, tetePile(*z));
        *z = depiler(*z);
    }
    while(!estvide_zone(pileA)){
        *z = empiler(*z, tetePile(pileA));
        pileA = depiler(pileA);
    }
    return l;
}

Tzone creerTzoneVide(){
    Tzone zone = creerPileVide();  // le type Tzone (equivalent au type pile) est un pointeur sur cellule
    return zone;
}

Tzone ajouterUnitedansZone(Tzone z, Tunite *u){
    z = empiler(z,u);
    //printf("\n unité ajoute dans la zone \n");
    return z;
}

Tzone supprimerUnitedansZone(Tzone* z,Tunite *u){
    bool found_unite = false;
    pile pileA;
    pileA = creerPileVide();

    while (!estvide_zone(*z) && !found_unite){
        if(comp_egal_AegalB(*tetePile(*z),*u)){             // Il faut faire les fonctions de la liste Double. On compare les Tunite dans leur globalités
           *z = depiler(*z);
           found_unite = true;
           }else{
               pileA = empiler(pileA,tetePile(*z));
               *z = depiler(*z);
           }
    }
     // on remet les boites enlevés
    while (!estVide(pileA)){
        *z = empiler(*z, tetePile(pileA));
        pileA=depiler(pileA);
    }
    return *z;
}

bool UniteEstPresentedansZone(Tzone* z, Tunite *u){
    bool found_unite = false;
    pile Searchpile = *z;
    pile pileA = creerPileVide();

    while(!estvide_zone(Searchpile) || !(found_unite)){
        if(comp_egal_AegalB(*tetePile(*z),*u)){
            found_unite = true;
        }else{
        Searchpile = depiler(Searchpile);
        pileA = empiler(pileA, tetePile(Searchpile));
        }
    }
    while(!estVide(pileA)){
        *z = empiler(*z, tetePile(pileA));
        pileA = depiler(pileA);
    }
    return found_unite;
}


bool UniteAuSolPresente(Tzone* z){
    bool found_unite_sol = false;
    pile Searchpile = *z;
    pile pileA = creerPileVide();

    while(!estvide_zone(Searchpile) || !(found_unite_sol)){
        if(maposition(*tetePile(Searchpile)) == sol){
            found_unite_sol = true;
        }else{
            Searchpile = depiler(Searchpile);
            pileA = empiler(pileA, tetePile(pileA));
        }
    }
    while(!estVide(pileA)){
        *z = empiler(*z, tetePile(pileA));
        pileA = depiler(pileA);
    }

    return found_unite_sol;
}

bool UniteEnVolPresente(Tzone* z){
    bool found_unite_vol = false;
    pile Searchpile = *z;
    pile pileA = creerPileVide();

    while(!estvide_zone(Searchpile) || !(found_unite_vol)){
        if(maposition(*tetePile(Searchpile)) == air){
            found_unite_vol = true;
        }else{
            Searchpile = depiler(Searchpile);
            pileA = empiler(pileA, tetePile(pileA));
        }
    }
    while(!estVide(pileA)){
        *z = empiler(*z, tetePile(pileA));
        pileA = depiler(pileA);
    }

    return found_unite_vol;
}

bool estvide_zone(Tzone z){
    return ((estVide(z)) == 1);
}

Tzone affichezone(Tzone z ){
 pile pileA;
 pileA = creerPileVide();

 //on depile, on affiche à la volée et on remplie dans une copie
 while (estVide(z)!=true) {
     afficheUnite(*tetePile(z));
     pileA = empiler(pileA, tetePile(z));
     z=depiler(z);
 }
 // on remet la pile à l'endroit
 while (!estVide(pileA)){
    z = empiler(z, tetePile(pileA));
    pileA=depiler(pileA);
 }
 return z;  //l'adresse s n'est pas forcément la même qu'en entrée de fct, car on on a déplier (free) et re-empiler (malloc)
}
