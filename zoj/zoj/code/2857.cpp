#include <iostream>
#include <string>
#include <fstream>
using namespace std;
long long data1[110][110],data2[110][110],data3[110][110];

int main(){
	ifstream in("C:\\temp.txt");
	int  N, M;
	int CASE = 1; 
	while (cin >> N >> M&&N+M){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j)
			cin >> data1[i][j];
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> data2[i][j];
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> data3[i][j];
		printf("Case %d:\n", CASE++);
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j < M; ++j)
				printf("%lld,", (data1[i][j] + data2[i][j] + data3[i][j]) / 3);
			printf("%lld\n", (data1[i][M] + data2[i][M] + data3[i][M]) / 3);
		}




	}





	return 0;
}