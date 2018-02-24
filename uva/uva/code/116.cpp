#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int N, M;
int data[110][110], dp[110][110], pace[110][110];

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	while (in >> N >> M){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j)
			in >> data[i][j];

		for (int i = 1; i <= N; ++i){
			dp[i][M] = data[i][M];
		}

		for (int j = M-1; j >= 1; --j){
			for (int i = 1; i <= N; ++i){
				dp[i][j] = dp[i][j + 1] + data[i][j];
				pace[i][j] = i;

				int row = i - 1;
				if (row == 0)
					row = N;
				if (dp[i][j] > dp[row][j + 1] + data[i][j] ||
					dp[i][j] == dp[row][j + 1] + data[i][j] && row < pace[i][j]){
					dp[i][j] = dp[row][j + 1] + data[i][j];
					pace[i][j] = row;
				}

				row = i + 1;
				if (row > N)
					row = 1;
				if (dp[i][j] > dp[row][j + 1] + data[i][j] ||
					dp[i][j] == dp[row][j + 1] + data[i][j] && row < pace[i][j]){
					dp[i][j] = dp[row][j + 1] + data[i][j];
					pace[i][j] = row;
				}
			}
		}

		int mmin = dp[1][1], idx = 1;
		for (int i = 1; i <= N; ++i){
			if (dp[i][1] < mmin){
				idx = i;
				mmin = dp[i][1];
			}
		}
		printf("%d", idx);
		int r = idx, col = 1;
		while (col < M){
			r = pace[r][col];
			printf(" %d", r);
			col++;
		}
		cout << endl;
		cout << mmin << endl;

	}


	return 0;
}