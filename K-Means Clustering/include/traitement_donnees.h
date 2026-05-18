#ifndef TRAITEMENT_DONNEES_H
#include <stdlib.h>
#include <stdio.h>

#define STB_IMAGE_IMPLMENTATION
#include "stb_image/stb_image.h"
#include "stb_image/stb_image_write.h"
#include "stb_image/stb_image_resize.h"

/*
Fonction qui retourne dans les paramètres les valeurs RGB d'un pixel donné dans l'image.
*/
void get_pixel(stbi_uc *image, size_t img_width, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a);

#endif