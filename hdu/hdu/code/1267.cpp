#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 _fun(int n,int k){
	if (n == 0)
		return 0;
	int res = 1;
	for (int i = n; i >n-k; --i)
		res *= i;
	return res;
}

_int64 fun(int a,int b){
	if (a == 0)
		return 1;
	return _fun(b,a) / _fun(a,a);
}

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		if (N < M)
			cout << 0 << endl;
		else
			cout << fun(M, N + M) - fun(M - 1, N + M) << endl;
	}





	return 0;
}