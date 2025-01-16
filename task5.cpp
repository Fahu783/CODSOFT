#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void loadAndDisplayImage(const string& filePath) {
    Mat img = imread(filePath);
    if (img.empty()) {
        cout << "Error loading image" << endl;
        return;
    }
    imshow("Loaded Image", img);
    waitKey(0);
}

Mat applyGrayscaleFilter(const Mat& img) {
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    return gray;
}

Mat applyBlurFilter(const Mat& img) {
    Mat blurred;
    GaussianBlur(img, blurred, Size(5, 5), 0);
    return blurred;
}

Mat applySharpenFilter(const Mat& img) {
    Mat sharpened;
    Mat kernel = (Mat_<float>(3, 3) <<
                  0, -1, 0,
                  -1, 5,-1,
                  0, -1, 0);
    filter2D(img, sharpened, img.depth(), kernel);
    return sharpened;
}

Mat adjustBrightnessContrast(const Mat& img, double alpha, int beta) {
    Mat adjusted;
    img.convertTo(adjusted, -1, alpha, beta);
    return adjusted;
}

Mat resizeImage(const Mat& img, int width, int height) {
    Mat resized;
    resize(img, resized, Size(width, height));
    return resized;
}

Mat cropImage(const Mat& img, Rect region) {
    return img(region);
}

void saveImage(const Mat& img, const string& filePath) {
    imwrite(filePath, img);
    cout << "Image saved at " << filePath << endl;
}

int main() {
    string filePath = "input_image.jpg";
    Mat img = imread(filePath);

    if (img.empty()) {
        cout << "Error loading image" << endl;
        return -1;
    }

    imshow("Original Image", img);
    waitKey(0);

    Mat grayImage = applyGrayscaleFilter(img);
    imshow("Grayscale Image", grayImage);
    waitKey(0);

    Mat blurredImage = applyBlurFilter(img);
    imshow("Blurred Image", blurredImage);
    waitKey(0);

    Mat sharpenedImage = applySharpenFilter(img);
    imshow("Sharpened Image", sharpenedImage);
    waitKey(0);

    Mat adjustedImage = adjustBrightnessContrast(img, 1.2, 50);
    imshow("Adjusted Image", adjustedImage);
    waitKey(0);

    Mat resizedImage = resizeImage(img, 300, 300);
    imshow("Resized Image", resizedImage);
    waitKey(0);

    Rect region(50, 50, 200, 200);
    Mat croppedImage = cropImage(img, region);
    imshow("Cropped Image", croppedImage);
    waitKey(0);

    saveImage(resizedImage, "output_image.jpg");

    return 0;
}
