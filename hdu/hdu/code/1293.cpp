#include <iostream>
#include <string>
#include <fstream>
using namespace std;

_int64 dp[1010][2];


_int64 dfs(_int64 n, bool ok){
	if (n == 0) return 1;
	if (dp[n][ok])
		return dp[n][ok];
	if (ok)
		return dp[n][ok] = 2 * dfs(n - 1, 0) + dfs(n - 1, 1);
	else 
		return dp[n][ok] = dfs(n - 1, 0) + dfs(n - 1, 1);
}



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		memset(dp, 0, sizeof(dp));
		cout << dfs(N, 1) << endl;

	}
	return 0;
}