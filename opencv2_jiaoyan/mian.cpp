#include<iostream>
#include<opencv2/core/core.hpp> 
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
void salt(Mat &  image, int n) {
	for (int k = 0;k < n;k++) {
			int i = rand() % image.cols;
			int j = rand() % image.rows;
			if (image.channels() == 1) {//�Ҷ�ͼ
				image.at<uchar>(j, i) = 225;
			}
			else if (image.channels() == 3) {//��ͼ
				image.at<Vec3b>(j, i)[0] = 225;
				image.at<Vec3b>(j, i)[1] = 225;
				image.at<Vec3b>(j, i)[2] = 225;
			}
	}
}
int main() {
	Mat image =imread("pic.jpg");
	Mat image1 = imread("pic.jpg");
	salt(image,3000);
	namedWindow("image");
	imshow("image",image);
	namedWindow("ԭͼ");
	imshow("ԭͼ", image1);
	waitKey();
	return 0;
}