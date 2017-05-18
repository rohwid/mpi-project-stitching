#include <stdio.h>
#include <iostream>
#include <fstream>
#include <mpi.h>
#include "opencv2/gpu/gpu.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
	MPI_Init(NULL, NULL);

  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	// Get the name of the processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);

	// Print off a hello world message
  printf("Processing from processor %s, rank %d out of %d processors\n", processor_name, world_rank, world_size);

	vector< Mat > vImg;

	vector< vector< Rect > > vvRect;
	Mat rImg;

	vImg.push_back(imread("./stitching_img/m1.jpg"));
	vImg.push_back(imread("./stitching_img/m2.jpg"));
	vImg.push_back(imread("./stitching_img/m3.jpg"));
	vImg.push_back(imread("./stitching_img/m4.jpg"));
	vImg.push_back(imread("./stitching_img/m5.jpg"));
	vImg.push_back(imread("./stitching_img/m6.jpg"));


	int c = gpu::getCudaEnabledDeviceCount();
	printf("Gpu Device %d\n", c);

	Stitcher stitcher = Stitcher::createDefault(1);


	unsigned long AAtime = 0, BBtime = 0;
	AAtime = getTickCount();


	stitcher.stitch(vImg, rImg);

	BBtime = getTickCount();
	printf("ProcessingTime %.2lf sec \n", (BBtime - AAtime) / getTickFrequency());

	//imshow("Stitching Result", rImg);

	waitKey(0);

	imwrite("output.jpg", rImg);

	MPI_Finalize();
}
