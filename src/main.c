//#include "mainhead.h"
#include <stdio.h>
#include <stdlib.h>
//#include "stb_image_resize.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"

int functionPathToFile(char *path);
int functionOpenfile(char *path, unsigned char *img, unsigned char *h_img, unsigned char *path_2);
struct Structure {
        unsigned char r;
        unsigned char g;
        unsigned char b;
};
unsigned char luminanceFromRGB(unsigned char r, unsigned char g, unsigned char b);
unsigned char calc_ascii_char(struct Structure *Pixel, char *scale, unsigned int brightnessLevels, int i);
void printingAscii(struct Structure *Pixel, int size, char *scale, unsigned int brightnessLevels);
int functionWriteToStructure(unsigned char *img, int size, struct Structure *Pixel);

int main() {
    char *path = NULL;
    unsigned char *path_2 = NULL;
    unsigned char *img = NULL;
    path = malloc(sizeof(char));
    path_2 = malloc(sizeof(unsigned char));
    img = malloc(sizeof(unsigned char));
    unsigned char h_img[400000];
    char scale[] = "$@&B%8WM#ZO0QoahkbdpqwmLCJUYXIjft/\\|()1{}[]l?zcvunxr!<>i;:*-+~_,\"^`'. ";
    unsigned int brightnessLevels = (sizeof(scale) / sizeof(scale[0]) - 2);
   // h_img = malloc(sizeof(unsigned char));
    int size;
    printf("Before_Path\n");
    functionPathToFile(path); //reduce on 3 because of structure with 3 types;
    printf("Before_Open_File\n");
    size = functionOpenfile(path, img, h_img, path_2) / 3;
    struct Structure Pixel[size];
    printf("huy\n");
    functionWriteToStructure(h_img, size, Pixel);
    printf("%d\n", h_img[0]);
    printingAscii(Pixel, size, scale, brightnessLevels);
    //stbi_image_free(Pixel);
    return 0;
}

int functionOpenfile(char *path, unsigned char *img, unsigned char *h_img, unsigned char *path_2) {
    int width, height, channels, out_w, out_h;
    img = stbi_load(path, &width, &height, &channels, 3);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }  
    out_w = width / 4;
    out_h = height / 4;
    //h_img = realloc(h_img,width*height*3 * sizeof(unsigned char));
    for (int i = 0; i <= width * height; i++) {
             h_img[i]=img[i];
    } 
    for (int i = 0; i <= 10; i++) {
        printf("%d", img[i]);
    }
    printf("\n");
    path_2 = img;
    stbir_resize_uint8(img , width, height, 0,
                        path_2, out_w, out_h, 0, 3);

           for (int i = 0; i <= out_w * out_h; i++) {
             h_img[i]=img[i];
       } 
    for (int i = 0; i <= 10; i++) {
        printf("%d", img[i]);
    }

    printf("\n");

    return out_w * out_h;
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

int functionWriteToStructure(unsigned char *h_img, int size, struct Structure *Pixel) {
        printf("functionWriteToStructure\n");
        int i = 0;
        while (i < size) {
                Pixel[i].r = h_img[i];
                Pixel[i].g = h_img[i + 1];
                Pixel[i].b = h_img[i + 2];
        printf("%d", h_img[i]);
        printf("%d", Pixel[i].r);       
        i+=3;
                        }
printf("%d\n", h_img[2]);

        return 0;
}
unsigned char luminanceFromRGB(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned char) (0.2126 * r + 0.7152 * g + 0.0722 * b);
}

unsigned char calc_ascii_char(struct Structure *Pixel, char *scale, unsigned int brightnessLevels, int i) {
    unsigned char ch = luminanceFromRGB(Pixel[i].r, Pixel[i].g, Pixel[i].b);
    int rescaled = ch * brightnessLevels / 256;
    return scale[brightnessLevels - rescaled];
}


//stbir_resize_uint8(      input_pixels , in_w , in_h , 0,
//                         output_pixels, out_w, out_h, 0, 3)

void printingAscii(struct Structure *Pixel, int size, char *scale, unsigned int brightnessLevels) {
        printf("printingASCII\n");
        for (int i = 0; i <= size; i++) {
        printf("%c", calc_ascii_char(Pixel, scale, brightnessLevels, i));
        //if(i == 44) {
        //        printf("\n");
        }
    }

//void functionPri3ntascii() {
//    for (int i = 0; i <= width * height)
    //unsigned char *new_img = malloc(3 * sizeof(unsigned char) * width * height)
//}