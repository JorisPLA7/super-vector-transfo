#include "simplif_douglas_bezier.h"
#include "image_pbm.h"
#include "TTV.h"
#include "image_pbm.h"
#include "types_macros.h"
#include "directX12.h"
#include "trouver_vect.h"

// #define SYNTAXE printf("Erreur de syntaxe saisissez: %s <nom fich entree pbm ou contours> <nom fich sortie sans extension> <finesse d>\n", argv[0]);

void creer_eps_bezier(FILE* sortie_contours,FILE* sortie_eps,int mode,TTV_Point C,double d,int H,int L){
	if (mode==2){
		tab_bezier2 tab2=creer_tab_bezier2();
		tab2=simplification_douglas_peucker_bezier2(C,0,C.nb-1,d);
		
		ecrire_countour_bezier2(tab2,sortie_eps,H);

	}
}





int tests_bezier(){
	Bezier2 b2;
	b2.c0=set_point(0,0);
	b2.c1=set_point(1,2);
	b2.c2=set_point(4,0);
	afficher_point(calcul_point_bezier2(b2,0));
	afficher_point(calcul_point_bezier2(b2,0.5));

	Bezier3 b3=conversion_b2_b3(b2);
	printf("\nApres conversion en b3 : (c0,c1,c2,c3)\n");
	
	afficher_point(b3.c0);
	afficher_point(b3.c1);
	afficher_point(b3.c2);
	afficher_point(b3.c3);
	printf("\nCalcul des points pour b3 :\n");
	afficher_point(calcul_point_bezier3(b3,0));
	afficher_point(calcul_point_bezier3(b3,0.5));

	TTV_Point seq = creer_TTV_point_vide();
	seq = ajouter_element_TTV_Point(seq,set_point(0,0));
	seq =ajouter_element_TTV_Point(seq,set_point(1,0));
	seq =ajouter_element_TTV_Point(seq,set_point(1,1));
	seq =ajouter_element_TTV_Point(seq,set_point(1,2));
	seq =ajouter_element_TTV_Point(seq,set_point(2,2));
	seq =ajouter_element_TTV_Point(seq,set_point(3,2));
	seq =ajouter_element_TTV_Point(seq,set_point(3,3));
	seq =ajouter_element_TTV_Point(seq,set_point(4,3));
	seq =ajouter_element_TTV_Point(seq,set_point(5,3));

	b2=approx_bezier2(seq,0,8);
	printf("Affichage des points de la courbe approx : (c0,c1,c2)\n");
	afficher_point(b2.c0);
	afficher_point(b2.c1);
	afficher_point(b2.c2);

    Point p;
    double step;
    for(int i =1; i <= seq.nb-1 ; i++){
        step =(double)i/(double)(seq.nb-1);
        p = seq.tab[i];
        printf("distance point %d : %10.3f\n", i, distance_point_bezier2(p,b2, step) );
    }

	//Creation du fichier EPS correspondant apres utilisation de l'algo du cours
	FILE* sortie_contours =stdout;
	FILE* sortie_eps = fopen("sorties/test.eps","w");
	int mode=2; 
	double d=2.;
	int H=500;
	int L=H;
	creer_eps_bezier(sortie_contours,sortie_eps,mode,seq,d,H,L);
	return 0;
}

int main(int argc, char** argv) {
	FILE* sortie_contours = stdout; 
  FILE* sortie_eps = stdout;
	Image I = lire_fichier_image(argv[1]);
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
	// On ecrit le debut du fichier de sortie
	fprintf(sortie_eps, "%%!PS-Adobe-3.0 EPSF-3.0\n");
  fprintf(sortie_eps, "%%%%BoundingBox: 0 0 %d %d\n", I.L, I.H);

	double d=2.;
	//Pour chaque contour on ecrit dans le fichier de sortie la simplification en bezier
  for(int j=0;j<C.nb;j++){  
		creer_eps_bezier(sortie_contours,sortie_eps,2,C.c[j],d,I.H,I.L);
	}

	fprintf(sortie_eps, "\nshowpage");
	//tests_bezier();


	
    return 0;
}
