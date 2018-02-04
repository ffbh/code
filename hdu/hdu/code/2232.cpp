#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[101][4];
int data[4][4];
int num[4];

int main(){
	ifstream in("C:\\temp.txt");
	dp[0][0] = 1;
	for (int i = 1; i <= 100;++i)
	for (int j = 0; j < 4; ++j){
		int a, b, c;
		a = j;
		b = (j + 1) % 4;
		c = (j + 3) % 4;
		dp[i][j] = (dp[i - 1][a] + dp[i - 1][b] + dp[i - 1][c]) % 9937;
	}
	int N;
	while (cin >> N){
		if (N == 0){
			cout << 1 << endl;
			continue;
		}
		for (int i = 0; i < 4; ++i)
		for (int k = 0; k < 4; ++k)
			data[i][k] = dp[N][(k + i) % 4];
		for (int i = 0; i < 4; ++i)
			num[i] = i;
		int ans = 1;
		for (int i = 0; i < 4; ++i)
			 ans = (ans*data[i][num[i]]) % 9937;
		while (next_permutation(num, num + 4)){
			int temp = 1;
			for (int i = 0; i < 4; ++i)
				temp = (temp*data[i][num[i]]) % 9937;
			ans = (ans + temp) % 9937;
		}
		cout << ans << endl;
	}
	return 0;
}