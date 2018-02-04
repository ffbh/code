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
using namespace std;
#define DEBUG (0)
#define INF ((long long)1e18)
bool bb[100], vis[120];
struct Node{
	int to, d, idx;
	Node(int a, int b,int c){
		to = a;
		d = b;
		idx = c;
	}
};
vector<Node> vi[120];
long long dist[120];
stringstream ss;

long long  dd[110][110];
int pace[110];
long long f[110][110];
int spfa(int a, int b,int time){
	for (int i = 0; i < 120; ++i)
		dist[i] = INF;
	memset(vis, 0, sizeof(vis));
	queue<int> qi;
	dist[b] = 0;
	qi.push(b);
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		for (int i = 0; i < vi[u].size(); ++i){
			int d = vi[u][i].d;
			int v = vi[u][i].to;
			int idx = vi[u][i].idx;
			if (f[a][idx] <= time){
				continue;
			}

			if (dist[v] > dist[u] + d || (dist[v] == dist[u] + d && pace[v] > u)){
				dist[v] = dist[u] + d;
				pace[v] = u;
				if (!vis[v]){
					vis[v] = 1;
					qi.push(v);
				}
			}

		}
	}
	return pace[a];
	
}

int cale(int a, int b){
	int time = 0;
	while (a != b){
		int x = spfa(a, b, time);
		time += dd[a][x];
		a = x;
	}
	return time;
}

class AdaptiveRouting {
	public:
	int deliveryTime(vector <string> layout, vector <int> failed, int A, int B) {
		for (int i = 0; i < 110;++i)
		for (int j = 0; j < 110; ++j){
			if (i == j){
				dd[i][j] = 0;
			}
			else{
				dd[i][j] = INF;
			}
		}

		for (int i = 0; i < 120; ++i)
			vi[i].clear();
		memset(bb, 0, sizeof(bb));
		for (int i = 0; i < failed.size(); ++i){
			bb[failed[i]] = 1;
		}
		for (int i = 0; i < layout.size(); ++i){
			ss.clear();
			ss.str(layout[i]);
			long long a, b, c;
			ss >> a >> b >> c;
			if (!bb[i]){
				dd[a][b] = min(dd[a][b], c);
				dd[b][a] = min(dd[b][a], c);
			}
			vi[a].push_back(Node(b, c,i));
			vi[b].push_back(Node(a, c,i));
		}


		for (int i = 1; i <= 99; ++i)
		for (int j = 1; j <= 99;++j)
		for (int k = 1; k <= 99; ++k){
			if (i != j&&i != k&&j != k){
		//		long long a = dd[j][k];
		//		long long b = dd[j][i];
		//		long long c = dd[i][k];
				if (dd[j][k] > dd[j][i] + dd[i][k])
					dd[j][k] = dd[j][i] + dd[i][k];
			}
		}
		for (int i = 0; i < 110;++i)
		for (int j = 0; j < 110; ++j)
			f[i][j] = INF;

		for (int i = 0; i < failed.size(); ++i){
			int p = failed[i];
			ss.clear();
			ss.str(layout[failed[i]]);
			int a, b, c;
			ss >> a >> b >> c;
			for (int k = 1; k <= 99; ++k){
				f[k][p] = min(dd[a][k], dd[b][k]);
			}
		}


		if (dd[A][B] == INF){
			return -1;
		}
		else 
			return  cale(A, B);


	}
};



#if 0
int main(){
	
	vector<string> p({ "1 2 1", "1 2 22" });
	vector<int> ff({ 0 });


	AdaptiveRouting so;
	cout<<so.deliveryTime(p,ff,1,2)<<endl;
















	return 0;
}
#endif

