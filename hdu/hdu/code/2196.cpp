#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Node{
	int to, v;
};
vector<Node> vi[10001];
int dist[10001];
void dfs(int u, int f,int len){
	for (int i = 0; i < vi[u].size();++i)
	if (vi[u][i].to != f){
		int son = vi[u][i].to;
		int v = vi[u][i].v;
		if (dist[son] < len + v)
			dist[son] = len + v;
		dfs(son, u,len+v);
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		for (int i = 0; i < 10001; ++i){
			vi[i].clear();
			dist[i] = 0;
		}
		for (int i = 2; i <= N; ++i){
			int a, b;
			cin >> a >> b;
			vi[i].push_back(Node{ a, b });
			vi[a].push_back(Node{ i, b });
		}
		dfs(1, -1,0);
		int mmax = 0;
		int ff;
		for (int i = 1; i <= N; ++i)
		if (dist[i] > mmax){
			mmax = dist[i];
			ff = i;
		}
		dfs(ff, -1,0);
		for (int i = 1; i <= N; ++i)
		if (dist[i] > mmax){
			mmax = dist[i];
			ff = i;
		}
		dfs(ff, -1,0);
		for (int i = 1; i <= N; ++i)
			printf("%d\n", dist[i]);
	}




	return 0;
}