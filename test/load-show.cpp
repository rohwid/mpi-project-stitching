#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    	Mat image;

    	// Read the file
    	image = imread("./Lenna.png", CV_LOAD_IMAGE_COLOR);

	// Check for invalid input
    	if(! image.data )
    	{
        	cout <<  "Could not open or find the image" << std::endl ;
        	return -1;
    	}

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
