#ifndef HATEFUL_IO_H
#define HATEFUL_IO_H
#define NB_DONNEES 500

enum Genre {MALE, FEMALE};

typedef struct donnee {
    enum Genre genre;
    float taille;
    float poids;
    float imc;
}t_donnee;

//Il faut mettre un pointeur aulieu de mettre un tableau directement.
void lire_fichier(char* nom_fichier, t_donnee* donnees);


#endif