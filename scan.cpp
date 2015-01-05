/*************************************************************************
	> File Name: scan.cpp
	> Author: FangXin
	> Mail:fangxin327@126.com 
	> Created Time: Mon 05 Jan 2015 04:38:35 PM CST
	> Discribtion:This program scan an image and reduce the colour and then display it  
 ************************************************************************/
#include<iostream>
#include<cv.h>
#include<opencv2/core/core.hpp>
#include<highgui.h>

using namespace std;
using namespace cv;

Mat& ScanImageAndReduceC(Mat& I, const uchar* const table);

int main(int argc, char* argv[])
{
    int divideWith = 0;
    stringstream s;

    s << argv[2];
    s >> divideWith;
    if( !s || !divideWith ){
	cout << "Invalid number entered for dividing" << endl;
	return -1;
    }
    uchar table[256];
    for (int i = 0; i < 256; i++)
	table[i] = (uchar) (divideWith * (i/divideWith));

    double t = (double)getTickCount();

    char* imageName = argv[1];
    
    Mat image;
    image = imread( imageName, 1);
    if ( !image.data ){
	cout << "Input image wrong" << endl;
	return -1;
    }
    Mat image_reduced = image.clone();
    image_reduced = ScanImageAndReduceC(image_reduced,table);

    namedWindow(imageName, CV_WINDOW_AUTOSIZE);
    namedWindow("reduced_image",CV_WINDOW_AUTOSIZE);
    
    imshow(imageName,image);
    imshow("reduced_image",image_reduced);

    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "time passed in second:" << t << endl;
    waitKey(0);
    return 0;
    
}


Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
    CV_Assert(I.depth() != sizeof(uchar));//accept only char type matrics 
    
    int channels = I.channels();
    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous()){
	nCols *= nRows;
	nRows = 1;
    }
    int i,j;
    uchar* p;
    for (i = 0; i<nRows;i++){
	p = I.ptr<uchar>(i);
	for(j = 0;j < nCols;j++){
	    p[j] = table[p[j]];
	}
    }
    return I;
} 
