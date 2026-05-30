#include "allo.h"
#include "traitement_donnees.h"
int main(void){
    int width, height, channels; //Ces variables seront remplies avec l'appel de la fonction stbi_load

    unsigned char *img = stbi_load("src/fleur.jpg", &width, &height, &channels, 4);
    stbi_uc r,g,b,a;

    if (img == NULL){
        printf("Raison: %s\n",stbi_failure_reason());
        printf("Erreur de chargement de l'image...");
    }

    //Commençons le carnage:
    //Collecte de points:
    int nb_pixel = width * height;
    struct t_couleur* pixels = malloc(sizeof(struct t_couleur) * nb_pixel);

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            int i = y * width + x;

            get_pixel(img,width,x,y,&pixels[i].r,&pixels[i].g,&pixels[i].b,&pixels[i].a);
        }
    }

    printf("Premier pixel: r=%d g=%d b=%d a=%d\n", pixels[0].r, pixels[0].g, pixels[0].b, pixels[0].a);

    // Créer clusters:
    struct t_couleur* clusters = malloc(sizeof(struct t_couleur) * NB_CLUSTERS);
    //initialiser clusters:
    for(int i = 0; i < NB_CLUSTERS; i++){
        int index_aleatoire = nb_aleatoire(0, nb_pixel);
        clusters[i].a = pixels[index_aleatoire].a;
        clusters[i].r = pixels[index_aleatoire].r;
        clusters[i].g = pixels[index_aleatoire].g;
        clusters[i].b = pixels[index_aleatoire].b;
    }

    // Début de l'algorithme:
    int fin = 0;
    while(fin == 0){
        for(int i = 0; i < nb_pixel; i++){
            cluster_plus_proche(clusters, &pixels[i]);
        }
        calculer_centroides(clusters,pixels,width,height, &fin);
    }

    printf("Cluster 0: r=%d g=%d b=%d\n", clusters[0].r, clusters[0].g, clusters[0].b);
    printf("Pixel 0 cluster: %d\n", pixels[0].index_cluster_associe);
    ///Écrire la nouvelle image:
    
    //Appliquer les clusters:
    for(int i = 0; i < nb_pixel; i++){
        int c = pixels[i].index_cluster_associe;
        img[4*i+0] = clusters[c].r;
        img[4*i+1] = clusters[c].g;
        img[4*i+2] = clusters[c].b;
        img[4*i+3] = 255;
    }

    stbi_write_png("fleur_compressee.png", width, height, 4, img, width * 4);

    free(pixels);
    free(clusters);
    stbi_image_free(img);
    
    return 0;
}