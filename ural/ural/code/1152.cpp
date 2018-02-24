#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N;
vector<int> state;
void Init(){
	for (int i = 0; i <= (1 << (N+1)); ++i){
		if (i&(i << 1))
			continue;
		state.push_back(i);
	}
}
int dp[20000000];
int data[30];


int main(){
	ifstream in("C:\\temp.txt");
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> data[i];
	Init();
	dp[0] = 0;
	int ans = INT_MAX;
	for (int i = 1; state[i] < (1 << (N)); ++i){
		bool flag = 1;
		int cost = 0;
		dp[state[i]] = INT_MAX;
		if (!(state[i] & 1) && !(state[i] & (1 << (N - 1))) && !(state[i] & (1 << N - 2)))
			cost += data[N - 1];
		if (!(state[i] & 1) && !(state[i] & (1 << (N - 1))) && !(state[i] &2))
			cost += data[0];
		for (int j = 1; j < N-1; ++j){
			int key = (1 << j);
			if (state[i]&key || state[i]&(key << 1) || state[i]&(key >> 1))
				continue;
			cost += data[j];
			flag = 0;
		}
		for (int j = 0; j < N;++j)
		if (state[i]&(1 << j)){
			int tmp = (state[i] ^ (1 << j));
			if (dp[state[i]]>dp[tmp] + cost)
				dp[state[i]]=dp[tmp] + cost;
		}
		if (flag&&ans > dp[state[i]])
			ans = dp[state[i]];
	}
	cout << ans << endl;
	return 0;
}