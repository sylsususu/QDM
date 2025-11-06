#pragma once
#include <opencv2/opencv.hpp>
class SaveThread
{
public:
	SaveThread(const cv::Mat& image, const std::string& filename) : image(image), filename(filename) {}

	void operator()()
	{

		cv::imwrite(filename, image);
	}

private:
	cv::Mat image;
	std::string filename;
};

