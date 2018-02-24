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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

int n, m;
vector<pii> vi[1010];
void Init(){
	for (int i = 0; i < 1010; ++i)
		vi[i].clear();
}



void input(){



}
struct Node{
	int city, di;
	bool operator<(const Node& p)const{
		if (di != p.di)
			return di > p.di;
		else
			return city < p.city;
	}
	Node(int a, int b){
		city = a;
		di = b;
	}
};
int INF = 1 << 29;
int d[1010], precost[1010];
bool vis[1010];
int dijstra(int s){
	priority_queue<Node> Q;
	for (int i = 0; i < n; ++i){
		d[i] = INF;
	}
	memset(vis, 0, sizeof(vis));
	d[s] = 0;
	precost[s] = 0;
	Q.push(Node(s, d[s]));
	int cost = 0;
	while (!Q.empty()){
		Node u = Q.top();
		Q.pop();
		if (vis[u.city])
			continue;
		vis[u.city] = 1;
		cost += precost[u.city];

		for (pii& p : vi[u.city]){
			if (d[p.first] > d[u.city] + p.second){
				d[p.first] = d[u.city] + p.second;
				precost[p.first] = p.second;
				Q.push(Node(p.first, d[p.first]));
			}
		}
	}

	for (int i = 0; i < n;++i)
	if (!vis[i])
		return INF;
	return cost;

}

int main(){

	while (in >> n >> m){
		Init();
		while (m-- > 0){
			int a, b, c;
		//	in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			vi[a].pb(mp(b, c));
		}

		int anscity = -1, anscost = INF;
		for (int k = 0; k < n; ++k){
			int ret = dijstra(k);
			if (ret < anscost){
				anscost = ret;
				anscity = k;
			}

		}

		if (anscity != -1){
			printf("%d %d\n", anscost,anscity);
		}
		else
			printf("impossible\n");

		printf("\n");
	}


	return 0;
}





