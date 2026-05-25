#define STB_IMAGE_IMPLEMENTATION
#include "traitement_donnees.h"
#define NB_CLUSTERS 16

void get_pixel(stbi_uc *image, size_t img_width, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a){
    const stbi_uc *p = image + (4 * (y * img_width + x));
    if(p == NULL){
        return;
    }
    *r = p[0];
    *g = p[1];
    *b = p[2];
    *a = p[3];
}

void cluster_plus_proche(struct t_couleur clusters[],struct t_couleur *couleur){
    int distance_min = distance_cluster_couleur(*couleur, clusters[0]);
    int indice_cluster = 0;

    for(int i = 1; i < NB_CLUSTERS; i++){
        int nouvelle_distance = distance_cluster_couleur(*couleur, clusters[i]);
        if (nouvelle_distance < distance_min){
            distance_min = nouvelle_distance;
            indice_cluster = i;
        }
    }

    couleur->index_cluster_associe = indice_cluster;
}