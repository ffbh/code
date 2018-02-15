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
#define lson (root<<1)  
#define rson (root<<1|1)  

int n, a[2010];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}

int dp[5][2010];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int ans = 0;
		dp[0][0] = 0;
		for (int i = 0; i < 4;++i)
		for (int j = 0; j < n; ++j){
			
			int k = a[j + 1];
			if (k % 2 != i % 2){
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + 1);
			}
			else{
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
			}
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
		}
		for (int i = 0; i < 4;++i)
		for (int j = 1; j <= n; ++j){
			ans = max(ans, dp[i][j]);
		}
		
		cout << ans << endl;













	}


	return 0;
}





