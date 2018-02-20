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

int n, m;
vector<pll> V[200010];
vector<pll> city;
LL cost[200010];

void input(){
	in >> n >> m;
	for (int i = 1; i <= m; ++i){
		LL u, v, w;
//		in >> u >> v >> w;
		scanf("%lld%lld%lld", &u, &v, &w);
		V[u].push_back(mp(v, w));
		V[v].push_back(mp(u, w));
	}
	for (int i = 1; i <= n; ++i){
	
	//	in >> cost[i];
		scanf("%lld", &cost[i]);

	}


}

LL dp[200010];

bool cmp(pll& a,pll& b){
	return a.first > b.first;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		for (int i = 1; i <= n; ++i)
			dp[i] = cost[i];

		priority_queue<pll> Q;
		for (int i = 1; i <= n; ++i){
			Q.push(mp(-cost[i], i));
		}

		while (!Q.empty()){
			pll u = Q.top();
			Q.pop();
			u.first = -u.first;
			if (u.first == dp[u.second]){

				for (pll son : V[u.second]){
					if (dp[son.first] > dp[u.second] + 2 * son.second){
						dp[son.first] = dp[u.second] + 2 * son.second;
						Q.push(mp(-dp[son.first], son.first));
					}
				}
			}
		}

		for (int i = 1; i <= n; ++i)
			printf("%lld ", dp[i]);
		cout << endl;














	}


	return 0;
}





