#include "simplif_douglas_bezier.h"


tab_bezier2 concatener_bezier2_struct(tab_bezier2 L1, tab_bezier2 L2) {
	tab_bezier2 B=L1;
	for (int i=0;i<L2.n;i++){
		B.tab[L1.n+i]=L2.tab[i];
	}
	B.n=L1.n+L2.n;
	return B;
}




tab_bezier2 simplification_douglas_peucker_bezier2(TTV_Point C,int j1, int j2, double d){
	int n = j2-j1;
	
	//Approximation de la sequence C
	Bezier2 B = approx_bezier2(C,j1,j2);
	tab_bezier2 L=creer_tab_bezier2();
	
	int dmax=0;
	int k = j1; 
	
	for (int j=j1+1;j<=j2;j++){
		int i=j-j1;
		double ti=(double)i/(double)n;
		double dj=distance_point_bezier2(C.tab[j],B,ti);
		if (dmax<dj){
			dmax=dj;
			k=j;
		}
	}

	if (dmax<d){
		L.tab[0]=B;
		L.n=1;
	}
	else {
		tab_bezier2 L1=creer_tab_bezier2();
		tab_bezier2 L2=creer_tab_bezier2();
		L1=simplification_douglas_peucker_bezier2(C,j1,k,d);
		L2=simplification_douglas_peucker_bezier2(C,k,j2,d);
		L=concatener_bezier2_struct(L1,L2);
	}
	return L;
}
