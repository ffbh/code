#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool prime[1010];

void Init(){
	for (int i = 2; i < 1000;++i)
	if (!prime[i]){
		for (int j = i; j*i < 1000; ++j)
			prime[i*j] = 1;
	}
}

int dp[10010][100];
int main(){
	ifstream in("C:\\temp.txt");
	Init();
	for (int i = 10; i < 100; ++i)
		dp[2][i] = 1;
	for (int i = 3; i <= 10000;++i)
	for (int j = 10; j < 100;++j)
	for (int k = 0; k < 10; ++k){
		if (prime[j * 10 + k] && dp[i - 1][j])
			continue;
		int key = j % 10 * 10 + k;
		dp[i][key] = dp[i][key] + dp[i - 1][j];
		if (dp[i][key] > 1000000009)
			dp[i][key] -= 1000000009;
	}
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < 100; ++i)
		sum = (sum + dp[N][i]) % 1000000009;
	cout << sum << endl;
	return 0;
}