#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void convertToASCII(const Mat& image, int width, int height) {
    const string asciiChars = "@%#*+=-:. ";

    double aspectRatio = static_cast<double>(width) / static_cast<double>(height);
    double imageAspectRatio = static_cast<double>(image.cols) / static_cast<double>(image.rows);
    double scaleWidth = 1.0, scaleHeight = 1.0;

    if (aspectRatio > imageAspectRatio) {
        scaleHeight = static_cast<double>(height) / static_cast<double>(image.rows);
    }
    else {
        scaleWidth = static_cast<double>(width) / static_cast<double>(image.cols);
    }

    Mat resizedImage;
    resize(image, resizedImage, Size(), scaleWidth, scaleHeight);

    Mat grayImage;
    cvtColor(resizedImage, grayImage, COLOR_BGR2GRAY);

    Mat asciiImage(height * 15, width * 10, CV_8UC3, Scalar(255, 255, 255));  // White background

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int intensity = static_cast<int>(grayImage.at<uchar>(i, j));
            int index = static_cast<int>((intensity / 255.0) * (asciiChars.length() - 1));

            Vec3b color = asciiImage.at<Vec3b>(i * 15, j * 10);
            color[0] = color[1] = color[2] = 255 - intensity;

            putText(asciiImage, string(1, asciiChars[index]), Point(j * 10, i * 15), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0), 1);
        }
    }

    imwrite("ascii_art_image.jpg", asciiImage);
}

int main() {
    Mat image = imread("C:/Users/manav/Desktop/image.png");

    if (image.empty()) {
        cerr << "Error: Could not open or find the image" << endl;
        return -1;
    }

    int width = 800;
    int height = 600;

    convertToASCII(image, width, height);

    return 0;
}
