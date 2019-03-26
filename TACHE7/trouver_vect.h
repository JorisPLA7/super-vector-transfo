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

Image rafraichir_masque(Image I, Contours C);

Image creer_masque(Image I);

Point trouver_pixel_depart(Image I);

void nouvelle_orientation(Image I, Robot *r);

void avancer(Robot *r);

TTV_Point memoriser_position(Robot r,TTV_Point tab_points);

void afficher_contour(Image I, Point p, TTV_Point *tab_points);

void tourner_gauche(Robot *r);

void tourner_droite(Robot *r);

void traduction_contour_M(Image I, Point p, TTV_Point *tab_points, Image *M);





#endif

