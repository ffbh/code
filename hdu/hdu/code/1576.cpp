#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
const int mod = 9973;
int qm(int a, int p){
	a %= mod;
	int ret = 1;
	while (p){
		if (p & 1)
			ret = ret*a%mod;
		a = a*a%mod;
		p /= 2;
	}

	return ret;

}

int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T-- > 0){
		int n, b;
		cin >> n >> b;
		cout << n*qm(b, mod - 2) % mod << endl;

	}















	return 0;
}