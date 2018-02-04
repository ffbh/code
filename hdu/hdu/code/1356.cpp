#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b){
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

void ex_gcd(long long a,long long b,long long& x,long long& y){
	if (b == 0){
		x = 1;
		y = 0;
	}
	else{
		ex_gcd(b, a%b, x, y);
		long long temp = x;
		x = y;
		y = (temp - a / b*y);
	
	}
}


int main(){
	ifstream in("C:\\input.txt");
	long long a, b, d, x, y, ansx, ansy;
	while (in >> a >> b >> d && a + b + d){
		int g = gcd(a, b);

		d /= g;
		
		ex_gcd(a, b, x, y);

		x *= d;
		y *= d;
	//	cout << x << " " << y << endl;
		long long absum = abs(x) + abs(y);
		long long sum = abs(x)*a + abs(y)*b;
		ansx = x;
		ansy = y;
		for (int i = 1;; ++i){
			long long tmpx = x + b/g  * i;
			long long tmpy = y - a/g * i;
			if (abs(tmpx) + abs(tmpy) < absum || abs(tmpx) + abs(tmpy) == absum && abs(tmpx)*a + abs(tmpy)*b < sum){
				ansx = tmpx;
				ansy = tmpy;
				absum = abs(tmpx) + abs(tmpy);
				sum = abs(tmpx)*a + abs(tmpy)*b;
			}
			else
				break;
		}

		for (int i = -1;; --i){
			long long tmpx = x + b/g * i;
			long long tmpy = y - a/g * i;
			if (abs(tmpx) + abs(tmpy) < absum || abs(tmpx) + abs(tmpy) == absum && abs(tmpx)*a + abs(tmpy)*b < sum){
				ansx = tmpx;
				ansy = tmpy;
				absum = abs(tmpx) + abs(tmpy);
				sum = abs(tmpx)*a + abs(tmpy)*b;
			}
			else
				break;
		}
	

		cout << abs(ansx) << " " << abs(ansy) << endl;


		


	


	}
















	return 0;
}