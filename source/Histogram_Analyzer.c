// Project Code
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma pack(2) 

typedef struct {
    unsigned short signature;   
    unsigned int fileSize;      
    unsigned short reserved1;   
    unsigned short reserved2;   
    unsigned int dataOffset;    
} BMPHeader;

typedef struct {
    unsigned int headerSize;    
    int width;                  
    int height;                 
    unsigned short planes;      
    unsigned short bitDepth;    
    unsigned int compression;   
    unsigned int imageSize;     
    int xPixelsPerMeter;        
    int yPixelsPerMeter;        
    unsigned int colorsUsed;    
    unsigned int importantColors;
} DIBHeader;

void readBMP(const char* filename, BMPHeader* bmpHeader, DIBHeader* dibHeader, unsigned char** imageData) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }


    fread(bmpHeader, sizeof(BMPHeader), 1, file);

    if (bmpHeader->signature != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(file);
        return;
    }

    fread(dibHeader, sizeof(DIBHeader), 1, file);

    if (dibHeader->bitDepth != 24 || dibHeader->compression != 0) {
        fprintf(stderr, "Unsupported BMP format\n");
        fclose(file);
        return;
    }

    int padding = (4 - (dibHeader->width * 3) % 4) % 4;

    imageData = (unsigned char)malloc(dibHeader->width * dibHeader->height * 3);

    fseek(file, bmpHeader->dataOffset, SEEK_SET);
    fread(*imageData, 1, dibHeader->width * dibHeader->height * 3, file);

    fclose(file);
}

void histogram(unsigned char* imageData, int width, int height, int* redFrequency, int* greenFrequency, int* blueFrequency) {
    
    for (int i = 0; i < 256; i++) {
        redFrequency[i] = 0;
        greenFrequency[i] = 0;
        blueFrequency[i] = 0;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            blueFrequency[imageData[(i * width + j) * 3]]++;
            greenFrequency[imageData[(i * width + j) * 3 + 1]]++;
            redFrequency[imageData[(i * width + j) * 3 + 2]]++;
        }
    }


}

void displayHistogram(int* redFrequency, int* greenFrequency, int* blueFrequency, int size) {
    
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (redFrequency[i] > max) {
            max = redFrequency[i];
        }
        if (greenFrequency[i] > max) {
            max = greenFrequency[i];
        }
        if (blueFrequency[i] > max) {
            max = blueFrequency[i];
        }
    }

    double scale = 80.0 / max;

    printf("Red Histogram\n");
    for (int i = 0; i < size; i++) {
        printf("%3d: ", i);

        printf("\033[31m"); 
        int barLength = (int)(redFrequency[i] * scale);
        for (int j = 0; j < barLength; j++) {
            printf("*");
        }
        printf("\033[0m"); 
        printf("\n");
    }

    printf("Green Histogram\n");
    for (int i = 0; i < size; i++) {
        
        printf("%3d: ", i);
        printf("\033[32m"); 
        int barLength = (int)(greenFrequency[i] * scale);
        for (int j = 0; j < barLength; j++) {
            printf("*");
        }
        printf("\033[0m");
        printf("\n");
    }

    printf("Blue Histogram\n");
    for (int i = 0; i < size; i++) {
        printf("%3d: ", i);

        printf("\033[34m"); 
        int barLength = (int)(blueFrequency[i] * scale);
        for (int j = 0; j < barLength; j++) {
            printf("*");
        }
        printf("\033[0m"); 
        printf("\n");
    }
}

int main() {
    const char* filename = "Input Image.png";

    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    unsigned char* imageData;

    readBMP(filename, &bmpHeader, &dibHeader, &imageData);

    int redFrequency[256];
    int greenFrequency[256];
    int blueFrequency[256];

histogram(imageData, dibHeader.width, dibHeader.height, redFrequency, greenFrequency, blueFrequency);

displayHistogram(redFrequency, greenFrequency, blueFrequency, 256);

free(imageData);

return 0;
}