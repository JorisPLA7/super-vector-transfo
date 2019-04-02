#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2017/2018
#############################################################################
# utilisation des variables internes $< $@ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond à toutes les dépendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################


#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'édition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = test_image_pbm test_geom2d t5_eps_multi_contours t6_simplification t7_simplif_douglas_bezier


#############################################################################
# definition des regles
#############################################################################

########################################################
# la règle par défaut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules
t7_simplif_douglas_bezier.o : t7_simplif_douglas_bezier.c simplif_douglas_bezier.h geom2d.h TTV.h bezier.h types_macros.h image_pbm.h directX12.h trouver_vect.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module t7_simplif_douglas_bezier"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

simplif_douglas_bezier.o : simplif_douglas_bezier.c simplif_douglas_bezier.h geom2d.h TTV.h bezier.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module simplif_douglas_bezier"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

bezier.o : bezier.c bezier.h geom2d.h TTV.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module bezier"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

simplification_douglas.o : simplification_douglas.c simplification_douglas.h  TTV.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module simplification_douglas"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

t6_simplification.o : t6_simplification.c trouver_vect.h image_pbm.h geom2d.h types_macros.h TTV.h directX12.h simplification_douglas.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module t6_simplification"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

directX12.o : directX12.c directX12.h geom2d.h TTV.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module directX12 (c)"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

TTV.o : TTV.c TTV.h types_macros.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module TTV"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

trouver_vect.o : trouver_vect.c trouver_vect.h image_pbm.h geom2d.h TTV.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module trouver_vect"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

t5_eps_multi_contours.o : t5_eps_multi_contours.c trouver_vect.h image_pbm.h geom2d.h types_macros.h TTV.h directX12.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module t5_eps_multi_contours"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

image_pbm.o : image_pbm.c image_pbm.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_image_pbm.o : test_image_pbm.c image_pbm.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

geom2d.o : geom2d.c geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geom2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_geom2d.o : test_geom2d.c geom2d.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_geom2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
		
########################################################
# regles explicites de creation des executables
t7_simplif_douglas_bezier : t7_simplif_douglas_bezier.o simplif_douglas_bezier.o bezier.o geom2d.o TTV.o image_pbm.o directX12.o trouver_vect.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

#bezier : bezier.o geom2d.o TTV.o simplif_douglas_bezier.o
#	@echo ""
#	@echo "---------------------------------------------"
#	@echo "Creation de l'executable "$@
#	@echo "---------------------------------------------"
#	$(CC) $^ $(LDOPTS) -o $@

t6_simplification : t6_simplification.o trouver_vect.o image_pbm.o geom2d.o TTV.o directX12.o simplification_douglas.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

t5_eps_multi_contours : t5_eps_multi_contours.o trouver_vect.o image_pbm.o geom2d.o TTV.o directX12.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_image_pbm : test_image_pbm.o image_pbm.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_geom2d : test_geom2d.o geom2d.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@


# regle pour "nettoyer" le répertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
