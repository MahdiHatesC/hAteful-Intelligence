#include <stdio.h>
#include "hateful_io.h"

int main() {
    t_donnee donnees[NB_DONNEES];
    lire_fichier("src/donnees.csv", donnees);
    
    for (int i = 0; i < 5; i++) {
        printf("donnee[%d]: genre=%d, taille=%d, poids=%d, imc=%d\n",
            i, donnees[i].genre, donnees[i].taille, donnees[i].poids, donnees[i].imc);
    }
    return 0;
}