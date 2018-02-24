#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int mod = 10007;
vector<int> prime;
bool ok[2010];
void Init(){
	prime.push_back(-1);
	for (int i = 2; i<2010; ++i){
		if (!ok[i]){
			prime.push_back(i);
			for (int j = i; j<2010; j += i){
				ok[j] = 1;
			}

		}
	}
}

int quick_mod(int a, int p){
	int ret = 1;
	while (p){
		if (p & 1)
			ret = (ret*a) % mod;
		a = (a*a) % mod;
		p /= 2;
	}
	return ret;
}



int num[320];



int main(){
	ifstream in("C:\\input.txt");
	Init();


	int inv4 = quick_mod(4, mod - 2);
	int a, b;
	int CASE = 1;
	while (cin >> a >> b){
		for (int i = 0; i<320; ++i)
			num[i] = 0;
		for (int i = 1; i<prime.size() && prime[i] <= a; ++i){
			while (a%prime[i] == 0){
				a /= prime[i];
				num[i]++;
			}
		}
		if (a != 1)
			num[0] = 1;
		int sum = 1;
		for (int i = 0; i<prime.size(); ++i){
			if (num[i] > 0){
				num[i] = (num[i]*b)%mod;
				int t = num[i] + 1;
				sum = sum *(t*t % mod*((t*t+2*t+1)%mod)% mod*inv4%mod) % mod;
			}
		}
		printf("Case %d: %d\n", CASE++, sum);

	}

}