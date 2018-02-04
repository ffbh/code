#include <iostream>
//#include <fstream>
#include <map>
#include <vector>
using namespace std;
//ifstream in("C:\\temp.txt");
int Start, End;
map<_int64, int> mii;
vector<int> vi[1010];
bool vis[1010];
int N;
int size;
int getNum(){
	_int64 res = 0;
	int t;
	//in >> res;
	scanf("%I64d", &res);
	if (res < 0) return res;
	for (int i = 1; i < N; ++i){
	//	in >> t;
		scanf("%d", &t);
		res = res * 10 + t;
	}
	if (mii[res] == 0)
		mii[res] = size++;
	return mii[res];
}

bool dfs(int n){
	int ss = vi[n].size();
	vis[n] = 1;
	for (int i = 0; i < ss; ++i){
		int j = vi[n][i];
		if (j == End)return 1;
		if (!vis[j] && dfs(j))
			return 1;
	}
	return 0;
}

int main(){
	int MAZE = 1;
	while (cin >> N&&N){
		for (int i = 0; i < 1010; ++i)
			vi[i].clear();
		mii.clear();
		memset(vis, 0, sizeof(vis));
		size = 1;
		Start = getNum();
		End = getNum();
		int a, b;
		while (1){
			a = getNum();
			if (a < 0)break;
			b = getNum();
			vi[a].push_back(b);
			vi[b].push_back(a);
		}
		if (dfs(Start))printf("Maze #%d can be travelled\n", MAZE++);
		else printf("Maze #%d cannot be travelled\n", MAZE++);
	
	
	}

	return 0;
}