#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#define INF (1<<28)
int dp[20][20];

int main(){
	ifstream in("C:\\temp.txt");
	
	int a, b;
	while (cin >> a >> b){
		for (int i = 15; i >= 0;--i)
		for (int j = 15; j >= 0;--j)
		if (j == 0 && i != 0)
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + a);
		else if (i == 0 && j != 0)
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + b);
		else if (i != 0 && j != 0)
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j] + a, dp[i][j - 1] + b));
	}
	cout << dp[15][15] << endl;




	return 0;
}