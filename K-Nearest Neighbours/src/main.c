#include "hateful_io.h"
#define NB_DONNEES 200

int main() {
    t_donnee donnee[NB_DONNEES];
    lire_fichier("donnees.csv",donnee);
    return 0;
}