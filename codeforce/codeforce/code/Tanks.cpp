#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

LL N, K, V;
LL a[5010];

bool dp[5010][5010];
int pace[5010][5010];
int water[5010];
int mark[5010];
void input(){
	in >> N >> K >> V;
	for (int i = 1; i <= N; ++i)
		in >> a[i];


}


void print(int cnt,int x,int y){
	if (cnt > 0)
		printf("%d %d %d\n", cnt, x, y);
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL sum = 0;
		for (int i = 1; i <= N; ++i)
			sum += a[i];


		if (sum < V){
			cout << "NO" << endl;
		}
		else{

			if (V%K == 0){
				cout << "YES" << endl;
				for (int i = 2; i <= N; ++i){
					print(1e9, i, 1);
					a[1] += a[i];
				}
				print(V / K, 1, 2);
				return 0;
			}

			for (int i = 1; i <= N; ++i)
				water[i] = a[i] % K;
			dp[0][0] = 1;
			for (int i = 0; i < N; ++i){
				for (int j = 0; j < K; ++j){
					if (dp[i][j] == 0)
						continue;
					dp[i + 1][(j + water[i + 1]) % K] = 1;
					pace[i + 1][(j + water[i + 1]) % K] = i;
				}
				for (int j = 0; j < K; ++j){
					if (dp[i + 1][j] == 0 && dp[i][j] == 1){
						dp[i + 1][j] = 1;
						pace[i + 1][j] = -1;
					}
				}
			}
			if (dp[N][V%K] == 0){
				cout << "NO" << endl;
			}
			else{
				cout << "YES" << endl;
				int A = N, B = V%K;
				vector<int> all;
				while (A){
					if (pace[A][B] == -1){
						A--;
					}
					else{
						all.push_back(A);
						B = (B - water[A] + K) % K;
						A--;
					}
				}

				for (int p : all){
					mark[p] = 1;
				}



				int aim = all[0];
				for (int k = 1; k < all.size(); ++k){
					//	printf("%d %d %d\n", (int)1e9, all[k], aim);
					print(1e9, all[k], aim);
					a[aim] += a[all[k]];
				}

				int other = -1;
				for (int i = 1; i <= N; ++i)
				if (mark[i] == 0)
					other = i;
				for (int i = 1; i <= N; ++i){
					if (!mark[i] && i != other){
						//		printf("%d %d %d\n", (int)1e9, other, i);
						print(1e9, i, other);
						a[other] += a[i];
					}

				}


				if (other != -1){
					if (a[other] / K > 0){
						//		printf("%d %d %d\n", a[other] / K, other, aim);
						print(a[other] / K, other, aim);
						a[aim] += a[other] / K*K;
					}
				}
				int rest;
				if (aim == 1){
					rest = N;
				}
				else{
					rest = aim - 1;
				}

				while (a[aim] > V){
					LL time = min((a[aim] - V) / K, (LL)1e9);

					//	printf("%lld %d %d\n", time, aim, rest);
					print(time, aim, rest);
					a[aim] -= time*K;

				}
			}


		}














	}


	return 0;
}





