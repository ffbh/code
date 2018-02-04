#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
	ifstream in("C:\\temp.txt");
	double x1, y1, x2, y2, x3, y3;
	int T;
	cin >> T;
	while (T--){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		double a, b, c, k, f;
		a = (y1 - y2) / (-x1*x1 - x2*x2 + 2 * x1*x2);
		b = -2 * a*x1;
		c = y1 + a*x1*x1;
		k = (y2 - y3) / (x2 - x3);
		f = y2 - k*x2;
		double ans1, ans2;
		ans1 = a*x3*x3*x3 / 3.0 + b*x3*x3 / 2.0 + c*x3 - k*x3*x3 / 2.0 - f*x3;
		ans2 = a*x2*x2*x2 / 3.0 + b*x2*x2 / 2.0 + c*x2 - k*x2*x2 / 2.0 - f*x2;
		printf("%.2f\n", ans1 - ans2);
	}
	return 0;
}