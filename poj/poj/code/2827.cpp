#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Node{
	int a, b, v;
}data[10010];
struct S{
	int to, d;
	S(int _to,int _d){
		to = _to;
		d = _d;
	}
	S(){}
};

map<int, int> mii;
int x[20010];
bool ok;

int dist[20010][20010];
bool vis[20010][20010];
void Init(){
	
	memset(vis, -1, sizeof(vis));
}

void spfa(int s,int e,int mark){
	ok = 1;

	queue<S> qi;
	for (int i = 0; i < vi[s][0].size(); ++i){
		S u;
		u.to = vi[s][0][i].to;
		u.d = vi[s][0][i].d;
		vis[u.to] = mark;
		qi.push(u);
	}
	for (int i = 0; i < vi[s][1].size(); ++i){
		S u;
		u.to = vi[s][0][i].to-1;
		u.d = vi[s][0][i].d;
		vis[u.to] = mark;
		qi.push(u);
	}
	while (!qi.empty()){
		S u = qi.front();
		qi.pop();
		if (u.to == e)
			return u.d;
		for (int i = 0; i < vi[u.to + 1][0].size(); ++i){
			S v;
			v.to = vi[u.to + 1][0][i].to;
			v.d = u.d + vi[u.to + 1][0][i].d;
			if (vis[v.to] != mark){
				vis[v.to] = mark;
				qi.push(v);
			}
		}
		for (int i = 0; i < vi[u.to][1].size(); ++i){
			S v;
			v.to = vi[u.to][1][i].to-1;
			v.d = u.d + vi[u.to][1][i].d;
			if (vis[v.to] != mark){
				vis[v.to] = mark;
				qi.push(v);
			}
		}
	}
	ok = 0;
}



int main(){
	ifstream in("C:\\input.txt");

	Init();

	int M, size = 0;
	in >> M;
	for (int i = 1; i <= M; ++i){
		in >> data[i].a >> data[i].b >> data[i].v;
		if (data[i].a > data[i].b)
			swap(data[i].a, data[i].b);
		x[size++] = data[i].a;
		x[size++] = data[i].b;
	}
	sort(x, x + size);
	size = unique(x, x + size) - x;
	for (int i = 0; i < size; ++i)
		mii[x[i]] = i+1;
	for (int i = 1; i <= M; ++i){
		if (i == 5){
			int t = 0;
		}
		int a = mii[data[i].a];
		int b = mii[data[i].b];
		int v = data[i].v;
		if (!vis[a][b] ){
			printf("Accept\n");
			spfa(a, b, i);
		}
		else{
			if (dist[a][b] == v)
				printf("Accept\n");
			else
				printf("Bug Detected %d\n", dist[a][b]);

		}

	}

	return 0;
}