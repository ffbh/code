#include <iostream>
//nclude <fstream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
int dd[510];
vector<int> vi[510];
bool vis[510];
int main(){
//fstream in("C:\\temp.txt");
	int N, M;
	int a, b;
	while (cin >> N >> M){
		for (int i = 0; i < 510; ++i)
			vi[i].clear();
		memset(dd, 0, sizeof(dd));
		memset(vis, 0, sizeof(vis));
		priority_queue<int,vector<int>, greater<int> > pp;
		for (int i = 0; i < M; ++i){
			scanf("%d%d", &a, &b);
			vi[a].push_back(b);
			dd[b]++;
		}
		for (int i = 1; i <= N; ++i)
		if (dd[i] == 0){
			pp.push(i);
			vis[i] = 1;
		}
		int kk = 1;
		for (int i = 1; i < N; ++i){
			int k = pp.top();
			printf("%d ", k);
			pp.pop();
			int size = vi[k].size();
			for (int j = 0; j < size; ++j){
				int d = vi[k][j];
				dd[d]--;
				if (dd[d] == 0&&!vis[d])
					pp.push(d);
			}
			
		}
		cout << pp.top() << endl;
	}

	return 0;
}