#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TAILLE 5

typedef struct coordonnee
{
    int nX;
    int nY;
}coordonnee;

typedef enum booleen
{
    HAUT = 1,
    BAS = 0
}booleen;

void init(int [TAILLE][TAILLE]);
booleen rechercher_vide(int [TAILLE][TAILLE], coordonnee);
int placer(int [TAILLE][TAILLE], coordonnee, int);
void avancer(int [TAILLE][TAILLE], coordonnee *, booleen);
void avancer_d(coordonnee *);
void corriger(int [TAILLE][TAILLE], coordonnee *);
void avancer_g(coordonnee *);
void afficher(int [TAILLE][TAILLE]);

#endif
