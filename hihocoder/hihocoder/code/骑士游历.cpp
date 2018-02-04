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
const long long mod = 1000000007;
long long mat[70][70];
long long tmp[70][70];

int getID(int x,int y){
	return x * 8 + y;
}

bool IN(int x, int y){
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}
int dirs[8][2] = { 1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1 };


void mul(long long a[70][70], long long  b[70][70], long long  ret[70][70],int n){
	long long  temp[70][70];
	for (int i = 0; i < 64;++i)
	for (int j = 0; j < 64; ++j){
		temp[i][j] = 0;
		for (int k = 0; k < 64; ++k)
			temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % mod;
	}
	//memcpy(ret, temp, sizeof(ret));
	for (int i = 0; i < 64; ++i)
	for (int j = 0; j < 64; ++j)
		ret[i][j] = temp[i][j];

}

/*void mul(long long  a[70][70], long long  b[70][70], long long  ans[70][70], int n){
	long long  tmp[70][70];
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j){
		tmp[i][j] = 0;
		for (int k = 0; k < n; ++k){
			tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
		}
	}
	

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		ans[i][j] = tmp[i][j];
}*/

void quick_mod(int p){
	long long  temp[70][70];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < 64; ++i)
		temp[i][i] = 1;
	while (p>0){
		if (p & 1){
			mul(temp, mat, temp,64);
		}
		mul(mat, mat, mat,64);
		p /= 2;
	}

	memcpy(mat, temp, sizeof(mat));
}

int main(){
	ifstream in("C:\\input.txt");
	int N, R, C;
	cin >> N >> R >> C;

	R--;
	C--;

	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < 8;++i)
	for (int j = 0; j < 8; ++j){
		int x, y;
		if (i == 1 && j == 2){
			int t = 0;
		}

		for (int k = 0; k < 8; ++k){
			x = i + dirs[k][0];
			y = j + dirs[k][1];
			if (IN(x, y)){
				mat[getID(x, y)][getID(i, j)] = 1;
			
			}
		}		
	}

/*	for (int i = 0; i < 64; ++i){
		for (int j = 0; j < 64; ++j){
			cout << mat[i][j];
		}
		cout << endl;
	}*/
	
	quick_mod(N);
	
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < 64;++i)
		tmp[getID(R,C)][i] = 1;
	
	

	//mul(mat, tmp, mat,64);

	/*for (int i = 0; i < 64; ++i){
		for (int j = 0; j < 64; ++j){
			cout << mat[i][j];
		}
		cout << endl;
	}
	*/

	long long ans = 0;
/*	int x, y;
	for (int k = 0; k < 8; ++k){
		x = R + dirs[k][0];
		y = C + dirs[k][1];
		if (IN(x, y)){
			ans = (ans + mat[getID(R,C)][getID(x,y)]) % mod;
		}
	}*/
	for (int i = 0; i < 64; ++i)
		ans = (ans + mat[i][getID(R, C)]) % mod;
	
	cout << ans << endl;

	return 0;
}