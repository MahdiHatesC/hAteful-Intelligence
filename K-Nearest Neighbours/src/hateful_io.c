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
        int taille;
        int poids;
        int imc;
            if (token) {
            //Le genre
            strncpy(genre,token,sizeof(genre) -1);
            genre[sizeof(genre) - 1] = '\0';
            token = strtok(NULL, ",");


            if (!token) { i++; continue; }
            
            
            //Le taille
            sscanf(token,"%d",&taille);
            token = strtok(NULL, ",");
            
            if (!token) { i++; continue; }
            
            //Le poids
            sscanf(token,"%d",&poids);
            token = strtok(NULL, ",");

            if (!token) { i++; continue; }

            //IMC
            sscanf(token,"%d",&imc);

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

