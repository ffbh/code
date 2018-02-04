#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
long long  dp[100010];
bool vis[100010];
int N, M;
long long ans;
struct Data{
	Data(int _to, long long _v){
		to = _to;
		v = _v;
	}
	bool operator<(const Data& p)const{
		return to < p.to;
	}
	int to;
	long long num, v;
};
struct Ans{
	vector<Data> vd[100010];
	void add(int a, int b, long long c){
		if (a>b)
			swap(a, b);
		vd[a].push_back(Data(b, c));
	}

	void setV(int a, int b, long long  v){
		if (a>b)
			swap(a, b);
		int aim = find(a, b);
		vd[a][aim].v = v;
	}

	long long getChazhiandSet(int a, int b, long long v){
		if (a>b)
			swap(a, b);
		int aim = find(a, b);
		long long old = vd[a][aim].num * (v - vd[a][aim].v);
		vd[a][aim].v = v;
		return old;
	}

	void setNum(int a, int b, long long num){
		if (a>b)
			swap(a, b);
		int aim = find(a, b);
		vd[a][aim].num = num;
	}


	long long getAns(int a, int b){
		if (a>b)
			swap(a, b);
		int aim = find(a, b);
		return vd[a][aim].num*vd[a][aim].v;
	}

	void Sort(){
		for (int i = 1; i <= N; ++i)
			sort(vd[i].begin(), vd[i].end());
	}

	int find(int a, int b){
		int L = 0;
		int R = vd[a].size() - 1;
		while (L <= R){
			int mid = (L + R) / 2;
			if (vd[a][mid].to == b)
				return mid;
			else if (vd[a][mid].to < b)
				L = mid + 1;
			else
				R = mid - 1;
		}
	}
}data;
vector<int> vi[100010];
void dfs(int u){
	vis[u] = 1;
	dp[u] = 1;
	for (int i = 0; i < vi[u].size(); ++i){
		int v = vi[u][i];
		if (vis[v])
			continue;
		dfs(v);
		dp[u] += dp[v];
		data.setNum(u, v, dp[v] * (N - dp[v]));
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	cin >> N >> M;
	//scanf("%d%d", &N, &M);
	for (int i = 1; i < N; ++i){
		long long  a, b, c;
		cin >> a >> b >> c;
		//	scanf("%d%d%d", &a, &b, &c);
		vi[a].push_back(b);
		vi[b].push_back(a);
		data.add(a, b, c);
	}
	data.Sort();
	dfs(1);
	ans = 0;
	for (int i = 1; i <= N; ++i)
	for (int j = 0; j < vi[i].size(); ++j){
		ans += data.getAns(i, vi[i][j]);
	}
	ans /= 2;
	while (M--){
		char s[10];
		//scanf("%s", s);
		cin >> s;
		if (s[0] == 'Q'){
			//	printf("%lld\n", ans);
			cout << ans << endl;
		}
		else{
			long long a, b, c;
			cin >> a >> b >> c;
			//	scanf("%d%d%d", &a, &b, &c);
			long long old = data.getChazhiandSet(a, b, c);
			ans += old;
		}

	}


	return 0;
}