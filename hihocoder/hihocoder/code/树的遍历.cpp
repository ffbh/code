#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
	int p, q;
	bool operator<(const Node& p)const{
		return q > p.q;
	}
};
vector<int> vi[10010];
int N, p[10010], q[10010];


int dfs(int u,int f,Node* addr){
	Node* data = new Node[vi[u].size()];
	int size = 0;
	int sum = p[u] - q[u];
	for (int i = 0; i < vi[u].size(); ++i){
		int v = vi[u][i];
		if (v == f)
			continue;
		sum += dfs(v, u,&data[size++]);
	}
	if (size == 0){
		addr->p = p[u];
		addr->q = q[u];
		return p[u] - q[u];
	}
	else{
		sort(data, data + size);
		int mmax = p[u];
		addr->p = mmax;
		mmax -= q[u];
		for (int i = 0; i < size; ++i){
			mmax += data[i].p;
			if (addr->p < mmax)
				addr->p = mmax;
			mmax -= data[i].q;
		}
		addr->q = addr->p - sum ;
		return addr->p - addr->q;
	}
}


int main(){
	ifstream in("C:\\input.txt");
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", &p[i], &q[i]);
	while (--N){
		int a, b;
		scanf("%d%d", &a, &b);
		vi[a].push_back(b);
		vi[b].push_back(a);
	}
	Node ans;
	dfs(1,0,&ans);
	cout << ans.p << endl;
	return 0;
}