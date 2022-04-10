#ifndef MAINHEAD_H
#define MAINHEAD_H

#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../src/stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "../src/stb_image_resize.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../src/stb_image_write.h"

int functionPathToFile(char *path);
int functionOpenfile(char *path, unsigned char *img, unsigned char *h_img, unsigned char *path_2, int *out_width);
struct Structure {
        unsigned char r;
        unsigned char g;
        unsigned char b;
};
unsigned char luminanceFromRGB(unsigned char r, unsigned char g, unsigned char b);
unsigned char calc_ascii_char(struct Structure *Pixel, char *scale, unsigned int brightnessLevels, int i);
void printingAscii(struct Structure *Pixel, int size, char *scale, unsigned int brightnessLevels, int *out_width);
int functionWriteToStructure(unsigned char *img, int size, struct Structure *Pixel);

#endif  // MAINHEAD_H
