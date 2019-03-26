#ifndef TTV
#define TTV

#include "geom2d.h"
#include "types_macros.h"


typedef struct TTV_Point_struct {
  UINT nb; //nombre d'elem
  UINT cap; //capacite du tableau (sizeof)
  UINT taille_elt; //taille d'un element
  Point *tab; //tableau de points
} TTV_Point;

TTV_Point creer_TTV_point_vide();

TTV_Point ajouter_element_TTV_Point(TTV_Point T,Point e);

TTV_Point concatener_TTV_Point(TTV_Point T1, TTV_Point T2);

void supprime_TTV_Point(TTV_Point *ptr_T);


void ecrire_fichier(FILE* f, TTV_Point tab_points);




#endif
