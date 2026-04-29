#include <stdio.h>
#include "hateful_io.h"

int main() {
    t_donnee donnees[NB_DONNEES];
    lire_fichier("src/donnees.csv", donnees);
    
    for(int i = 0; i < NB_DONNEES; ++i){
        printf("%f\n",donnees[i].poids);
    }

    system("pause");
    return 0;
}