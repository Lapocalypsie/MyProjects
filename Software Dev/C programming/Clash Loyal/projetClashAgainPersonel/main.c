//NOM prénom étudiant 1 : Rasolosoa Jimmy
//NOM prénom étudiant 2 : Brisseau  Tiffany

#include "SDL.h"
#include "maSDL.h"    //bibliothèque avec des fonction d'affichage pour le jeu 2048
#include "clashagain.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/*--------- Main ---------------------*/
int main(int argc, char* argv[])
{
    SDL_Window *pWindow;
    SDL_Init(SDL_INIT_VIDEO);

    pWindow = SDL_CreateWindow(
        "Appuyez sur ECHAP pour quitter, S/C ET D/V les gerer les sauvegardes",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        LARGEURJEU*40,
        HAUTEURJEU*40,
        SDL_WINDOW_SHOWN
    );

    SDL_Surface* pWinSurf = SDL_GetWindowSurface(pWindow);  //le sprite qui couvre tout l'écran
    SDL_Surface* pSpriteTour = SDL_LoadBMP("./data/Tour.bmp");  //indice 0 dans tabSprite (via l'enum TuniteDuJeu)
    SDL_Surface* pSpriteTourRoi = SDL_LoadBMP("./data/TourRoi.bmp"); //indice 1
    SDL_Surface* pSpriteArcher = SDL_LoadBMP("./data/Archer.bmp"); //indice 2
    SDL_Surface* pSpriteChevalier = SDL_LoadBMP("./data/Chevalier.bmp"); //indice 3
    SDL_Surface* pSpriteDragon = SDL_LoadBMP("./data/Dragon.bmp"); //indice 4
    SDL_Surface* pSpriteGargouille = SDL_LoadBMP("./data/Gargouille.bmp"); //indice 5
    SDL_Surface* pSpriteEau = SDL_LoadBMP("./data/Eau.bmp"); //indice 6  Ne figure pas dans l'enum TuniteDuJeu
    SDL_Surface* pSpriteHerbe = SDL_LoadBMP("./data/Herbe.bmp"); //indice 7 idem
    SDL_Surface* pSpritePont = SDL_LoadBMP("./data/Pont.bmp"); //indice 8 idem
    SDL_Surface* pSpriteTerre = SDL_LoadBMP("./data/Terre.bmp"); //indice 9 idem

    // ASTUCE : on stocke le sprite d'une unité à l'indice de son nom dans le type enum TuniteDuJeu, dans le tableau TabSprite
    // SAUF pour l'Eau, l''herbe et le pont qui apparaitront en l absence d'unité (NULL dans le plateau) et en foction de certains indices x,y définissant le chemin central
    SDL_Surface* TabSprite[10]={pSpriteTour,pSpriteTourRoi,pSpriteArcher,pSpriteChevalier,pSpriteDragon,pSpriteGargouille,pSpriteEau,pSpriteHerbe,pSpritePont,pSpriteTerre};


    if ( pSpriteTour )  //si le permier sprite a bien été chargé, on suppose que les autres aussi
    {
        TplateauJeu jeu = AlloueTab2D(LARGEURJEU,HAUTEURJEU);
        initPlateauAvecNULL(jeu,LARGEURJEU,HAUTEURJEU);
        affichePlateauConsole(jeu,LARGEURJEU,HAUTEURJEU);

        ///********************* NOUVEAUTE ***************************
        TplateauJeuUpgrade jeuUpgrade = AlloueTab2D_Tzone(LARGEURJEU,HAUTEURJEU);  //code fourni
        initPlateauTzoneAvecNULL(jeuUpgrade,LARGEURJEU,HAUTEURJEU);

        TPlayer player1 = initPlayer(rouge);
        TPlayer player2 = initPlayer(bleu);
        ///********************* fin NOUVEAUTE ***************************

        prepareAllSpriteDuJeu(jeu,LARGEURJEU,HAUTEURJEU,TabSprite,pWinSurf);
        maj_fenetre(pWindow);

        //A COMMENTER quand vous en aurez assez de cliquer sur ces popups ^^

        message("Welcome in ClashAgain","Ceci est un point de depart de votre future interface de votre jeu ClashAgain");
        message("et fin","ECHAP->quitter, A,D,C et G pour les achats d'unités (si version humain vs ordi)");

        /**********************************************************************/
        /*                                                                    */
        /*              DEFINISSEZ/INITIALISER ICI VOS VARIABLES              */
        /*              remarque : player1, player2 et jeuUpgrade  sont definis lignes 52-55
        // FIN de vos variables                                                              */
        /**********************************************************************/

    AjouterUnite(&player1.listeU, creeTourRoi(5,1, rouge) );
    AjouterUnite(&player1.listeU, creeTour(5,3, rouge) );
    AjouterUnite(&player2.listeU, creeTourRoi(5,17, bleu) );
    AjouterUnite(&player2.listeU, creeTour(5,15, bleu) );

//    AjouterUnite(&player1.listeU,creeDragon(7,2,rouge));
//    AjouterUnite(&player1.listeU,creeChevalier(2,3,rouge));
//
//    AjouterUnite(&player2.listeU,creeDragon(2,17,bleu));
//    AjouterUnite(&player2.listeU,creeChevalier(7,18,bleu));
//
//    displayListPlayer(player1.listeU);
        int nb_tour =1;

        // boucle principale du jeu
        int cont = 1;
        while ( cont != 0 && tourRoiDetruite(player1.listeU) == 1 && tourRoiDetruite(player2.listeU) ==1){   //VOUS DEVEZ GERER (DETECTER) LA FIN DU JEU -> tourRoiDetruite
                SDL_PumpEvents(); //do events

                printf(" \n C'EST REPARTI POUR UN TOUR MON AMI \n");

                initPlateauAvecNULL(jeu,LARGEURJEU,HAUTEURJEU);
                initPlateauTzoneAvecNULL(jeuUpgrade,LARGEURJEU,HAUTEURJEU);

                /****************************** Nouveautés *****************************************/
                /*                                                                     */
                /*                                                                     */
                //APPELEZ ICI VOS FONCTIONS QUI FONT EVOLUER LE JEU
                //
                /*  Vous manipulez ici:
                //
                //  player1, player2 et jeuUpgrade                                                                    */
                /*                                                                     */
                // FIN DE VOS APPELS
                /******************************* fin nouveautés****************************************/
                player1.elixir = AcheteUnite(&player1.listeU, player1.elixir);
                player2.elixir = AcheteUnite(&player2.listeU, player2.elixir);
                displayListPlayer(player1.listeU);
                printf("\n");
                displayListPlayer(player2.listeU);
                printf("\n");



                ///********************* NOUVEAUTE ***************************

                PositionnePlayerOnPlateau_Upgade( player1.listeU, jeuUpgrade);
                PositionnePlayerOnPlateau_Upgade( player2.listeU, jeuUpgrade);
                jeu = ConversionEnTplateauJeu(jeuUpgrade);



               // finalcombat(&player1.listeU,&player2.listeU,jeuUpgrade);
                 // Abletoattack(player1.listeU,player2.listeU);
//                printf("Nous displayons les listes apres les combats \n");
//                displayListPlayer(player1.listeU);
//                printf("\n");
//                displayListPlayer(player2.listeU);

                movep(player1.listeU, player2.listeU, jeu);
                movep2(player2.listeU, player1.listeU, jeu);

                printf(" \nLE TOUR %d EST PASSEE \n\n", nb_tour);
                nb_tour ++;



                ///********************* fin NOUVEAUTE ***************************







                //affichage du jeu à chaque tour
                efface_fenetre(pWinSurf);
                prepareAllSpriteDuJeu(jeu,LARGEURJEU,HAUTEURJEU,TabSprite,pWinSurf);
                maj_fenetre(pWindow);
                SDL_Delay(500);  //valeur du délai à modifier éventuellement

                //LECTURE DE CERTAINES TOUCHES POUR LANCER LES RESTAURATIONS ET SAUVEGARDES
                const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
                if ( pKeyStates[SDL_SCANCODE_G] ){
                        /* Ajouter vos appels de fonctions ci-dessous qd le joueur appuye sur D */

                        // APPELEZ ICI VOTRE FONCTION DE SAUVEGARDE/RESTAURATION DEMANDEE
                        message("achat unité","Placer ici votre fonction d'achat d'une Gargouille");

                        //Ne pas modifiez les 4 lignes ci-dessous
                        efface_fenetre(pWinSurf);
                        prepareAllSpriteDuJeu(jeu,LARGEURJEU,HAUTEURJEU,TabSprite,pWinSurf);
                        maj_fenetre(pWindow);
                        SDL_Delay(300);
                }
                if ( pKeyStates[SDL_SCANCODE_C] ){
                        /* Ajouter vos appels de fonctions ci-dessous qd le joueur appuye sur C */

                        // APPELEZ ICI VOTRE FONCTION DE SAUVEGARDE/RESTAURATION DEMANDEE
                        message("achat unité","Placer ici votre fonction d'achat d'un Chevalier");

                        //Ne pas modifiez les 4 lignes ci-dessous
                        efface_fenetre(pWinSurf);
                        prepareAllSpriteDuJeu(jeu,LARGEURJEU,HAUTEURJEU,TabSprite,pWinSurf);
                        maj_fenetre(pWindow);
                        SDL_Delay(300);
                }
                if ( pKeyStates[SDL_SCANCODE_D] ){
                        /* Ajouter vos appels de fonctions ci-dessous qd le joueur appuye sur D */

                        // APPELEZ ICI VOTRE FONCTION DE SAUVEGARDE/RESTAURATION DEMANDEE
                        message("achat unité","Placer ici votre fonction d'achat d'un Dragon?");

                        //Ne pas modifiez les 4 lignes ci-dessous
                        efface_fenetre(pWinSurf);
                        prepareAllSpriteDuJeu(jeu,LARGEURJEU,HAUTEURJEU,TabSprite,pWinSurf);
                        maj_fenetre(pWindow);
                        SDL_Delay(300);
                }
                if ( pKeyStates[SDL_SCANCODE_Q] ){
                        /* Ajouter vos appels de fonctions ci-dessous qd le joueur appyue sur S */

                        // APPELEZ ICI VOTRE FONCTION DE SAUVEGARDE/RESTAURATION DEMANDEE
                        message("achat unité","Placer ici votre fonction d'achat d'un Archer");

                        //Ne pas modifiez les 4 lignes ci-dessous
                        efface_fenetre(pWinSurf);
                        prepareAllSpriteDuJeu(jeu,LARGEURJEU,HAUTEURJEU,TabSprite,pWinSurf);
                        maj_fenetre(pWindow);
                        SDL_Delay(300);
                }
                if ( pKeyStates[SDL_SCANCODE_ESCAPE] ){
                        cont = 0;  //sortie de la boucle
                }

        }
        //fin boucle du jeu

        SDL_FreeSurface(pSpriteTour); // Libération de la ressource occupée par le sprite
        SDL_FreeSurface(pSpriteTourRoi);
        SDL_FreeSurface(pSpriteArcher);
        SDL_FreeSurface(pSpriteChevalier);
        SDL_FreeSurface(pSpriteDragon);
        SDL_FreeSurface(pSpriteGargouille);
        SDL_FreeSurface(pSpriteEau);
        SDL_FreeSurface(pSpriteHerbe);
        SDL_FreeSurface(pSpritePont);
        SDL_FreeSurface(pWinSurf);
    }
    else
    {
        fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
    }

    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return 0;
}
