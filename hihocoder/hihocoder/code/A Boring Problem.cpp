#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
using namespace std;
const long long mod = 1000000007;
int N, K;
string s;
long long sum[100010];
long long C[210][210];//C i j
long long P[100010][210];//P i j = p[i]^j
long long sumP[210];

void Init(){
	memset(C, 0, sizeof(C));
	for (int i = 1; i <= 110; ++i){
		C[i][0] = 1;
		C[i][1] = i;
		C[i][i] = 1;
	}
	for (int j = 2; j < 110;++j)
	for (int i = 3; i < 110; ++i)
		C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%mod;
}



void getdata(){
	ofstream on("C:\\input.txt");
	for (int i = 0; i < 50000; ++i)
		on << rand() % 10;
	on << endl;

}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int T;
	cin >> T;
	while (T--){
		cin >> N >> K >> s;
		memset(sumP, 0, sizeof(sumP));
		memset(P, 0, sizeof(P));
		sum[0] = 0;
		for (int i = 0; i < N; ++i){
			sum[i + 1] = sum[i] + s[i] - '0';
		}
		for (int i = 1; i <= N; ++i){
			P[i][0] = 1;
			for (int j = 1; j <= K; ++j){
				P[i][j] = (P[i][j - 1] * sum[i]) % mod;
			}
		}

		sumP[0] = 1;
		for (int i = 1; i <= N; ++i){
			long long ans = 0;
			for (int j = 0; j <= K; ++j){
				ans = (ans + P[i][K - j] * sumP[j])%mod;
				if (j % 2 == 1){
					sumP[j] = ((sumP[j] - C[K][j] * P[i][j])%mod + mod) % mod;
				}
				else{
					sumP[j] = (sumP[j] + C[K][j] * P[i][j]) % mod;
				}
			}
			printf("%lld ", ans);
		}
		printf("\n");
	}

	return 0;
}