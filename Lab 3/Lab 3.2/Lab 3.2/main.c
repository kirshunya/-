#define _CRT_SECURE_NO_WARNINGS
#define CONST 128
#include <stdio.h>
#include <stdlib.h>
#include "Source.h"
#include <math.h>
#include <stdint.h>

int main() 
{
    char name[CONST];
    printf("Enter a filename: ");
    scanf("%s", name);
    FILE* input_file = fopen(name, "rb");
    if (!input_file) {
        printf("Error: could not open input file.\n");
        return -1;
    }

    BMPHeader header;
    fread(&header, sizeof(header), 1, input_file);

    if (header.file_header.type != 0x4D42) {
        printf("Error: not a BMP file.\n");
        fclose(input_file);
        return -1;
    }

    if (header.info_header.bit_count != 24) {
        printf("Error: only 24-bit images are supported.\n");
        fclose(input_file);
        return -1;
    }

    fseek(input_file, header.file_header.offset, SEEK_SET);

    int width = header.info_header.width;
    int height = header.info_header.height;

    Pixel* pixels = malloc(width * height * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), width * height, input_file);

    int chs = 0;
    printf("Chose:\n");
    printf("1. Negative\n");
    printf("2. Black and white\n");
    printf("3. Gammacorection\n");
    printf("4. Median filtering\n");
    input_size(&chs);

    switch (chs) 
    {
        case 1:
        {
            for (int i = 0; i < width * height; i++) {
                pixels[i].red = 255 - pixels[i].red;
                pixels[i].green = 255 - pixels[i].green;
                pixels[i].blue = 255 - pixels[i].blue;
            }
            break;
        }
        case 2:
        {
            unsigned char average;
            for (int i = 0; i < width * height; i++) {
                average = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
                pixels[i].red = average;
                pixels[i].green = average;
                pixels[i].blue = average;
            }
            break;
        }
        case 3:
        {
            float gamma = 0;
            printf(":Input gamma cf:\n");
            scanf("%f", &gamma);
            printf("Gamma = %f\n", gamma);
            for (int i = 0; i < width * height; i++) {
                pixels[i].red = (unsigned char)(pow((double)pixels[i].red / 255.0, gamma) * 255.0 + 0.5);
                pixels[i].green = (unsigned char)(pow((double)pixels[i].green / 255.0, gamma) * 255.0 + 0.5);
                pixels[i].blue = (unsigned char)(pow((double)pixels[i].blue / 255.0, gamma) * 255.0 + 0.5);
            }

            Pixel* pixels = malloc(width * height * sizeof(Pixel));

            break;
        }
        case 4:
        {
            Pixel window[9];
            for (int y = 1; y < height - 1; y++) 
            {
                for (int x = 1; x < width - 1; x++) 
                {
                    int k = 0;
                    for (int j = -1; j <= 1; j++)
                    {
                        for (int i = -1; i <= 1; i++) 
                        {
                            window[k++] = pixels[(y + j) * width + x + i];
                        }
                    }
                    pixels[y * width + x] = median(window, k);
                }
            }
            break;
        }
         
    }

    FILE* output_file = fopen("output.bmp", "wb");
    if (!output_file) {
        printf("Error: could not open output file.\n");
        free(pixels);
        fclose(input_file);
        return -1;
    }

    fwrite(&header, sizeof(header), 1, output_file);
    fseek(output_file, header.file_header.offset, SEEK_SET);
    fwrite(pixels, sizeof(Pixel), width * height, output_file);


    fseek(output_file, header.file_header.offset, SEEK_SET);

    for (int y = height - 1; y >= 0; y--) 
    {
        for (int x = 0; x < width; x++) 
        {
            Pixel* p = &pixels[y * width + x];
            fread(p, sizeof(Pixel), 1, output_file);
            printf("\033[48;2;%d;%d;%dm ", p->red, p->green, p->blue); //используется для установки цвета фона текста в терминале, который поддерживает истинный цвет (24-битный цвет). Три значения %d представляют собой значения красного, зеленого и синего (RGB) цветов соответственно.
        }
        printf("\033[0m\n");
        fseek(output_file, (4 - ((width * 3) % 4)) % 4, SEEK_CUR);
    }

    free(pixels);
    fclose(input_file);
    fclose(output_file);
    return 0;
}
