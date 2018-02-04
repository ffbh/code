#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);
void cale(double a, double b, double s, double m, double n){
	double x = a * m;
	double y = b * n;
	printf("%.2f %.2f\n", atan2(y, x)*180.0/PI, sqrt(x*x + y*y) / s);
}


int main(){
	ifstream in("C:\\input.txt");
	int a, b, s, m, n;
	while (cin >> a >> b >> s >> m >> n){
		if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0){
			break;
		}
		cale(a, b, s, m, n);
	}
















	return 0;
}