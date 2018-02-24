#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int pace[110][510];
int data[110][510];
int sum[110][510];
int dp[110][510];
int N, M;
void PrintPath(int x,int y){
	if (x < 1)
		return;
	if (x == 1){
		printf("%d ", y);
		return;
	}
	else{
		PrintPath(x - 1, pace[x][y]);
		if (y < pace[x][y]){
			for (int i = pace[x][y]; i >= y; --i)
				printf("%d ", i);
				
		}
		else{
			for (int i = pace[x][y]; i <= y; ++i)
				printf("%d ", i);
		}
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	
	while (in >> N >> M){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
			in >> data[i][j];
			sum[i][j] = sum[i][j - 1] + data[i][j];
		}
		for (int i = 1; i <= M; ++i)
			dp[0][i] = 0;
		for (int i = 1; i <= N-1; ++i){
			int mmin = INT_MAX;
			int u = 1;
			for (int j = 1; j <= M; ++j){
				if (mmin > dp[i-1][j] - sum[i][j-1]){
					mmin = dp[i-1][j] - sum[i][j-1];
					u = j;
				}
				dp[i][j] = mmin + sum[i][j];
				pace[i][j] = u;
			}
			mmin = INT_MAX;
			u = M;
			for (int j = M; j >= 1; --j){
				if (mmin > dp[i-1][j] + sum[i][j]){
					mmin = dp[i-1][j] + sum[i][j];
					u = j;
				}
				if (dp[i][j] > mmin - sum[i][j - 1]){
					pace[i][j] = u;
					dp[i][j] = mmin - sum[i][j - 1];
				}
			}
		}
		int u, mmin = INT_MAX;
		for (int i = 1; i <= M;++i)
		if (mmin > dp[N-1][i]+data[N][i]){
			mmin = dp[N-1][i]+data[N][i];
			u = i;
		}
		PrintPath(N-1, u);
		printf("%d\n", u);

	}
	return 0;
}