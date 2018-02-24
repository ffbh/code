#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool dp[60][25010];
int data[110];
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		int sum = 0;
		memset(dp, 0, sizeof(dp));	
		for (int i = 0; i < N; ++i){
			cin >> data[i];
			sum += data[i];
		}
		int D = (N % 2 == 0) ? N / 2 : N / 2 + 1;
		dp[0][0] = 1;
		for (int j = 0; j < N; ++j)
		for (int k = sum/2; k >= data[j]; --k)
		for (int i = D; i >=1; --i)
		if (dp[i - 1][k - data[j]])
			dp[i][k] = 1;
		if (N % 2 == 0){
			for (int i = sum / 2; i >= 0; --i)
			if (dp[D][i]){
				printf("%d %d\n", i, sum - i);
				break;
			}
		}
		else{
			for (int i = sum / 2; i >= 0; --i)
			if (dp[D][i]||dp[D-1][i]){
				printf("%d %d\n", i, sum - i);
				break;
			}

		}
	}
	return 0;
}