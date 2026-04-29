#include "statistiques.h"

void calculer_moyenne(t_donnee* donnees, float* moyenne_taille, float* moyenne_poids){
    float total_taille = 0;
    float total_poids = 0;

    for(int i = 0; i < NB_DONNEES; i++){
        total_poids += donnees[i].poids;
        total_taille += donnees[i].taille;
    }

    *moyenne_poids = total_poids / NB_DONNEES;
    *moyenne_taille = total_taille / NB_DONNEES;
}

float calculer_ecarts_types(t_donnee* donnee, float moyenne_taille,float moyenne_poids){
    
}