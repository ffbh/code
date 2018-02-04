
#include<iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
struct Node{
	int to, m;
	Node(int a, int b){
		to = a;
		m = b;
	}
};

int size;
vector<int> vi[10010];
vector<int> confi[10010];
vector<int> ans;
vector<Node> mark[10010];
int pace[10010], dist[10010], nex[10010], tran[10010];
bool vis[10010];
int N, M, K;
int a, b;
void dfs(int p){
	if (p == a){
		ans.push_back(p);

	}
	else{
		dfs(pace[p]);
		ans.push_back(p);

	}
}

void Init(){
	for (int i = 0; i < 10010; ++i){
		vi[i].clear();
		mark[i].clear();
	}

	size = 1;
}

int getLineNum(int a, int b){
	for (int i = 0; i < mark[a].size(); ++i)
	if (mark[a][i].to == b){
		return mark[a][i].m;
	}
}

void spfa(int st, int en){
	for (int i = 0; i<10010; ++i){
		dist[i] = (1 << 26);
		vis[i] = 0;
		confi[i].clear();
	}
	//memset(vis,0,sizeof(vis));
	queue<int> qi;
	qi.push(st);
	dist[st] = 0;
	vis[st] = 1;
	tran[st] = 0;
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		vis[u] = 0;
		for (int i = 0; i<vi[u].size(); ++i){
			int v = vi[u][i];
			int line = getLineNum(u, v);
			int time = tran[u];
			if (confi[u].size() == 0){

			}
			else{
				bool f = 0;
				for (int i = 0; i<confi[u].size(); ++i){
					if (confi[u][i] == line){
						f = 1;
						break;
					}
				}
				if (!f)
					time++;
			}
			if (dist[v] > dist[u] + 1 || dist[v] == dist[u] + 1 && time <= tran[v]){
				if (time == tran[v]){
					confi[v].push_back(line);
				}
				else{
					confi[v].clear();
					confi[v].push_back(line);
				}
				dist[v] = dist[u] + 1;
				tran[v] = time;
				pace[v] = u;
				if (!vis[v]){
					vis[v] = 1;
					qi.push(v);
				}
			}
		}
	}
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N){
		Init();
		for (int k = 1; k <= N; ++k){
			cin >> M;
			int pre, now;
			cin >> pre;
			for (int i = 1; i<M; ++i){
				cin >> now;
				vi[pre].push_back(now);
				vi[now].push_back(pre);
				mark[pre].push_back(Node(now, k));
				mark[now].push_back(Node(pre, k));
				pre = now;
			}
		}
		cin >> K;
		while (K-->0){
			cin >> a >> b;
			spfa(a, b);
			cout << dist[b] << endl;
			ans.clear();
			dfs(b);
			int pos = 0;

			int pre = ans[pos], start = ans[pos];

			int linenum = getLineNum(ans[0], ans[1]);
			pos++;
			while (pos < ans.size()){
				int now = ans[pos];
				pos++;
				int nowlinenum = getLineNum(pre, now);
				if (nowlinenum != linenum){
					printf("Take Line#%d from %04d to %04d.\n", linenum, start, pre);
					start = pre;
					linenum = nowlinenum;
				}
				pre = now;
			}
			printf("Take Line#%d from %04d to %04d.\n", linenum, start, b);
		}

	}
	return 0;
}
