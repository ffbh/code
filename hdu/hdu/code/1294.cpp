#include <iostream>
#include <fstream>
 using namespace std;

long long  ans[50];
long long  dp[50][50];

long long  dfs(int x, int mins){
	if (x == 0)
		return 1;
	if (dp[x][mins] != -1)
		return dp[x][mins];
	long long  sum = 0;
	for (int i = mins; i <= x; ++i){
		sum += dfs(x - i, i) * ans[i];
	}
	return dp[x][mins] = sum;
}

void Init(){
	ans[0] = ans[1] = ans[2] = 1;
	memset(dp, -1, sizeof(dp));


	for (int i = 1; i <= 40; ++i){

		ans[i] = dfs(i - 1, 1);
	}
}




int main(){
	Init();
	ifstream in("C:\\input.txt");
	int N;
	while (cin >> N){
		cout << ans[N] << endl;

	}







}
