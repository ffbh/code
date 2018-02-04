#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF (1<<29)
int N, M, x;
int dp[60][1010];
struct Node{
	int x, v;
	bool operator<(const Node& p)const{
		return x < p.x;
	}
}data[60][1010],tmp[1010];


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M >> x;
		for (int i = 1; i <= N; ++i)
		for (int j = 0; j < M; ++j)
		//	in>>data[i][j].x;
			scanf("%d", &data[i][j].x);
		for (int i = 1; i <= N; ++i)
		for (int j = 0; j < M; ++j)
		//	in >> data[i][j].v;
			scanf("%d", &data[i][j].v);
		for (int i = 1; i <= N; ++i)
			sort(data[i], data[i] + M);
		for (int j = 0; j < M; ++j)
			dp[1][j] = abs(x - data[1][j].x) + data[1][j].v;
		for (int i = 1; i < N; ++i){
			int mmin, k;
			for (int j = 0; j < M; ++j){
				tmp[j].x = data[i][j].x;
				tmp[j].v = dp[i][j] - data[i][j].x;
			}
			mmin = INF;
			k = 0;
			for (int j = 0; j < M; ++j){
				while (k < M&&data[i + 1][j].x >= tmp[k].x){
					if (tmp[k].v < mmin)
						mmin = tmp[k].v;
					k++;
				}
				dp[i + 1][j] = mmin + data[i + 1][j].v + data[i+1][j].x;
			}
			for (int j = M-1; j >=0; --j){
				tmp[j].x = data[i][j].x;
				tmp[j].v = dp[i][j] + data[i][j].x;
			}
			mmin = INF;
			k = M - 1;
			for (int j = M-1; j >=0; --j){
				while (k >=0&&data[i + 1][j].x < tmp[k].x){
					if (tmp[k].v < mmin)
						mmin = tmp[k].v;
					k--;
				}
				if (dp[i + 1][j] > mmin + data[i + 1][j].v - data[i+1][j].x)
				dp[i + 1][j] = mmin + data[i + 1][j].v - data[i+1][j].x;
			}
		}
		int mmin = INF;
		for (int i = 0; i < M; ++i)
		if (dp[N][i] < mmin)
			mmin = dp[N][i];
		cout << mmin << endl;

	}
	return 0;
}