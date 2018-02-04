#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int prime[7000];//6543
int cnt;
bool Is(int n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)return 0;
	return 1;
}

int ans[500];
int kk;
int main(){
	ifstream in("C:\\temp.txt");
	cnt = 0;
	for (int i = 2; i <= 65535;++i)
	if (Is(i))
		prime[cnt++] = i;
	int N;
	while (cin >> N){
		kk = 0;
		for (int i = 0; i < cnt&&N>1;++i)
		while (N%prime[i]==0){
			ans[kk++] = prime[i];
			N /= prime[i];
		}
		for (int i = 0; i < kk - 1; ++i)
			printf("%d*", ans[i]);
		cout << ans[kk - 1] << endl;



	}



	return 0;
}