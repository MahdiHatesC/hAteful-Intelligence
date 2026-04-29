#ifndef HATEFUL_IO_H
#define HATEFUL_IO_H

void lire_fichier(char* nom_fichier);

enum Genre {MALE, FEMALE};

struct donnee {
    enum Genre genre;
    int taille;
    int poids;
    int imc;
} typedef t_donnee;

#endif