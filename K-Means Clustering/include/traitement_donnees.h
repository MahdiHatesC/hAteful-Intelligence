#ifndef TRAITEMENT_DONNEES_H
#define TRAITEMENT_DONNEES_H
#include <stdlib.h>
#include <stdio.h>
#include "../stb_image/stb_image.h"

typedef struct t_couleur{
    int r;
    int g;
    int b;
    int a;
    int index_cluster_associe;
};

/*
Fonction qui retourne dans les paramètres les valeurs RGB d'un pixel donné dans l'image.
*/
void get_pixel(stbi_uc *image, size_t img_width, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a);

/*
Fonction qui assigne à un point le cluster le plus proche.
*/
void cluster_plus_proche(struct t_couleur clusters[],struct t_couleur couleur);

int distance_cluster_couleur(struct t_couleur couleur, struct t_couleur cluster){
    int da = (couleur.a - cluster.a)*(couleur.a - cluster.a);
    int dr = (couleur.r - cluster.r)*(couleur.r - cluster.r);
    int dg = (couleur.g - cluster.g)*(couleur.g - cluster.g);
    int db = (couleur.b - cluster.b)*(couleur.b - cluster.b);
    return da + dr + dg + db;
}

#endif