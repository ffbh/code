#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long s1, s2, v1, v2, m;

long long ex_gcd(long long n, long long m, long long& x, long long& y){
	if (m == 0){
		x = 1;
		y = 0;
		return n;
	}
	else{
		long long gcd = ex_gcd(m, n%m, x, y);
		long long temp = x;
		x = y;
		y = temp - n / m*y;
		return gcd;
	}
}


int main(){
	ifstream in("C:\\input.txt");
	long long x, y;
	cin >> s1 >> s2 >> v1 >> v2 >> m;
	if (v1 < v2){
		swap(v1, v2);
		swap(s1, s2);
	}
	long long speed = v1 - v2;
	long long dist = (s2 + m - s1) % m;
	long long gcd = ex_gcd(speed, m, x, y);
	long long mul = dist / gcd;
	if (dist % gcd != 0)
		cout << -1 << endl;
	else{
		dist /= gcd;
		speed /= gcd;
		m /= gcd;
		ex_gcd(speed, m, x, y);
		cout << (x%m + m) % m*dist%m << endl;
	}


	return 0;
}