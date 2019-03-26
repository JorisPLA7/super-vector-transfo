#include <string.h>
#include "TTV.h"
#include "image_pbm.h"
#include "types_macros.h"
#include "trouver_vect.h"
#include "directX12.h"
#include "simplification_douglas.h"


#define SYNTAXE printf("Erreur de syntaxe saisissez: %s <nom fich entree pbm ou contours> <nom fich sortie sans extension> <finesse d>\n", argv[0]);


int main(int argc, char *argv[]) {
  double duck;
  Image I;
  FILE* sortie_contours = NULL; 
  FILE* sortie_eps = NULL;
  char contours_stroke[1000] = {0} ;
  char eps_fill[1000]= {0} ;
	
  if (argc != 4){
    SYNTAXE
    return 1;
  }
  else if (argc == 4) {
      
      //lecture finesse dans duck
      sscanf(argv[3], "%lf", &duck);
      
      strcpy(contours_stroke, argv[2]);
      strcat(contours_stroke, "_simplifie.contours");
      sortie_contours = fopen(contours_stroke, "w"); //choix de sortie optionnel
     
      strcpy(eps_fill, argv[2]);
      strcat(eps_fill, "_simplifie.eps");
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
  
  //on extrait les contours tant que masque non vide
  //on simpifie les contours
  for (int i =0; !est_vide(M); i++){
    p_depart[i]=trouver_pixel_depart(M);
    
    afficher_contour(I, p_depart[i], &C.c[i]);
    
		C.nb++;
		
		
		//retire des pixels noirs 
    rafraichir_masque(M, C);
 
  }
	

	int segments=0;
	//On ecrit les contours dans le fichier de sortie 
	for(int i=0;i<C.nb;i++){
		C.c[i] = simplif_douglas(C.c[i] ,0, C.c[i].nb-2, duck);
		ecrire_fichier(sortie_contours,C.c[i],i);
		segments+=C.c[i].nb;
	}

	//Affichage des contours correspondants (directX12)
	afficher_graphiques_multiples(C,sortie_eps,I.L,I.H,2);

  printf("Nom de l'image : %s. Nombre de contours : %d. Somme des nombres de segments : %d\n",argv[1],C.nb,segments/2);
  return 0;  
  
}
