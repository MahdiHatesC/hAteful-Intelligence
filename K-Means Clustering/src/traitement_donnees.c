#include "traitement_donnees.h"

void get_pixel(stbi_uc *image, size_t img_width, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a){
    const stbi_uc *p = image + (4 * (y * img_width + x));

    *r = p[0];
    *g = p[1];
    *b = p[2];
    *a = p[3];
}

