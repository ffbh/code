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


int n, m;
string str;

vector<int> vi[300010];
int deg[300010];

void input(){
	in >> n >> m;
	in >> str;
	for (int i = 1; i <= m; ++i){
		int a, b;
		in >> a >> b;
		a--;
		b--;
		deg[b]++;
		vi[a].push_back(b);
	}


}


bool vis[300010];
int ans[300010][30];
int ANS;
void DFS(int p){
	if (vis[p])
		return;
	vis[p] = 1;
	for (int son : vi[p]){
		DFS(son);
		for (char c = 0; c < 30; ++c){
			ans[p][c] = max(ans[p][c], ans[son][c]);
		}
	}

	ans[p][str[p] - 'a']++;
	for (int k = 0; k < 30; ++k)
		ANS = max(ANS, ans[p][k]);


}


bool mark[300010];


bool dfs(int p){
	
	if (mark[p])
		return 1;
	if (vis[p])
		return 0;
	vis[p] = 1;
	mark[p] = 1;
	for (int son : vi[p]){
		if (dfs(son))
			return 1;
	}
	mark[p] = 0;
	return 0;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 0; i < n; ++i){
			if (deg[i] != 0)
				continue;
			if (dfs(i)){
				cout << -1 << endl;
				return 0;
			}
		}

		for (int i = 0; i < n; ++i){
			if (!vis[i] && deg[i] != 0){
				cout << -1 << endl;
				return 0;
			}
		}


		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; ++i){
			if (deg[i] != 0)
				continue;
			DFS(i);
		}
		cout << ANS << endl;









	}


	return 0;
}





