#include <iostream>
#include <string>
#include <fstream>
using namespace std;

_int64 fun(_int64 a,_int64 b){
	_int64 ans = 1;
	for (_int64 i = b; i > b - a; --i)
		ans *= i;
	while (a > 1){
		ans /= a--;
	}
	return ans;
}

int main(){
	ifstream in("C:\\temp.txt");
	string s;
	int T;
	in >> T;
	while (T--){
		cin >> s;
		int N = s.length();
		_int64 ans = 0;
		for (int i = 0; i * 2 <= N; ++i)
			ans += fun(i , N-i);

		cout << ans << endl;
	}
	return 0;
}