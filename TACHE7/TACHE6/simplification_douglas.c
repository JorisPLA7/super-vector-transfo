#include "simplification_douglas.h"

TTV_Point simplif_douglas(TTV_Point C, int j1, int j2, double d) {
  
  //valeur de retour simplifiée, L dans le poly
  TTV_Point simple = creer_TTV_point_vide();
  TTV_Point L1=creer_TTV_point_vide();
	TTV_Point L2=creer_TTV_point_vide();
  double dmax = 0;
  int k = j1;
  double dj;
  for(int j = j1+1; j<=j2; j++) {
    dj = distance_point_segment(C.tab[j], C.tab[j1], C.tab[j2]);
		//printf("Distance: %lf\n",dj);
    if (dmax< dj){
      dmax = dj;
      k=j;
    }
  }
  
  //si tous les points intermediaires sont dans la zone de tolérance.
  if (dmax <= d) {
		
    simple = ajouter_element_TTV_Point(simple,C.tab[j1]);
    simple = ajouter_element_TTV_Point(simple,C.tab[j2]);
        
  }
  else {
    L1 = simplif_douglas(C, j1, k, d);
    L2 = simplif_douglas(C, k, j2, d);
    
    simple = concatener_TTV_Point(L1,L2);
  }
  return simple;
  

}
