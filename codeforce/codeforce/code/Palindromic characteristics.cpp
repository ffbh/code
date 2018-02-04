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
string s;
int n;
int ans[5010];
int dp[5010][5010];

bool judge(int a,int b){
	if (s[a] != s[b])
		return 0;
	if (a + 1 <= b - 1)
		return dp[a + 1][b - 1] >= 1;
	else
		return 1;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> s;
	n = s.length();
	s = '$' + s;
	for (int i = 1; i <= n; ++i){
		dp[i][i] = 1;
		ans[1]++;
	}

	for (int len = 2; len <= n; ++len){

		for (int i = 1; i + len - 1 <= n; ++i){
			int j = i + len - 1;
			if (!judge(i, j))
				dp[i][j] = 0;
			else{
				if (i == 2 && j == 3){
					int t = 0;
				}
				int ll = i + len / 2 - 1;
				int rr = j - len / 2 + 1;
				int l = dp[i][ll];
				int r = dp[rr][j];
				if (l == r)
					dp[i][j] = l + 1;
				else
					dp[i][j] = 1;

				ans[dp[i][j]]++;
			}
		}
	}
	for (int i = n - 1; i >= 1; --i)
		ans[i] += ans[i + 1];
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << endl;















	return 0;
}





