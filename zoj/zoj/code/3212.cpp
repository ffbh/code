#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int data[21][21];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int main(){
	ifstream in("C:\\temp.txt");
	int T, N, M, K;
	cin >> T;
	while (T--){
		for (int i = 0; i <= 20;++i)
		for (int j = 0; j <= 20; ++j)
			data[i][j] = 1;
		cin >> N >> M >> K;
		for (int i = 1; i <= N-2&&K; ++i)
		for (int j = 1; j <= M-2&&K; ++j){
			data[i][j] = 0;
			K--;
			for (int k = 0; k < 4; ++k){
				int tx = i + dirs[k][0];
				int ty = j + dirs[k][1];
				data[tx][ty] = 0;
			}
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < M-1; ++j)
				printf("%d ", data[i][j]);
			printf("%d\n",data[i][M-1]);
		}
	}

	return 0;
}