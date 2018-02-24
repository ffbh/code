#include <iostream>

using namespace std;


int reverse(int n){
	int m = 0;
	while (n){
		m = 10 * m + n % 10;
		n /= 10;
	}
	return m;
}
int main(){
	int N;
	int k;
	int V;
	while (cin >> N){
		int M = -1;
		k = 0;
		V = N;
		while (1){
			M = reverse(N);
			if (N == M)break;
			N += M;
			//printf("--->%d", N);
			k++;
		}
		cout << k << endl;
		N = V;
		cout << V;
		while (1){
			M = reverse(N);
			if (N == M)break;
			N += M;
			printf("--->%d", N);
		}
		cout << endl;
	}


	return 0;
}