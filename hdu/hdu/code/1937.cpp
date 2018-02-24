#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int sum[310][310];
int N, M, K;


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M >> K&&N + M + K){
		for (int i = 1; i <= N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M; ++j){
				int tmp = (s[j] == '.') ? 1 : 0;
				sum[i][j + 1] = sum[i - 1][j + 1] + tmp;
			}
		}
		int mmax = 9999999;
		for (int i = 1; i <= N;++i)
		for (int j = i; j <= N; ++j){
			int L, R;
			L = 1;
			R = 1;
			int tmp = 9999999;
			int tsum = 0;
			while (L <= M){
				while (R <= M&&tsum < K||R<L){
					tsum += sum[j][R] - sum[i - 1][R];
					R++;
				}
				if (tsum >= K && (R - L)*(j - i + 1) < mmax)
					mmax = (R - L)*(j - i + 1);
				tsum -= sum[j][L] - sum[i - 1][L];
				L++;
			}
		}
		cout << mmax << endl;
	}
	return 0;
}