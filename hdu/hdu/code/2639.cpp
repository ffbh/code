#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int w, v;
}data[110];
int dp[40][1010];
int temp[110], t;
int N, M, K;
bool cmp(int a, int b){
	return a > b;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		//in >> N >> M >> K;
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 0; i < N; ++i)
			//in >> data[i].w;
			scanf("%d", &data[i].w);
		for (int i = 0; i < N; ++i)
			//in >> data[i].v;
			scanf("%d", &data[i].v);
		memset(dp, 0, sizeof(dp));
		for (int k = 0; k < N; ++k)
		for (int i = M; i >= data[k].v; --i){
			t = 0;
			for (int j = 1; j <= K; ++j){
				temp[t++] = dp[j][i];
				temp[t++] = dp[j][i - data[k].v] + data[k].w;
			}
			sort(temp, temp + t,cmp);
			t = unique(temp, temp + t) - temp;
			for (int j = 1; j <= K; ++j)
			if (j <= t)
				dp[j][i] = temp[j - 1];
			else
				dp[j][i] = 0;
		}
		cout << dp[K][M] << endl;
	}
	return 0;
}