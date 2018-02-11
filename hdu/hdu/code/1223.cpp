
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



LL dp[70][70];
LL sum[70];
int main(){
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	dp[1][1] = 1;
	for (int i = 1; i<60;++i)
	for (int j = 1; j <= i; ++j){
		if (dp[i][j] >0){
			dp[i + 1][j] += dp[i][j] * j;
			dp[i + 1][j + 1] += dp[i][j] * (j + 1);
		}
	}
	for (int i = 1; i < 60;++i)
	for (int j = 1; j <= i; ++j)
		sum[i] += dp[i][j];

	int T;
	in >> T;
	while (T-- > 0){
		int t;
		in >> t;
		cout << sum[t] << endl;





	}




	return 0;
}





