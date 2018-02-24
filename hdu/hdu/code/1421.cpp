#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[2010];
int dp[1010][2010];

int main(){
	ifstream in("C:\\temp.txt");
	int N, K;
	while (cin >> N >> K){
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		sort(data + 1, data + 1 + N);
		for (int i = 1; i <= K; ++i){
			dp[i][2 * i] = dp[i - 1][2 * (i - 1)] +
				(data[2 * i] - data[2 * i - 1])*(data[2 * i] - data[2 * i - 1]);
			for (int j = 2 * i + 1; j <= N; ++j)
				dp[i][j] = min(dp[i][j - 1],
				dp[i - 1][j - 2] + (data[j] - data[j - 1])*(data[j] - data[j - 1]));
		}
		cout << dp[K][N] << endl;


	}



	return 0;
}