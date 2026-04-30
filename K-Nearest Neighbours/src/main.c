#include <stdio.h>
#include "hateful_io.h"
#include "statistiques.h"
#include "vecteurs.h"

int main() {
    t_donnee donnees[NB_DONNEES];
    lire_fichier("src/donnees.csv", donnees);

    float moyenne_taille, moyenne_poids, moyenne_imc;
    float et_taille, et_poids, et_imc;
    float taille, poids, imc;
    int nb_hommes, nb_femmes;

    calculer_moyennes(donnees,&moyenne_taille,&moyenne_poids,&moyenne_imc);
    calculer_ecarts_types(donnees,moyenne_taille,moyenne_poids,moyenne_imc, &et_taille, &et_poids, &et_imc);
    t_donnee* donnees_traitees = normaliser_donnees(donnees,moyenne_taille,moyenne_poids,moyenne_imc,et_taille,et_poids,et_imc);
    
    printf("Entrez la taille(cm):\n");
    scanf("%f", &taille);

    printf("Entrez le poids:\n");
    scanf("%f", &poids);

    imc = calculer_imc(poids, taille);
    imc = index_imc(imc);

    taille = (taille - moyenne_taille) / et_taille;
    poids = (poids - moyenne_poids) / et_poids;
    imc = (imc - moyenne_imc) / et_imc;

    voisins_plus_proches(donnees_traitees, 3, &nb_hommes, &nb_femmes, taille, poids, imc);

    printf("taille normalisee: %f\n", taille);
    printf("poids normalise: %f\n", poids);
    printf("imc normalise: %f\n", imc);
    printf("Hommes: %d, Femmes: %d\n", nb_hommes, nb_femmes);

    if(nb_femmes > nb_hommes){
        printf("Vous etes une femme.");
    } else {
        printf("Vous etes un homme.");
    }

    system("pause");
    return 0;
}