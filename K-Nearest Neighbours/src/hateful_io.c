#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hateful_io.h"

void lire_fichier(char* nom_fichier){
    FILE* fichier = fopen(nom_fichier,"r");

    if (fichier == NULL){
        printf("le nom de fichier n'est pas bon.");
        return;
    }

    // commencer la lecture:
    char buffer[100]; //Caractère assez gros pour lire la plus grosse ligne du fichier
    while(fgets(buffer,100,fichier)){
        char* token = strtok(buffer, ",");
        while(token) {
            printf("%s\n",token);
            token = strtok(NULL, ",");
            printf("%s\n",token);
            token = strtok(NULL, ",");
            printf("%s\n",token);
            token = strtok(NULL, ",");
            printf("%s\n",token);
            token = strtok(NULL, ",");
        }     
    }

    fclose(fichier);
}

