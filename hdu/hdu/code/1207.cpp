#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 data[70];
_int64 fun(int n){
	_int64 ans = 1;
	while (n-->0)
		ans <<= 1;
	return ans;
}

void Init(){
	data[1] = 1;
	data[2] = 3;
	for (int i = 3; i <= 65; ++i){
		_int64 mmin =  - 1;
		for (int j = i/5+1; j < i; ++j){
			_int64 temp = 2*data[j] + fun(i-j)-1;
			if (mmin>temp||mmin == -1)
				mmin = temp;
		}
		data[i] = mmin;
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	Init();
	int N;
	while (cin >> N)
		cout << data[N] << endl;




	return 0;
}