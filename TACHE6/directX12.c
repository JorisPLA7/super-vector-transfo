#include <stdio.h>
#include <stdlib.h>
#include "geom2d.h" //pour le type Point
#include "TTV.h" //pour le type TTV_Point


//adapte le repere des images vers le repere adobe
Point transfo_p(Point entree, int H) {
  Point p = {entree.x, H-entree.y};
  return p;
  
}


void afficher_graphique_mode0(TTV_Point tab_points,FILE* sortie,int H){
  Point p;
  p = transfo_p(tab_points.tab[0], H);
  fprintf(sortie, "%10.3f %10.3f moveto ", p.x, p.y);
    
  for (int i = 1; i<tab_points.nb; i++) {
    p = transfo_p(tab_points.tab[i], H);
    fprintf(sortie, "\n%10.3f %10.3f lineto", p.x, p.y);
      
  //   %10.3f
  //10 cra au total 3 apres la virgule
    
    }
  fprintf(sortie, "\n0 setlinewidth stroke\n");
}

void afficher_graphique_mode1(TTV_Point tab_points,FILE* sortie,int H){
  Point p,p2;
  
  for (int i = 0; i<tab_points.nb-1; i++) {
    p = transfo_p(tab_points.tab[i], H);
    p2 = transfo_p(tab_points.tab[i+1],H);
    fprintf(sortie,"newpath\n%10.3f %10.3f 0.2 0 360 arc fill\nclosepath\n",p.x,p.y);
    fprintf(sortie, "newpath\n%10.3f %10.3f moveto %10.3f %10.3f lineto\n0 setlinewidth stroke\nclosepath\n", p.x, p.y,p2.x,p2.y);
      
  //   %10.3f
  //10 cra au total 3 apres la virgule
    
    }
}


void afficher_graphique_mode2(TTV_Point tab_points,FILE* sortie,int H){
  Point p;
  p = transfo_p(tab_points.tab[0], H);
  fprintf(sortie, "%10.3f %10.3f moveto ", p.x, p.y);
    
  for (int i = 1; i<tab_points.nb; i++) {
    p = transfo_p(tab_points.tab[i], H);
    fprintf(sortie, "\n%10.3f %10.3f lineto", p.x, p.y);
      
  //   %10.3f
  //10 cra au total 3 apres la virgule
    
    }
  
}

//cree le document EPS et le fait afficher si désiré
void afficher_graphique(TTV_Point tab_points,int L, int H, FILE* sortie, char mode){
  
  
  fprintf(sortie, "%%!PS-Adobe-3.0 EPSF-3.0\n");
  //def taille image 
  fprintf(sortie, "%%%%BoundingBox: 0 0 %d %d\n", L, H);
  
  if (tab_points.nb > 0) {
    switch (mode){
      case 0 :
        afficher_graphique_mode0(tab_points,sortie,H);
        break;
      case 1 :
        afficher_graphique_mode1(tab_points,sortie,H);
        break;
      case 2 :
        afficher_graphique_mode2(tab_points,sortie,H);
				fprintf(sortie, "\n0 setlinewidth fill\n");
        break;
    }
    
    
    
  }
  fprintf(sortie, "\nshowpage");
}


void afficher_graphiques_multiples(Contours C,FILE *sortie,int L,int H,int mode){
	fprintf(sortie, "%%!PS-Adobe-3.0 EPSF-3.0\n");
  //def taille image 
  fprintf(sortie, "%%%%BoundingBox: 0 0 %d %d\n", L, H);
	for (int i=0;i<C.nb;i++){
		switch (mode){
      case 0 :
        afficher_graphique_mode0(C.c[i],sortie,H);
        break;
      case 1 :
        afficher_graphique_mode1(C.c[i],sortie,H);
        break;
      case 2 :
        afficher_graphique_mode2(C.c[i],sortie,H);
        break;
    }
	}
	if(mode==2)fprintf(sortie, "\n0 setlinewidth fill\n");
}
