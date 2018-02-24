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
long long dp[12][4100];
vector<int> vi[4100];
bool ok[4100];
int h, w;
bool judge(int state){
	int num = 0;
	for (int i = 0; i < w; ++i){
		int p = 1 << i;
		if (state&p){
			num++;
		}
		else{
			if (num % 2 == 1)
				return 0;
		}
	}
	return num % 2 == 0;
}

bool judgechanstate(int state1, int state2){
	for (int i = 0; i < w; ++i){
		int p = 1 << i;
		if (!(state1&p)){
			if (!(state2&p))
				return 0;
			state2 -= p;
		}
	}
	return judge(state2);
}

void Init(){
	memset(ok, 0, sizeof(ok));
	w = 11;
	for (int i = 0; i < 1 << 11 + 10; ++i)
		ok[i] = judge(i);
	for (int i = 0; i < 4100; ++i)
	for (int j = 0; j < 4100; ++j)
	if (judgechanstate(i, j))
		vi[i].push_back(j);
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	while (cin >> h >> w&&h){
		if (h*w % 2 == 1)
			cout << 0 << endl;
		else{
			if (h < w)
				swap(h, w);
			memset(dp, 0, sizeof(dp));
			int max_state = 1 << w;
			for (int i = 0; i < max_state; ++i)
			if (ok[i])
				dp[1][i] = 1;
			for (int k = 1; k < h; ++k){
				for (int i = 0; i < max_state; ++i){
					if (dp[k][i] > 0){
						for (int j = 0; j < vi[i].size() && vi[i][j]<max_state; ++j){
							dp[k + 1][vi[i][j]] += dp[k][i];

						}
					}
				}
			}
			cout << dp[h][max_state - 1] << endl;
		}

	}

	return 0;
}
