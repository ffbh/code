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
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;


class DistanceZeroAndOne {
public:
	int N;
	vector <string> ans;
	vector<int> vi[60];
	bool ok[60][60];
	bool put(vector<int> dist, int p){
		if (dist[p] != 0)
			return 0;
		for (int a : dist){
			if (a >= N)
				return 0;
		}
		for (int i = 0; i < 60; ++i)
			vi[i].clear();
		for (int i = 0; i < N; ++i){
			vi[dist[i]].push_back(i);
		}
		if (vi[0].size() != 1){
			return 0;
		}
		memset(ok, 0, sizeof(ok));
		for (int i = 1; i < 60; ++i){
			if (!vi[i].empty() && vi[i - 1].empty())
				return 0;

			for (int a : vi[i])
			for (int b : vi[i]){
				if (a != b)
					ok[a][b] = ok[b][a] = 1;;
			}
			for (int a : vi[i])
			for (int b : vi[i - 1]){
				ok[a][b] = ok[b][a] = 1;
			}
		}

		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		if (!ok[i][j]){
			ans[i][j] = 'N';
		}
		return 1;
	}

	bool vis[60];
	bool bfs(){
		memset(vis, 0, sizeof(vis));
		int num = 0;
		vis[0] = 1;
		queue<int> qi;
		qi.push(0);
		while (!qi.empty()){
			int u = qi.front();
			qi.pop();
			num++;
			for (int i = 0; i < N; ++i){
				if (ans[u][i] == 'Y'){
					if (!vis[i]){
						vis[i] = 1;
						qi.push(i);
					}
				}
			}
		}
		return num == N;
	}

	bool test(int start, vector<int> d){
		memset(vis, 0, sizeof(vis));
		queue<int> qi;
		qi.push(start);
		vis[start] = 1;
		while (!qi.empty()){
			int u = qi.front();
			qi.pop();
			for (int i = 0; i < N; ++i){
				if (ans[u][i]=='Y' && !vis[i]){
					vis[i] = 1;
					qi.push(i);
					if (d[i] != d[u] + 1)
						return 0;
				}
			}
		}
		return 1;
	}

	vector <string> construct(vector <int> a, vector <int> b) {
		vector <string> empty;

		N = a.size();
		string kN(N, 'N');
		string kY(N, 'Y');
		ans.clear();
		for (int i = 0; i < N; ++i){
			ans.push_back(kY);
		}


		if (!put(a, 0) || !put(b, 1) || !bfs() || !test(0, a) || !test(1, b))
			return empty;
		return ans;




	}
};



#if 0
int main(){
	vector<int> a({ 0, 2, 1, });
	vector<int> b({ 2, 0, 1 });




	DistanceZeroAndOne so;
	vector<string> ans = so.construct(a, b);
	for (string s : ans)
		cout << s << endl;

	return 0;
}
#endif






// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
