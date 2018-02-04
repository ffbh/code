#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char cale(_int64 c, _int64 d, _int64 N){
	_int64 res = 1;
	while (d > 0){
		if (d % 2)
			res = (res*c)%N;
		c = (c*c)%N;
		d /= 2;
	}
	return char(res);
}

int main(){
	//ifstream in("C:\\temp.txt");
	_int64 p, q, e, d, t;
	int n;
	while (cin >> p >> q >> e >> n){
		_int64 N = p*q;
		_int64 F = (p - 1)*(q - 1);
		for (d = 1;;++d)
		if ((d*e)%F == 1)
			break;
		while (n--){
		//	in >> t;
			scanf("%I64d", &t);
			putchar(cale(t,d,N));
		}
		cout << endl;
	}
	return 0;
}