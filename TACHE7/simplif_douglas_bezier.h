#ifndef simplif_douglas_bezier
#include "bezier.h"
#define simplif_douglas_bezier

#define bezier_N_MAX 10000

typedef struct tab_bezier2_struct {
	Bezier2 tab[bezier_N_MAX];
	int n;
} tab_bezier2;

typedef struct tab_bezier3_struct {
	Bezier3 tab[bezier_N_MAX];
	int n;
} tab_bezier3;

tab_bezier2 creer_tab_bezier2();
tab_bezier2 concatener_bezier2_struct(tab_bezier2 L1, tab_bezier2 L2);

tab_bezier3 creer_tab_bezier3();
tab_bezier3 concatener_bezier3_struct(tab_bezier3 L1, tab_bezier3 L2);

tab_bezier2 simplification_douglas_peucker_bezier2(TTV_Point C,int j1, int j2, double d);















#endif 
