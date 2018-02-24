#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
int n, m, x;
char s[100010], t[100010];
int dp[35][100010][2];

bool cale(){
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	for (int k = 0; k <= x; ++k){
		for (int i = 0; i <= n; ++i){
			if (dp[k][i][0] == m || dp[k][i][1] == m)
				return 1;
			//	dp[k][i][0] = max(dp[k][i][0], dp[k][i][1]);
			int j;

			j = dp[k][i][0];
			if (j != -1){
				j++;
				if (i + 1 <= n){
					dp[k][i + 1][0] = max(dp[k][i + 1][0], dp[k][i][0]);


					if (s[i + 1] == t[j]){
						dp[k + 1][i + 1][1] = max(dp[k + 1][i + 1][1], j);
					}
				}
			}

			j = dp[k][i][1];
			if (j != -1){
				j++;
				if (i + 1 <= n){
					dp[k][i + 1][0] = max(dp[k][i + 1][0], dp[k][i][1]);



					if (s[i + 1] == t[j]){
						dp[k][i + 1][1] = max(dp[k][i + 1][1], j);
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

	in >> n >> (s + 1) >> m >> (t + 1) >> x;


	if (cale()){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}













	return 0;
}