#ifndef GEOM2D
#define GEOM2D

//TYPES

typedef struct Vecteur_struct {
  double x, y; //coordonnées
} Vecteur;

typedef struct Point_struct {
  double x, y; //coordonnées
} Point;

//OPERATIONS

Point set_point(double x, double y);

Point add_point(Point P1, Point P2);

//retourne vecteur correspondant à AB->
Vecteur vect_bipoint(Point A, Point B);

Point mult_scalaire_point(double lambda, Point A);

Vecteur mult_scalaire_vect(double lambda, Vecteur A);

double norme_vecteur(Vecteur A);

double produit_vect (Vecteur A , Vecteur B);

double distance_point(Point A, Point B);

//EFFETS DE BORD

void afficher_point(Point A);

void afficher_vect(Vecteur A);

#endif //GEOM2D

