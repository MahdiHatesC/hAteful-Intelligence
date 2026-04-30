#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include "hateful_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/*
Calculer toutes les moyennes d'un tableau de donnees
*/
void calculer_moyennes(t_donnee* donnee, float* moyenne_taille, float* moyenne_poids, float* moyenne_imc);

/*
Trouver l'écart type
*/
void calculer_ecarts_types(t_donnee* donnee, float moyenne_taille,float moyenne_poids, float moyenne_imc, float* et_taille, float* et_poids, float* et_imc);
/*
Retourner un tableau possèdant les données normalisées. On veut que la moyenne soit de zéro, et que l'écart-type soit de 1.

applique la formule suivante:

z = x - mu / sigma -> donnnée - moyenne de la population / écart-type;

*/
t_donnee* normaliser_donnees(t_donnee* donnees, float moyenne_taille, float moyenne_poids, float moyenne_imc, float et_taille, float et_poids, float et_imc);

#endif