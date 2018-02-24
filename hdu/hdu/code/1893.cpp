#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[1000001];
int dfs(int x){
	if (x < 0)
		return 0;
	else if (x < 1000)
		return 1;
	else if (dp[x])
		return dp[x];
	else
		return dp[x] = (dfs(x - 1000) + dfs(x - 3140)) % 1000000007;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		double x;
		scanf("%lf", &x);
		//in >> x;
		cout << dfs(int(x * 1000)) << endl;
	}

	return 0;
}