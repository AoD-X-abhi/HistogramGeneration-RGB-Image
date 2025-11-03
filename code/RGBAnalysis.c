/* RGBAnalysis.c - Complete and Fixed */
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HIST_BINS   256
#define MAX_STARS   80

typedef struct {
    unsigned int r[HIST_BINS];
    unsigned int g[HIST_BINS];
    unsigned int b[HIST_BINS];
} Histogram;

void compute_histogram(const unsigned char *data, int w, int h, int channels, Histogram *hist) {
    memset(hist, 0, sizeof(*hist));
    for (int i = 0; i < w * h; ++i) {
        int idx = i * channels;
        if (channels >= 1) hist->b[data[idx + 0]]++;
        if (channels >= 2) hist->g[data[idx + 1]]++;
        if (channels >= 3) hist->r[data[idx + 2]]++;
    }
}

unsigned int find_max(const unsigned int hist[HIST_BINS]) {
    unsigned int max = 0;
    for (int i = 0; i < HIST_BINS; ++i)
        if (hist[i] > max) max = hist[i];
    return max ? max : 1;
}

void print_histogram(const char* color, const unsigned int hist[HIST_BINS], const char* ansi_color) {
    unsigned int max_val = find_max(hist);
    double scale = (double)MAX_STARS / max_val;

    printf("\n\033[1mFor %s\033[0m\n", color);
    for (int i = 0; i < HIST_BINS; ++i) {
        printf("Pixel Value %d: ", i);
        if (hist[i] == 0) {
            printf("This value not present\n");
        } else {
            int stars = (int)round(hist[i] * scale);
            printf("%s", ansi_color);
            for (int j = 0; j < stars && j < MAX_STARS; ++j) putchar('*');
            printf("\033[0m\n");
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int w, h, comp;
    unsigned char *data = stbi_load(filename, &w, &h, &comp, 0);
    if (!data) {
        fprintf(stderr, "Error: cannot load '%s'\nReason: %s\n", filename, stbi_failure_reason());
        return EXIT_FAILURE;
    }

    unsigned char *rgb = NULL;
    int channels = comp;
    if (comp == 4) {
        rgb = malloc((size_t)w * h * 3);
        if (!rgb) {
            stbi_image_free(data);
            fprintf(stderr, "Error: out of memory\n");
            return EXIT_FAILURE;
        }
        for (int i = 0; i < w * h; ++i) {
            rgb[i*3+0] = data[i*4+0];
            rgb[i*3+1] = data[i*4+1];
            rgb[i*3+2] = data[i*4+2];
        }
        stbi_image_free(data);
        data = rgb;
        channels = 3;
    }

    printf("Loaded: %s (%dx%d, %d channel%s)\n", filename, w, h, channels, channels > 1 ? "s" : "");

    Histogram hist;
    compute_histogram(data, w, h, channels, &hist);

    print_histogram("Red",   hist.r, "\033[31m");
    print_histogram("Green", hist.g, "\033[32m");
    print_histogram("Blue",  hist.b, "\033[34m");

    if (rgb) free(rgb);
    else stbi_image_free(data);

    return EXIT_SUCCESS;  // This line was fine
}  // ← THIS WAS MISSING! Add this closing brace