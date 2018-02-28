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
double dp[210][210];
bool vis[210][210];

int arr[210], aim;
double poss[210];
int K;
double a, b, c;


int getAim(){
	set<int> S;
	for (int i = 1; i <= N; ++i)
		S.insert(arr[i]);
	if (S.size() < K)
		return -1;
	for (int k : S){
		K--;
		if (K == 0)
			return k;
	}
	assert(0);
}

void Init(){
	memset(vis, 0, sizeof(vis));

}

void input(){
	for (int i = 1; i <= N; ++i)
		in >> arr[i];
	in >> K >> a >> b;
	


}

double dfs(int l,int r){
	if (vis[l][r])
		return dp[l][r];
	vis[l][r] = 1;

	if (l > r)
		return dp[l][r] = 0;

	double& ref = dp[l][r];
	ref = 0;
	double chance = 1.0 / (r - l + 1);
	for (int k = l; k <= r; ++k){
		ref += chance * (dfs(l, k - 1)*b + poss[k] * a + dfs(k + 1, r)*c);
	}
	return ref;


}

int main(){

	while (in >> N){
		if (N < 0)
			break;
		input();
		c = 1 - a - b;
		Init();
		aim = getAim();
		if (aim == -1){
			printf("%.3f\n",0);
			continue;
		}

		for (int i = 1; i <= N; ++i)
			poss[i] = arr[i] == aim ? 1.0 : 0;
		printf("%.3f\n", dfs(1, N));
	}


	return 0;
}





