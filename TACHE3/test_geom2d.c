#include "geom2d.h"
#include <stdio.h>

int main(int argc, char **argv){
  Point A = set_point(10,10);
  Point B = set_point(-1,5);
  Point C = add_point(A,B);
  afficher_point(A);
  afficher_point(B);
  afficher_point(C);
  
  Vecteur V = vect_bipoint(A,B);
  Vecteur V2 = vect_bipoint(A,C);
  afficher_vect(V);
  afficher_vect(V2);
  
  V=mult_scalaire_vect(2,V);
  C=mult_scalaire_point(3,C);
  afficher_point(C);
  afficher_vect(V);
  
  printf("Norme de V : %f\n",norme_vecteur(V));
  printf("Produit de V et V2 : %f\n", produit_vect(V,V2));
  printf("Distance entre A et B : %f\n", distance_point(A,B)); 
}

