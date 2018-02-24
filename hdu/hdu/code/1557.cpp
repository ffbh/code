#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int data[22];
int ans[22];
int V;
int N;
bool vis[22];


void dfs(int pos, int v)
{
	int i;
	if (2*v>V)
	{
		for (i = 0; i < N; i++)
		{
			if (2*(v - data[i]) <= V&&vis[i]) ans[i]++;
		}
	}
	if (pos == N) return;
	else
	{
		for (i = pos; i < N; i++)//从pos上开始 防止重复 
		{
			if (!vis[i])
			{
				vis[i] = 1;
				dfs(i +1, v + data[i]);
				vis[i] = 0;
			}
		}
	}
}

int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int sum;
	while (cin >> N){
		sum = 0;
		memset(ans, 0, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			cin >> data[i];
			sum += data[i];
		}
		V = sum;
		dfs(0, 0);
		for (int i = 0; i < N-1; ++i)
			printf("%d ", ans[i]);
		printf("%d\n", ans[N-1]);
	}

	return 0;
}
