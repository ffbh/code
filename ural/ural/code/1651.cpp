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
struct Node{
	int to, time;
	Node(int a, int b){
		to = a;
		time = b;
	}
};


vector<Node> vi[10010];
int vis[10010];
int dist[10010];
int st, en, N, p1, p2;
vector<int> ans;
int anslen;
vector<int> tmp;
void Init(){
	for (int i = 0; i < 10010; ++i)
		vi[i].clear();
	for (int i = 0; i < 10010; ++i){
		vis[i] = (1 << 23);
		dist[i] = vis[i];
	}
	ans.clear();
	tmp.clear();
	anslen = 999999999; 
}



void dfs(int p,int time,int d){
	if (p == en){
		if (tmp.size() < anslen){
			anslen = tmp.size();
			ans = tmp;
		}
		return;
	}

	if (vis[p] > time || dist[p] > d){
		vis[p] = min(time,vis[p]);
		dist[p] = min(d, dist[p]);
		for (int i = 0; i < vi[p].size(); ++i){
			int v = vi[p][i].to;
			int tm = vi[p][i].time;
			if (tm <= time)
				continue;
			tmp.push_back(v);
			dfs(v, tm,d+1);
			tmp.pop_back();
		}
	}
}

int main(){
	ifstream in("C:\\input.txt");
	while (in >> N){
		Init();
		in >> st;
		p1 = st;
		for (int i = 2; i <= N - 1; ++i){
			in >> p2;
			vi[p1].push_back(Node(p2,i));
			p1 = p2;
		}
		in >> en;
		vi[p1].push_back(Node(en,N));
		dfs(st, 0,0);
		printf("%d", st);
		for (int p : ans)
			printf(" %d", p);
		cout << endl;
	}
	return 0;
}