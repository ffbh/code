#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long x, y, k;
long double  mat[2][2];
long double a1, b1, a2, b2, ak, bk, fx, fy;

void InitM(){
	mat[0][0] = mat[0][1] = mat[1][0] = 1;
	mat[1][1] = 0;
}

void mul(long double a[2][2], long double b[2][2], long double ans[2][2]){
	long double tmp[2][2];
	for (int i = 0; i < 2;++i)
	for (int j = 0; j < 2; ++j){
		tmp[i][j] = 0;
		for (int k = 0; k < 2; ++k)
			tmp[i][j] += a[i][k] * b[k][j];
	}
	memcpy(ans, tmp, sizeof(tmp));
}

void qm(int p){
	InitM();
	long double ret[2][2];
	memset(ret, 0, sizeof(ret));
	for (int i = 0; i < 2; ++i)
		ret[i][i] = 1;
	while (p){
		if (p & 1){
			mul(ret, mat, ret);
		}
		mul(mat, mat, mat);
		p /= 2;
	}
	memcpy(mat, ret, sizeof(mat));
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> x >> fx >> y >> fy >> k){
		long long mmax = 0;
		if (x < 2){
			mmax = max(2 - x, mmax);
		}
		if (y < 2){
			mmax = max(2 - y, mmax);
		}
		if (k < 2){
			mmax = max(2 - k, mmax);
		}
		x += mmax;
		y += mmax;
		k += mmax;
		qm(x - 1);
		a1 = mat[0][0];//fi
		b1 = mat[1][0];//fi-1
		qm(y - 1);
		a2 = mat[0][0];
		b2 = mat[1][0];
		qm(k - 1);
		ak = mat[0][0];
		bk = mat[1][0];
		long double ab = a1*b2 - a2*b1;
		long double fxy = b2*fx - b1*fy;
		long double ansx = fxy / ab;
		long double ansy = (fx - a1*ansx) / b1;
	//	cout << ak*ansx + bk*ansy << endl;
		printf("%.0lf\n", ak*ansx + bk*ansy);


	}
	return 0;
}