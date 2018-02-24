#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
ifstream in("C:\\temp.txt");
#define INF (1<<28)
int N, M, K, size;
int TAR;
vector<int> vi[550];
int mark[550][550];
map<string, int> msi;
int pace[550];
bool vis[550];
int getInput(){
	string s;
	in >> s;
	if (!msi[s])
		msi[s] = size++;
	return msi[s];
}

bool bfs(){
	queue<int> qi;
	qi.push(0);
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	pace[0] = 0;
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		if (temp == TAR)
			return 1;
		for (int i = 0; i < vi[temp].size(); ++i){
			int son = vi[temp][i];
			if (!vis[son]&&mark[temp][son]>0){
				vis[son] = 1;
				pace[son] = temp;
				qi.push(son);
			}
		}
	}
	return 0;
}

int MaxFlow(){
	int flow = 0;
	int now, pre;
	int mmin = INT_MAX;
	while (bfs()){
		now = TAR;
		while (pace[now]){
			pre = pace[now];
			if (mark[pre][now] < mmin)
				mmin = mark[pre][now];
			now = pre;
		}
		now = TAR;
		while (pace[now]){
			pre = pace[now];
			mark[pre][now] -= mmin;
			mark[now][pre] += mmin;
			now = pre;
		}
		flow += mmin;
	}
	return flow;
}




int main(){
	int T;
	in >> T;
	TAR = 499;
	while (T--){
		size = 1;
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i < 550; ++i)
			vi[i].clear();
		msi.clear();
		in >> N;
		for (int i = 1; i <= N; ++i){
			int ans = getInput();
			vi[ans].push_back(TAR);
			vi[TAR].push_back(ans);
			mark[ans][TAR]++;
		}
		in >> M;
		for(int i=0;i<M;++i){
			string s;
			in >> s;
			int ans = getInput();
			vi[0].push_back(ans);
			vi[ans].push_back(0);
			mark[0][ans]++;
		}
		in >> K;
		while (K--){
			int a = getInput();
			int b = getInput();
			vi[a].push_back(b);
			vi[b].push_back(a);
			mark[a][b] = INF;
		}
		cout << M - MaxFlow() << endl;
	}
	return 0;
}