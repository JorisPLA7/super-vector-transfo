#include <math.h>
#include <stdio.h>
#include "geom2d.h"

Point set_point(double x, double y) {
  Point P = {x, y};
  return P;
}

Point add_point(Point P1, Point P2) {
  return set_point(P1.x+P2.x, P1.y+P2.y);
}

Vecteur vect_bipoint(Point A, Point B){
  Vecteur V = {B.x-A.x, B.y-A.y};
  return V;
}

Point mult_scalaire_point(double lambda, Point A) {
  return set_point(lambda*A.x, lambda*A.y);
}


Vecteur mult_scalaire_vect(double lambda, Vecteur A){
  Vecteur V = {lambda*A.x, lambda*A.y};
  return V;
}

double norme_vecteur(Vecteur A){
  return sqrt(pow(A.x,2) + pow(A.y,2));
}

double produit_vect (Vecteur A , Vecteur B){
  return (A.x*B.x + A.y*B.y);
}

double distance_point(Point A, Point B){
  return sqrt(pow(A.x-B.x,2) + pow(A.y-B.y,2));
}


void afficher_point(Point A){
  fprintf(stdout, "Point :\n   x=%f\n   y=%f\n", A.x, A.y); 
}


void afficher_vect(Vecteur A){
  fprintf(stdout, "Vecteur :\n   x=%f\n   y=%f\n", A.x, A.y);
}


