#include <stdio.h>
#include "TTV.h"
#include "image_pbm.h"
#include "types_macros.h"
#include "trouver_vect.h"

#define SYNTAXE printf("Erreur de syntaxe saisissez: %s <nom fich entree> [nom fich sortie]\n", argv[0]);

int main(int argc, char *argv[]) {
  Image I;
  FILE* sortie = stdout; //stdout sortie par defaut 
  
  
  if (argc<2 && argc>3){
    SYNTAXE
    return 1;
  }
  else if (argc == 3) {
    sortie = fopen(argv[2], "a"); //choix de sortie optionnel
  }
  
  I = lire_fichier_image(argv[1]);
  ecrire_image(I);
  
  Point p = trouver_pixel_depart(I);
  //afficher_point(p);
  TTV_Point tab_points = creer_TTV_point_vide();
  afficher_contour(I, &tab_points);
  
  fprintf(sortie, "Fichier %s, taille L %d * H %d comporte un contour en %d points.\n",argv[1], I.L, I.H, tab_points.nb);
  //ecrire_fichier(sortie, tab_points);
  
  
  return 0;  
  
}
