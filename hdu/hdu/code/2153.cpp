#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[12][12];


int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		int size = 1;
		memset(data, 0, sizeof(data));
		for (int i = 1; i <= N; ++i)
			data[1][i] = size++;
		for (int i = 2; i <= N; ++i)
			data[i][N] = size++;
		for (int i = N - 1; i >= 1; --i)
			data[N][i] = size++;
		for (int i = N - 1; i >= 2; --i)
			data[i][1] = size++;
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= N; ++j)
			if (data[i][j])
				printf("%3d", data[i][j]);
			else
				printf("   ");
			putchar('\n');
		}
	}
	return 0;
}