# **BMP Image Histogram Analyzer**

## **Project Overview**
In image processing, understanding the distribution of pixel intensities in an image is crucial for tasks like contrast enhancement, image segmentation, and feature extraction. BMP (Bitmap) images are commonly used due to their simple, uncompressed format. However, analyzing the intensity distribution of BMP images, especially for large datasets, can be challenging without automation. A BMP image histogram analyzer in C is needed to address this problem by reading a BMP file, calculating the histogram of pixel intensities (frequency distribution), and providing insights into the brightness and contrast characteristics of the image.

This project is a simple C program that reads a BMP image file, extracts its pixel data, and computes histograms for the Red, Green, and Blue (RGB) color channels. The histograms are then displayed as bar charts in the terminal, color-coded for easy visualization.

## **Input Image**
![Colour Image](HistogramGeneration-RGB-Image\images\Input Image.png)


## **Code Overview**
- BMPHeader: Represents the header of the BMP file.
- DIBHeader: Represents the DIB header, containing image dimensions and format.
- readBMP: Function to read and parse BMP and DIB headers and extract pixel data.
- histogram: Calculates frequency distributions for the RGB channels.
- displayHistogram: Displays the histograms in the terminal using ASCII characters.

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
- **MacOS**: Install GCC by running:
  ```bash
  xcode-select --install
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
  brew install gcc

- **Windows**: Install GCC by:
  - Download the MinGW installer and follow the installation instructions.
  - Make sure to add MinGW's bin directory to your system's PATH environment variable.
  - For users preferring an IDE, Visual Studio comes with a C compiler that can also be used to compile C programs.

