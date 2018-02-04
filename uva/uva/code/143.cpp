#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
struct Node{
	double x, y;
}data[5];

double getDist(Node& a,Node& b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double cale(Node& p1,Node& p2,Node& p3){
	double a, b, c, p;
	a = getDist(p1,p2);
	b = getDist(p1, p3);
	c = getDist(p2, p3);
	p = (a + b + c) / 2.0;

	return sqrt(p*(p - a)*(p - b)*(p - c));
}

/*int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

	while (true){	
		bool ok = 0;
		for (int i = 0; i < 3; ++i){
			in >> data[i].x >> data[i].y;
			if (fabs(data[i].x) > 1e-7 || fabs(data[i].y) > 1e-7){
				ok = 1;
			}
		}
		if (!ok)
			break;

		double min_x, min_y, max_x, max_y;
		min_x = min(min(data[0].x, data[1].x), data[2].x);
		max_x = max(max(data[0].x, data[1].x), data[2].x);
		min_y = min(min(data[0].y, data[1].y), data[2].y);
		max_y = max(max(data[0].y, data[1].y), data[2].y);
		Node tmp;
		double area = cale(data[0], data[1], data[2]);
		int num = 0;
		int lx = floor(min_x) - 1;
		int rx = ceil(max_x) + 1;
		int ly = floor(min_y) - 1;
		int ry = ceil(max_y) + 1;
		if (lx < 1)
			lx = 1;
		if (ly < 1)
			ly = 1;
		if (rx>99)
			rx = 99;
		if (ry>99)
			ry = 99;
		for (int i = 1; i <= 99;++i)
		for (int j = 1; j <= 99; ++j){
			tmp.x = i;
			tmp.y = j;
			double tmparea = 0;
			tmparea += cale(data[0], data[1], tmp);
			tmparea += cale(data[0], data[2], tmp);
			tmparea += cale(data[1], data[2], tmp);

			if (fabs(area - tmparea) < 1e-9){
				num++;
			}
		}
		printf("%4d\n", num);
	}




	return 0;
}*/