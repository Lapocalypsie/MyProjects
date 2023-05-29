#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include<stdbool.h>
#include"types.h"

typedef struct cellule{
    Tunite* elem_sol;
    Tunite* elem_vol;
} *perso;

perso creerPersoVide();
int estVidePerso(perso p);
perso ajoutUnite_solPerso(perso p, Tunite* a);
perso ajoutUnite_volPerso(perso p, Tunite* b);
perso supprimerUnite_solPerso(perso p);
perso supprimerUnite_volPerso(perso p);
Tunite* get_elemsol(perso p);
Tunite* get_elemvol(perso p);
bool estVide_vol(perso p);
bool estVide_sol(perso p);



#endif // PERSO_H_INCLUDED
