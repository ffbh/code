#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int T, N;
vector<int> vi[200010];

void Init(){
	for (int i = 0; i < 200010; ++i)
		vi[i].clear();
}

int size[200010];
int dept[200010];
long long cnt[200010];

int dfs(int p,int f,int d){
	size[p] = 1;
	cnt[p] = 0;
	dept[p] = d;
	for (int i = 0; i < vi[p].size(); ++i){
		int v = vi[p][i];
		if (v == f){
			continue;
		}
		size[p] += dfs(v,p,d+1);
		cnt[p] += cnt[v];
	}
	cnt[p] += size[p] - 1;
	return size[p];
}

int main(){
	ifstream in("C:\\input.txt");
	in >> T;
	while (T-- > 0){
		Init();
		in >> N;
		for (int i = 1; i < N; ++i){
			int a, b;
			in >> a >> b;
			vi[a].push_back(b);
			vi[b].push_back(a);
		}
		dfs(1,-1,0);
	//	cout << cnt[1] << endl;
		long long ans = 0;
		for (int i = 2; i <= N; ++i){
			if (ans < (dept[i]-1) * size[i]){
				ans = (dept[i]-1) * size[i];
			}
		}
		cout << cnt[1] - ans << endl;


	}
















	return 0;
}