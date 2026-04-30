#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hateful_io.h"

void lire_fichier(char* nom_fichier, t_donnee* donnees){
    FILE* fichier = fopen(nom_fichier,"r");

    if (fichier == NULL){
        printf("le nom de fichier n'est pas bon.");
        return;
    }

    // commencer la lecture:
    char buffer[100]; //Caractère assez gros pour lire la plus grosse ligne du fichier
    int i = 0;
    fgets(buffer,100,fichier);
    while(fgets(buffer,100,fichier) && i < NB_DONNEES){
        t_donnee nouvelle_donnee;
        char* token = strtok(buffer, ",");
        char genre[10];
        float taille;
        float poids;
        float imc;
            if (token) {
            //Le genre
            strncpy(genre,token,sizeof(genre) -1);
            genre[sizeof(genre) - 1] = '\0';
            token = strtok(NULL, ",");


            if (!token) { i++; continue; }
            
            
            //Le taille
            sscanf(token,"%f",&taille);
            token = strtok(NULL, ",");
            
            if (!token) { i++; continue; }
            
            //Le poids
            sscanf(token,"%f",&poids);
            token = strtok(NULL, ",");

            if (!token) { i++; continue; }

            //IMC
            sscanf(token,"%f",&imc);

            nouvelle_donnee.genre = (strcmp(genre,"Male") ? FEMALE : MALE);
            nouvelle_donnee.taille = taille;
            nouvelle_donnee.poids = poids;
            nouvelle_donnee.imc = imc;

            donnees[i] = nouvelle_donnee;
        }
           
        i++;
    }

    fclose(fichier);
}

int calculer_imc(float poids_livres, float taille_m){
    float poids_kg = poids_livres * 0.453592f;
    return poids_kg / (taille_m * taille_m);
}

int index_imc(float imc){
    if (imc < 16)   return 0;
    if (imc < 18.5) return 1;
    if (imc < 25)   return 2;
    if (imc < 30)   return 3;
    if (imc < 35)   return 4;
    return 5;
}

