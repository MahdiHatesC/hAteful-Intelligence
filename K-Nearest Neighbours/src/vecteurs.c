#include "vecteurs.h"

void voisins_plus_proches(t_donnee* donnee_traitees, float k, int* nb_hommes, int* nb_femmes, float taille, float poids, float imc){
    *nb_hommes = 0;
    *nb_femmes = 0;

    float k_carre = k * k;
    float poids_carre;
    float taille_carre;
    float imc_carre;

    for(int i = 0; i < NB_DONNEES; ++i){
        poids_carre = (donnee_traitees[i].poids - poids) * (donnee_traitees[i].poids - poids);
        taille_carre = (donnee_traitees[i].taille - taille) * (donnee_traitees[i].taille - taille);
        imc_carre = (donnee_traitees[i].imc - imc) * (donnee_traitees[i].imc - imc);

        if(k_carre >= (poids_carre + taille_carre + imc_carre)){
            if(donnee_traitees[i].genre == MALE){
                *nb_hommes += 1;
            } else {
                *nb_femmes += 1;
            }
        }
    }
}