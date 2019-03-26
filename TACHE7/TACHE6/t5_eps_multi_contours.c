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
  
  // reste à ajouter une exeption si plus de MAXCONTOURS contours ! ! ! !
  //on extrait les contours 1 par 1 tant que le masque est non vide <=> il reste
  //des contours à découvrir
  for (int i =0; !est_vide(M); i++){
    p_depart[i]=trouver_pixel_depart(M);
    //afficher_contour(I, p_depart[i], &C.c[i]);
		traduction_contour_M(I, p_depart[i], &C.c[i] ,&M);
		C.nb++;
    //rafraichir_masque(M, C); //retire les points noir du masque couverts par des contours précédents.
 
  }
	//Affichage des contours correspondants (directX12)
	afficher_graphiques_multiples(C,sortie_eps,I.L,I.H,2);

	int cpt_segments=0;
	//On ecrit les contours dans le fichier de sortie 
	for(int i=0;i<C.nb;i++){
		ecrire_fichier(sortie_contours,C.c[i],i);
		cpt_segments+=C.c[i].nb-1;
		//-2 car 1 seg de moins que de pointes et il y a 
	}
	
  printf("Nom de l'image : %s. Nombre de contours : %d. Somme des nombres de segments : %d\n",argv[1], C.nb, cpt_segments);
  return 0;  
  
}
