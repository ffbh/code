#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
int N, M;
int cost[1001];
vector<int> vi[1001];
int DFN[1001], low[1001];
stack<int> si;
bool In[1001];
int link[1001];
bool nroot[1001];
int Index;
int Bcnt;

void tarjin(int n){
	DFN[n] = low[n] = ++Index;
	si.push(n);
	In[n] = 1;
	for (int i = 0; i < vi[n].size();++i){
		int son = vi[n][i];
		if (!DFN[son]){
			tarjin(son);
			if (low[n]>low[son])
				low[n] = low[son];
		}
		else if (In[son]){
			if (low[n] > DFN[son])
				low[n] = DFN[son];
		}
	}
	if (DFN[n] == low[n]){
		Bcnt++;
		int v;
		do{
			v = si.top();
			In[v] = 0;
			si.pop();
			link[v] = Bcnt;
		} while (n != v);
	}
}

int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		Index = 0;
		Bcnt = 0;
		for (int i = 1; i <= N; ++i){
		//	in >> cost[i];
			scanf("%d", &cost[i]);
			vi[i].clear();
			DFN[i] = low[i] = 0;
			In[i] = 0;
			nroot[i] = 0;
		}
		while (M--){
			int a, b;
			//in >> a >> b;
			scanf("%d%d", &a, &b);
			vi[a].push_back(b);
		}
		for (int i = 1; i <= N;++i)
		if (!DFN[i])
			tarjin(i);
		for (int k = 1; k <= N; ++k)
		for (int i = 0; i < vi[k].size();++i){
			int son = vi[k][i];
			if (link[k] != link[son])
				nroot[link[son]] = 1;
		}
		int ans = 0;
		int num = 0;
		for (int i = 1; i <= Bcnt;++i)
		if (!nroot[i]){
			int mmin = INT_MAX;
			for (int j = 1; j <= N;++j)
			if (link[j] == i&&cost[j] < mmin)
				mmin = cost[j];
			ans += mmin;
			num++;
		}
		printf("%d %d\n", num, ans);
	}
	return 0;
}