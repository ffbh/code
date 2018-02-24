#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point{
	double x,y;
}data[3];
Point temp;
double getArea(int a,int b){
	return fabs((data[a].x - temp.x)*(data[b].y - temp.y) -
		(data[a].y - temp.y)*(data[b].x - temp.x));
}

int main(){
	ifstream in("C:\\temp.txt");
	while (1){
		double sum = 0;
		double minx, miny, maxx, maxy;
		minx = miny = DBL_MAX;
		maxx = maxy = DBL_MIN;
		for (int i = 0; i < 3; ++i){
			cin >> data[i].x >> data[i].y;
			sum += data[i].y + data[i].y;
			if (minx > data[i].x)
				minx = data[i].x;
			if (miny > data[i].y)
				miny = data[i].y;
			if (maxx < data[i].x)
				maxx = data[i].x;
			if (maxy < data[i].y)
				maxy = data[i].y;
		}
		temp.x = data[0].x;
		temp.y = data[0].y;
		double S = getArea(1, 2);
		if (sum == 0)
			break;
		int num = 0;
		minx = max(minx, 1.0);
		miny = max(miny, 1.0);
		maxx = min(maxx, 99.0);
		maxy = min(maxy, 99.0);
		for (int i = int(minx); i <= ceil(maxx); ++i)
		for (int j = int(miny); j <= ceil(maxy); ++j){
			temp.x = i;
			temp.y = j;
			double s1, s2, s3;
			s1 = getArea(0, 1);
			s2 = getArea(0, 2);
			s3 = getArea(1, 2);
			if (fabs(S - s1 - s2 - s3) < 1e-9)
				num++;
		}
		printf("%4d\n", num);
	}
	return 0;
}