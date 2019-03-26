#include "geom2d.h"
#include <stdio.h>

int main(int argc, char **argv){
  Point A = set_point(4,1);

  Point B = set_point(0,0);
	Point D = set_point(3,0);

	Point F = set_point(-1, 1);
	Point G = set_point(2, 1);
	Point H = set_point(200, 0);
	Point I = set_point(200, 1);
	
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
  
  double rez0 = distance_point_segment(A, B, D);
  double rez1 = distance_point_segment(F, B, D);
  double rez2 = distance_point_segment(G, B, D);
  double rez3 = distance_point_segment(H, B, D);
  double rez4 = distance_point_segment(I, B, D);
  
  printf("Norme de V : %f\n",norme_vecteur(V));
  printf("Produit de V et V2 : %f\n", produit_scalaire(V,V2));
  printf("Distance entre A et B : %f\n", distance_point(A,B)); 
	printf("Distance de A à BD = %f \n",	rez0); 
	printf("Distance de F à BD = %f \n",	rez1); 
	printf("Distance de G à BD = %f \n",	rez2); 
	printf("Distance de H à BD = %f \n",	rez3); 
	printf("Distance de I à BD = %f \n",	rez4);
	
}

