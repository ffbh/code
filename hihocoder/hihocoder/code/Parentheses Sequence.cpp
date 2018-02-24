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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  

LL mod = (LL)1e9 + 7;

string str;

pll dp[1010][1010];

void add(pll& a, pll b, int k){
	b.second += k;
	if (a.second > b.second)
		a = b;
	else if (a.second == b.second){
		a.first %= mod;
		b.first %= mod;
		a.first += b.first;
		a.first %= mod;
		if (a.first < 0)
			a.first += mod;
	}

}

int main(){
	for (int i = 0; i < 1010; ++i)
	for (int j = 0; j < 1010; ++j)
		dp[i][j] = mp(99999999, 9999999);

	in >> str;
	int n = str.length();
	str = '-' + str;
	dp[0][0] = mp(1, 0);
	for (int i = 1; i <= n; ++i){
		if (str[i] == '('){
			for (int j = n; j >= 0; --j){

				if (j > 0)
					add(dp[i][j], dp[i - 1][j - 1], 1);
				if (j == n){
					add(dp[i][j], dp[i - 1][j], 2);
				}
				else
					add(dp[i][j], dp[i][j + 1], 1);
			}
		}
		else{
			for (int j = 0; j <= n; ++j){

				add(dp[i][j], dp[i - 1][j + 1], 1);

				if (j > 0)
					add(dp[i][j], dp[i][j - 1], 1);
				else
					add(dp[i][j], dp[i - 1][j], 2);

			}

		}


	}
	cout << dp[n][0].second-n <<" "<<dp[n][0].first<< endl;;


	return 0;
}





