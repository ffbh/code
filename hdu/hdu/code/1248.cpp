#include <iostream>
//#include <string>
//#include <fstream>
using namespace std;
bool dp[10010];
int value[5] = { 150, 200, 350 };
int main(){
	//ifstream in("C:\\temp.txt");
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int k = 0; k < 3;++k)
	for (int i = value[k]; i <= 10000;++i)
	if (dp[i - value[k]])
		dp[i] = 1;

	int N,M;
	cin >> N;
	while (N--){
		cin >> M;
		int ans = 0;
		for (int i = M; i >= 0;--i)
		if (dp[i])break;
		else ans++;
		cout << ans << endl;
	}

	return 0;
}