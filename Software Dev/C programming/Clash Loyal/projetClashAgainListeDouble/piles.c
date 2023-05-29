#include <stdio.h>
#include <stdlib.h>

#include "piles.h"
#include "types.h"
#include "utils.h"

//initListe ne fait pas de malloc, juste une initialisation à NULL du pointeur de liste
void initListedouble(T_listedouble *l){
*l=NULL;
}

//Fonction de traitement de listeplayer
/*---------------------------------------------------------------------------------------*/

//void initListe(TListePlayer *l){
//*l=NULL;
//}


//bool listeVide(TListePlayer l){
//    return (l==NULL);
//}

bool listeVidedouble(T_listedouble l){
    return (l==NULL);
}

//void afficheListeV1(TListePlayer l){
//    TListePlayer courant = l;
//    while (courant!=NULL){
//        //printf(" %d ",*(courant->pdata));
//        printf("valeur: %p \n",*(courant->pdata));
//        courant=courant->suiv;
//    }
//    printf("\n");
//}


//TListePlayer getptrLastCell(TListePlayer l)
//{
//    TListePlayer courant = l;
//
//    if (listeVide(courant)) {
//        //if (DEBUG) printf("Erreur getptrLastCell liste vide");
//    }
//    else {
//        while(courant->suiv != NULL){
//            courant=courant->suiv;
//        }
//    }
//    return courant;
//}

//TListePlayer getptrNextCell(TListePlayer l)
//{
//    TListePlayer courant = l;
//
//    if (listeVide(courant)) {
//        //if (DEBUG) printf("Erreur getptrNextCell liste vide");
//    }
//    else {
//        courant=courant->suiv;
//    }
//    return courant;
//}

//Tunite* getPtrData(TListePlayer l)
//{
//    if (listeVide(l)) {
//        //if (DEBUG) printf("Erreur getPtrData liste vide");
//        return NULL;  // fera planter le main
//    }
//    else return l->pdata;  // ptr sur notre entier stocké
//}

//void swapPtrData( TListePlayer source, TListePlayer destination )
//{
//    if (listeVide(source)||listeVide(destination)){
//            //if (DEBUG) printf("Erreur swapPtrData ptr = NULL");
//    }
//    else {  //swap
//    int* tmp = source->pdata;
//    source->pdata = destination->pdata;
//    destination->pdata = tmp;
//    }
//}

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



//A vous la suite

//void afficheListeV1( T_listedouble l)
//{
//    T_listedouble courant = l ;
//    while(courant!=NULL){
//        print(*(courant->pdata));
//        courant = courant->suiv;
//    }
//}

T_listedouble ajoutEnTete(T_listedouble l, Tunite mydata)
{
    T_listedouble newc = (T_listedouble)malloc(sizeof(struct T_cell)); // nouvelle cellule créé avec un pointeur dessus
    newc->pdata = (Tunite*)malloc(sizeof(Tunite)); // nouvelle place pour un int avec un pointeur dessus
     *(newc->pdata)= mydata;
    if (listeVide(l)){
        newc -> suiv = NULL;
        newc -> prec = NULL;
    } else {
        newc -> prec = NULL;
        newc -> suiv = l;
        l -> prec = newc; // on raccorche l'ancienne liste à la nouvelle cellule pour ne pas la perdre
    }
    return newc;
}



T_listedouble ajoutEnFin(T_listedouble l, Tunite mydata)
{
    T_listedouble parcours  = l;
    T_listedouble newc = (T_listedouble)malloc(sizeof(struct T_cell)); // nouvelle cellule créé avec un pointeur dessus
    Tunite *newpdata = (Tunite*)malloc(sizeof(Tunite)); // nouvelle place pour un int avec un pointeur dessus
    newc->pdata = newpdata;
    *newpdata = mydata;
     if (listeVide(l)){
        newc -> suiv = NULL;
        newc -> prec = NULL;
        return newc;
    } else {
        while( parcours ->suiv !=NULL){
            parcours = parcours->suiv;
        }
        parcours ->suiv = newc;
        newc ->prec = parcours;
        newc -> suiv = NULL;
        return l;
    }
}

T_listedouble ajoutEnN(T_listedouble l, int pos, Tunite mydata)
{
    T_listedouble newc = (T_listedouble)malloc(sizeof(struct T_cell)); // nouvelle cellule créé avec un pointeur dessus
    Tunite *newpdata = (Tunite*)malloc(sizeof(Tunite)); // nouvelle place pour un int avec un pointeur dessus
    newc->pdata = newpdata;
    *newpdata = mydata;
    T_listedouble parcours2, parcours =  l;
    int position = 1; // je suppose que la première cellule est en position 1

    while( position != pos -1){
        position ++;
        parcours = parcours ->suiv;
    }

    parcours2 = parcours ->suiv ;
    parcours ->suiv = newc;
    parcours2-> prec = newc;
    newc -> prec = parcours;
    newc -> suiv = parcours2;

    return l;
}

T_listedouble suppEnTete(T_listedouble l)
{
    l = l->suiv;
    free(l -> prec -> pdata);
    free(l -> prec);
    return l;
}

T_listedouble suppEnFin(T_listedouble l)
{
    T_listedouble courant = l;
    while( courant ->suiv !=NULL){
        courant = courant->suiv;
    }
    courant ->prec ->suiv = NULL;
    free(courant ->pdata);
    free(courant);
    return l;
}

//je suppose que la prmeière cellule est à l'indice 1
T_listedouble suppEnN(T_listedouble l, Tunite unite)
{
    T_listedouble parcours1 = l;
    T_listedouble parcours2;
    while(!comp_egal_AegalB(*(l->pdata), unite)){
        parcours1 = parcours1 ->suiv;
    }
    parcours2 = parcours1 ->suiv;
    parcours2 ->prec = parcours1 ->prec;
    parcours1 ->prec ->suiv = parcours2;
    free(parcours1->pdata);
    free(parcours1);
    return l;
}

// on suppose que le pointeur est pas forcément au début
T_listedouble getptrFirstCell(T_listedouble l)
{
    while(l ->prec !=NULL){
        l = l->prec;
    }
    return l;
}


T_listedouble getptrLastCelldouble(T_listedouble l)
{
    while(l ->suiv !=NULL){
        l = l->suiv;
    }
    return l;
}


T_listedouble getptrNextCelldouble(T_listedouble l)
{
    return l ->suiv;
}


T_listedouble getptrPrevCell(T_listedouble l)
{
    return l ->prec;
}

void AjouterUnitelistedouble(T_listedouble *player, Tunite *nouvelleUnite){
    T_listedouble newp = malloc(sizeof( T_listedouble));
    if (player ==NULL)
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

//je suppose que le pointeur sur liste l pointe sur la première cellule
// ou pour être sûre j'utilise la fonction "getptrFirstCell"
Tunite* getPtrDatadouble(T_listedouble l)
{
    return l -> pdata;
}

void swapPtrDatadouble( T_listedouble source, T_listedouble destination )
{
    Tunite* sauv = source ->pdata;
    source ->pdata = destination ->pdata;
    destination -> pdata = sauv;
}

int getNbreCelldouble(T_listedouble l)
{
    l = getptrFirstCell(l);
    int count = 1 ;
    if(listeVide(l)){
        return 0;
    } else {
        while(l->suiv != NULL){
            count ++;
            l = l->suiv;
        }
        return count;
    }
}

//int getSizeBytesdouble(T_listedouble l)
//{
//    int nb = getNbreCell(l);
//    return nb*(sizeof(struct T_cell));
//}

T_listedouble creatNewListeFromFusion(T_listedouble l1, T_listedouble l2)
{
    T_listedouble l1_bis = getptrFirstCell(l1), l2_bis = getptrFirstCell(l2);
    T_listedouble newliste = NULL;

    while(l1_bis !=NULL){
        // printf("1");
        newliste = ajoutEnTete(newliste, *(l1_bis->pdata));
        l1_bis = l1_bis ->suiv;
    }
    while(l2_bis !=NULL){
        // printf("2");
        newliste = ajoutEnTete(newliste, *(l2_bis->pdata));
        l2_bis = l2_bis ->suiv;
    }
    //printf("newliste = %p", newliste);
    return newliste;
}


T_listedouble addBehind(T_listedouble debut, T_listedouble suite)
{
    T_listedouble debutsuiv = debut ->suiv;
    T_listedouble finsuite = getptrLastCell(suite);
    debut -> suiv = suite;
    suite ->prec = debut;
    finsuite -> suiv = debutsuiv;
    debutsuiv ->prec = finsuite;
    return debut;
}

//retourne le pointeur sur la cellule contenant la valeur recherchée
T_listedouble findCell(T_listedouble l, Tunite data)
{
//    while(*(l->pdata) != data){
//        l = l->suiv;
//    }
//    return l;
    if (listeVidedouble(l)){
        return l;
    } else if(comp_egal_AegalB(*(getPtrDatadouble(l)), data)){
            return l;
    } else findCell(getptrNextCelldouble(l), data);
}


/*int getOccurences(T_listedouble l, int data)
{
    int count =0;
    while(l != NULL){
        if(*(l->pdata) == data){
            count ++;
        }
        l = l->suiv;
    }
    return count;
}*/



// étape 2
//T_listedouble createnewlist(int taille)
//{
//    T_listedouble newl=NULL; // = (T_listedouble)malloc(sizeof(struct T_cell));
//    for(int i = 0; i<taille; i++){
//        newl = ajoutEnTete(newl, rand()%100);
//    }
//    return newl;
//}
//
//void AfficheTab(int tab[], int taille)
//{
//    for(int i =0; i<taille; i++){
//        printf("la case %d contient la valeur %d \n", i, tab[i]);
//    }
//}

// on fait allocation dynamique pour garder en mémoire le tableau
// on lui met un pointeur pour pouvoir y accéder
// tab[i] permet d'accéder à la case i du tableau pointeur par tab
//int* ListtoTab(T_listedouble l, int taille)
//{
//    T_listedouble courant = l;
//    int *tab = (int*)malloc(taille * sizeof(int));
//    for(int i=0; i<taille; i++){
//        tab[i] = *(courant->pdata);
//        courant = courant->suiv;
//    }
//    return tab;
//}

//int* ListotTabfree(T_listedouble l, int taille)
//{
//    T_listedouble courant = l;
//    T_listedouble tofree;
//    int *tab = (int*)malloc(taille * sizeof(int));
//    for(int i=0; i<taille; i++){
//        tab[i] = *(courant->pdata);
//        tofree = courant;
//        courant = courant ->suiv;
//        free(tofree->pdata);
//        free(tofree);
//    }
//    return tab;
//}

//T_listedouble TabtoList(int tab[], int taille)
//{
//    T_listedouble l;
//    initListe(&l);
//    for (int i = 0; i<taille;i ++){
//       l = ajoutEnFin(l, tab[i]);
//    }
//    return l;
//}

void tri_selection(int *tableau /*ou int tab[]*/, int taille)
{
    int en_cours, plus_petit, j, temp;
    for (en_cours = 0; en_cours < taille - 1; en_cours++){
        plus_petit = en_cours;
        for (j = en_cours; j < taille; j++){
            if (tableau[j] < tableau[plus_petit])  plus_petit = j;
        }
        temp = tableau[en_cours];
        tableau[en_cours] = tableau[plus_petit];
        tableau[plus_petit] = temp;
    }
}

// fonction qui trie une liste via un tableau
// sur lequel on applique un tri par sélection
//T_listedouble trie_liste_via_tableau(T_listedouble l)
//{
//    int taille = getNbreCell(l);
//    printf("test taille \n");
//    int *deb_tab = ListtoTab(l, taille);
//    printf("test tableau \n");
//    tri_selection(deb_tab, taille);
//    printf("test tri \n");
//    l = TabtoList(deb_tab, taille);
//    printf("test rempli liste \n");
//    return l;
//}

// étape 3

/*void tri_selection_liste(T_listedouble l)
{
    T_listedouble courant = getptrFirstCell(l), toswap;
    T_listedouble plus_petit;

    while(courant != NULL)
    {
        plus_petit = courant;
        toswap = plus_petit;
        while(toswap != NULL)
        {
            if(*(toswap -> pdata) < *(plus_petit ->pdata))
            {
                swapPtrData(toswap,courant);
            }
            toswap = getptrNextCell(toswap);
        }
        courant = getptrNextCell(courant);
    }
}*/

// étape 4

//T_listedouble creerListeNElem(int taille){
//    T_listedouble newl=NULL; // = (T_listedouble)malloc(sizeof(struct T_cell));
//    for(int i = 0; i<taille; i++){
//        newl = ajoutEnFin(newl,getPersAlea(getRandInt(1,99)));
//    }
//    return newl;
//}

//int getOccurences(T_listedouble l, Tunite data)
//{
//    int count =0;
//    while(l != NULL){
//        if (fcompare(l->pdata->taille,data, egaltaille)){
//            count ++;
//        }
//        l = l->suiv;
//    }
//    return count;
//}

