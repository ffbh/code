#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int mat[8][8];
const int mod = 12357;

bool judge(int state,int w){
	int num = 0;
	for (int i = 0; i < w; ++i){
		int p = 1 << i;
		if (state&p){
			num++;
		}
		else{
			if (num % 2 == 1)
				return 0;
		}
	}
	return num % 2 == 0;
}

bool judgechanstate(int state1, int state2,int w){
	for (int i = 0; i < w; ++i){
		int p = 1 << i;
		if (!(state1&p)){
			if (!(state2&p))
				return 0;
			state2 -= p;
		}
	}
	return judge(state2,w);
}

void mul(int a[8][8], int b[8][8], int ans[8][8], int n){
	int tmp[8][8];
	for (int i = 0; i < n;++i)
	for (int j = 0; j < n; ++j){
		tmp[i][j] = 0;
		for (int k = 0; k < 8; ++k){
			tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
		}
	}
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		ans[i][j] = tmp[i][j];
}

void quick_mod(int p,int n){
	int ret[8][8];
	memset(ret, 0, sizeof(ret));
	for (int i = 0; i < n; ++i)
		ret[i][i] = 1;
	while (p){
		if (p & 1){
			mul(ret, mat, ret,n);
		}
		mul(mat, mat, mat,n);
		p /= 2;
	}
	for (int i = 0; i < n;++i)
	for (int j = 0; j < n; ++j)
		mat[i][j] = ret[i][j];
}


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	for (int i = 0; i < 8;++i)
	for (int j = 0; j < 8; ++j)
		mat[i][j] = judgechanstate(i, j,3);

	quick_mod(N, 8);
	cout << mat[7][7] << endl;















	return 0;
}