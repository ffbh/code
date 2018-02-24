#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;
long long mat1[52][52], mat2[52][52], ans[52][52], tmp[52][52];
string s;

void Init(){
	for (int i = 0; i < 26; ++i)
		s += 'a' + i;
	for (int i = 0; i < 26; ++i)
		s += 'A' + i;
	memset(mat1, 0, sizeof(mat1));
	memset(mat2, 0, sizeof(mat2));
	for (int i = 0; i < 52; ++i)
	for (int j = 0; j < 52; ++j){
		if (abs(s[i] - s[j]) < 32){
			mat1[i][j] = mat2[i][j] = 1;
		}
		else if (abs(s[i] - s[j]) == 32){
			mat1[i][j] = 1;
		}
	}
}

void quickmod(int p, long long ma[52][52]){
	long long mat[52][52];
	memcpy(mat, ma, sizeof(mat));
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < 52; ++i)
		ans[i][i] = 1;

	while (p>0){
		if (p & 1){
			for (int i = 0; i < 52; ++i)
			for (int j = 0; j < 52; ++j){
				tmp[i][j] = 0;
				for (int k = 0; k < 52; ++k)
					tmp[i][j] = (tmp[i][j] + ans[i][k] * mat[k][j]) % MOD;
			}
			memcpy(ans, tmp, sizeof(ans));
		}

		for (int i = 0; i < 52; ++i)
		for (int j = 0; j < 52; ++j){
			tmp[i][j] = 0;
			for (int k = 0; k < 52; ++k)
				tmp[i][j] = (tmp[i][j] + mat[i][k] * mat[k][j]) % MOD;
		}
		memcpy(mat, tmp, sizeof(mat));
		p /= 2;
	}
}

long long getAns(long long mat[52][52]){
	long long sum = 0;
	for (int i = 0; i < 52; ++i)
	for (int j = 0; j < 52; ++j){
		sum = (sum + mat[i][j]) % MOD;
	}
	return sum;
}

int main(){
	ifstream in("C:\\input.txt");
	int T, N;
	Init();
	in >> T;
	while (T--){
		in >> N;
		quickmod(N - 1, mat1);
		long long ans1 = getAns(ans);
		quickmod(N - 1, mat2);
		long long ans2 = getAns(ans);
		cout << (ans1 - ans2 + MOD) % MOD << endl;


	}
















	return 0;
}