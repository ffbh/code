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
#define INF (1<<28)
int N;
int a[510];
vector<int> V[1010];

pii g[1010][1010];

void Init(){
	for (int i = 0; i < 1010; ++i)
		V[i].clear();
}


int dist[1010], pace[1010];

void spfa(){
	queue<int> Q;
	Q.push(0);
	for (int i = 0; i < 1010; ++i)
		dist[i] = INF;
	dist[0] = 0;
	while (!Q.empty()){
		int u = Q.front();

		Q.pop();
		for (int v : V[u]){
			if (g[u][v].first > 0){
				if (dist[v] > dist[u] + g[u][v].second){
					dist[v] = dist[u] + g[u][v].second;
					pace[v] = u;
					Q.push(v);
				}
			}
		}
	}

}

int main(){
	while (in >> N){
		Init();
		for (int i = 1; i <= N; ++i)
			//    in >> a[i];
			scanf("%d", &a[i]);

		int O = 0;
		int E = N * 2 + 1;
		for (int i = 1; i <= N; ++i){
			if (a[i] > 0){
				V[O].push_back(i);
				V[i].push_back(O);
				g[O][i] = mp(a[i]-1, 0);
				g[i][O] = mp(0, 0);
			}
			else{
				V[i+N].push_back(E);
				V[E].push_back(i+N);
			//        g[E][i] = mp(0, 0);
				g[i+N][E] = mp(1, 0);

			}
		}


		for (int i = 1; i <= N; ++i){
			if (a[i] - 1 > 0){
				for (int j = 1; j <= N; ++j){
					if (a[j] != 0)
						continue;
					int d = abs(i - j);
					if (i > j){
						d = min(j + N - i, d);
					}
					else{
						d = min(i + N - j, d);
					}
					V[i].push_back(j + N);
					V[j + N].push_back(i);
					g[i][j + N] = mp(1, d);
					g[j + N][i] = mp(0, -d);
				}
			}
		}

		int ans = 0;
		while (1){
			spfa();
			if (dist[E] == INF)
				break;
			int en = E;
			int flow = INF;
			while (en != O){
				int p = pace[en];
				flow = min(flow, g[p][en].first);
				en = p;
			}
			en = E;
			while (en != O){
				int p = pace[en];
				g[p][en].first -= flow;
				g[en][p].first += flow;
				en = p;
			}
			ans += dist[E];
		}
		printf("%d\n", ans);

	}



	return 0;
}
