#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int map[22][22];


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		memset(map, 0, sizeof(map));
		int x, y;
		x = N / 2 + 1;
		y = N / 2;
		int size = 1;
		int M = N*N;
		while (M--){
			map[x][y] = size++;
			x = (x + 1) % N;
			y = (y + 1) % N;
			if (map[x][y]){
				x = (x + 1) % N;
				y = (y - 1 + N) % N;
			}
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j)
				printf("%4d", map[i][j]);
			putchar('\n');
		}
	}
	return 0;
}