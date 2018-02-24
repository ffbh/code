#include <iostream>
#include <string> 
#include <fstream>
#include <cmath>
using namespace std;
#define exp (1e-9)
double H, h, D;
double cale(double m){
	double k, b, y;
	k = (h - H) / m;
	b = H;
	y = k*D + H;
	if (y >= 0)
		y += D - m;
	else
		y = (h*m) / (H - h);
	return y;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> H >> h >> D;
		double l, r, m, y1,y2;
		l = 0;
		r = D;
		while (r - l >= exp){
			double m1, m2;
			m1 = l + (r - l) / 3.0;
			m2 = l + 2 * (r - l) / 3.0;
			y1 = cale(m1);
			y2 = cale(m2);
			if (y1 < y2)
				l = m1;
			else
				r = m2;
		}
		printf("%.3f\n", cale((l+r)/2.0));
	}


	return 0;
}
