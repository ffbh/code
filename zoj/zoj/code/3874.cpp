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
int data[10], N;
vector<int> vi[10];
bool vis[10];

void Init(){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 10; ++i)
		vi[i].clear();
}

void dfs(int p){
	if (vis[p])
		return;
	vis[p] = 1;
	for (int i = 0; i < vi[p].size(); ++i)
		dfs(vi[p][i]);

}
bool judge(){
	Init();
	for (int i = 0; i < N;++i)
	for (int j = i + 1; j < N; ++j){
		if (data[i] > data[j]){
			vi[data[i]].push_back(data[j]);
			vi[data[j]].push_back(data[i]);
		}
	}

	dfs(data[0]);

	for (int i = 0; i < N;++i)
	if (!vis[i])
		return 0;
	return 1;
}

void show(){
	for (int i = 0; i < N; ++i)
		cout << data[i] << " ";
	cout << endl;
}

int dp[100];

int cale(int n){
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		ans *= i;
	return ans;
}
int main(){
	ifstream in("C:\\input.txt");
	N = 4;
	for (int i = 0; i < N; ++i)
		data[i] = i;
	int num = 0;
	if (!judge()){
		show();
		num++;
	}
	while (next_permutation(data, data + N)){
		if (!judge()){
			show();
			num++;
		}
	}
	cout << num << endl;
	


	/*dp[1] = dp[2] = 1;
	for (int i = 3; i <= 7; ++i){
		dp[i] = cale(i - 1) + dp[i - 1] * (i - 2);
		cout << dp[i] << endl;
	}*/











	return 0;
}