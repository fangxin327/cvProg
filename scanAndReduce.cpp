/*************************************************************************
	> File Name: scanAndReduce.cpp
	> Author: FangXin
	> Mail:fangxin327@126.com 
	> Created Time: Thu 18 Dec 2014 10:16:55 AM CST
 ************************************************************************/

#include<iostream>
#include"opencv2/core/core.hpp"

using namespace std;
using namespace cv;

Mat& ScanImageAndReduce( Mat& I, const uchar* const table)
{
	//accept only char type matrics
	CV_Assert(I.depth() != sizeof(uchar));

	int channels = I.channels();
	int nRows = I.rows;
	int nCols = I.cols;

	if(I.isContinuous()){
		nCols *= nRows;
		nRows = 1;
	}

	int i,j;
	uchar* p;
	for( i = 0; i < nRows; i++){
		p = I.ptr<uchar>(i);
		for( j = 0; j < nCols; j++)
			p[j] = table[p[j]];
	}
	return I;
}

int main()
{
	double t = (double)getTickCount();

}
