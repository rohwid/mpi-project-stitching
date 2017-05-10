#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include "opencv2\gpu\gpu.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2\stitching\stitcher.hpp"

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{

	vector< Mat > vImg;

	vector< vector< Rect > > vvRect;
	Mat rImg;

	vImg.push_back(imread(".\\stitching_img\\m1.jpg"));
	vImg.push_back(imread(".\\stitching_img\\m2.jpg"));
	vImg.push_back(imread(".\\stitching_img\\m3.jpg"));
	vImg.push_back(imread(".\\stitching_img\\m4.jpg"));
	vImg.push_back(imread(".\\stitching_img\\m5.jpg"));
	vImg.push_back(imread(".\\stitching_img\\m6.jpg"));
	
	
	int c = gpu::getCudaEnabledDeviceCount();
	printf("Gpu Device %d\n", c);

	Stitcher stitcher = Stitcher::createDefault(1);


	unsigned long AAtime = 0, BBtime = 0;
	AAtime = getTickCount();

	
	stitcher.stitch(vImg, rImg);

	BBtime = getTickCount();
	printf("ProcessingTime %.2lf sec \n", (BBtime - AAtime) / getTickFrequency());

	imshow("Stitching Result", rImg);

	waitKey(0);

	imwrite("output.jpg", rImg);
}