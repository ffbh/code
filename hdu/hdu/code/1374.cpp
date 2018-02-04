#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
#define PI 3.141592653589793


int main(){
	ifstream in("C:\\temp.txt");
	double x1, y1, x2, y2, x3, y3;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		double mx1, my1, mx2, my2;
		double k1, k2;
		mx1 = (x1 + x2) / 2.0;
		my1 = (y1 + y2) / 2.0;
		k1 = (y1 - y2) / (x1 - x2);
		if (k1)
			k1 = -1.0 / k1;
		else{
			mx1 = (x3 + x2) / 2.0;
			my1 = (y3 + y2) / 2.0;
			k1 = (y3 - y2) / (x3 - x2);
			k1 = -1.0 / k1;
		}
		mx2 = (x1 + x3) / 2.0;
		my2 = (y1 + y3) / 2.0;
		k2 = (y1 - y3) / (x1 - x3);
		if (k2)
			k2 = -1.0 / k2;
		else{
			mx2 = (x2 + x3) / 2.0;
			my2 = (y2 + y3) / 2.0;
			k2 = (y2 - y3) / (x2 - x3);
			k2 = -1.0 / k2;
		}
		double midx, midy;
		midx = (k1*mx1 - k2*mx2 + my2 - my1) / (k1 - k2);
		midy = k1*(midx - mx1) + my1;
		double r = sqrt((x1 - midx)*(x1-midx) + (y1 - midy)*(y1-midy));
		printf("%.2f\n", 2 * PI*r);
	}
	return 0;
}