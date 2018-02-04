#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N;
struct node{
	int to;
	int v;
};
vector<node> vi[10100];
vector<node> tvi[10100];
int dd[10100];
bool vis[10100];

int fun1(){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i <= N; ++i)
		dd[i] = INT_MAX;
	int size = vi[1].size();
	for (int i = 0; i < size; ++i){
		int son = vi[1][i].to;
		dd[son] = vi[1][i].v;
	}
	vis[1] = 1;
	for (int k = 0; k < N - 1; ++k){
		int u;
		int mmin = INT_MAX;
		for (int i = 1; i <= N;++i)
		if (mmin>dd[i] && !vis[i]){
			u = i;
			mmin = dd[i];
		}
		vis[u] = 1;
		int sz = vi[u].size();
		for (int i = 0; i < sz; ++i){
			int son = vi[u][i].to;
			int v = vi[u][i].v;
			if (!vis[son] && dd[son]>dd[u] + v)
				dd[son] = dd[u] + v;
		}
	}
	int ans = 0;
	for (int i = 2; i <= N; ++i)
		ans += dd[i];
	return ans;
}

int fun2(){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i <= N; ++i)
		dd[i] = INT_MAX;
	int size = tvi[1].size();
	for (int i = 0; i < size; ++i){
		int son = tvi[1][i].to;
		dd[son] = tvi[1][i].v;
	}
	vis[1] = 1;
	for (int k = 0; k < N - 1; ++k){
		int u;
		int mmin = INT_MAX;
		for (int i = 1; i <= N; ++i)
		if (mmin>dd[i] && !vis[i]){
			u = i;
			mmin = dd[i];
		}
		vis[u] = 1;
		int sz = tvi[u].size();
		for (int i = 0; i < sz; ++i){
			int son = tvi[u][i].to;
			int v = tvi[u][i].v;
			if (!vis[son] && dd[son]>dd[u] + v)
				dd[son] = dd[u] + v;
		}
	}
	int ans = 0;
	for (int i = 2; i <= N; ++i)
		ans += dd[i];
	return ans;
}


int main(){
	//ifstream in("C:\\temp.txt");
	int T,K;
	cin >> T;
	int a, b, c;
	node t;
	while (T--){
		cin >> N >> K;
		for (int i = 0; i < 1010; ++i)
			vi[i].clear();
		for (int i = 0; i < 1010; ++i)
			tvi[i].clear();
		for (int i = 1; i <= K; ++i){
			//in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			if (a == b)continue;
			t.v = c;
			t.to = b;
			vi[a].push_back(t);
			t.to = a;
			tvi[b].push_back(t);
		}
		cout << fun1() + fun2() << endl;
	}



	return 0;
}