#include <stdio.h>
#include <stdlib.h>
#include "header.h"



//Faire un point .h et un .c pour le main et un .c pour les fonction


int main()
{
    coordonnee coord;
    coord.nX = TAILLE/2-1;
    coord.nY = TAILLE/2;
    int nValeur = 1;
    booleen nVide;
    int nGrille[TAILLE][TAILLE];
    init(nGrille);

    while(nValeur<=TAILLE*TAILLE){
        nVide = rechercher_vide(nGrille, coord);
        if(nVide==BAS){
            nValeur = placer(nGrille, coord, nValeur);
            avancer(nGrille, &coord, nVide);
        }else{
            avancer(nGrille, &coord, nVide);
        }
    }

    afficher(nGrille);

    return 0;
}


