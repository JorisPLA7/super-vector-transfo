#ifndef bezier
#include "TTV.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define bezier
#define bezier_N_MAX 10000

typedef struct Bezier2_struct {
	Point c0;
	Point c1;
	Point c2;
} Bezier2;

typedef struct Bezier3_struct {
	Point c0;
	Point c1;
	Point c2;
	Point c3;
} Bezier3;

typedef struct tab_bezier2_struct {
	Bezier2 tab[bezier_N_MAX];
	int n;
} tab_bezier2;

typedef struct tab_bezier3_struct {
	Bezier3 tab[bezier_N_MAX];
	int n;
} tab_bezier3;

tab_bezier2 creer_tab_bezier2();
tab_bezier3 creer_tab_bezier3();

double distance_point_bezier2(Point P,Bezier2 B,double ti);
Point calcul_point_bezier2(Bezier2 b,double t);
Point calcul_point_bezier3(Bezier3 b,double t);
Bezier3 conversion_b2_b3(Bezier2 b);

Bezier2 approx_bezier2(TTV_Point seq,int j1,int j2);

void ecrire_countour_bezier2(tab_bezier2 tab2,FILE* sortie,int H);










#endif //bezier
