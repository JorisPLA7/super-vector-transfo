#include <stdio.h>
#include "image_pbm.h"
#include "types_macros.h"

#define SYNTAXE printf("Erreur de syntaxe saisissez: %s <nom fichier a ouvrir> \n", argv[0]);

int main(int argc, char *argv[]) {
  Image I;
  
  if (argc != 2){
    SYNTAXE
    return 1;
  }
  
  I = lire_fichier_image(argv[1]);
  ecrire_image(I);
  
  effet_negatif(&I);

  ecrire_image(I);
  
  return 0;  
  
}
