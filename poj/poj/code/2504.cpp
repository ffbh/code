#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
struct Node{
	double x, y;
	double M(){
		return sqrt(x*x + y*y);
	}
}data[3];
const double PI = acos(-1.0);
const double Exp = 1e-8;
bool dequal(double a, double b){
	return fabs(a - b) < Exp;
}

void getCenterPoint(Node& ans){
	double x1, y1, x2, y2, k1, k2, b1, b2;
	if (dequal(data[0].y, data[1].y)){
		x1 = (data[0].x + data[2].x) / 2.0;
		y1 = (data[0].y + data[2].y) / 2.0;
		x2 = (data[1].x + data[2].x) / 2.0;
		y2 = (data[1].y + data[2].y) / 2.0;
		k1 = (data[0].x - data[2].x) / (data[2].y - data[0].y);
		k2 = (data[1].x - data[2].x) / (data[2].y - data[1].y);
	}
	else if (dequal(data[0].y, data[2].y)){
		x1 = (data[0].x + data[1].x) / 2.0;
		y1 = (data[0].y + data[1].y) / 2.0;
		x2 = (data[1].x + data[2].x) / 2.0;
		y2 = (data[1].y + data[2].y) / 2.0;
		k1 = (data[0].x - data[1].x) / (data[1].y - data[0].y);
		k2 = (data[1].x - data[2].x) / (data[2].y - data[1].y);
	}
	else{
		x1 = (data[0].x + data[1].x) / 2.0;
		y1 = (data[0].y + data[1].y) / 2.0;
		x2 = (data[0].x + data[2].x) / 2.0;
		y2 = (data[0].y + data[2].y) / 2.0;
		k1 = (data[0].x - data[1].x) / (data[1].y - data[0].y);
		k2 = (data[0].x - data[2].x) / (data[2].y - data[0].y);
	}
	b1 = y1 - k1*x1;
	b2 = y2 - k2*x2;
	ans.x = (b2 - b1) / (k1 - k2);
	ans.y = k1*ans.x + b1;
}

double getDist(Node& a,Node& b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool chaji(Node& a,Node& b){
	return a.x*b.y - a.y*b.x>=0;

}

double getAngle(){
	Node tmp;
	tmp.x = 1;
	tmp.y = 0;
	bool sign = chaji(tmp, data[0]);
	double angle = acos((data[0].x*tmp.x + data[0].y*tmp.y) / data[0].M() / tmp.M());
	if (sign)
		return angle;
	else
		return 2*PI - angle;
}

int main(){
	ifstream in("C:\\input.txt");
	int CASE = 1;
	while (cin >> N&&N){
		for (int i = 0; i < 3; ++i)
			cin >> data[i].x >> data[i].y;
		Node center;
		getCenterPoint(center);
		/*cout << center.x << " " << center.y << endl;
		for (int i = 0; i < 3; ++i){
			cout << getDist(center, data[i]) << endl;*/
		double r = getDist(center, data[0]);
		double m_ang = 360.0 / N;
		for (int i = 0; i < 3; ++i){
			data[i].x -= center.x;
			data[i].y -= center.y;
		}
		double startangle = getAngle() *180/PI;
		double lx, ly, rx, ry;
		lx = rx = data[0].x;
		ly = ry = data[0].y;
		for (int i = 0; i < N; ++i){
			double nowangle = (startangle + m_ang*i);
			if (nowangle > 360.0)
				nowangle -= 360;
			nowangle = nowangle *PI / 180.0;
			double x = cos(nowangle)*r;
			double y = sin(nowangle)*r;
			if (x < lx)
				lx = x;
			if (x > rx)
				rx = x;
			if (y < ly)
				ly = y;
			if (y > ry)
				ry = y;
		}
		printf("Polygon %d: %.3f\n", CASE++, (rx - lx)*(ry - ly));
	}
















	return 0;
}