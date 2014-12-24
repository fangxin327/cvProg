/*************************************************************************
	> File Name: matDemo.cpp
	> Author: FangXin
	> Mail:fangxin327@126.com 
	> Created Time: Wed 17 Dec 2014 05:15:43 PM CST
        > Discribtion: 
 ************************************************************************/
#include<iostream>
#include"opencv2/core/core.hpp"
#include<cv.h>
using namespace std;
using namespace cv;
int main(int argc , char ** argv)
{
	Mat A(100, 100, CV_8UC3, Scalar(0,0,255));
	cout << "A = " << endl << " " << A << endl;
	namedWindow("test",CV_WINDOW_AUTOSIZE);
	imshow("test", A);

	waitKey(0);
	return 0;

}

