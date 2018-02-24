#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int v, num;
}data[110];
int ans[110];
int pace[110][100010];
int dp[100010];
bool vis[110];


int main(){
	ifstream in("C:\\temp.txt");
	int M;
	cin >> M;
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i){
		cin >> ans[i];
	}
	if (M == 0){
		for (int i = 1; i <= N; ++i)
			cout << i << " ";
		cout << endl;
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i <=N ; ++i){
		for (int j = M; j >= ans[i]; --j)
		if (dp[j - ans[i]]){
			dp[j] += dp[j - ans[i]];
			pace[i][j] = i;
		}
	}
    if (!dp[M])
		cout << 0 << endl;
	else if (dp[M]>1)
		cout << -1 << endl;
	else{
		int now = M;
		int K = N;
		while (now){
			vis[pace[K][now]] = 1;
			now -= ans[pace[K][now]];
			K--;
		}
		for (int i = 1; i <= N;++i)
		if (!vis[i])
			cout << i << " ";
		cout << endl;
	}
	return 0;
}