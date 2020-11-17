#include "opencv-utils.h"
#include <opencv2/imgproc.hpp>

void myFlip(Mat src) {
    flip(src, src, 0);
}

void myBlur(Mat src, float sigma) {
    GaussianBlur(src, src, Size(), sigma);
}
void myCanny(Mat src, float sigma){

    Mat dst, detected_edges,src_gray,edge,src_gray2,mask,gray;

    const int ratio = 3;
    const int kernel_size = 3;

    cvtColor(src, gray, COLOR_RGB2GRAY);
    blur( gray, gray, Size(3,3) );
    Canny(gray, edge, (int)sigma, 100);
    cvtColor(edge, dst, COLOR_GRAY2RGBA,4);
    src = cv::Scalar(0);
    dst.copyTo(src);





}
