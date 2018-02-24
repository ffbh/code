#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> vi[110];
struct Node{
	vector<int> A, B;
};
int mark[110];

vector<Node> V;

bool bfs(int s){
	mark[s] = 0;
	queue<int> qi;
	qi.push(s);
	Node temp;
	while (!qi.empty()){
		int u = qi.front();
		if (mark[u] == 0){
			temp.A.push_back(u);
		}
		else{
			temp.B.push_back(u);
		}
		qi.pop();
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i];
			if (mark[v] == -1){
				mark[v] = 1 - mark[u];
				qi.push(v);
			}
			else{
				if (mark[v] != 1 - mark[u])
					return 0;
			}
		}
	}
	V.push_back(temp);
	return 1;
}
bool vis[110][110];
vector<int> tmp, ans;
bool dfs(int pos, int sum){
	if (vis[pos][sum])
		return 0;
	vis[pos][sum] = 1;
	if (pos == V.size()){
		if (sum == N / 2){
			ans = tmp;
			return 1;
		}
		return 0;
	}
	if (sum > N / 2)
		return 0;
	tmp.push_back(0);
	if (dfs(pos + 1, V[pos].A.size() + sum))
		return 1;
	tmp.pop_back();

	tmp.push_back(1);
	if (dfs(pos + 1, V[pos].B.size() + sum))
		return 1;
	tmp.pop_back();
	return 0;
}
vector<int> ansA, ansB;

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	for (int i = 1; i <= M; ++i){
		int a, b;
		cin >> a >> b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}
	N *= 2;
	bool ok = 1;
	memset(mark, -1, sizeof(mark));
	for (int i = 1; i <= N; ++i){
		if (mark[i] == -1){
			if (!bfs(i)){
				ok = 0;
				break;
			}
		}
	}

	if (ok){
		if (dfs(0, 0)){
			for (int i = 0; i < V.size(); ++i){
				if (ans[i] == 0){
					for (int t : V[i].A){
						ansA.push_back(t);
					}
					for (int t : V[i].B){
						ansB.push_back(t);
					}
				}
				else{
					for (int t : V[i].A){
						ansB.push_back(t);
					}
					for (int t : V[i].B){
						ansA.push_back(t);
					}
				}
			}
			sort(ansA.begin(), ansA.end());
			sort(ansB.begin(), ansB.end());
			for (int i = 0; i<ansA.size(); ++i){
				cout << ansA[i] << " ";
			}
			cout << endl;
			for (int i = 0; i<ansB.size(); ++i){
				cout << ansB[i] << " ";
			}
			cout << endl;

		}
		else{
			cout << "IMPOSSIBLE" << endl;
		}
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}







	return 0;
}