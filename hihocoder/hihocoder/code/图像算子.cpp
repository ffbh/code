#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
const double ep = 1e-8;
int H, W, D;
double A[61][61], B[61][61];
double g[4000][30], b[4000];
bool vis[4000];

void init(){
	int  x = 0, y;
	for (int i = 0; i < H - D + 1;++i)
	for (int j = 0; j < W - D + 1; ++j){
		b[++x] = B[i][j];
	}
	x = 1;
	for (int i = 0; i < H - D + 1;++i)
	for (int j = 0; j < W - D + 1; ++j){
		y = 1;
		for (int a = i; a < i + D;++a)
		for (int b = j; b < j + D; ++b)
			g[x][y++] = A[a][b];
		x++;
	}
}

void _swap(int _a, int _b){
	for (int i = 1; i <= D*D; ++i)
		swap(g[_a][i], g[_b][i]);
	swap(b[_a], b[_b]);
}

void gauss(){
	/*for (int i = 1; i <= D*D; ++i){
		for (int j = 1; j <= D*D; ++j)
			cout << round(g[i][j]) << " ";
		cout << endl;
	}
	cout << endl;*/
/*	for (int i = 1; i <= D*D; ++i){
		for (int j = 1; j <= D*D; ++j){
			if (i == j)
				continue;
			double p = -g[j][i] / g[i][i];
			for (int k = 1; k <= D*D; ++k)
				g[j][k] += g[i][k] * p;
			b[j] += b[i] * p;
		}
	}*/
	int index = 1;
	int N = (H - D + 1)*(W - D + 1);
	for (int i = 1; i <= N; ++i){
		int mmax = i;
		for(int j=i+1;j<=N;++j)
		if (fabs(g[j][index]) > g[mmax][index])
			mmax = j;
		if (i != mmax)
			_swap(i, mmax);
		if (fabs(g[i][index]) < ep){
			vis[i] = 1;
			//cout << i << endl;
			continue;
		}
		for (int j = 1; j <= N; ++j){
			if (vis[j] || i == j)
				continue;
			double p = -g[j][index] / g[i][index];
			for (int k = 1; k <= D*D; ++k)
				g[j][k] += g[i][k] * p;
			b[j] += b[i] * p;
		}
		index++;
		if (index > D*D)
			break;
	}

/*	for (int i = 1; i <= D*D; ++i){
		for (int j = 1; j <= D*D; ++j)
			cout << round(g[i][j]) << " ";
		cout << endl;
	}*/

//	for (int i = 1; i <= D*D; ++i)///////
//		ans[i] = b[i] / g[i][i] ;
	index = 0;
	for (int i = 1; i <= N; ++i){//////
		if (vis[i])
			continue;
		index++;
		if (fabs(b[i] / g[i][index]) < ep)
			putchar('0');
		else
			printf("%.0f", b[i] / g[i][index]);
		if (index%D == 0)
			putchar('\n');
		else
			putchar(' ');
		if (index == D*D)
			break;
	}

}




int main(){
	ifstream in("C:\\input.txt");
	cin >> H >> W >> D;
	for (int i = 0; i < H;++i)
	for (int j = 0; j < W; ++j)
		cin >> A[i][j];
	for (int i = 0; i < H - D + 1; ++i)
	for (int j = 0; j < W - D + 1; ++j)
		cin >> B[i][j];
	init();
	gauss();


	return 0;
}