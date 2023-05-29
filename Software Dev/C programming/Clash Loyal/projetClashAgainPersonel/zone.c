#include "zone.h"
#include "types.h"
#include "clashagain.h"


// a vous de coder les fonctions citées dans zone.h
// + celles que vous pourriez inventer pour MANIPULER UN TZONE.

TListePlayer getAllUnitInZone(Tzone* z){
    TListePlayer l;
    initListe(&l);
    AjouterUnite(&l, get_elemsol(*z));
    AjouterUnite(&l, get_elemvol(*z));
    return l;
}

Tzone creerTzoneVide(){
    Tzone zone = creerPersoVide();  // le type Tzone (equivalent au type pile) est un pointeur sur cellule
    return zone;
}

Tzone ajouterUnitedansZone(Tzone z, Tunite *u){
    if(maposition(*u)==0){
        z = ajoutUnite_solPerso(z, u);
    }else if (maposition(*u)==2){
        z = ajoutUnite_volPerso(z, u);
    }
    //printf("\n unité ajoute dans la zone \n");
    return z;
}

Tzone supprimerUnitedansZone(Tzone* z,Tunite *u){
    if(comp_egal_AegalB(*u, *get_elemsol(*z))){
        *z = supprimerUnite_solPerso(*z);
    }else if (comp_egal_AegalB(*u, *get_elemvol(*z))){
        *z = supprimerUnite_volPerso(*z);
    }
    return *z;
}

bool UniteEstPresentedansZone(Tzone* z, Tunite *u){
    return comp_egal_AegalB(*u, *get_elemsol(*z)) || comp_egal_AegalB(*u, *get_elemvol(*z));
}


bool UniteAuSolPresente(Tzone* z){
    estVide_sol(*z);
}

bool UniteEnVolPresente(Tzone* z){
    estVide_vol(*z);
}

bool estvide_zone(Tzone z){
    return ((estVidePerso(z)) == 1);
}

void affichezone(Tzone z){
    if (estVidePerso(z)==1){
        printf("type perso vide");
    }
    else {
        printf("unite remplie ");
    }
}

Tunite* tetezone(Tzone z){
    if(estVide_sol(z)){
        return get_elemvol(z);
    }
    else{
     return get_elemsol(z);
    }
     // arbitrairement on désigne la tete de zone comme étant l'unité au sol de la zone
}
