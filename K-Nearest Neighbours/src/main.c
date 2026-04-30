#include <stdio.h>
#include "hateful_io.h"
#include "statistiques.h"

int main() {
    t_donnee donnees[NB_DONNEES];
    lire_fichier("src/donnees.csv", donnees);

    float moyenne_taille, moyenne_poids, moyenne_imc;
    float et_taille, et_poids, et_imc;

    calculer_moyennes(donnees,&moyenne_taille,&moyenne_poids,&moyenne_imc);
    calculer_ecarts_types(donnees,moyenne_taille,moyenne_poids,moyenne_imc, &et_taille, &et_poids, &et_imc);
    t_donnee* donnees_traitees = normaliser_donnees(donnees,moyenne_taille,moyenne_poids,moyenne_imc,et_taille,et_poids,et_imc);
    
    float max = donnees_traitees[0].taille;
    for(int i = 0; i < NB_DONNEES; ++i){
        if(donnees_traitees[i].taille > max) {
            max = donnees_traitees[i].taille;
        }
    }
    printf("%f\n",max);

    system("pause");
    return 0;
}