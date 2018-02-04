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
using namespace std;
vector<int> V;
vector<int> vi[40];
int mat[40][40], ans[40][40], In[40];
int test[40];
int N, M;
bool vis[40];
vector<int> tmp;
void Init(){
	N = 0;
	tmp.clear();
	V.clear();
	for (int i = 0; i < 40; ++i){
		test[i] = -1;
		In[i] = 0;
		vis[i] = 0;
		vi[i].clear();
		
	}
	for (int i = 0; i < 40; ++i)
	for (int j = 0; j < 40; ++j){
		mat[i][j] = 0;
		ans[i][j] = 0;
	}
}



void dfs_f(int start,int now){
	ans[start][now] = -1;
	test[now] = start;
	for (int i = 0; i < vi[now].size(); ++i){
		int to = vi[now][i];
		if ( test[to] != start)
			dfs_f(start, to);
	}

}

void dfs(int start, int now){
	if (start != now)
		ans[start][now]++;
	for (int i = 0; i < vi[now].size(); ++i){
		int to = vi[now][i];
		if (vis[to]){
			dfs_f(start, to);
			continue;
		}
		dfs(start, to);
	}

}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int CASE = 0;
	while (in >> M){
		Init();
		for (int i = 0; i < M; ++i){
			int a, b;
			in >> a >> b;
			vi[a].push_back(b);
			In[b]++;
			mat[a][b] = 1;
			N = max(N, a);
			N = max(N, b);
		}

		for (int k = 0; k <= N; ++k)
		for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= N; ++j)
		if (mat[i][k] && mat[k][j])
			mat[i][j] = 1;


		for (int i = 0; i <= N; ++i){
			for (int j = i + 1; j <= N; ++j){
				if (mat[i][j] && mat[j][i]){
					V.push_back(i);
					V.push_back(j);
				}
			}
		}


		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		for (int j = 0; j < V.size(); ++j){
			int u = V[j];
			vis[u] = 1;
			for (int k = 0; k <= N; ++k){
				if (mat[u][k])
					ans[u][k] = -1;
			}
			for (int k = 0; k < vi[u].size(); ++k){
				In[vi[u][k]]--;
			}
		}


		queue<int>	qi;
		for (int i = 0; i <= N; ++i){
			if (vis[i])
				continue;
			if (In[i] == 0){
				qi.push(i);
			}
		}

		while (!qi.empty()){
			int u = qi.front();
			qi.pop();
			dfs(u, u);
			for (int i = 0; i < vi[u].size(); ++i){
				int to = vi[u][i];
				if (!vis[to] && --In[to] == 0){
					qi.push(to);
				}
			}
		}

		printf("matrix for city %d\n", CASE++);
		for (int i = 0; i <= N; ++i){
			for (int j = 0; j < N; ++j)
				printf("%d ", ans[i][j]);
			printf("%d\n", ans[i][N]);

		}


	}

	return 0;
}