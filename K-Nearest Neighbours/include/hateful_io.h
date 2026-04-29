#ifndef HATEFUL_IO_H
#define HATEFUL_IO_H
#define NB_DONNEES 200

enum Genre {MALE, FEMALE};

struct donnee {
    enum Genre genre;
    int taille;
    int poids;
    int imc;
} typedef t_donnee;

//Il faut mettre un pointeur aulieu de mettre un tableau directement.
void lire_fichier(char* nom_fichier, t_donnee* donnee);


#endif