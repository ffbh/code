#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
int N, M , F;
struct Data{
	int u, v, w;
}data[100010];
vector<int> vn[1010];
vector<int> V;
bool mark[1010];////////////////
bool vis[1010];
int map[1010][1010];
int pace[1010];

bool spfa(){
	queue<int> qi;
	pace[1] = 0;
	for (int i = 1; i <= N + 1; ++i){
		vis[i] = 0;
	}
	qi.push(1);
	vis[1] = 1;
	while (!qi.empty()){
		int temp = qi.front();
		if (temp == N + 1)
			return 1;
		qi.pop();
		for (int i = 0; i < vn[temp].size(); ++i){
			int son = vn[temp][i];
			if (map[temp][son]>0 && !vis[son]){
				pace[son] = temp;
				vis[son] = 1;
					qi.push(son);
			}
		}
	}
	return 0;
}



int MaxFlow(){
	int flow = 0;
	while(spfa()){
		int now, pre, mmin;
		mmin = INT_MAX;
		now = N + 1;
		while (pace[now]){
			pre = pace[now];
			if (map[pre][now] < mmin)
				mmin = map[pre][now];
			now = pre;
		}
		flow += mmin;
		now = N + 1;
		while (pace[now]){
			pre = pace[now];
			map[pre][now] -= mmin;
			map[now][pre] += mmin;
			now = pre;
		}
	}
	return flow;
}

void setcolor(){
	queue<int> qi;
	qi.push(1);
	mark[1] = 1;
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		for (int i = 0; i < vn[temp].size(); ++i){
			int son = vn[temp][i];
			if (!mark[son]&&map[temp][son]>0){
				mark[son] = 1;
				qi.push(son);
			}
		}
	}
}





int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (cin >> N >> M >> F){
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 1010; ++i)
			vn[i].clear();
		V.clear();
		for (int i = 0; i < M; ++i){
			//in >> data[i].u >> data[i].v >> data[i].w;
			scanf("%d%d%d", &data[i].u, &data[i].v, &data[i].w);
			vn[data[i].u].push_back(data[i].v);
			vn[data[i].v].push_back(data[i].u);
			map[data[i].u][data[i].v] += data[i].w;
		}
		int sum = 0;
		while (F--){
			int u, w;
			//in >> u >> w;
			scanf("%d%d", &u, &w);
			sum += w;
			vn[u].push_back(N+1);
			vn[N+1].push_back(u);
			map[u][N + 1] += w;
		}
		printf("Case %d: %d\n", CASE++, sum - MaxFlow());
		memset(mark,0, sizeof(mark));
		setcolor();
		for (int i = 0; i < M; ++i){
			if (mark[data[i].u] == 1 && mark[data[i].v] == 0)
				V.push_back(i + 1);
		}
		printf("%d", V.size());
		for (int i = 0; i < V.size(); ++i)
			printf(" %d", V[i]);
		printf("\n");
	}
	return 0;
}