#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N, M;
struct Room{
	int bugs, brins;
};
Room room[110];
int dp[110][110];
vector<int> vi[110];
void dfs(int r, int t, int f){
	if (t < room[r].bugs)
		return;
	int rest = t - room[r].bugs;
	for (int i = room[r].bugs; i <= t; ++i)
		dp[r][i] = room[r].brins;
	int size = vi[r].size();
	for (int i = 0; i < size; ++i){
		int son = vi[r][i];
		if (son == f)continue;;
		dfs(son, rest, r);
		for (int j = t; j > room[r].bugs; --j)
		for (int k = j - room[r].bugs; k >= 1; --k)
		if (dp[r][j] < dp[r][j - k] + dp[son][k])
			dp[r][j] = dp[r][j - k] + dp[son][k];

	}
}
int main(){
	//    ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		if (N <= 0) break;
		memset(dp, 0, sizeof(dp));
		memset(room, 0, sizeof(room));
		for (int i = 1; i < 110; ++i)
			vi[i].clear();
		int bugs, brins;
		for (int i = 1; i <= N; ++i){
			//    in >> bugs >> brins;
			scanf("%d%d", &bugs, &brins);
			bugs = (bugs + 19) / 20;
			room[i].brins = brins;
			room[i].bugs = bugs;
		}
		int a, b;
		for (int i = 1; i < N; ++i){
			//    in >> a >> b;
			scanf("%d%d", &a, &b);
			vi[a].push_back(b);
			vi[b].push_back(a);

		}
		if (M == 0)//比如所有的房子里都没有bugs，此时没人，所以收益为0！！！！！！！
			//如果不加，则对于那些没有bugs的房子，会有收益，其实没有，故M==0时要分开讨论
			printf("0\n");
		else{
			dfs(1, M, -1);
			cout << dp[1][M] << endl;
		}
	}

	return 0;
}