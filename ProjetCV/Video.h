
#include "opencv2/opencv.hpp"
#include "opencv2/photo.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
using namespace cv;
using namespace std;
using namespace std::chrono;

int windowsizeX = 500;
int windowsizeY = 500;

enum Dérection {
	RIGHT = 1, RIGHTDOWN = 2, UPRIGHT = 3,
	LEFT = 4, STOP = 5, UPLEFT = 6,
	DOWN = 7, UP = 8, LEFTDOWN = 9
};
enum forma { CERCLE = 1, TRIENGLE = 2, CARRE = 3 };
class PointFixe
{
private:
	int posx;
	int posy;
public:
	int getx() { return posx; }
	int gety() { return posy; }
	PointFixe(int x, int y) {
		posx = x;
		posy = y;
		posx = max(5, posx);
		posy = max(5, posy);
		posx = min(posx, windowsizeX - 5);
		posy = min(posy, windowsizeY - 5);
	}
	PointFixe() {
	}
	void update(int x, int y) {
		posx = x;
		posy = y;
		posx = max(5, posx);
		posy = max(5, posy);
		posx = min(posx, windowsizeX - 5);
		posy = min(posy, windowsizeY - 5);
	}
	void createpoint(Mat frame,int r, int g, int b) {
		circle(frame, Point(posx, posy), 5, Scalar(r, g, b), FILLED);
	}


};

// class object 
class forms {
	int pAx, pAy, pBx, pBy;
	Dérection dct = STOP;
	forma form;
	bool isconflicate;
	int r, g, b;
public:
	forms(int x, int y  ,int i) {
		pAx = x;
		pAy = y;
		dct = (Dérection)((rand() % 9) + 1);
		form = (forma)i;
		isconflicate = false;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
	}
	int getX()
	{
		return pAx;
	}
	int getY()
	{
		return pAy;
	}
	int getBX()
	{
		return pBx;
	}
	int getBY()
	{
		return pBy;
	}
	int* getrgb()
	{
		int ar[3];
		ar[0] = r;
		ar[0] = g;
		ar[0] = b;
		return ar;
	}
	forma getform()
	{
		return form;
	}
	void randomDirection() {
		dct = (Dérection)(1);
	}
	void createforms(Mat frame) {
		switch (form)
		{
		case CERCLE:
			pBx = 20;
			pBy = 20;
			pAx = min(pAx, windowsizeX- pBx);
			pAy = min(pAy, windowsizeY- pBy);
			circle(frame, Point(pAx, pAy), pBx, Scalar(r, g, b), FILLED);
			break;
		case TRIENGLE:
			pBx = 20;
			pBy = 30;
			pAx = min(pAx, windowsizeX - pBx);
			pAy = min(pAy, windowsizeY - pBy);
			triangle(frame);
			break;
			break;
		case CARRE:
			pBx = 30;
			pBy = 30;
			pAx = min(pAx, windowsizeX - pBx);
			pAy = min(pAy, windowsizeY - pBy);
			rectangle(frame, Rect(pAx, pAy, pBx, pBy), Scalar(r, g, b), FILLED);
			break;
		}
	}
	void triangle(Mat frame) {
		typedef std::vector<cv::Point> point_vector;
		typedef std::vector<point_vector> contour_vector;
		Point p1 = Point(pAx+pBx/2,pAy);
		Point p2 = Point(pAx,pAy+pBy);
		Point p3 = Point(pAx+pBx,pAy+pBy);
		vector<Point> contours;
		contours.push_back(p1);
		contours.push_back(p2);
		contours.push_back(p3);

		contour_vector hulls(1);

		// Initialize the contour with the convex hull points
		cv::convexHull(cv::Mat(contours), hulls[0]);
		cv::drawContours(frame, hulls, 0, Scalar(r, g, b), -1);

	}
	bool CheckConflicate(int a[][4])
	{

		int len = sizeof(a) / sizeof(a[0]);
		for(int i = 0;i<len;i++)
		{
			if ((abs(pAx - a[i][0]) <= max(pBx, a[i][2])) && (abs(pAy - a[i][1]) <= max(pBy, a[i][3])))
			{
				isconflicate = true;
				return true;
			}
		}
		isconflicate = false;
		return false;
	}
	void Déplacement(Mat Frame, forms **tab ,int a[][4]) {
		CheckConflicate(a);
		// object hit the bottom line 
		int num = 20 * ((((int)form + 2) % 5)%2) ;
		if ((pAx + pBx) == Frame.rows && dct == DOWN ) { dct = UP; }
		if ((pAx + pBx) == Frame.rows && dct == LEFTDOWN ) { dct = UPLEFT; }
		if ((pAx + pBx) == Frame.rows && dct == RIGHTDOWN) { dct = UPRIGHT; }
		// object hit the Right line 
		if ((pAy + pBy) == Frame.cols && dct == RIGHT ) { dct = LEFT; }
		if ((pAy + pBy) == Frame.cols && dct == UPRIGHT ) { dct = UPLEFT; }
		if ((pAy + pBy) == Frame.cols && dct == RIGHTDOWN ) { dct = LEFTDOWN; }
		// object hit the upper line
		if (pAx == num && dct == UP) { dct = DOWN; }
		if (pAx == num && dct == UPLEFT) { dct = LEFTDOWN; }
		if (pAx == num && dct == UPRIGHT) { dct = RIGHTDOWN; }
		// object hit the left line 
		if (pAy == num && dct == LEFT ) { dct = RIGHT; }
		if (pAy == num && dct == UPLEFT ) { dct = UPRIGHT; }
		if (pAy == num && dct == LEFTDOWN ) { dct = RIGHTDOWN; }

		//check conflicate
		if (isconflicate && dct == UP) { dct = DOWN; }
		if (isconflicate && dct == UPLEFT) { dct = LEFTDOWN; }
		if (isconflicate && dct == UPRIGHT) { dct = RIGHTDOWN; }

		if (isconflicate && dct == LEFT) { dct = RIGHT; }
		if (isconflicate && dct == UPLEFT) { dct = UPRIGHT; }
		if (isconflicate && dct == LEFTDOWN) { dct = RIGHTDOWN; }

		if (isconflicate && dct == DOWN) { dct = UP; }
		if (isconflicate && dct == LEFTDOWN) { dct = UPLEFT; }
		if (isconflicate && dct == RIGHTDOWN) { dct = UPRIGHT; }

		if (isconflicate && dct == RIGHT) { dct = LEFT; }
		if (isconflicate && dct == UPRIGHT) { dct = UPLEFT; }
		if (isconflicate && dct == RIGHTDOWN) { dct = LEFTDOWN; }
		switch (dct) {
		case LEFT:
			pAy--;
			break;
		case UPLEFT: pAx--; pAy--;	break;
		case UP: pAx--;	break;
		case UPRIGHT:pAy++; pAx--;	break;
		case RIGHT: pAy++;	break;
		case RIGHTDOWN: pAy++; pAx++;	break;
		case DOWN: pAx++;	break;
		case LEFTDOWN: pAx++; pAy--; break;
		case STOP:  randomDirection(); break;
		}
	}

};

void create_video(int t, int r, int c,int time, int pointFix,int ar,int g, int b)
{
	int FPS = 5;
	int FramesizeX = windowsizeX;
	int FramesizeY = windowsizeY;
	int arr[100][4];
	auto start = high_resolution_clock::now();

	PointFixe * LespointFixe[100];
	forms * LesForms[50];
	freopen("CONOUT$", "w", stdout);
	std::cout << "This works" << std::endl;
	//la capture vidéo ici une webcam
	VideoCapture cap;
	if (!cap.open(0))


		namedWindow("camera");
	resizeWindow("camera", Size(windowsizeX, windowsizeY));
	VideoWriter video("output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 20, Size(windowsizeX, windowsizeY)); //write the video


	// declaration des object point fixe  . 
	for (int i = 0; i < pointFix; i++) {
		int m = (rand() % FramesizeX) + 1;
		int n = (rand() % FramesizeY) + 1;
		LespointFixe[i] = new PointFixe(m, n);
	}
	// declaration des object .

	for (int i = 0; i < t; i++) {
		int a = (rand() % FramesizeX - 30);
		int b = (rand() % FramesizeY - 30);
		LesForms[i] = new forms(a,b,2);
		//save shapes position
		arr[i][0] = LesForms[i]->getX();
		arr[i][1] = LesForms[i]->getY();
		arr[i][2] = LesForms[i]->getBX();
		arr[i][3] = LesForms[i]->getBY();
	}
	for (int i = t; i < c+t; i++) {
		int a = (rand() % FramesizeX-30);
		int b = (rand() % FramesizeY-30);
		LesForms[i] = new forms(max(20, a), max(b, 20),1);
		//save shapes position
		arr[i][0] = LesForms[i]->getX();
		arr[i][1] = LesForms[i]->getY();
		arr[i][2] = LesForms[i]->getBX();
		arr[i][3] = LesForms[i]->getBY();
	}
	for (int i = c+t; i < c+r+t; i++) {
		int a = (rand() % FramesizeX);
		int b = (rand() % FramesizeY);
		LesForms[i] = new forms(a, b,3);
		//save shapes position
		arr[i][0] = LesForms[i]->getX();
		arr[i][1] = LesForms[i]->getY();
		arr[i][2] = LesForms[i]->getBX();
		arr[i][3] = LesForms[i]->getBY();
	}

	for (;;)
	{	// new Picture to add to the video 
		Mat frame;
		cap >> frame;
		frame = Mat(FramesizeX, FramesizeY, CV_8UC3);
		if (frame.empty()) break; // end of video stream

								  // draw the fix points 

		for (int i = 0; i < pointFix; i++) {
			LespointFixe[i]->createpoint(frame, ar, g, b);
		}
		auto test = duration_cast<milliseconds> (high_resolution_clock::now() - start);
		if (test.count() >= time * 1000)
		{
			for (int i = 0; i < pointFix; i++) {
				int m = (rand() % FramesizeX) + 1;
				int n = (rand() % FramesizeY) + 1;
				LespointFixe[i]->update(m, n);
			}
			start = high_resolution_clock::now();
		}
		for (int i = 0; i < c + r + t; i++) {
			LesForms[i]->Déplacement(frame, LesForms,arr);
			LesForms[i]->createforms(frame);
			//save shapes position
			arr[i][0] = LesForms[i]->getX();
			arr[i][1] = LesForms[i]->getY();
			arr[i][2] = LesForms[i]->getBX();
			arr[i][3] = LesForms[i]->getBY();
		}
		// passe the image to the video 
		video.write(frame);
		if (waitKey(FPS) == 27) break; // stop capturing by pressing ESC 
		imshow("camera", frame);

	} // end  the for loop 
	  //Pour relcher la capture on utilize :
	cap.release();
	//Pour relcher le writer on utilize :
	video.release();
}
