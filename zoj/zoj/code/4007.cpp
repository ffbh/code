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

int n;

vector<int> vi[100010];

int Y[100010];

void Init(){
	for (int i = 0; i <= n; ++i)
		vi[i].clear();


}

void input(){
	in >> n;
	Init();
	for (int i = 1; i <= n; ++i){
		in >> Y[i];
	}
	for (int i = 1; i < n; ++i){
		int a, b;
		in >> a >> b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}



}

LL dp[100010][2];

void dfs(int p, int f){
	
	dp[p][0] = dp[p][1] = 0;
	if (Y[p] == 0){
		dp[p][1] = (LL)1e16;
	}
	else if (Y[p] == 1){
		dp[p][0] = (LL)1e16;
	}
	for (int son : vi[p]){
		if (son == f)
			continue;
		dfs(son, p);
		for (int mark = 0; mark <= 1; ++mark){
			if (Y[p] != -1 && Y[p] != mark)
				continue;
			dp[p][mark] += min(dp[son][mark], dp[son][1 - mark] + 1);
		}
	}
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
	
		input();

		dfs(1, -1);
		printf("%lld\n", min(dp[1][0], dp[1][1]));













	}


	return 0;
}





