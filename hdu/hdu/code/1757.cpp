#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int K, MOD;
int mat[10][10];


void quickmod(int m){
	int temp[10][10] = { 0 };
	int tmp[10][10];
	for (int i = 0; i < 10; ++i)
		temp[i][i] = 1;
	while (m > 0){
		if (m & 1){
			for (int i = 0; i < 10;++i)
			for (int j = 0; j < 10; ++j){
				tmp[i][j] = 0;
				for (int k = 0; k < 10; ++k){
					tmp[i][j] = (tmp[i][j] + temp[i][k] * mat[k][j]) % MOD;
				}
			}
			memcpy(temp, tmp, sizeof(temp));
		}

		for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j){
			tmp[i][j] = 0;
			for (int k = 0; k < 10; ++k){
				tmp[i][j] = (tmp[i][j] + mat[i][k] * mat[k][j]) % MOD;
			}
		}
		memcpy(mat, tmp, sizeof(mat));
		m /= 2;
	}
	memcpy(mat, temp, sizeof(mat));
}

int main(){
//	ifstream in("C:\\input.txt");
	while (cin >> K >> MOD){
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < 10; ++i)
			cin >> mat[i][0];
		for (int i = 1; i < 10; ++i){
			mat[i - 1][i] = 1;
		}

		if (K < 10){
			printf("%d\n", K%MOD);
			continue;
		}
		
		quickmod(K - 9);
		int ans = 0;
		for (int i = 0; i < 10; ++i)
			ans = (ans + (9 - i)*mat[i][0]) % MOD;

		printf("%d\n", ans%MOD);







	}
















	return 0;
}