#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
int K ,V ,N;
int dp[60][5010];
priority_queue<int> q;
int main(){
	ifstream in("C:\\temp.txt");
	in >> K >> V >> N;
	int weight, value;
	memset(dp, -111111, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i){
		in >> weight >> value;
		while (!q.empty()) q.pop();
		for (int j = V; j >= weight; --j){
				for (int k = 0; k < K; ++k){
					q.push(dp[k][j]);
					q.push(dp[k][j - weight] + value);
					dp[k][j] = q.top();
					q.pop();
				}
		}
	}
	int ans = 0;
	for (int k = 0; k < K; ++k){
		ans += dp[k][V];
		//cout << dp[k][j] << " ";
		//cout << endl;
	}
	cout << ans << endl;
	//cout << endl;


	return 0;
}
