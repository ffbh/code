#include <iostream>
//#include <fstream>
#include <vector>
using namespace std;
bool vis[100010];
bool mark[100010];
vector <int> vi[100010];

bool dfs(int v, int f){
	int size = vi[v].size();
	for (int i = 0; i < size; ++i){
		int j = vi[v][i];
		if (j != f&&j!=v){
			if (vis[j] == 1)
				return 0;
			vis[j] = 1;
			if (dfs(j, v) == 0)
				return 0;
		}
	
	}
	return 1;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int a, b;
	while (cin >> a >> b){
		if (a == -1 && b == -1)break;
		memset(vis, 0, sizeof(vis));
		memset(mark, 0, sizeof(mark));
		if (a == 0){
			cout << "Yes" << endl;
			continue;
		}
		vi[a].push_back(b);
		vi[b].push_back(a);
		mark[a] = mark[b] = 1;
		//while (in >> a >> b){
		while (scanf("%d%d",&a,&b)){
			if (a == 0 && b == 0)break;
			vi[a].push_back(b);
			vi[b].push_back(a);
			mark[a] = mark[b] = 1;
		}
		
		int ans = 1;
		int flag = 0;
		for (int i = 0; i < 100010; ++i){
			if (mark[i] && !vis[i]){
				vis[i] = 1;
				flag++;
				if (dfs(i, 0) == 0){
					ans = 0;
					break;
				}
			}
		
		}
		if (ans&&flag==1)cout << "Yes" << endl;
		else cout << "No" << endl;

		for (int i = 1; i < 100010; ++i)
			vi[i].clear();





	}


	return 0;
}