#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

_int64 fun(_int64 n){
	_int64 ans = 1;
	for (int i = 1; i <= n; ++i)
		ans *= i;
	return ans;
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	char c;
	_int64 m, n;
	while (T--){
		cin >> c >> n >> m;
		if (c == 'A'){
			cout << fun(n) / fun(n - m) << endl;
		}
		else
			cout << fun(n) / fun(m) / fun(n - m) << endl;
	
	
	
	}

	return 0;
}