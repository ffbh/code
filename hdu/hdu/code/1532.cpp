#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
struct node{
	int minflow;
	int id;
};
vector<int> vi[250];
int map[250][250];
int pace[250];
bool vis[250];

int bfs(){
	queue<node> qi;
	node temp1, temp2;
	memset(vis, 0, sizeof(vis));
	temp1.id = 1;
	temp1.minflow = INT_MAX;
	vis[temp1.id] = 1;
	qi.push(temp1);
	while (!qi.empty()){
		temp1 = qi.front();
		qi.pop();
		int size = vi[temp1.id].size();
		for (int i = 0; i < size; ++i){
			temp2.id = vi[temp1.id][i];
			temp2.minflow = temp1.minflow;
			if (!vis[temp2.id]&&map[temp1.id][temp2.id]){
				vis[temp2.id] = 1;
				pace[temp2.id] = temp1.id;
				if (temp2.minflow>map[temp1.id][temp2.id])
					temp2.minflow = map[temp1.id][temp2.id];
				if (temp2.id == N) return temp2.minflow;
				qi.push(temp2);
			}
		}
	}
	return 0;
}


void fun(int n,int mf){
	if (pace[n])
		fun(pace[n], mf);
	map[pace[n]][n] -= mf;
	map[n][pace[n]] += mf;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int a, b, c;
	while (cin >> M >> N){
		for (int i = 0; i < 210; ++i)
			vi[i].clear();
		memset(map, 0, sizeof(map));

		for (int i = 0; i < M; ++i){
			//in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			vi[a].push_back(b);
			vi[b].push_back(a);
			map[a][b] += c;
		}
		int ans = 0;
		int mflow;
		pace[1] = 0;
		while (mflow = bfs()){
			ans += mflow;
			fun(N, mflow);
		}
		cout << ans <<  endl;
	
		
	
	}

	return 0;
}