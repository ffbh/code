#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int K, N;
int data[5010];
int dp[1100][5010];
#define cal(a) ((data[a]-data[a-1])*(data[a]-data[a-1]))


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> K >> N;
		K += 8;
		for (int i = N; i >= 1; --i)
			cin >> data[i];
		for (int i = 1; i <= K; ++i){
			dp[i][3 * i] = dp[i - 1][3 * (i - 1)+1] + cal(3 * i);
			for (int j = 3 * i + 1; j <= N; ++j)
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 2] + cal(j));
		}
		cout << dp[K][N] << endl;
	}
	return 0;
}