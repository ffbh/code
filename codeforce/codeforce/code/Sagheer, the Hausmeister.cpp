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
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

int n, m;
char mmp[110][110];

int dp[110][2];

void input(){
	in >> n >> m;
	for (int i = n; i >= 1; --i)
		in >> mmp[i];
}

pii cale(int k ){
	pii ans(1010, -1);
	for (int i = 0; i <= m + 1; ++i){
		if (mmp[k][i] == '1'){
			ans.first = min(ans.first, i);
			ans.second = i;
		}
	}
	return ans;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 0; i < 110; ++i)
			dp[i][0] = dp[i][1] = 999999;
		int up = -1;
		for (int k = n; k >= 1; --k){
			pii t = cale(k);
			if (t.second != -1){
				up = k;
				break;
			}
		}

		if (up == -1){
			cout << 0 << endl;
			return 0;
		}

		dp[1][0] = 0;
		dp[1][1] = m + 1;
		for (int i = 2; i <= up; ++i){
			dp[i][0] = dp[i - 1][1] + m + 2;
			dp[i][1] = dp[i - 1][0] + m + 2;

			pii ret = cale(i - 1);
			if (ret.second == -1){
				dp[i][0] = min(dp[i - 1][0]+1,dp[i][0]);
				dp[i][1] = min(dp[i - 1][1]+1,dp[i][1]);
			}
			else{
				dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2 * ret.second + 1);
				dp[i][1] = min(dp[i][1], dp[i - 1][1] + 2 * (m + 1 - ret.first) + 1);
			}
		}

		pii ret = cale(up);
		cout << min(dp[up][0] + ret.second, dp[up][1] + m + 1 - ret.first) << endl;
	










	}


	return 0;
}





