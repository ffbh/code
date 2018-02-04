#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[110];
int temp[110];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		while (N--){
			int a, b;
			cin >> a >> b;
			memset(temp, 0, sizeof(temp));
			for (int i = a; i <= b;++i)
			for (int j = 0; j <= M;++j)
			if (j + i <= M)
				temp[j + i] += dp[j];
			memcpy(dp, temp, sizeof(dp));
		}
		cout << dp[M] << endl;
	}
	return 0;
}