//#include <stdio.h>
#include <string.h>
#include "TTV.h"
#include "image_pbm.h"
#include "types_macros.h"
#include "trouver_vect.h"
#include "directX12.h"

#define SYNTAXE printf("Erreur de syntaxe saisissez: %s <nom fich entree> <nom fich sortie sans extension>\n", argv[0]);



int main(int argc, char *argv[]) {
  Image I;
  FILE* sortie_contours = stdout; //stdout sortie par defaut 
  FILE* sortie_eps = stdout;
  char contours_stroke[1000] = {0} ;
  char eps_fill[1000]= {0} ;

  if (argc != 3){
    SYNTAXE
    return 1;
  }
  else if (argc == 3) {
      
      strcpy(contours_stroke, argv[2]);
      strcat(contours_stroke, ".contours");
      sortie_contours = fopen(contours_stroke, "w"); //choix de sortie optionnel
     
      strcpy(eps_fill, argv[2]);
      strcat(eps_fill, ".eps");
      sortie_eps = fopen(eps_fill, "w"); 
  }
  
  I = lire_fichier_image(argv[1]);
  
  // le masque est une image
  Image M = creer_masque(I);
  //MAXCONTOURS defini dans TTV.h
  // on crée une variable contenant MAXCONTOURS ttv pour chaque contours
  Contours C = creer_Contours_vide(MAXCONTOURS);
  
  Point p_depart[MAXCONTOURS];  // on crée autant de pts de depart que de 
  //contours, c'est logique.
  //déso si c'est un peu dégueu de pas avoir les deux dans une seule variable.
  
  ecrire_image(I); //affichage
  ecrire_image(M);
  
  printf("debut\n");
  
  
  // reste à ajouter une exeption si plus de MAXCONTOURS contours ! ! ! !
  //on extrait les contours 1 par 1 tant que le masque est non vide <=> il reste
  //des contours à découvrir
  for (int i =0; !est_vide(M); i++) {
  //par la je suspecte une segfault, d'ou les print de partout
  //bonne chance 0:)
    //printf("AAA\n");
    p_depart[i]= trouver_pixel_depart(M);
    
    //printf("BBB\n");
    afficher_point(p_depart[i]);
    //printf("BBBis\n");
    
    afficher_contour(I, p_depart[i], &C.c[i]);
    
    //printf("CCc\n");
    rafraichir_masque(M, C); //retire les points noir du masque couverts par des contours précédents.
    
    //printf("DDD\n");
    ecrire_image(M);
  
  }
  
  /*
  //pour point dans departs afficher_point(point);
  
  
  
  //////
  ecrire_fichier(sortie_contours, tab_points);
  
  //mode 0 on fait que les traits
  
  
  /////////         //contours
  afficher_graphique(tab_points, I.L,  I.H, sortie_eps, 2);
  //char execution[1000] = "gv ";
  
  //strcat(execution, nom_eps);
  //system(execution);
   */

  return 0;  
  
}
