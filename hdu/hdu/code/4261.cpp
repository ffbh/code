#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <functional>
using namespace std;
int N, K;
int data[2010];
int dp[30][2010];
int cost[2010][2010];
void Init(){
	int sum;
	priority_queue<int> upper;
	priority_queue<int, vector<int>, greater<int> >lower;
	for (int i = 0; i < N; ++i){
		sum = 0;
		while (!upper.empty()) upper.pop();
		while (!lower.empty()) lower.pop();
		for (int j = i; j < N; ++j){
			if (lower.empty() || data[j] >lower.top()){
				lower.push(data[j]);
				sum += data[j];
			}
			else{
				upper.push(data[j]);
				sum -= data[j];
			}
			if (lower.size() != upper.size()&&lower.size()!=upper.size()+1){
				if (lower.size() < upper.size()){
					int top = upper.top();
					upper.pop();
					sum += 2 * top;
					lower.push(top);
				}
				else{
					int top = lower.top();
					lower.pop();
					sum -= 2 * top;
					upper.push(top);
				}
			}
			if (lower.size() != upper.size())
				cost[i][j] = sum - lower.top();
			else
				cost[i][j] = sum;
		}
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> K&&N+K){
		for (int i = 0; i < N; ++i)
			//in >> data[i];
			scanf("%d", &data[i]);
		Init();
		for (int i = 0; i < N; ++i)
			dp[1][i] = cost[0][i];
		for (int i = 2; i <= K;++i)
		for (int j = i - 1; j < N; ++j){
			dp[i][j] = INT_MAX;
			for (int k = 0; k + 1 <= j;++k)
			if (dp[i][j]>dp[i - 1][k] + cost[k + 1][j])
				dp[i][j] = dp[i - 1][k] + cost[k + 1][j];
		}
		cout << dp[K][N - 1] << endl;
	}
	return 0;
}