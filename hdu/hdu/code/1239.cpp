#include <iostream>
#include <string>
//#include <fstream>
#include <cmath>
using namespace std;
int prime[10000];//9593
bool fun(int n){
	for (int i = 2;i<=sqrt(n);++i)
	if (n%i == 0)return false;
	return 1;

}
int main(){
	//ofstream out("C:\\temp10.txt");
	int k = 1;
	for (int i = 2; i <= 100000;++i)
	if (fun(i))
		prime[k++] = i;
	int m, a, b, p, q, mmax;
	while (cin >> m >> a >> b){
		if (m == 0 && a == 0 && b == 0)break;
		mmax = 0;
		for (int i = 1; i < 9593; ++i){
			if (prime[i]>m / 2)break;
			for (int j = i; j < 9593; ++j){
				if (prime[j]>m / 2)break;
				if (prime[i] * prime[j] <= m&&
					double(prime[i]) / prime[j] >= double(a) / b
					&&prime[i] * prime[j]>mmax){
					mmax = prime[i] * prime[j];
					p = prime[i];
					q = prime[j];
				}
			}
		}
			printf("%d %d\n", p, q);
	
	
	
	}





	return 0;
}