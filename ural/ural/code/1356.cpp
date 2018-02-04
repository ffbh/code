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
vector<int> prime;
bool vis[MMAX];

void Init(){
	for (int i = 2; i < MMAX;++i)
	if (!vis[i]){
		prime.push_back(i);
		for (int j = i + i; j < MMAX; j += i)
			vis[j] = 1;
	}

}

bool judge(int p){
	for (int i = 2; i <= sqrt(p);++i)
	if (p%i == 0)
		return 0;
	return 1;
}

int test(int p){

	for (int i = 0; i<prime.size()&&prime[i] < p - 1;++i)
		if (judge(p - prime[i]))
			return prime[i];

		return -1;
	}


int main(){
	ifstream in("C:\\input.txt");
	Init();
	/*for (int i = 1e8;; ++i){
		if (judge(i)){
			cout << i << endl;
			break;
		}
	}*/

	int T, N;
	cin >> T;
	while (T-- > 0){

		cin >> N;

		if (judge(N)){
			cout << N << endl;
		}
		else{
			int ans = -1;
			for (int i = 0; i<prime.size()&& prime[i] < N - 1 ; ++i){
				if (judge(N - prime[i])){
					ans = prime[i];
					break;
				}
			}
			if (ans != -1)
				cout << ans << " " << N - ans << endl;
			else{
				int M;
				int tmp = N;

				while (1){
					tmp--;
					while (!judge(tmp))
						tmp--;
					M = N - tmp;
					int ret = test(M);
					if (ret != -1){
						ans = ret;
						break;
					}
				}
				cout << tmp << " " << ans << " " << N - tmp - ans << endl;
			}
		}
	}
	return 0;
}