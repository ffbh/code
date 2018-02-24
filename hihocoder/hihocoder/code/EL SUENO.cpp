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
#define INF (1<<29)
struct Node{
	int f, in, ip, c;
}data[2010];

vector<int> vi[2010];
int kill[2010];
int dp[20010];
bool dfs(int p){
	Node& now = data[p];

	if (now.in == 0){
		kill[p] = now.c;
		return 1;
	}
	else{
		vector<pair<int, int> > P;
		for (int i = 0; i < vi[p].size(); ++i){
			int son = vi[p][i];
			if (dfs(son)){
				P.push_back(make_pair(kill[son], data[son].ip));
			}
		}

		for (int i = 0; i <= now.in; ++i){
			dp[i] = INF;
		}
		dp[0] = 0;
		if (p == 1){
			int t = 0;
		}

		for (int i = 0; i < P.size(); ++i){
			int cost = P[i].first;
			int val = P[i].second;
			for (int k = now.in; k >= 0;--k){
			//	int pre = ;
			//	if (dp[pre] != INF)
				dp[k] = min(dp[k], dp[max(k - val, 0)] + cost);
			}
		}

		if (dp[now.in] != INF){
			kill[p] = dp[now.in] + now.c;
		}
		else{
			kill[p] = INF;
		}
		return dp[now.in] != INF;
	}
}


void getInput(int n){
	ofstream ou("C:\\input.txt");
	ou << n << endl;
	srand(time(0));
	for (int i = 1; i <= n; ++i){
		if (i == 1){
			ou << i - 1 << " " << 500 << " " << 0 << " " << 100 << endl;
			continue;
		}
		int p = abs(rand()) % 10;
		if (p){
			ou << abs(rand()) % (i - 1) + 1 << " " << abs(rand()) % 19999 + 1 << " " << abs(rand()) % 19999 + 1 << " " << abs(rand()) % 999 + 1 << endl;
		}
		else{
			ou << abs(rand()) % (i - 1) + 1 << " " << 0 << " " << abs(rand()) % 19999 + 1 << " " << abs(rand()) % 999 + 1 << endl;
		}
	}

}

int main(){
	//getInput(2000);
	//return 0;
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int N;
	while (in >> N){
		for (int i = 0; i < 2010; ++i){
			kill[i] = INF;
			vi[i].clear();
		}
		for (int i = 1; i <= N; ++i){
			in >> data[i].f >> data[i].in >> data[i].ip >> data[i].c;
		}
		int root;
		for (int i = 1; i <= N; ++i){
			if (data[i].f == 0){
				root = i;
			}
			else{
				data[i].ip = min(data[i].ip, data[data[i].f].in);
				vi[data[i].f].push_back(i);
			}
		}


		dfs(root);

		if (kill[root] == INF){
			cout << -1 << endl;
		}
		else{
			cout << kill[root] << endl;
		}
	}
	return 0;
}





