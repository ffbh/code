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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

void _init(){



}

int n, m;
vector<int> edge[500010];
int num[500010];
int ans[500010];
vector<int> group[500010];
void input(){
	in >> n >> m;
	for (int i = 1; i <= m; ++i){
		in >> num[i];
		for (int j = 1; j <= num[i]; ++j){
			int k;
			in >> k;
			group[i].push_back(k);
		}
	}
}

bool vis[500010];

void bfs(int g){
	vector<int> p;
	queue<int> Q;
	Q.push(g);
	vis[g] = 1;
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		p.push_back(u);
		for (int v : edge[u]){
			if (!vis[v]){
				vis[v] = 1;
				Q.push(v);
			}
		}
	}
	for (int pp : p){
		ans[pp] = p.size();
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		for (int i = 1; i <= m; ++i){
			for (int j = 1; j < group[i].size(); ++j){
				edge[group[i][0]].push_back(group[i][j]);
				edge[group[i][j]].push_back(group[i][0]);
			}
		}


		for (int i = 1; i <= n; ++i){
			if (vis[i])
				continue;
			bfs(i);
		}


		for (int i = 1; i <= n; ++i){
			cout << ans[i] << " ";
		}
		cout << endl;










	}


	return 0;
}





