#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/photo.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

cv::Mat Dilation(int erosion_elem,int erosion_size,Mat source , void*)
{
	Mat dst = source.clone();
	int dilation_type = 0;
	if (erosion_elem == 0) { dilation_type = MORPH_RECT; }
	else if (erosion_elem == 1) { dilation_type = MORPH_CROSS; }
	else if (erosion_elem == 2) { dilation_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(dilation_type,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));
	/// Apply the dilation operation
	dilate(source, dst, element);
	return dst;
}
cv::Mat Erosion(int erosion_elem, int erosion_size, Mat source, void*)
{
	Mat dst = source.clone();
	int erosion_type = 0;
	if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
	else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
	else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(erosion_type,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));
	/// Apply the erosion operation
	erode(source, dst, element);
	return dst;
}
cv::Mat Morphology_Operations(int erosion_elem, int erosion_size,int morph_operator, Mat source, void*)
{
	Mat dst = source.clone();
	int morph_elem = 0;
	if (erosion_elem == 0) { morph_elem = MORPH_RECT; }
	else if (erosion_elem == 1) { morph_elem = MORPH_CROSS; }
	else if (erosion_elem == 2) { morph_elem = MORPH_ELLIPSE; }

	// Since MORPH_X : 2,3,4,5 and 6
	int operation = morph_operator + 2;

	Mat element = getStructuringElement(morph_elem, cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1), cv::Point(erosion_size, erosion_size));

	/// Apply the specified morphology operation
	morphologyEx(source, dst, operation, element);
	return dst;
}