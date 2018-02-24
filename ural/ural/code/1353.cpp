#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[10][90];

int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i < 10; ++i)
		dp[1][i] = 1;
	for (int i = 2; i < 10;++i)
	for (int k = 0; k < 10;++k)
	for (int j = k; j < 90; ++j)
		dp[i][j] += dp[i-1][j-k];
	int sum = 0;
	int S;
	cin >> S;
	for (int i = 1; i < 10; ++i)
		sum += dp[i][S];
	if (S == 1)
		sum++;
	cout << sum << endl;





	return 0;
}