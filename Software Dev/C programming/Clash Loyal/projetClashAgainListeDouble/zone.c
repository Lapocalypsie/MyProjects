#include "zone.h"
#include "types.h"
#include "clashagain.h"


// a vous de coder les fonctions citées dans zone.h
// + celles que vous pourriez inventer pour MANIPULER UN TZONE.

TListePlayer getAllUnitInZone(T_listedouble* z){
    TListePlayer l;
    initListe(&l);

    while(!listeVidedouble(*z)){
        AjouterUnite(&l,getPtrDatadouble(z));
    }
    return l;
}

Tzone creerTzoneVide(){
    Tzone zone;
    initListedouble(&zone);  // le type Tzone (equivalent au type pile) est un pointeur sur cellule
    return zone;
}

Tzone ajouterUnitedansZone(Tzone z, Tunite *u){
    AjouterUnitelistedouble(&z,u);
    //printf("\n unité ajoute dans la zone \n");
    return z;
}

Tzone supprimerUnitedansZone(Tzone* z,Tunite *u){
    Tzone zone = *z;

    while (!estvide_zone(zone)){
        if(comp_egal_AegalB(*getPtrDatadouble(zone),*u)){             // Il faut faire les fonctions de la liste Double. On compare les Tunite dans leur globalités
            supprimerUnite(z,getPtrDatadouble(*z));
        }
        zone = getptrNextCelldouble(zone);
    }
    return *z;
}

bool UniteEstPresentedansZone(Tzone* z, Tunite *u){
    Tzone zone = *z;
    bool found_unite = false;

    while(!estvide_zone(zone) || found_unite != true){
        if(comp_egal_AegalB(*getPtrDatadouble(zone),*u)){
            found_unite = true;
        }
        zone = getPtrDatadouble(zone);
    }
    return found_unite;
}


bool UniteAuSolPresente(Tzone* z){
    bool found_unite_sol = false;
    Tzone zone = *z;

    while(!estvide_zone(zone) || found_unite_sol != true ){
        if(maposition(*getPtrDatadouble(zone)) == sol){
            found_unite_sol = true;
        }
        zone = getptrNextCelldouble(zone);
    }
    return found_unite_sol;
}

bool UniteEnVolPresente(Tzone* z){
    bool found_unite_vol = false;
    Tzone zone = *z;

    while(!estvide_zone(zone) || found_unite_vol != true ){
        if(maposition(*getPtrDatadouble(zone)) == air){
            found_unite_vol = true;
        }       zone = getptrNextCelldouble(zone);
    }
    return found_unite_vol;
}

bool estvide_zone(Tzone z){
    return ((listeVidedouble(z)));
}

void affichezone(Tzone z ){
    Tzone zone = z;

 //on depile, on affiche à la volée et on remplie dans une copie
 while (!estvide_zone(zone)) {
     afficheUnite(getPtrDatadouble(zone));
             printf("On rentre ici \n");

     zone = getptrNextCelldouble(zone);
    }
 }

Tunite *tetezone(Tzone z){
    return getPtrDatadouble(z);
}
