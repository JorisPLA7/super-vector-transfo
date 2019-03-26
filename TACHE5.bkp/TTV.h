#ifndef TTV
#define TTV

#include "geom2d.h"
#include "types_macros.h"

//nombre de contours opour initialiser la structure contours
#define MAXCONTOURS 10000 

typedef struct TTV_Point_struct {
  UINT nb; //nombre d'elem
  UINT cap; //capacite du tableau (sizeof)
  UINT taille_elt; //taille d'un element
  Point *tab; //tableau de points
} TTV_Point;

typedef struct TTV_contours_struct {
  UINT nb; //nombre de contours
  TTV_Point c[MAXCONTOURS]; //tableau de contours
  
} Contours;

Contours creer_Contours_vide(int max_contours);

TTV_Point creer_TTV_point_vide();

TTV_Point ajouter_element_TTV_Point(TTV_Point T,Point e);

TTV_Point concatener_TTV_Point(TTV_Point T1, TTV_Point T2);

void supprime_TTV_Point(TTV_Point *ptr_T);


void ecrire_fichier(FILE* f, TTV_Point tab_points,int nb_contour);




#endif
