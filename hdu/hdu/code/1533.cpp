#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
struct Point{
	int x, y;
};
struct Node{
	int to, v;
};
int N;
int map[204][204];
vector<Node> vi[214];
int pace[204];
Point H[101];
int cnth;
Point P[101];
int cntp;
int dist[204];

bool spfa(){
	bool vis[204] = { 0 };
	for (int i = 0; i < 204; ++i)
		dist[i] = INT_MAX;
	queue<int> qi;
	qi.push(0);
	vis[0] = 1;
	dist[0] = 0;
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		vis[temp] = 0;
		for (int i = 0; i < vi[temp].size(); ++i){
			int son = vi[temp][i].to;
			int v = vi[temp][i].v;
			if (map[temp][son] && dist[son]>dist[temp] + v){
				dist[son] = dist[temp] + v;
				pace[son] = temp;
				if (!vis[son]){
					vis[son] = 1;
					qi.push(son);
				}
			}
		}
	}
	return dist[2 * N + 1] != INT_MAX;
}

void change(){
	int now = 2 * N + 1;
	now = 2 * N + 1;
	while (now){
		int pre = pace[now];
		map[pre][now] -= 1;
		map[now][pre] += 1;
		now = pre;
	}
}


int main(){
	//ifstream in("C:\\temp.txt");
	int  M;
	while (cin >> N >> M&&N + M){
		for (int i = 0; i <214; ++i)
			vi[i].clear();
		cnth = cntp = 1;
		string temp;
		for (int i = 0; i < N; ++i){
			cin >> temp;
			for (int j = 0; j < M; ++j)
			if (temp[j] == 'm'){
				P[cntp].x = i;
				P[cntp].y = j;
				cntp++;
			}
			else if (temp[j] == 'H'){
				H[cnth].x = i;
				H[cnth].y = j;
				cnth++;
			}
		}
		N = cntp - 1;
		Node t;
		for (int i = 1; i <= N; ++i){
			t.to = i;
			t.v = 0;
			vi[0].push_back(t);
			map[0][i] = 1;
			map[i][0] = 0;
		}
		t.to = 2 * N + 1;
		t.v = 0;
		for (int i = N + 1; i <= 2 * N; ++i){
			vi[i].push_back(t);
			map[i][2 * N + 1] = 1;
			map[2 * N + 1][i] = 0;
		}

		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j){
			map[i][N + j] = 1;
			map[N + j][i] = 0;
			t.to = N + j;
			t.v = abs(H[i].x - P[j].x) + abs(H[i].y - P[j].y);
			vi[i].push_back(t);
			t.to = i;
			t.v = -t.v;
			vi[N + j].push_back(t);
		}
		int res = 0;
		while (spfa()){
			change();
			res += dist[2 * N + 1];
		}
		cout << res << endl;
	}
	return 0;
}