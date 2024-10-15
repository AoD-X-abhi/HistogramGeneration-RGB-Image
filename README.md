# **BMP Image Histogram Analyzer**

## **Project Overview**
This project is a simple C program that reads a BMP image file, extracts its pixel data, and computes histograms for the Red, Green, and Blue (RGB) color channels. The histograms are then displayed as bar charts in the terminal, color-coded for easy visualization.

## **Features**
- Reads 24-bit BMP image files.
- Calculates and displays histograms for each color channel (Red, Green, Blue).
- Shows histograms using ASCII characters in the terminal, color-coded for red, green, and blue.
- Handles image data with proper alignment and padding.

## **Prerequisites**
To compile and run this program, you will need:
- A C compiler (e.g., GCC or Clang)
- Basic knowledge of working with C programs
- A BMP file to test the code (must be 24-bit uncompressed)

### **Installing a C Compiler**
If you're on:
- **Linux**: Install GCC by running:
  ```bash
  sudo apt-get update
  sudo apt-get install build-essential

