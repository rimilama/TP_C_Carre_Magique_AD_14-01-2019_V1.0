#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//**************************************************************************************************************//
//
//  Description : Procedure qui initialise le tableau
//
//  Entrées : 1 matrice
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void init(int nGrille[TAILLE][TAILLE]){
    int nI, nJ;

    for(nI=0;nI<TAILLE;nI++){;
        for(nJ=0;nJ<TAILLE;nJ++){
            nGrille[nI][nJ] = 0;
        }
    }
}


//**************************************************************************************************************//
//
//  Description : Fonction qui regarde si la case est vide
//
//  Entrées : 1 matrice, 1 structure
//
//  Sorties : 1 enum
//
//  Notes : /
//
//***************************************************************************************************************//
booleen rechercher_vide(int nGrille[TAILLE][TAILLE], coordonnee coord){
    if(nGrille[coord.nX][coord.nY] == 0){
        return BAS;
    }else{
        return HAUT;
    }
}


//**************************************************************************************************************//
//
//  Description : Fonction qui place un chiffre dans la matrice
//
//  Entrées : 1 matrice, 1 structure, 1 entier
//
//  Sorties : 1 entier
//
//  Notes : /
//
//***************************************************************************************************************//
int placer(int nGrille[TAILLE][TAILLE], coordonnee coord, int nValeur){
    nGrille[coord.nX][coord.nY] = nValeur;
    nValeur ++;
    return nValeur;
}


//**************************************************************************************************************//
//
//  Description : Procedure qui déplace un "pion" sur la matrice
//
//  Entrées : 1 matrice, 1 structure, 1 enum
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void avancer(int nGrille[TAILLE][TAILLE], coordonnee * coord, booleen nVide){
    if(nVide==BAS){
        avancer_d(coord);
    }else{
        corriger(nGrille, coord);
    }
}


//**************************************************************************************************************//
//
//  Description : Procedure qui deplace le "pion" sur la droite
//
//  Entrées : 1 structure
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void avancer_d(coordonnee * droit){
    if(droit->nX != 0){
        droit->nX --;
    }else{
        droit->nX = TAILLE-1;
    }

    if(droit->nY != TAILLE-1){
        droit->nY ++;
    }else{
        droit->nY = 0;
    }
}


//**************************************************************************************************************//
//
//  Description : Procedure qui corrige la position du "pion"
//
//  Entrées : 1 matrice, 1 structure
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void corriger(int nGrille[TAILLE][TAILLE], coordonnee * coord){
    int nVide;
    do{
        avancer_g(coord);
        nVide = rechercher_vide(nGrille, *coord);
    }while(nVide==HAUT);
}


//**************************************************************************************************************//
//
//  Description : Procedure qui deplace le "pion" sur la gauche
//
//  Entrées : 1 structure
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void avancer_g(coordonnee * gauche){
    if(gauche->nX != 0){
        gauche->nX --;
    }else{
        gauche->nX = TAILLE-1;
    }

    if(gauche->nY != 0){
        gauche->nY --;
    }else{
        gauche->nY = TAILLE-1;
    }
}


//**************************************************************************************************************//
//
//  Description : Procedure qui affiche la matrice remplie
//
//  Entrées : 1 matrice
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void afficher(int nGrille[TAILLE][TAILLE]){
    int nI, nJ;
    for(nI=0;nI<TAILLE;nI++){
            printf("| ");
        for(nJ=0;nJ<TAILLE;nJ++){
            if(nGrille[nI][nJ]<=9){
                printf("%d  | ", nGrille[nI][nJ]);
            }else{
                printf("%d | ", nGrille[nI][nJ]);
            }
        }
        printf("\n");
    }
}
