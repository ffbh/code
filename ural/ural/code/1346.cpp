#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[100010][2];
int data[100010];


int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	cin >> N >> M;
	N = M - N +1;
	for (int i = 1; i <= N; ++i)
		cin >> data[i];
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= N; ++i){
		if (data[i] > data[i - 1]){
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
		}
		else if (data[i] < data[i - 1]){
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]+ 1) ;
		}
		else {
			dp[i][1] = dp[i - 1][1];
			dp[i][0] = dp[i - 1][0];
		}
	}
	cout << min(dp[N][0], dp[N][1]) << endl;
	return 0;
}