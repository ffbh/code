#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vi;
vector<int> prime;
bool vis[100010];
void Init(){
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < 100000; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i; j < 100000; j += i)
				vis[j] = 1;
		}
	}
}


void getFactor(int n){
	vi.clear();
	for (int i = 0; n >= prime[i]; ++i){
		if (n%prime[i] == 0){
			vi.push_back(prime[i]);
			while (n%prime[i] == 0){
				n /= prime[i];
			}
		}
	}
}



int cale(int a, int b, int k){
	int ans = b;
	a /= k;
	b /= k;



	return ans;
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int T, a, b, k, CASE = 1;
	in >> T;
	while (T--){
		in >> a >> a >> b >> b >> k;
		if (a > b)
			swap(a, b);
		printf("Case %d: %d\n", CASE++, cale(a, b, k));

	}















	return 0;
}