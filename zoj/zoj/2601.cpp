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


int n, m;
int store[210];
vector<int> vi[210];
pii mmp[410][410];

int INF = (1 << 25);
vector<int> edge[410];

int STORE, TYPE;

int S, T;
int ans[210];
void Init(){
	for (int i = 0; i < 210; ++i)
		vi[i].clear();
	for (int i = 0; i < 410; ++i)
		edge[i].clear();
	memset(mmp, -1, sizeof(mmp));
	memset(ans, 0, sizeof(ans));

}

void input(){
	in >> m >> n;
	for (int i = 1; i <= m; ++i){
		int k;
		in >> k;
		while (k-->0){
			int type;
			in >> type;
			vi[i].push_back(type);
		}
	}
	for (int i = 1; i <= m; ++i)
		in >> store[i];

}

int dist[410], pace[410];

bool spfa(){
	for (int i = 0; i < 410; ++i)
		dist[i] = INF;
	dist[0] = 0;
	queue<int> Q;
	Q.push(S);
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		for (int v : edge[u]){
			if (mmp[u][v].first > 0){
				if (dist[v] > dist[u] + mmp[u][v].second){
					dist[v] = dist[u] + mmp[u][v].second;
					pace[v] = u;
					Q.push(v);
				}
			}
		}
	}
	return dist[T] != INF;
}



int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	bool ok = 0;
	while (TEST_CASE-- > 0){
		if (ok == 0){
			ok = 1;
		}
		else{
			printf("\n");
		}

		Init();
		input();

		
		STORE = 0;
		TYPE = m;
		
		S = 0;
		T = n + m + 2;
		for (int i = 1; i <= m; ++i){
			edge[S].push_back(i);
			edge[STORE+i].push_back(S);
			mmp[S][STORE+i] = mp(1, 0);
			mmp[STORE+i][S] = mp(0, 0);
		}

		for (int i = 1; i <= n; ++i){
			edge[TYPE+i].push_back(T);
			edge[T].push_back(TYPE+i);
			mmp[TYPE+i][T] = mp(1, 0);
			mmp[T][TYPE+i] = mp(0, 0);
		}

		for (int i = 1; i <= m; ++i){
			for (int k : vi[i]){
				int cost = 0;
				if (store[i] != k && store[i] != 0)
					cost = 1;

				edge[STORE + i].push_back(TYPE + k);
				edge[TYPE + k].push_back(STORE + i);
				mmp[STORE + i][TYPE + k] = mp(1, cost);
				mmp[TYPE + k][STORE + i] = mp(0, -cost);
			}
		}
		int a, b;
		a = b = 0;
		int U, V;
		while (spfa()){
			vector<int> P;
			int now = T;
			int flow = INF;
			while (now != S){
				if (now != T)
					P.push_back(now);
				int pre = pace[now];
				flow = min(flow, mmp[pre][now].first);
				now = pre;
			}

			now = T;
			while (now != S){
				int pre = pace[now];
				mmp[pre][now].first -= flow;
				mmp[now][pre].first += flow;
				now = pre;
			}

			a += flow;
			b += dist[T];
			reverse(P.begin(), P.end());

			for (int i = 0; i < P.size(); i += 2){
				int j = i + 1;
				if (j < P.size()){
					ans[P[i] - STORE] = P[j] - TYPE;
				}
			}
		}
		printf("%d %d\n", a, b);
		for (int i = 1; i <= m; ++i){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}


	return 0;
}





