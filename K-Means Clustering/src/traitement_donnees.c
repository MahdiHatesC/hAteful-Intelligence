#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "traitement_donnees.h"


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

void calculer_centroides(struct t_couleur clusters[], struct t_couleur *couleurs, int img_width, int img_height, int* fin){
    int nb_pixels = img_height * img_width;
    
    // Use int arrays to avoid overflow during accumulation
    int sum_r[NB_CLUSTERS] = {0};
    int sum_g[NB_CLUSTERS] = {0};
    int sum_b[NB_CLUSTERS] = {0};
    int count[NB_CLUSTERS] = {0};

    for(int i = 0; i < nb_pixels; i++){
        int k = couleurs[i].index_cluster_associe;
        sum_r[k] += couleurs[i].r;
        sum_g[k] += couleurs[i].g;
        sum_b[k] += couleurs[i].b;
        count[k]++;
    }

    *fin = 1;
    for(int i = 0; i < NB_CLUSTERS; i++){
        if(count[i] > 0){
            stbi_uc new_r = sum_r[i] / count[i];
            stbi_uc new_g = sum_g[i] / count[i];
            stbi_uc new_b = sum_b[i] / count[i];

            if(clusters[i].r != new_r || clusters[i].g != new_g || clusters[i].b != new_b){
                *fin = 0;
            }

            clusters[i].r = new_r;
            clusters[i].g = new_g;
            clusters[i].b = new_b;
        }
    }
}

int distance_cluster_couleur(struct t_couleur couleur, struct t_couleur cluster){
    int da = (couleur.a - cluster.a)*(couleur.a - cluster.a);
    int dr = (couleur.r - cluster.r)*(couleur.r - cluster.r);
    int dg = (couleur.g - cluster.g)*(couleur.g - cluster.g);
    int db = (couleur.b - cluster.b)*(couleur.b - cluster.b);
    return da + dr + dg + db;
}

int nb_aleatoire (int min, int max) {
    return (rand() % (max - min + 1)) + min;
}