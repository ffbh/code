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

LL n, W, B, X;
int a[1010], c[1010];
LL dp[2][100010];

void input(){
	in >> n >> W >> B >> X;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	for (int i = 1; i <= n; ++i)
		in >> c[i];
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		memset(dp, -1, sizeof(dp));
		dp[0][0] = W;
		int ans = 0;
		for (int i = 0; i <= n;++i)
		for (int j = 0; j < 100010; ++j){
			int f = i % 2;
			int nf = 1 - f;
			if (dp[f][j] < 0)
				continue;
			ans = max(ans, j);
			LL num_bird = a[i + 1];
			LL save_cost = c[i + 1];
			LL max_save = num_bird;
			if (save_cost > 0)
				max_save = min(dp[f][j] / save_cost, num_bird);
			for (int k = 0; k <= max_save; ++k){
				dp[nf][j + k] = max(dp[nf][j + k], min(dp[f][j] - k*save_cost + X, W + B*(j + k)));
			}
		}
	
	
		cout << ans << endl;














	}


	return 0;
}





