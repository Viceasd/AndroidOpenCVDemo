#include "opencv-utils.h"
#include <opencv2/imgproc.hpp>

void myFlip(Mat src) {
    flip(src, src, 0);
}

void myBlur(Mat src, float sigma) {
    GaussianBlur(src, src, Size(), sigma);
}
void myCanny(Mat src, float sigma){

    Mat dst, detected_edges,src_gray,edge1,src_gray2,mask;

    const int ratio = 3;
    const int kernel_size = 3;

    dst.create( src.size(), src.type() );

    cvtColor(src,src_gray,COLOR_BGR2GRAY);

    blur( src_gray, detected_edges, Size(3,3) );

    Canny( detected_edges, edge1, 0, 100, kernel_size );

    dst = cv::Scalar(0);
    src.copyTo( dst, edge1);
    src.convertTo(src, dst.type());
    dst.copyTo(src);





}
