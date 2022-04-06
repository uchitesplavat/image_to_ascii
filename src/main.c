//#include "mainhead.h"
#include <stdio.h>
#include <stdlib.h>
//#include "stb_image_resize.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

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
    int size, out_width = 0;
    printf("Before_Path\n");
    functionPathToFile(path); //reduce on 3 because of structure with 3 types;
    printf("Before_Open_File\n");
    size = functionOpenfile(path, img, h_img, path_2, &out_width);
    struct Structure Pixel[size];
    printf("huy\n");
    functionWriteToStructure(h_img, size, Pixel);
    printf("%d\n", h_img[0]);
    printingAscii(Pixel, size, scale, brightnessLevels, &out_width);
    printf("OUT_Width%d\n", out_width);
    printf("OUT_Size%d\n", size);
    //stbi_image_free(Pixel);
    return 0;
}

int functionOpenfile(char *path, unsigned char *img, unsigned char *h_img, unsigned char *path_2, int *out_width) {
    int width, height, channels, out_w, out_h;
    img = stbi_load(path, &width, &height, &channels, 3);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }  
    out_w = width / 4;
    out_h = height / 9;
    //h_img = realloc(h_img,width*height*3 * sizeof(unsigned char));
    //for (int i = 0; i <= width * height; i++) {
    //         h_img[i]=img[i];
    //} 
    //for (int i = 0; i <= 10; i++) {
    //    printf("%d", img[i]);
    //}
    //printf("\n");
    path_2 = img;
    stbir_resize_uint8(img , width, height, 0,
                        path_2, out_w, out_h, 0, 3);

           for (int i = 0; i <= out_w * out_h * 3; i++) {
             h_img[i]=img[i];
       } 
    //for (int i = 0; i <= 10; i++) {
    //    printf("%d", img[i]);
    //}

    //printf("\n");
    stbi_write_jpg("cat2.jpg", out_w, out_h, 3, path_2, 100);
    *out_width = out_w;
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
        int i = 0, d = 0;
        while (i < size * 3) {
                Pixel[d].r = h_img[i];
                Pixel[d].g = h_img[i + 1];
                Pixel[d].b = h_img[i + 2];
        //printf("%d", h_img[i]);
        //printf("%d ", Pixel[i].r);
        //printf("%d ", Pixel[i].g);
        //printf("%d\n", Pixel[i].b);       
        d++;
        i+=3;
                        }
//printf("%d\n", h_img[2]);

        return 0;
}
unsigned char luminanceFromRGB(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned char) (0.2126 * r + 0.7152 * g + 0.0722 * b);
}

unsigned char calc_ascii_char(struct Structure *Pixel, char *scale, unsigned int brightnessLevels, int i) {
    unsigned char ch = luminanceFromRGB(Pixel[i].r, Pixel[i].g, Pixel[i].b);
    //printf("%d ", Pixel[i].g);
    //printf("%d\n", Pixel[i].b);
    //if (ch == 0) {
    //   ch = 54;
    //}
    int rescaled = ch * brightnessLevels / 256;
    //printf("Scale %s\n", scale);
    //printf("Brightness - rescaled = %d\n", brightnessLevels - rescaled);
    return scale[brightnessLevels - rescaled];
}


//stbir_resize_uint8(      input_pixels , in_w , in_h , 0,
//                         output_pixels, out_w, out_h, 0, 3)

void printingAscii(struct Structure *Pixel, int size, char *scale, unsigned int brightnessLevels, int *out_width) {
        printf("printingASCII\n");
        int g = *out_width;
        for (int i = 0; i <= size; i++) {
            printf("%c", calc_ascii_char(Pixel, scale, brightnessLevels, i));
            //calc_ascii_char(Pixel, scale, brightnessLevels, i);
            if(i == g) {
                printf("\n");
                g += *out_width;
            }
        }
}
//void functionPri3ntascii() {
//    for (int i = 0; i <= width * height)
    //unsigned char *new_img = malloc(3 * sizeof(unsigned char) * width * height)
//}