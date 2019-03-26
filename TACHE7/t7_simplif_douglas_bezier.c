#include "bezier.h"


#define SYNTAXE printf("Erreur de syntaxe saisissez: %s <nom fich entree pbm ou contours> <nom fich sortie sans extension> <finesse d>\n", argv[0]);


int main(int argc, char** argv) {
    printf("tests :\n");
    tests_bezier();

    return 0;
}
