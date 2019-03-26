/****************************************************************************** 
  Implémentation du module image_pbm
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"types_macros.h"
#include"image_pbm.h"

/* macro donnant l'indice d'un pixel de coordonnées (_x,_y) de l'image _I */
#define INDICE_PIXEL(_I,_x,_y) ((_x)-1)+(_I).L*((_y)-1)

/* création d'une image PBM de dimensions L x H avec tous les pixels blancs */
Image creer_image(UINT L, UINT H)
{
	Image I;
	UINT i;
	
	I.L = L;
	I.H = H;
	
	/* alloctaion dynamique d'un tableau de L*H Pixel*/
	I.tab = (Pixel *)malloc(sizeof(Pixel)*L*H);
	
	/* test si le tableau a ete correctement alloue */
	if (I.tab == (Pixel *)0)
	{
		ERREUR_FATALE("Impossible de creer une image");
	}
	
	/* remplir le tableau avec des pixels blancs */
	for (i=0; i<L*H; i++)
		I.tab[i] = BLANC;
		
	return I;
}

/* suppression de l'image I = *p_I*/
void supprimer_image(Image *p_I)
{
	free(p_I->tab);
	p_I->L = 0;
	p_I->H = 0;
}

/* renvoie la valeur du pixel (x,y) de l'image I
   si (x,y) est hors de l'image la fonction renvoie BLANC */
Pixel get_pixel_image(Image I, int x, int y)
{
	if (x<1 || x>I.L || y<1 || y>I.H)
		return BLANC;
	return I.tab[INDICE_PIXEL(I,x,y)];
}

/* change la valeur du pixel (x,y) de l'image I avec la valeur v
   si (x,y) est hors de l'image la fonction ne fait rien */
void set_pixel_image(Image I, int x, int y, Pixel v)
{
	if (x<1 || x>I.L || y<1 || y>I.H)
		return;
	I.tab[INDICE_PIXEL(I,x,y)] = v;
}

/* lire l'image dans le fichier nommé nom_f
   s'il y a une erreur dans le fichier le programme s'arrete en affichant
   un message */
Image lire_fichier_image(char *nom_f)
{
	FILE *f;
	UINT L,H;
	//UINT x,y;
	char *ligne;
	char c;
	size_t n;
	ssize_t l_ligne;
	//int res_fscanf;
	Image I;
	
	/* ouverture du fichier nom_f en lecture */
	f = fopen(nom_f, "r");
	if (f == (FILE *)NULL)
	{
		ERREUR_FATALE("lire_fichier_image : ouverture du fichier impossible\n");
	}
	
	/* lecture et test de la ligne 1 */
	ligne = (char *)NULL;
	n = 0;
	l_ligne = getline(&ligne, &n, f);
	/* la ligne est correcte si et ssi ligne = {'P','1',0} 
	  soit une chaine de 3 caracteres (le dernier est le caractere nul) */
	if (l_ligne != 3)
	{
		ERREUR_FATALE("lire_fichier_image : ligne 1 incorrecte\n");
	}
	if ((ligne[0] != 'P') || (ligne[1] != '1'))
	{
		ERREUR_FATALE("lire_fichier_image : ligne 1 incorrecte\n");
	}
	free(ligne);
	
	/* lecture et test de la ligne 2 */
	ligne = (char *)NULL;
	n = 0;
	getline(&ligne, &n, f);
	
	if(ligne[0]!='#'){
	  ERREUR_FATALE("Commentaire manquant en ligne 2. Erreur fatale.\n");
	}
  free(ligne);

	/* lecture des dimensions */
	fscanf(f, "%d", &L);
	fscanf(f, "%d", &H);
	

	
	/* création de l'image de dimensions L x H */
	I = creer_image(L,H);
	
	/* lecture des pixels du fichier 
	   seuls les caracteres '0' (BLANC) ou '1' (NOIR) 
	   doivent etre pris en compte */
	
	for(int i=0; i<I.H; i++){
    for(int j=0; j<I.L; j++){
      //pour chaque pixel :

      c=' ';
      
      //on lit jusqu'à avoir éliminé les separateurs
      // <=> jusqu'à avoir un '1' ou '0'    
      while (c!='1' && c!='0'){
        //à chaque lecture on vérifie que le fichier ne soit pas déjà lu en entier
        if (feof(f)){
	        ERREUR_FATALE("Taille de l'image incorrecte. Erreur fatale.\n");
	      }
	      fscanf(f, "%c",&c);
	    }
	    //on est sorti du while <=> on a un '1' ou  un '0'
	    set_pixel_image(I, j+1, i+1, c-'0');
      
      }
    }
    
    
	/*
	while (i<H*L){
	  if (feof(f)){
	    ERREUR_FATALE("Taille de l'image incorrecte. Erreur fatale.\n");
	  }
	  fscanf(f, "%c",&c);
	  if(c=='1'||c=='0'){
	    I.tab[i]=c-'0';
	    i++;
	  }
	  
	}
	*/
	
	
	/* fermeture du fichier */
	fclose(f);
	
	return I;
}

/* écrire l'image I à l'écran */
void ecrire_image(Image I)
{
  //afficher taille image
  fprintf(stdout, "image de taille L: %d x H: %d \n", I.L, I.H);
  //aff image
  char a;
  Pixel p;
  for(int i=1; i<=I.H; i++){
    for(int j=1; j<=I.L; j++){
      //aff ligne
      p = get_pixel_image(I, j, i);
      
      a =( (p==1)?  '#' : '_' ) ;
            
      fprintf(stdout, "%c", a);
    }
    //retour à la ligne
    fprintf(stdout, "\n");
  }
}


void effet_negatif(Image* I){
  Pixel p;
  for(int i=1; i<=I->H; i++){
    for(int j=1; j<=I->L; j++){
      //aff ligne
      p = get_pixel_image(*I, j, i);
      set_pixel_image(*I, j, i, 1-p);
    }
    //retour à la ligne

  }
}

