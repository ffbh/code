#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> state;
int map[110];
int data[110];
short dp[110][300][300];
void Init(){
	for (int i = 0; i <= (1 << 11); ++i){
		int c = i >> 2;
		int d = i << 2;
		if (!(i&c) && !(i&d))
			state.push_back(i);
	}
}	
int N,M;
int ans;
int getC(int n){
	int num = 0;
	while (n){
		if (n & 1)
			num++;
		n >>= 1;
	}
	return num;
}

int main(){
	ifstream in("C:\\temp.txt");
	Init();
	while (in >> N >> M){
		for (int i = 1; i <= N; ++i){
			map[i] = 0;
			for (int j = 0; j < M; ++j){
				int t;
				in >> t;
				t = t ? 0 : 1;
				map[i] = map[i] * 2 + t;
			}
		}
		memset(dp, 0, sizeof(dp));
		for (int k = 0; state[k] < (1 << M); ++k)
		if (!(map[1] & state[k])){
			int temp = getC(state[k]);
			for (int i = 0; state[i] < (1 << M); ++i)
				dp[1][k][i] = temp;
		}
		if (N >= 2)
		for (int k = 0; state[k] < (1 << M); ++k){
			if (!(map[2] & state[k]))
			for (int i = 0; state[i] < (1 << M); ++i)
			if (!(state[k] & (state[i] << 1)) && !(state[k] & (state[i] >> 1)))
				dp[2][k][i] = dp[1][i][0] + getC(state[k]);
		}
		for (int i = 3; i <= N; ++i){
			for (int k = 0; state[k] < (1 << M); ++k)
			if (!(state[k] & map[i])){
				int temp = getC(state[k]);
				for (int j = 0; state[j] < (1 << M); ++j)
				if (!(state[k] & (state[j] << 1)) && !(state[k] & (state[j] >> 1)))
				for (int e = 0; state[e] < (1 << M); ++e)
				if (!(state[k] & state[e]) && dp[i][k][j] < dp[i - 1][j][e] + temp)
					dp[i][k][j] = dp[i - 1][j][e] + temp;
			}
		}
		int mmax = 0;
		for (int i = 0; state[i] < (1 << M); ++i)
		for (int j = 0; state[j] < (1 << M); ++j)
		if (dp[N][i][j]>mmax)
			mmax = dp[N][i][j];
		cout << mmax << endl;
	}
	return 0;
}