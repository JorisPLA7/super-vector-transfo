#include "bezier.h"


Point calcul_point_bezier2(Bezier2 b,double t){
	Point p;
	p.x=b.c0.x*pow(1-t,2)+b.c1.x*2*t*(1-t)+b.c2.x*pow(t,2);
	p.y=b.c0.y*pow(1-t,2)+b.c1.y*2*t*(1-t)+b.c2.y*pow(t,2);
	return p;
}

Point calcul_point_bezier3(Bezier3 b,double t){
	Point p;
	p.x=b.c0.x*pow(1-t,3)+b.c1.x*3*t*pow(1-t,2)+b.c2.x*3*pow(t,2)*(1-t)+b.c3.x*pow(t,3);
	p.y=b.c0.y*pow(1-t,3)+b.c1.y*3*t*pow(1-t,2)+b.c2.y*3*pow(t,2)*(1-t)+b.c3.y*pow(t,3);
	return p;
}

//a verifier 
Bezier3 conversion_b2_b3(Bezier2 b2){
	Bezier3 b3;
	b3.c0=b2.c0;
	b3.c1.x=(1./3.)*b2.c0.x+(2./3.)*b2.c1.x;
	b3.c1.y=(1./3.)*b2.c0.y+(2./3.)*b2.c1.y;
	b3.c2.x=(2./3.)*b2.c1.x+(1./3.)*b2.c2.x;
	b3.c2.y=(2./3.)*b2.c1.y+(1./3.)*b2.c2.y;
	b3.c3=b2.c2;
	return b3;
}


Bezier2 approx_bezier2(TTV_Point seq,int j1,int j2){
	Bezier2 b2;
	Bezier2 seq_b2[10000];
	double ti;
	int n=j2-j1;
	double nr = (double)n;
	printf("n = %d\n", n);
	if (n==2){
		b2.c0=seq.tab[j1];
		b2.c1=seq.tab[j1];
		b2.c2=seq.tab[j2];
	}
	else if (n>2){
		for (int i=1;i<n;i++){
			b2.c0=seq.tab[j1];
			ti=i/nr;
			b2.c1.x=(seq.tab[i+j1].x-pow(1-ti,2)*seq.tab[j1].x-pow(ti,2)*seq.tab[j2].x)/(2*ti*(1-ti));
			b2.c1.y=(seq.tab[i+j1].y-pow(1-ti,2)*seq.tab[j1].y-pow(ti,2)*seq.tab[j2].y)/(2*ti*(1-ti));
			b2.c2=seq.tab[j2];
			printf("c1.x = %10.3f, c1.y = %10.3f\n",b2.c1.x,b2.c1.y);
			seq_b2[i-1]=b2;
		}
		
		b2.c0=seq.tab[j1];
		double compteur_x=0;
		double compteur_y=0;
		double compteur_wi=0;
		for (int i=1;i<n;i++){	
			ti=i/nr;
			compteur_x+=2*ti*(1-ti)*seq_b2[i-1].c1.x;
			compteur_y+=2*ti*(1-ti)*seq_b2[i-1].c1.y;
		}
		for (int i=1;i<n;i++){
			ti=i/nr;
			compteur_wi+=2*ti*(1-ti);	
		}
		printf("compteur_x = %10.3f, compteur_y = %10.3f.,compteur_wi=%10.3f\n", compteur_x,compteur_y,compteur_wi);
		b2.c1.x=compteur_x/compteur_wi;
		b2.c1.y=compteur_y/compteur_wi;
		
		b2.c2=seq.tab[j2];
	}
	return b2;	
	
}





int main(){
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


}
