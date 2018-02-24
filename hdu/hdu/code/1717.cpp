#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
_int64 gcd(_int64 n, _int64 m){
	if (m == 0)
		return n;
	else
		return gcd(m, n%m);
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	string s;
	cin >> T;
	_int64 a, b, c, d;
	bool flag;
	while (T--){
		flag = 1;
		a = c = 0;
		b = d = 1;
		cin >> s;
		for (int i = 2; i < s.length(); ++i){
			if (s[i] == '(')
				flag = 0;
			if (s[i] >= '0'&&s[i] <= '9'){
				if (flag){
					a = a * 10 + s[i] - '0';
					b *= 10;
				}
				c = c * 10 + s[i] - '0';
				d *= 10;
			}
		}
		if (flag){
			int g = gcd(b, a);
			printf("%I64d/%I64d\n", a / g, b / g);
		}
		else {
			int g = gcd(d - b, c - a);
			printf("%I64d/%I64d\n", (c-a) / g, (d-b) / g);
		}
	}
	return 0;
}