//#include "mainhead.h"
#include <stdio.h>
#include <stdlib.h>
//#include "stb_image_resize.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int functionPathToFile(char *path);
int functionOpenfile(char *path, unsigned char *img);
struct Structure {
        unsigned char r;
        unsigned char g;
        unsigned char b;
};
int functionWriteToStructure(unsigned char *img, int size, struct Structure *Pixel);

int main() {
    char *path = NULL;
    unsigned char *img = NULL;
    path = malloc(sizeof(char));
    img = malloc(sizeof(unsigned char));
    int size;
    size = functionPathToFile(path) / 3; //reduce on 3 because of structure with 3 types;
    struct Structure Pixel[size];
    //struct Stucture Pixel;
    functionOpenfile(path, img);
    functionWriteToStructure(img, size, Pixel);
    return 0;
}

int functionOpenfile(char *path, unsigned char *img) {
    int width, height, channels;
    img = stbi_load(path, &width, &height, &channels, 3);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }    
    for (int i = 0; i <= width * height; i++) {
        printf("%d", img[i]);
    }
    printf("\n");
    return width*height;
    //return img;
}
int functionPathToFile(char *path) {
        char *new_path = path;
        int i = 0;
        printf("Type path to the image file: ");
        while(scanf("%c", &path[i]) && path[i] != '\n') {
                i++;
                new_path = realloc(new_path, i*sizeof(char));
        }
        new_path = realloc(path, i + 1*sizeof(char));
        path[i] = '\0';
return 0;
}
int functionWriteToStructure(unsigned char *img, int size, struct Structure *Pixel) {
        for (int i = 0; i < size * 3;) {
                Pixel[i].r = img[i];
                Pixel[i].g = img[i + 1];
                Pixel[i].b = img[i + 2];
                i += 3;
        }
return 0;
}
//void functionPrintascii() {
//    for (int i = 0; i <= width * height)
    //unsigned char *new_img = malloc(3 * sizeof(unsigned char) * width * height)
//}
