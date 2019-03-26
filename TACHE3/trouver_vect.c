#include "trouver_vect.h"
#include "geom2d.h"
#include <stdio.h>
#include "types_macros.h"


Point trouver_pixel_depart(Image I){
  Point p;
  p.x = -1.;
  p.y = -1.; //valeurs impossibles retournées uniquement si rien n'est trouvé dans l'image
  
  //parcours de l'image
  for(double y =0.; y<I.H; y++){
    for(double x=0.; x<I.L; x++){
      if (get_pixel_image(I, x+1, y)==BLANC && get_pixel_image(I, x+1, y+1) == NOIR){
        p.x = x;
        p.y = y;
        return p;
        //on retourne le point qui correspond aux exigeances  
      }
    }
  }
  return p;//en cas d'erreur c'est {-1,-1}
  
  
}

void tourner_gauche(Robot* r){
  r->o =(r->o-1)%4; //voir l'implémentation du type enum;
}

void tourner_droite(Robot* r){
  r->o =(r->o+1)%4;
}

void nouvelle_orientation(Image I, Robot* r){
  Pixel pg; 
  Pixel pd;
  
  //recup valeurs pg et pd
  switch (r->o) {
    case Nord :
      pg=get_pixel_image(I,r->p.x, r->p.y) ;
      pd=get_pixel_image(I,r->p.x+1, r->p.y) ;
      break;
    case Est : 
      pg=get_pixel_image(I,r->p.x+1, r->p.y) ;
      pd=get_pixel_image(I,r->p.x+1, r->p.y+1) ;
      break;
    case Sud :
      pg=get_pixel_image(I,r->p.x+1, r->p.y+1) ;
      pd=get_pixel_image(I,r->p.x, r->p.y+1) ;
      break;
    case Ouest : 
      pg=get_pixel_image(I,r->p.x, r->p.y+1) ;
      pd=get_pixel_image(I,r->p.x, r->p.y) ;
      break;
  }
  
  if (pg == NOIR) {
    tourner_gauche(r); //r est (déjà) un pointeur à cet endroit
  }
  else if (pd == BLANC) {
    tourner_droite(r);
  }
   
  
}

void avancer(Robot *r){
  switch (r->o) {
    case Nord :
      r->p.y--;
      break;
    case Est : 
      r->p.x++;
      break;
    case Sud :
      r->p.y++;
      break;
    case Ouest : 
      r->p.x--;
      break;
  }
}

TTV_Point memoriser_position(Robot r, TTV_Point tab_points){
  //affchage desactivé car problématique pour les grandes images
  //fprintf(stdout, "Robot: X: %f  Y: %f  O: %d\n ", r.p.x, r.p.y, r.o);
  
  return ajouter_element_TTV_Point(tab_points, r.p);
}

void afficher_contour(Image I, TTV_Point *tab_points) {
  Point depart = trouver_pixel_depart(I);
  Robot r;
  r.p = depart;
  r.o = Est; //notre robot est opérationnel à présent
  
  do {
    *tab_points = memoriser_position(r, *tab_points);
    avancer(&r);
    nouvelle_orientation(I, &r);
    
  } while ( !( (r.p.x == depart.x) && (r.p.y == depart.y) && (r.o == Est) )); //ne pas negliger le "!" qui renverse la condition !
  
  *tab_points = memoriser_position(r, *tab_points);
}














