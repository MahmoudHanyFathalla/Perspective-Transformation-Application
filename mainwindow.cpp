#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1250, 650);

    // Load the first image using OpenCV
    cv::Mat image1 = cv::imread("C:/Users/hp/Desktop/foot.jpg");

    // Check if the first image is loaded successfully
    if (!image1.empty()) {
        // Convert BGR to RGB for OpenCV images
        cv::cvtColor(image1, image1, cv::COLOR_BGR2RGB);

        // Get the size of the first QLabel (label)
        QSize labelSize1 = ui->label->size();

        // Resize the first image to fit the first QLabel while maintaining the aspect ratio
        cv::resize(image1, image1, cv::Size(labelSize1.width(), labelSize1.height()));

        // Convert OpenCV Mat to QImage for the first image
        QImage img1 = QImage(image1.data, image1.cols, image1.rows, image1.step, QImage::Format_RGB888);

        // Display the first image in the first QLabel (label)
        ui->label->setPixmap(QPixmap::fromImage(img1));

        // Apply perspective transformation to the first image (example parameters)
        cv::Mat transformedImage = applyPerspectiveTransformation(image1);

        // Convert the transformed image to QImage
        QImage transformedImg = QImage(transformedImage.data, transformedImage.cols, transformedImage.rows,
                                       transformedImage.step, QImage::Format_RGB888);

        // Display the transformed image in the second QLabel (label_2)
        ui->label_2->setPixmap(QPixmap::fromImage(transformedImg));
    } else {
        qDebug() << "Error: Unable to load the first image.";
    }

    // Load the second image using OpenCV
    cv::Mat image2 = cv::imread("C:/Users/hp/Desktop/tvv.jpg");

    // Check if the second image is loaded successfully
    if (!image2.empty()) {
        // ... (omitting some code for brevity)
    } else {
        qDebug() << "Error: Unable to load the second image.";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

cv::Mat MainWindow::applyPerspectiveTransformation(const cv::Mat &inputImage)
{
    // Define four points to create a perspective transformation
    std::vector<cv::Point2f> srcPoints, dstPoints;

    // Define example source points (coordinates of a rectangle in the original image)
    srcPoints.push_back(cv::Point2f(100, 100));
    srcPoints.push_back(cv::Point2f(400, 100));
    srcPoints.push_back(cv::Point2f(400, 400));
    srcPoints.push_back(cv::Point2f(100, 400));

    // Define example destination points (coordinates of the corresponding rectangle in the transformed image)
    dstPoints.push_back(cv::Point2f(100, 100));
    dstPoints.push_back(cv::Point2f(300, 100));
    dstPoints.push_back(cv::Point2f(300, 300));
    dstPoints.push_back(cv::Point2f(100, 300));

    // Get the perspective transformation matrix
    cv::Mat perspectiveMatrix = cv::getPerspectiveTransform(srcPoints, dstPoints);

    // Apply the perspective transformation to the input image
    cv::Mat transformedImage;
    cv::warpPerspective(inputImage, transformedImage, perspectiveMatrix, inputImage.size());

    return transformedImage;
}
