#include <opencv2/opencv.hpp>
#include <stdio.h>

#define CSI_CAM 0

/*
CSI Camera:
Supported Resolution and FPS mode 
2592 x 1944 FR=30.000000 CF=0x1109208a10 SensorModeType=4 CSIPixelBitDepth=10 DynPixelBitDepth=10
2592 x 1458 FR=30.000000 CF=0x1109208a10 SensorModeType=4 CSIPixelBitDepth=10 DynPixelBitDepth=10
1280 x 720  FR=120.000000 CF=0x1109208a10 SensorModeType=4 CSIPixelBitDepth=10 DynPixelBitDepth=10
*/

#if CSI_CAM

#define     WIDTH  	1280
#define     HEIGHT  720
#define     FPS  	120

std::string get_tegra_pipeline(int width, int height, int fps) 
{
    return "nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(width) + ", height=(int)" +
           std::to_string(height) + ", format=(string)I420, framerate=(fraction)" + std::to_string(fps) +
           "/1 ! nvvidconv flip-method=0 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}
#endif

const std::string videoStreamAddress = "http://admin:admin@192.168.1.106/cgi-bin/video.jpg";


int main()
{
	// Create image matrix
    cv::Mat img;
    cv::Mat dst;
//    cv::VideoCapture input;
#if CSI_CAM
	 // Onboard camera
     // Define the gstream pipeline
    std::string pipeline = get_tegra_pipeline(WIDTH, HEIGHT, FPS);
    std::cout << "Using pipeline: \n\t" << pipeline << "\n";
    cv::VideoCapture input(pipeline, cv::CAP_GSTREAMER);  

#else
    // USB camera

	 
#endif
    
    for(;;)
	{
		cv::VideoCapture input(videoStreamAddress,cv::CAP_GSTREAMER);
		input.read(img);
		cv::imshow("dst", img);
		char c = cv::waitKey(1);
	 	// Wait for Esc key to press
      	if(c == '\x1b')
         	break;
     }
}

