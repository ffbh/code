#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int map[220][220];
int G[2][220];
int F[2][220];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		for (int i = 0; i < N; ++i)
			cin >> G[0][i];
		for (int i = 0; i < N; ++i)
			cin >> G[1][i];
		for (int i = 0; i < M; ++i)
			cin >> F[0][i];
		for (int i = 0; i < M; ++i)
			cin >> F[1][i];
		int len, shift;
		len = shift = 0;
		for (int i = 0; i < N; ++i)
			len += G[0][i] + G[1][i];
		for (int i = 0; i < M; ++i){
			shift += F[0][i] * F[1][i];
		}
		if (shift%len == 0){
			int size = len - 1;
			for (int i = 0; i < N; ++i){
				while (G[0][i]--)
					map[size--][0] = 1;
				while (G[1][i]--)
					map[size--][0] = 0;
			}
			int line = 1;
			for (int k = 0; k < M; ++k){
				int yiwei = F[0][k];
				while (F[1][k]--){
					for (int i = 0; i < len; ++i)
						map[i][line] = map[(i + yiwei+len) % len][line - 1];
					line++;
				}
			}
			for (int i = 0; i < len; ++i){
				for (int j = 0; j < line-1; ++j)
					printf("%d", map[i][j]);
				putchar('\n');
			}
		}
		else
			printf("Can not make beautilful cloth !\n");
	}
	return 0;
}