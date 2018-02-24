#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long 
const ll mod = 1000000007;
ll dp[40], sum = 0;
int f[40];//0-25

void add(ll num){
	sum = (sum + num) % mod;
}

void initF(){
	f[0] = f[1] = 1;
	for (int i = 2; f[i - 1] < 150000; ++i){
		f[i] = f[i - 1] + f[i - 2];
	}
}

int main(){
	ifstream in("C:\\input.txt");

	initF();

	int N;
	cin >> N;

	while (N--){
		int a;
		cin >> a;
		if (a == 1){
			add(dp[0]);
			dp[1] = (dp[1] + dp[0]) % mod;
			add(1);
			dp[0] = (dp[0] + 1) % mod;
		}
		else{
			int p = lower_bound(f + 1, f + 26, a) - f;
			if (f[p] != a)
				continue;
			add(dp[p - 1]);
			dp[p] = (dp[p] + dp[p - 1]) % mod;

		}
	}
	cout << sum << endl;
	return 0;
}





