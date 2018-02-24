#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M;
vector<int> vi[10010];
stack<int> si;
bool vis[10010];
int DFN[10010];
int low[10010];
int num[10010];
vector<int> v[10010];
int belong[10010];
int data[10010];
int cnt, index;

void tarjin(int u,int F){
	DFN[u] = low[u] = index++;
	si.push(u);
	vis[u] = 1;
	bool flag = 0;
	for (int i = 0; i < vi[u].size(); ++i){
		int son = vi[u][i];
		if (son == F&&!flag){
			flag = 1;
			continue;
		}
		if (DFN[son] == -1)
			tarjin(son,u);
		low[u] = min(low[u], low[son]);
	}
	if (low[u] == DFN[u]){
		int sum = 0;
		int v;
		do{
			v = si.top();
			si.pop();
			belong[v] = cnt;
			vis[v] = 0;
			sum += num[v];
		} while (v != u);
		data[cnt++] = sum;
	}
}
int MMIN;
int SUM;
int dfs(int u){
	vis[u] = 1;
	int sum = data[u];
	for (int i = 0; i < v[u].size(); ++i){
		int son = v[u][i];
		if (!vis[son])
			sum += dfs(son);
	}
	MMIN = min(MMIN, abs(SUM - sum - sum));
	return sum;
}


int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		cnt = 0;
		index = 0;
		SUM = 0;
		while (!si.empty())
			si.pop();
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			cin >> num[i];
			SUM += num[i];
			vi[i].clear();
			v[i].clear();
			DFN[i] = low[i] = -1;
		}
		while (M--){
			int a, b;
			cin >> a >> b;
			vi[a].push_back(b);
			vi[b].push_back(a);
		}
		tarjin(0,-1);
		if (cnt == 1){
			cout << "impossible" << endl;
			continue;
		}
		for (int i = 0; i < N;++i)
		for (int j = 0; j < vi[i].size(); ++j){
			if (belong[i] != belong[vi[i][j]])
				v[belong[i]].push_back(belong[vi[i][j]]);
		}
		memset(vis, 0, sizeof(vis));
		MMIN = INT_MAX;
		dfs(0);
		cout << MMIN << endl;
	}
	return 0;
}