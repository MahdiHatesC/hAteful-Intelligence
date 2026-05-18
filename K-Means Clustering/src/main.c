#include "allo.h"
#include "traitement_donnees.h"
int main(void){
    int width, height, channels; //Ces variables seront remplies avec l'appel de la fonction stbi_load

    unsigned char *img = stbi_load("src/fleur.jpg", &width, &height, &channels, 0);
    stbi_uc r,g,b,a;

    if (img == NULL){
        printf("Raison: %s\n",stbi_failure_reason());
        printf("Erreur de chargement de l'image...");
    }

    int nb_pixels = 0;
    for(int y = 0; y< height; y++){
        for(int x = 0; x < width; x++){
            nb_pixels++;
        }
    }
    printf("%d",nb_pixels / 1280);

}