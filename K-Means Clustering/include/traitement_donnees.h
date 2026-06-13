#ifndef TRAITEMENT_DONNEES_H
#define TRAITEMENT_DONNEES_H
#include <stdlib.h>
#include <stdio.h>
#include "../stb_image/stb_image.h"
#include "../stb_image/stb_image_write.h"
#define NB_CLUSTERS 16

typedef struct t_couleur{
    stbi_uc r, g, b, a; 
    int index_cluster_associe;
} t_couleur;

/*
Fonction qui retourne dans les paramètres les valeurs RGB d'un pixel donné dans l'image.
*/
void get_pixel(stbi_uc *image, size_t img_width, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a);

/*
Fonction qui assigne à un point le cluster le plus proche.
*/
void cluster_plus_proche(struct t_couleur clusters[],struct t_couleur *couleur);

int distance_cluster_couleur(struct t_couleur couleur, struct t_couleur cluster);

/*
Fonction qui calcule le centre de gravité.
*/

void calculer_centroides(struct t_couleur clusters[], struct t_couleur *couleurs, int img_width, int img_height, int* fin);

int nb_aleatoire (int min, int max);

#endif