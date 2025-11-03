# RGB Histogram Analyzer

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://github.com/AoD-X-abhi/HistogramGeneration-RGB-Image)
[![Loader](https://img.shields.io/badge/loader-stb__image-green.svg)](https://github.com/nothings/stb)
[![Build](https://img.shields.io/badge/build-gcc%20%7C%20clang-success.svg)]()

A **lightweight, terminal-based C program** that generates **color-coded histograms** for **Red, Green, and Blue channels** of any image format using the single-header library [`stb_image.h`](https://github.com/nothings/stb).

Supports: **JPEG, PNG, BMP, TIFF, WebP, TGA, PSD, HDR, PIC, PNM**

---

## Features

- **Cross-format image loading** via `stb_image.h`
- **256-bin histograms** for R, G, B channels
- **ASCII bar graphs** with **color-coded output** (ANSI)
- **Scalable bar width** and **frequency display**
- **No external dependencies** — pure C + standard library
- **Fast & lightweight** — ideal for CLI tools and embedded systems

---

## Prerequisites

| Tool | Command |
|------|--------|
| **GCC / Clang** | `sudo apt install build-essential` (Ubuntu) |
| **macOS** | `xcode-select --install` |
| **Windows** | [MinGW](http://www.mingw.org/) or WSL |

---

# Build & Run

## 1) Navigate to project root
cd HistogramGeneration-RGB-Image

## 2) Compile
gcc -O2 -std=c99 -o histogram code/RGBAnalysis.c -lm

## 3) Run with any image
./histogram code/sample.jpg
