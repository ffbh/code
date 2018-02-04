#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	_int64 a, b;
	int m;
	string res;
	while (cin >> m >> a >> b&&m){
		_int64 ans = a + b;
		res = "";
		while (ans){
			res += ans%m + '0';
			ans /= m;
		}
		int len = res.length()-1;
		while (len>=0&&res[len] == '0')len--;
		if (len < 0)
			cout << 0 ;
		else
		while (len >= 0)
			cout << res[len--];
		cout << endl;



	}
	return 0;
}