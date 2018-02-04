#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[13000];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		memset(dp, 0, sizeof(dp));
		while (N--){
			int a, b;
			//in >> a >> b;
			scanf("%d%d", &a, &b);
			for (int i = M; i >= a;--i)
			if (dp[i] < dp[i - a] + b)
				dp[i] = dp[i - a] + b;
		}
		cout << dp[M] << endl;
	}
	return 0;
}