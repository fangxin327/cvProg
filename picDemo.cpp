/*************************************************************************
  > File Name: picDemo.cpp
  > Author: FangXin
  > Mail:fangxin327@126.com 
  > Created Time: Fri 19 Dec 2014 04:00:38 PM CST
  > Discribtion: 
 ************************************************************************/
#include<cv.h>
#include<highgui.h>
#include<iostream>

using namespace std;
using namespace cv;
int main( int argc, char ** argv)
{
    char *imageName = argv[1];
    
    Mat image;
    image = imread( imageName, 1);
    if ( argc != 2 || !image.data ){
	printf( "No iamge data\n" );
	return -1;
    }

    Mat gray_image;
    cvtColor( image, gray_image, CV_BGR2GRAY );

    imwrite ("./Gray_Image.jpg", gray_image);

    namedWindow( imageName, CV_WINDOW_AUTOSIZE );
    namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

    imshow(imageName, image );
    imshow( "Gray image", gray_image );

    cout << "M = " << endl << " " << gray_image << endl ;

    waitKey(0);
    return 0;    
}
