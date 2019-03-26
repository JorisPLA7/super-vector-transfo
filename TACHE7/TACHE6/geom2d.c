#include <math.h>
#include <stdio.h>
#include "geom2d.h"


double distance_point_segment(Point p, Point s1, Point s2){
		if (s1.x == s2.x && s1.y == s2.y) return distance_point(p, s1);
		else {
		  Vecteur ab = vect_bipoint(s1, s2);
		  Vecteur ap = vect_bipoint(s1, p);
		  
		  double lambda = produit_scalaire(ap,ab)/produit_scalaire(ab,ab);
		  
		  Point q = s1;
		  q.x+= lambda*ab.x;
		  q.y+= lambda*ab.y;
		  		  
		  if(lambda<0) return norme_vecteur(ap);
		  else if (lambda <=1) return norme_vecteur(vect_bipoint(q, p));
		  else return norme_vecteur(vect_bipoint(s2, p));
		} 

}

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

double produit_scalaire(Vecteur A , Vecteur B){
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


