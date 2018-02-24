#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[110][110];
bool vis[110];
int N;
struct Node{
	int x, y;
}data[110];
bool chaji(Node& a, Node& b,Node& c){
	return ((a.x-c.x)*(b.y-c.y) - (a.y-c.y)*(b.x-c.x))>=0;
}

int dfs(int p1,int p2){
	if (dp[p1][p2] != -1)
		return dp[p1][p2];
	dp[p1][p2] = 0;
	for (int i = 1; i <= N; ++i)
	if (!vis[i]&&chaji( data[p1], data[p2],data[i])&&chaji(data[p2],data[i],data[0])){
		vis[i] = 1;
		int ret = dfs(p2, i);
		vis[i] = 0;
		dp[p1][p2] = max(dp[p1][p2], ret+1);
	}
	return dp[p1][p2];
}

int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N){
		memset(dp, -1, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		int mmax = 0;
		for (int i = 1; i <= N; ++i)
			in >> data[i].x >> data[i].y;
		data[0].x = 0;
		data[0].y = 0;
		vis[0] = 1;
		for (int i = 1; i <= N; ++i){
			vis[i] = 1;
			int ret = dfs(0, i)+2;
			vis[i] = 0;
			if (ret>mmax)
				mmax = ret;
		}
		cout << mmax << endl;
	}
	return 0;
}