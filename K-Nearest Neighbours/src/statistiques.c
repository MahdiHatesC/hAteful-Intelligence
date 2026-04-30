#include "statistiques.h"

void calculer_moyennes(t_donnee* donnees, float* moyenne_taille, float* moyenne_poids,float* moyenne_imc){
    float total_taille = 0;
    float total_poids = 0;
    float total_imc = 0;

    for(int i = 0; i < NB_DONNEES; i++){
        total_poids += donnees[i].poids;
        total_taille += donnees[i].taille;
        total_imc += donnees[i].imc;
    }

    *moyenne_poids = total_poids / NB_DONNEES;
    *moyenne_taille = total_taille / NB_DONNEES;
    *moyenne_imc = total_imc / NB_DONNEES;
}

void calculer_ecarts_types(t_donnee* donnee, float moyenne_taille,float moyenne_poids, float moyenne_imc, float* et_taille, float* et_poids, float* et_imc){
    float total_somme_poids = 0;
    float total_somme_taille = 0;
    float total_somme_imc = 0;

    for(int i = 0; i < NB_DONNEES; ++i){
        total_somme_poids += pow(donnee[i].poids - moyenne_poids,2);
        total_somme_taille += pow(donnee[i].taille - moyenne_taille,2);
        total_somme_imc += pow(donnee[i].imc - moyenne_imc,2);
    }

    *et_taille = sqrt(total_somme_taille / NB_DONNEES);
    *et_poids = sqrt(total_somme_poids / NB_DONNEES);
    *et_imc = sqrt(total_somme_imc / NB_DONNEES);
}

t_donnee* normaliser_donnees(t_donnee* donnees, float moyenne_taille, float moyenne_poids, float moyenne_imc, float et_taille, float et_poids, float et_imc){
    t_donnee* donnees_traites = malloc(NB_DONNEES * sizeof(t_donnee));
    if (!donnees_traites) return NULL;

    for(int i = 0; i < NB_DONNEES; ++i){
        donnees_traites[i].genre = donnees[i].genre;
        donnees_traites[i].poids = (donnees[i].poids - moyenne_poids) / et_poids;
        donnees_traites[i].taille = (donnees[i].taille - moyenne_taille) / et_taille;
        donnees_traites[i].imc = (donnees[i].imc - moyenne_imc) / et_imc;
    }

    return donnees_traites;
}