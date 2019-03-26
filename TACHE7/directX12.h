#ifndef dx12
#define dx12

#include <stdio.h>
#include <stdlib.h>
#include "TTV.h" //pour le type TTV_Point

//cree le document EPS et le fait afficher si désiré
void afficher_graphique(TTV_Point tab_points,int L, int H, FILE* sortie, char mode);

void afficher_graphiques_multiples(Contours C,FILE *sortie,int L,int H,int mode);



//ghg





#endif //dx12
