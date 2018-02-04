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


vector<int> vi[200010];
int n, m;

void input(){
	in >> n >> m;
	for (int i = 1; i <= m; ++i){
		int a, b;
		in >> a >> b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}
}

int f[200010];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
vector<int> all;
bool vis[200010];
int bfs(int p){
	queue<int> Q;
	vis[p] = 1;
	f[p] = find(p + 1);
	Q.push(p);
	int sz = 1;
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		int pos = 0;
		for (int v = find(1); v <= n; v = find(v + 1)){
			while (pos < vi[u].size() && vi[u][pos] < v){
				pos++;
			}
			if (pos < vi[u].size() && vi[u][pos] == v){
				continue;
			}
			vis[v] = 1;
			sz++;
			f[v] = find(v + 1);
			Q.push(v);
		}
	}
	return sz;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 0; i < n + 5; ++i)
			f[i] = i;

		for (int i = 1; i <= n; ++i)
			sort(vi[i].begin(), vi[i].end());

		for (int i = 1; i <= n; ++i){
			if (!vis[i]){
				all.push_back(bfs(i));
			}

		}

		sort(all.begin(), all.end());
		printf("%d\n", all.size());
		for (int ss : all){
			printf("%d ", ss);
		}
		cout << endl;












	}


	return 0;
}





