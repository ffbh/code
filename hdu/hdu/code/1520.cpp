#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[6100][2];
int data[6100];
int father[6100];
int N;
vector<int> vi[6100];

int find(int n){
	return n == father[n] ? n : father[n] = find(father[n]);
}
void dfs(int n){
	int size = vi[n].size();
	dp[n][0] = 0;
	dp[n][1] = data[n];
	if (size == 0)
		return;
	for (int i = 0; i < size; ++i){
		int son = vi[n][i];
		dfs(son);
		dp[n][0] = max(dp[n][0], dp[n][0] + max(dp[son][0], dp[son][1]));
		dp[n][1] = max(dp[n][1], dp[n][1] + dp[son][0]);
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N){
		for (int i = 0; i <= N; ++i)
			father[i] = i;
		for (int i = 0; i < 6100; ++i)
			vi[i].clear();
		for (int i = 0; i < 6100;++i)
		for (int j = 0; j < 2; ++j)
			dp[i][j] = INT_MIN;
		for (int i = 1; i <= N; ++i)
			//in >> data[i];
			scanf("%d", &data[i]);
		int a, b;
		//while (in >> a >> b&&a + b){
		while (scanf("%d%d",&a,&b)&&a+b){
			vi[b].push_back(a);
			int fa = find(a);
			int fb = find(b);
			father[fa] = fb;
		}
		int root = find(1);
		dfs(root);
		cout << max(dp[root][0], dp[root][1]) << endl;

	
	
	}

	return 0;
}