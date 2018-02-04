#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int ans[21] = { 0, 1, 2, 3, 4, 5, 6, 9, 12, 16, 20, 27, 36, 48, 64, 81, 108, 144, 192, 256, 324};
const long long  mod = 1000000007;

long long quickmod(long long d,long long  n){
	long long ret = 1;
	while (n){
		if (n & 1){
			ret = (ret * d) % mod;
		}
		d = (d*d) % mod;
		n /= 2;
	}
	return ret;

}

/*int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	if (N < 20){
		cout << ans[N] << endl;
	}
	else{
		int m = N % 5;
		long long base = ans[15 + m];
		long long  p = (N - 15) / 5;
		long long ret = quickmod(4, p);
		cout << (ret * base) % mod;
	}

	return 0;
}*/