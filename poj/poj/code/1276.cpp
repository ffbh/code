#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool dp[100010];

int main(){
	ifstream in("C:\\temp.txt");
	int M, N;
	while (cin >> M >> N){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		while (N--){
			int num, v;
			cin >> num >> v;
			int k = 1;
			while (k < num){
				for (int i = M; i >= k*v;--i)
				if (dp[i - k*v])
					dp[i] = 1;
				num -= k;
				k *= 2;
			}
			if (num){
				k = num;
				for (int i = M; i >= k*v; --i)
				if (dp[i - k*v])
					dp[i] = 1;
			}
		}
		for (int i = M; i >= 0;--i)
		if (dp[i]){
			cout << i << endl;
			break;
		}



	}








	return 0;
}