
#pragma once
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm> 

using namespace std;
using namespace cv;


cv::Mat filtreMediane(Mat src, int voisinage) {
	Mat dst = src;
	if (src.channels() != 1 || dst.channels() != 1) return dst;
	if (src.rows != dst.rows || src.cols != dst.cols) return dst;
	//if (voisinage % 2 != 1) return dst;
	Rect roi = Rect(0, 0, voisinage, voisinage);
	int *voisins = new int[voisinage*voisinage];  // un tableau pour le calcul de la m�diane
	for (int x = 0; x < src.rows; x++) {
		for (int y = 0; y < src.cols; y++) {
			if (x< (voisinage - 1) / 2 || x>(src.rows - 1 - (voisinage - 1) / 2) || y< (voisinage - 1) / 2 || y>(src.cols - 1 - (voisinage - 1) / 2))    // pour le bord copier les m�mes valeurs des pixels
			{
				dst.at<uchar>(x, y) = src.at<uchar>(x, y);
			}
			else
			{
				roi.y = x - (voisinage - 1) / 2;// on centre le voisinage sur le pixel en cours
				roi.x = y - (voisinage - 1) / 2;
				Mat img_roi = src(roi);
				for (int i = 0; i < voisinage; i++) {
					for (int j = 0; j < voisinage; j++) {
						voisins[i*voisinage + j] = img_roi.at<uchar>(i, j);
					}
				}
				sort(voisins, voisins + (voisinage*voisinage));   // on classe les valeurs
				dst.at<uchar>(x, y) = voisins[(voisinage*voisinage - 1) / 2];    // on choisit la valeur m�diane
			}
		}
	}
return dst;
}

cv::Mat filtreMoyen(Mat src, int voisinage) {
	Mat dst = src;
	if (src.channels() != 1 || dst.channels() != 1) return dst;// verifier que c�est en niveau de gris
	if (src.rows != dst.rows || src.cols != dst.cols) return dst;// meme dimensions
															 //on verifie que le voisinage est impair sinon on le corrige
	//if (voisinage % 2 != 1) return dst;
	Rect rec_roi = Rect(0, 0, voisinage, voisinage);// on initialise un carr� pour la RO
	int moyenne = 0;
	for (int x = 0; x < src.rows; x++) {
		for (int y = 0; y < src.cols; y++) {
			if (x< (voisinage - 1) / 2 || x>(src.rows - 1 - (voisinage - 1) / 2)
				|| y< (voisinage - 1) / 2 || y>(src.cols - 1 - (voisinage - 1) / 2))    // pour le bord copier les m�mes valeurs des pixels
			{
				dst.at<uchar>(x, y) = src.at<uchar>(x, y); // pour le bord copier les m�mes valeurs des pixels
			}
			else
			{
				moyenne = 0;
				rec_roi.y = x - (voisinage - 1) / 2; // on centre le voisinage sur le pixel en cours
				rec_roi.x = y - (voisinage - 1) / 2;
				Mat img_roi = src(rec_roi);// on initialise la region dinteret				
				for (int i = 0; i < voisinage; i++) { // on calcule la somme du voisinage
					for (int j = 0; j < voisinage; j++) {
						moyenne += img_roi.at<uchar>(i, j);
					}
				}
				moyenne /= voisinage*voisinage;// la moyenne
				dst.at<uchar>(x, y) = moyenne;
			}
		}
	}
return dst;
}

