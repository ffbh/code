#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[10010];
int data[10010];
int L[3], C[3];

int getC(int d){
	for (int i = 0; i < 3;++i)
	if (d <= L[i])
		return C[i];
	return -1;
}


int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 0; i < 3; ++i)
		cin >> L[i];
	for (int i = 0; i < 3; ++i)
		cin >> C[i];
	int N;
	cin >> N;
	int S, T;
	cin >> S >> T;
	if (S>T)
		swap(S, T);
	data[1] = 0;
	for (int i = 2; i <= N; ++i){
		cin >> data[i];
		dp[i] = INT_MAX;
	}
	dp[S] = 0;
	for (int i = S; i <= T;++i)
	for (int j = i + 1; j <= T; ++j){
		int cost = getC(data[j] - data[i]);
		if (cost == -1)
			break;
		if (dp[j] > dp[i] + cost)
			dp[j] = dp[i] + cost;
	}
	cout << dp[T] << endl;
	return 0;
}