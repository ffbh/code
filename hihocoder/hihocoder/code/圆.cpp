#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
double x, y, r, maxr, tmpr;
const double esp = 1e-6;



int main(){
	ifstream in("C:\\input.txt");

	int ansx, ansy, mminx, mmaxx, mminy, mmaxy;
	cin >> x >> y >> r;
	mminx = ceil(x - r);
	mmaxx = floor(x + r);
	for (int i = mmaxx; i >= mminx; --i){
		mmaxy = floor(y + sqrt(r * r - (i - x)*(i - x)));
		tmpr = sqrt(double(i - x)*(i - x) + (mmaxy - y)*(mmaxy - y));
		if (tmpr - maxr > esp){
			maxr = tmpr;
			ansx = i;
			ansy = mmaxy;
		}

		mminy = ceil(y - sqrt(r * r - (i - x)*(i - x)));
		tmpr = sqrt(double(i - x)*(i - x) + (mminy - y)*(mminy - y));
		if (tmpr - maxr > esp) {
			maxr = tmpr;
			ansx = i;
			ansy = mminy;
		}
	}
	printf("%d %d\n", ansx, ansy);













	return 0;
}