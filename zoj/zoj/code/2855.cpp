#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
struct Node{
	double lx, ly, rx, ry;
	double midx, midy;
	void cale(){
		midx = (lx + rx) / 2.0;
		midy = (ly + ry) / 2.0;
	}
}map;

int main(){
	ifstream in("C:\\temp.txt");
	double longitude, latitude, x, y;
	double PI = acos(-1.0);
	int M;
	while (cin >> longitude >> latitude){
		cin >> M;
	//	x = longitude;
		//y = latitude;
		x = longitude * PI / 180.0;
		y = log(tan(PI / 4.0 + (latitude*PI / 180.0) / 2.0));
		map.lx = -PI;
		map.rx = PI;
		map.ly = log(tan(PI / 4.0 + (-85.0*PI / 180.0) / 2.0));
		map.ry = log(tan(PI / 4.0 + (85.0*PI / 180.0) / 2.0));
		putchar('t');
		while (M--){
			map.cale();
			if (map.midx > x&&map.midy > y){
				putchar('t');
				map.rx = map.midx;
				map.ry = map.midy;
			}
			else if (map.midx > x&&map.midy < y){
				putchar('q');
				map.rx = map.midx;
				map.ly = map.midy;
			}
			else if (map.midx<x&&map.midy>y){
				putchar('s');
				map.lx = map.midx;
				map.ry = map.midy;
			}
			else{
				putchar('r');
				map.lx = map.midx;
				map.ly = map.midy;
			}
		}
		cout << endl;
	}
	return 0;
}