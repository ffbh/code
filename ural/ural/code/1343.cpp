#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
#define MMAX (int(3e6)+10)
vector<int> prime;
bool vis[MMAX];

void Init(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j += i)
				vis[j] = 1;
		}

	}

}

bool judge(long long p){
	for (int i = 0; i < prime.size() && prime[i] * prime[i] <= p; ++i){
		if (p % prime[i] == 0)
			return 0;
	}
	return 1;
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int N;
	long long ans = 0;
	cin >> N ;
	if (N)
		cin >> ans;
	for (int i = N; i < 12; ++i){
		ans *= 10;
	}
	if (ans == 0)
		ans++;
	while (!judge(ans) )
		ans++;
	printf("%012lld\n", ans);

	return 0;
}