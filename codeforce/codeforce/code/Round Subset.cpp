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
long long a[210];
pair<int, int> data[210];
int n, k;
int dp[6010][210];
#define INF (-1<<26)
int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;

	
	in >> n >> k;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	int sum = 0;
	for (int i = 1; i <= n; ++i){
		data[i].first = data[i].second = 0;
		while (a[i]&&a[i] % 2 == 0){
			a[i] /= 2;
			data[i].first++;
		}
		while (a[i]&&a[i] % 5 == 0){
			a[i] /= 5;
			data[i].second++;
		}
		sum += data[i].second;
	}
	
	for (int i = 0; i < 6010;++i)
	for (int j = 0; j < 210; ++j)
		dp[i][j] = INF;
	dp[0][0] = 0;
	for (int p = 1; p <= n; ++p){
		int x = data[p].first;
		int y = data[p].second;
		for (int j = k; j >= 1; --j){
		for (int i = sum; i >= y;--i)
			if (dp[i-y][j-1] != INF && dp[i][j] < dp[i - y][j - 1] + x){
				dp[i][j] = dp[i - y][j - 1] + x;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= sum; ++i){
		if (dp[i][k] != INF)
			ans = max(ans, min(i, dp[i][k]));
	}

	cout << ans << endl;











	return 0;
}





