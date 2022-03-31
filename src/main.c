//#include "mainhead.h"
#include <stdio.h>
#include <stdlib.h>
//#include "stb_image_resize.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


int functionOpenfile();

int main() {
    //struct Stucture Pixel;
    functionOpenfile();
    return 0;
}

//int functionOpenfile(char path) {
int functionOpenfile() {
    int width, height, channels;
    unsigned char *img = stbi_load("Cat03.jpg", &width, &height, &channels, 3);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }    
    for (int i = 0; i <= width * height; i++) {
        printf("%c", img[i]);
    }
    return 0;
    //return img;
}

//void functionPrintascii() {
//    for (int i = 0; i <= width * height)
    //unsigned char *new_img = malloc(3 * sizeof(unsigned char) * width * height)
//}