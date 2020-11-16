#include "opencv-utils.h"
#include <opencv2/imgproc.hpp>

void myFlip(Mat src) {
    flip(src, src, 0);
}

void myBlur(Mat src, float sigma) {
    GaussianBlur(src, src, Size(), sigma);
}
void myCanny(Mat src, float sigma){
    Mat dst, detected_edges,src_gray,edge1;

    const int ratio = 3;
    const int kernel_size = 3;

    cvtColor(src,src_gray,COLOR_BGR2GRAY );
    blur( src_gray, detected_edges, Size(3,3) );

    Canny( detected_edges, edge1, (int)sigma, ((int)sigma)*ratio, kernel_size );
    dst = Scalar::all(0);
    src.copyTo( dst, edge1);
    dst.copyTo(src);

}
