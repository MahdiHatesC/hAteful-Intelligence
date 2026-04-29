#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include "hateful_io.h"
/*
Calculer toutes les moyennes d'un tableau de donnees
*/
void calculer_moyennes(t_donnee* donnee, float* moyenne_taille, float* moyenne_poids);

/*
Trouver l'écart type
*/
float calculer_ecarts_types(t_donnee* donnee, float moyenne_taille,float moyenne_poids);
/*
Retourner un tableau possèdant les données normalisées. On veut que la moyenne soit de zéro, et que l'écart-type soit de 1.
*/
t_donnee* normaliser_donnees(t_donnee donnee);

#endif