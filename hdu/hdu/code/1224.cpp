#include <iostream>
//#include <fstream>
using namespace std;

int N ,M;
bool map[110][110];
int value[110];
int dp[110];
bool vis[110];
int pace[110];

void Print(int n){
	if (pace[n] != 0)Print(pace[n]);
	printf("%d->", n);
}

void dfs(int n){
	for (int i = n+1; i <= N;++i)
	if (map[n][i] && dp[i] < dp[n] + value[i]){
		dp[i] = dp[n] + value[i];
		pace[i] = n;
		dfs(i);
	}
}
int main(){
	//ifstream in("C:\\temp.txt");
	int n;
	cin >> n;
	int CASE = 1;
	int ok = 0;
	while (n--){
		if (ok == 1)cout << endl;
		ok = 1;
		printf("CASE %d#\n", CASE++);
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		memset(pace, 0, sizeof(pace));
		memset(value, 0, sizeof(value));
		cin >> N;
		for (int i = 1; i <= N; ++i)
			scanf("%d", &value[i]);
			//in >> value[i];
		cin >> M;
		for (int i = 0; i < M; ++i){
			int a, b;
			scanf("%d%d", &a, &b);
			//in >> a >> b;
			if (a == N + 1)a = 1;
			if (b == N + 1)b = 1;
			map[a][b] = 1;
		}
		dfs(1);
		int ans = INT_MIN;
		int kk;
		for (int i = 1; i <= N; ++i)
			if (ans < dp[i] && map[i][1]){
				ans = dp[i];
				kk = i;
			}
		
		printf("points : %d\n",ans);
		printf("circuit : ");
		Print(kk);
		printf("1\n");
		
	}

	return 0;
}