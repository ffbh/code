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


int N;
LL K;
int label[40], h[40];


void input(){
	in >> N >> K;
	for (int i = 1; i <= N; ++i)
		in >> label[i];
}


LL dp[40];



vector<int> ans;

void dfs(int L,int R,LL K){
	if (L > R)
		return;

	vector<pii> all;
	for (int i = L; i <= R; ++i){
		all.push_back(mp(label[i], i));
	}
	sort(all.begin(), all.end());
	
	for (pii p : all){
		int lf = p.second - L;
		int rt = R - p.second;
		LL c = dp[lf] * dp[rt] - 1;
		if (c >= K){
			LL lc = K / dp[rt];
			LL rc = K%dp[rt];
			ans.push_back(p.first);
			dfs(L, p.second - 1, lc);
			dfs(p.second + 1, R, rc);
			break;
		}
		else{
			K -= c + 1;
		}
	}
}

int main(){

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i<40; ++i){
		for (int j = 0; j < i; ++j)
			dp[i] += dp[j] * dp[i - 1 - j];
	}



	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= N; ++i)
			h[label[i]] = i;

		K--;

		dfs(1, N, K);
		for (int p : ans)
			cout << p << endl;









	}


	return 0;
}





