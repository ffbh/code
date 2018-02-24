#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
void fun(double& m,int M){
	int d = int(m) /M;
	m -= d * M;
}

int quickmod(double k, int n){
	double ans = 1.0;
	while (n){
		if (n % 2){
			ans = ans*k;
			fun(ans,1024*64);
		}
		n /= 2;
		k *= k;
		fun(k,1024*64);
	}
	fun(ans, 1024);
	return int(ans);
}

int main(){
	ifstream in("C:\\temp.txt");
	const double K = sqrt(2) + sqrt(3);
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		cout << quickmod(K,2* N) << endl;
	}
	return 0;
}