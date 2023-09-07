
#pragma once
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;

cv::Mat filtroLaplace(cv::Mat src)
{
	cv::Mat output = src.clone();

	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			int sum = src.at<uchar>(y - 1, x)
				+ src.at<uchar>(y + 1, x)
				+ src.at<uchar>(y, x - 1)
				+ src.at<uchar>(y, x + 1)
				- 4 * src.at<uchar>(y, x);

			output.at<uchar>(y, x) = sum;
		}
	}
	return output;
}
cv::Mat filterGussien(cv::Mat src)
{
	Mat  dst;
	Mat gaussien; Point anchor; double delta; int ddepth;
	delta = 0;	//1	2	1	// 0	-1	0
	ddepth = -1;	//2	4	2	//-1	4	-1
	//1	2	1	// 0	-1	0
	gaussien = Mat::zeros(3, 3, CV_32FC1); gaussien.at<float>(0, 1) = (float)-1;
	gaussien.at<float>(1, 0) = (float)-1;
	gaussien.at<float>(1, 2) = (float)-1;
	gaussien.at<float>(2, 1) = (float)-1;
	gaussien.at<float>(1, 1) = (float)4;
	filter2D(src, dst, ddepth, gaussien, anchor, delta, BORDER_DEFAULT);
	return dst;
}