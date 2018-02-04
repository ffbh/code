#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int N;
struct Node{
	string name;
	int a, b, c;
}data[210];
vector<int> vi[210];

bool beat(int k1, int k2){
	int numk1 = 0, numk2 = 0;
	if (data[k1].a > data[k2].a)
		numk1++;
	else
		numk2++;

	if (data[k1].b > data[k2].b)
		numk1++;
	else
		numk2++;

	if (data[k1].c > data[k2].c)
		numk1++;
	else
		numk2++;

	return numk1 > numk2;

}
bool vis[210], mark[210];

void Init(){
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < 210; ++i)
		vi[i].clear();
}

void build(){
	for (int i = 1; i <= N; ++i){
		for (int j = i + 1; j <= N; ++j){
			if (beat(i, j))
				vi[i].push_back(j);
			else{
				vi[j].push_back(i);
			}
		}
	}
}



bool bfs(int start){
	queue<int> qi;
	memset(vis, 0, sizeof(vis));
	vis[start] = 1;
	qi.push(start);
	int num = 1;
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		if (mark[u])
			return 1;
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i];
			if (!vis[v]){
				num++;
				vis[v] = 1;
				qi.push(v);
			}
		}
	}
	return num == N;
}
int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N){
		Init();
		for (int i = 1; i <= N; ++i)
			cin >> data[i].name >> data[i].a >> data[i].b >> data[i].c;
		build();
		for (int i = 1; i <= N; ++i){
			if (bfs(i)){
				mark[i] = 1;
				cout << data[i].name << endl;
			}
		}
	}






	return 0;
}