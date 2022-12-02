CC = gcc
CFLAGS = -Wall -Werror -Wextra
DIR = ../build/

all: main

main: main.o mainhead.h stb_image_resize.h stb_image_write.h stb_image.h 
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) main.o -o $(DIR)main -lm

clean:
	rm -rf *.o *.a $(DIR)*
rebuild: clean all