#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
bool vis[2001];
bool mark[2001];
vector<int> vi[2001];
int N, M;

bool bfs(int s){
	queue<int> qi;
	vis[s] = 1;
	mark[s] = 0;
	qi.push(s);
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		for (int i = 0; i < vi[temp].size(); ++i){
			int son = vi[temp][i];
			if (!vis[son]){
				vis[son] = 1;
				mark[son] = mark[temp] ^ 1;
				qi.push(son);
			}
			else{
				if (mark[son] == mark[temp])
					return 0;
			}
		}
	}
	return 1;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		for (int i = 0; i < 2001; ++i)
			vi[i].clear();
		cin >> N >> M;
		while (M--){
			int a, b;
			//in >> a >> b;
			scanf("%d%d", &a, &b);
			vi[a].push_back(b);
			vi[b].push_back(a);
		}
		memset(vis, 0, sizeof(vis));
		memset(mark, 0, sizeof(mark));
		bool flag = 1;
		for (int i = 1; i <= N; ++i)
		if (!vis[i]){
			flag = bfs(i);
			if (!flag)
				break;
		}
		printf("Scenario #%d:\n", CASE++);
		if (!flag)
			cout << "Suspicious bugs found!" << endl;
		else
			cout << "No suspicious bugs found!" << endl;
		cout << endl;
	}

	return 0;
}