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
#define MMAX (int(1e5)+10)
bool vis[MMAX];
vector<int> prime;

void Init(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j += i)
				vis[i] = 1;
		}
	}
}



int main(){
	ifstream in("C:\\input.txt");
	Init();
	int T, a, b;
	cin >> T;
	while (T-- > 0){
		cin >> a >> b;
		if (b%a != 0)
			cout << 0 << endl;
		else if (a == b){
			cout << 1 << endl;
		}
		else{
			int k = b / a;
			int ans = 1;
			for (int i = 0; i < prime.size() && k != 1; ++i){
				while (k%prime[i] == 0){
					ans++;
					k /= prime[i];
				}
			}
			if (k != 1)
				ans++;
			cout << ans << endl;
		}
	}

	return 0;
}