#include <stdio.h>
#include <stdlib.h>
#include "perso.h"

perso creerPersoVide(){
    return NULL;
}

int estVidePerso(perso p){
    if(p==NULL){
        return 1;
    } else
        return 0;
}





perso ajoutUnite_solPerso(perso p, Tunite *a){
    perso new_unite = malloc(sizeof(perso));
    new_unite->elem_sol = a;
    new_unite->elem_vol = NULL;
    if (estVidePerso(p)==1){
        p = new_unite;
    }else if (estVide_sol(p) && !estVide_vol(p)){
        p->elem_sol = new_unite->elem_sol;
    }
    return p;
}

perso ajoutUnite_volPerso(perso p, Tunite* b){
    perso new_unite = malloc(sizeof(perso));
    new_unite->elem_vol = b;
    new_unite->elem_sol = NULL;
    if (estVidePerso(p)==1){
        p = new_unite;
    }else if (estVide_vol(p) && !estVide_sol(p)){
        p->elem_sol = new_unite->elem_vol;
    }
    return p;
}

perso supprimerUnite_solPerso(perso p){
    if(estVidePerso(p)==1){
        return NULL;
    } else {
        p->elem_sol = NULL;
        return p;
    }
}

perso supprimerUnite_volPerso(perso p){
    if(estVidePerso(p)==1){
        return NULL;
    } else {
        p->elem_vol = NULL;
        return p;
    }
}

Tunite* get_elemsol(perso p){
    return p->elem_sol;
}

Tunite* get_elemvol(perso p){
    return p->elem_vol;
}

bool estVide_vol(perso p){
    return get_elemvol(p) ==NULL;
}

bool estVide_sol(perso p){
    return get_elemsol(p) ==NULL;
}
