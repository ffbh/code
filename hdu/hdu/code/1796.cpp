#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long N, M;
long long data[12];
long long gcd(long long a, long long b){
	if (a%b==0)
		return b;
	return gcd(b, a%b);

}

long long lcm(long long a, long long b){
	if (a < b)
		swap(a, b);
	long long g = gcd(a, b);
	return a*b / g;
}


long long cale(int mask){
	int num = 0;
	long long K = 1;
	for (int i = 0; i < M; ++i){
		int p = 1 << i;
		if (mask & p){
			num++;
			K = lcm(K, data[i]);
			if (K > N)
				return 0;
		}
	}
	if (num % 2 == 1){
		return N / K;
	}
	else{
		return -N / K;
	}
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N >> M){
		N--;
		for (int i = 0; i < M; ++i){
			cin >> data[i];
			if (data[i] == 0){
				i--;
				M--;
			}
		}
		long long ans = N;
		for (int i = 1; i < (1 << M); ++i){
			ans -= cale(i);
		}
		cout << N - ans << endl;
	}
	return 0;
}


