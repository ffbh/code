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

int n, m, s;
vector<int> V[100010],g[100010];
int dp[100010][2];// 0 fail  1 win
int deg[100010];

void input(){
	in >> n >> m;
	for (int i = 1; i <= n; ++i){
		int c;
		in >> c;
//		scanf("%d", &c);
		while (c-- > 0){
			int t;
			in >> t;
	//		scanf("%d", &t);
			V[t].push_back(i);
			g[i].push_back(t);

			deg[i]++;
		}
	}
	in >> s;

}


int winpace[100010];
int failpace[100010];
bool vis[100010][2];

void print_pace(int p,int k){
	printf("%d ", p);
	if (k){
		
		print_pace(winpace[p], 1 - k);
	}
	else{
		if (failpace[p] != -1)
			print_pace(failpace[p], 1 - k);
	}
}

bool stack[100010];
bool vvv[100010];
bool cycle(int p){
	if (stack[p])
		return 1;
	if (vvv[p])
		return 0;
	vvv[p] = 1;
	stack[p] = 1;
	for (int v : g[p]){
		if (cycle(v))
			return 1;
	}
	stack[p] = 0;
	return 0;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		memset(dp, 0, sizeof(dp));
		queue<pii> Q;
		for (int i = 1; i <= n; ++i){
			if (deg[i] == 0){
				dp[i][0] = 1;
				failpace[i] = -1;
				winpace[i] = -1;
				Q.push(mp(i,0));
			}
		}

		while (!Q.empty()){
			pii u = Q.front();
			Q.pop();
			for (int v : V[u.first]){
				if (u.second == 0){
					dp[v][1] = 1;
					
					if (!vis[v][1]){
						winpace[v] = u.first;
						vis[v][1] = 1;
						Q.push(mp(v, 1));
					}
				}

				if (u.second == 1){
					dp[v][0] = 1;
					
					if (!vis[v][0]){
						failpace[v] = u.first;
						vis[v][0] = 1;
						Q.push(mp(v, 0));
					}
				}
				
			}
		}

		if (dp[s][1]){
			cout << "Win" << endl;
			print_pace(s, 1);
			cout << endl;
		}
		else if (cycle(s)){
			cout << "Draw" << endl;
		}
		else{
			cout << "Lose" << endl;
		}








	}


	return 0;
}





