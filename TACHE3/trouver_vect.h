#ifndef trouvervect
#define trouvervect

#include "geom2d.h"
#include "image_pbm.h"
#include "TTV.h"


typedef enum {Nord, Est, Sud, Ouest} Orientation;

typedef struct robot_struct {
  Point p;
  Orientation o;
  } Robot ;

Point trouver_pixel_depart(Image I);

void nouvelle_orientation(Image I, Robot *r);

void avancer(Robot *r);

TTV_Point memoriser_position(Robot r,TTV_Point tab_points);

void afficher_contour(Image I, TTV_Point *tab_points);

void tourner_gauche(Robot *r);

void tourner_droite(Robot *r);






#endif

