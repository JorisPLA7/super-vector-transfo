#include "TTV.h"
#include "geom2d.h"
#include "types_macros.h"
#include <stdio.h>



Contours creer_Contours_vide(int max_contours){
  Contours C;
  C.nb = 0;
  // on crée les (TTV_Point)s
  for (int i=0; i< max_contours; i++) {
    C.c[i] = creer_TTV_point_vide();
  }
  return C;
}


TTV_Point creer_TTV_point_vide(){
  TTV_Point T;
  T.nb = 0;
  T.cap = 10;
  T.taille_elt = sizeof(Point);
  T.tab = (Point*)malloc(sizeof(Point)*T.cap);
  if (T.tab==NULL){
    printf("Allocation du TTV_Point impossible\n");
    exit(1);
  }
  return T;
}

//ajoutrer un element au ttv
//quand le ttv est plein on double sa taille
TTV_Point ajouter_element_TTV_Point(TTV_Point T,Point e){
  
  //printf("TTV nb : %d cap : %d ", T.nb, T.cap);
  
  if (T.nb == T.cap){
    //printf(" !!! ");
    T.cap *=2;
    T.tab=realloc(T.tab,T.taille_elt*T.cap); //reallocation d'espace memoire
    if (T.tab==NULL){
      printf("Reallocation du TTV_Point impossible\n");
      exit(1);
    }  
  }
  
  //printf("nv_cap : %d \n", T.cap);
   
  //ajout de la valeur au ttv
  T.tab[T.nb]=e;
  //incrementation de la taille du ttv
  T.nb = T.nb+1; 
  return T;
}

TTV_Point concatener_TTV_Point(TTV_Point T1, TTV_Point T2){
  UINT i;
  if (T1.nb+T2.nb>T1.cap){
    T1.cap=T1.nb+T2.nb;
    T1.tab=realloc(T1.tab,T1.taille_elt*T1.cap);
    if (T1.tab==NULL){
      printf("Reallocation du TTV_Point impossible\n");
      exit(1);       
   }
 }
 for (i=0;i<T2.nb;i++) T1.tab[T1.nb+i]=T2.tab[i];
 T1.nb+=T2.nb;
 return T1;
}

void supprime_TTV_Point(TTV_Point *ptr_T){
  free(ptr_T->tab);
}

//f est déjà ouvert en ecriture
void ecrire_fichier(FILE* f, TTV_Point tab_points,int nb_contour){
  fprintf(f, "%d\n\n", nb_contour); //pour le moment on a un seul contour
  //pour 1 a 1
  fprintf(f, "%d\n", tab_points.nb); //nombre de points du contour 
  
  for(int i=0; i<tab_points.nb; i++){
    fprintf(f, " %0.1f %0.1f \n", tab_points.tab[i].x, tab_points.tab[i].y);
  }
  fprintf(f,"\n\n");
  return;
}








