#include "bezier.h"

tab_bezier2 creer_tab_bezier2(){
	tab_bezier2 nouveau;
	nouveau.n=0;
	return nouveau;
}

tab_bezier3 creer_tab_bezier3(){
	tab_bezier3 nouveau;
	nouveau.n=0;
	return nouveau;
}

double distance_point_bezier2(Point P,Bezier2 B,double ti){
	
	Point b_point = calcul_point_bezier2(B, 0.);
	double minimum = distance_point(P, b_point);
	double valeur_courante = minimum;
	for(double step=0; step<=1; step+=ti) {
		valeur_courante = distance_point(P, calcul_point_bezier2(B, step));
		
		if (valeur_courante < minimum){
			minimum = valeur_courante;
		}

	}
	return minimum;
}


double distance_point_bezier3(Point P,Bezier3 B,double ti){
	
	Point b_point = calcul_point_bezier3(B, 0.);
	double minimum = distance_point(P, b_point);
	double valeur_courante = minimum;
	for(double step=0; step<=1; step+=ti) {
		valeur_courante = distance_point(P, calcul_point_bezier3(B, step));
		
		if (valeur_courante < minimum){
			minimum = valeur_courante;
		}

	}
	return minimum;
}

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

void ecrire_countour_bezier2(tab_bezier2 tab2,FILE* sortie,int H){
	for (int j=0; j<tab2.n; j++){
		    fprintf(sortie, "%10.3f %10.3f moveto %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f curveto\n0 setlinewidth stroke\n",tab2.tab[j].c0.x,tab2.tab[j].c0.y, tab2.tab[j].c1.x,tab2.tab[j].c1.y,tab2.tab[j].c1.x,tab2.tab[j].c1.y,tab2.tab[j].c2.x,tab2.tab[j].c2.y);
	}

}



