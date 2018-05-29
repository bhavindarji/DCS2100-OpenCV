#include <opencv2/opencv.hpp>

const std::string videoStreamAddress = "http://admin:admin@192.168.1.106/cgi-bin/video.jpg";


int main()
{
    // Create image matrix
    cv::Mat img;
    cv::Mat dst;
    
    for(;;)
    {
	// Read image
	cv::VideoCapture input(videoStreamAddress,cv::CAP_GSTREAMER);
	// Load image
	input.read(img);
	// Display image
	cv::imshow("dst", img);

	char c = cv::waitKey(1);
	// Wait for Esc key to press
	if(c == '\x1b')
	break;
    }
}

