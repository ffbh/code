#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MMAX (2010)
#define INF (1<<28)
int N;
struct Node{
	int to, v;
};
vector<Node> vi[MMAX];
int IN[MMAX], time[MMAX], dist[MMAX];
bool vis[MMAX];

bool spfa(){
	queue<int> qi;
	memset(IN, 0, sizeof(IN));
	memset(vis, 0, sizeof(vis));
	fill(dist, dist + N + 10, -INF);
	dist[0] = 0;
	vis[0] = 1;
	qi.push(0);
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		vis[temp] = 0;
		for (int i = 0; i < vi[temp].size(); ++i){
			int son = vi[temp][i].to;
			int v = vi[temp][i].v;
			if (dist[son] < dist[temp] + v){
				dist[son] = dist[temp] + v;
				if (!vis[son]){
					vis[son] = 1;
					IN[son]++;
					if (IN[son]>N + 10)
						return 0;
					qi.push(son);
				}
			}
		}
	}
	return 1;
}




int main(){
	ifstream in("C:\\temp.txt");
	int CASE = 1;
	while (cin>>N&&N){
		vi[0].clear();
		for (int i = 1; i <= N; ++i){
			cin >> time[i];
			vi[i].clear();
			vi[0].push_back(Node{ i, 0 });
		}
		string s;
		while (cin >> s&&s != "#"){
			int a, b;
			cin >> a >> b;
			if (s == "FAF")
				vi[b].push_back(Node{ a, time[b] - time[a] });
			else if (s == "FAS")
				vi[b].push_back(Node{ a, -time[a] });
			else if (s == "SAF")
				vi[b].push_back(Node{ a, time[b] });
			else
				vi[b].push_back(Node{ a, 0 });
		}
		printf("Case %d:\n", CASE++);
		if (spfa()){
			for (int i = 1; i <= N; ++i)
				printf("%d %d\n", i, dist[i]);
		}
		else
			printf("impossible\n");
		cout << endl;
	}





	return 0;
}