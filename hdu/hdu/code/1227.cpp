#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[210];
int N, K;
int dp[35][210];
int sum[210][210];
void Init(){
	for (int i = 0; i < N; ++i){
		sum[i][i] = 0;
		for (int j = i + 1; j < N; ++j)
			sum[i][j] = sum[i][j - 1] + data[j] - data[(i + j) / 2];
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	int CASE = 1;
	while (in >> N >> K&&N + K){
		for (int i = 0; i < N; ++i)
			in >> data[i];
		Init();
		for (int i = 0; i < N; ++i)
			dp[1][i] = sum[0][i];
		for (int i = 2; i <= K; ++i)
		for (int j = i-1; j < N; ++j){
			dp[i][j] = INT_MAX;
			for (int k = 0; k + 1 <= j;++k)
			if (dp[i][j] > dp[i - 1][k] + sum[k + 1][j])
				dp[i][j] = dp[i - 1][k] + sum[k + 1][j];
		}
		printf("Chain %d\n", CASE++);
		printf("Total distance sum = %d\n\n", dp[K][N - 1]);
		
	}



	return 0;
}