#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
const int MMAX = 510;
struct Point{
	int x, y;
}data[MMAX];
int x[MMAX], y[MMAX], lx, ly;
int mmaxx, mmaxy;
int hash_X[10010], hash_Y[10010];
int dp[MMAX][MMAX];
//int dp_X[10010], dp_Y[10010];
struct Line{
	int a, b;
	Line(int a, int b){
		this->a = a;
		this->b = b;
	}
};
vector<Line> vy[10010];
vector<Line> vx[10010];
int C, N;

int funX(){
	for (int ans = 0; ans < 10010; ++ans){
		for (int i = 0;i< vx[ans].size(); ++i){
			int x1 = hash_X[vx[ans][i].a];
			int x2 = hash_X[vx[ans][i].b];
		/*	for (int j = 0;j< vy[ans].size(); ++j){
				int y1 = hash_Y[vy[ans][j].a];
				int y2 = hash_Y[vy[ans][j].b];
				if (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1] >= C)
					return ans;
			}*/
			for (int j = 0; j < ly; ++j)
			{
				//int p = lower_bound(y, y + ly, y[j] + ans) - y;
				int y1 = hash_Y[y[j]];
				int p = y[j] + ans;
				if (p > mmaxy)
					p = mmaxy;
				int y2 = hash_Y[p];
				if (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1] >= C)
						return ans;
			}

		}
	}
	return -1;
}

int funY(){
	for (int ans = 0; ans < 10010; ++ans){
		for (int i = 0; i< vy[ans].size(); ++i){
			int y1 = hash_Y[vy[ans][i].a];
			int y2 = hash_Y[vy[ans][i].b];
			/*	for (int j = 0;j< vy[ans].size(); ++j){
			int y1 = hash_Y[vy[ans][j].a];
			int y2 = hash_Y[vy[ans][j].b];
			if (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1] >= C)
			return ans;
			}*/
			for (int j = 0; j < lx; ++j)
			{
				//int p = lower_bound(y, y + ly, y[j] + ans) - y;
				int x1 = hash_X[x[j]];
				int p = x[j] + ans;
				if (p > mmaxx)
					p = mmaxx;
				int x2 = hash_X[p];
				if (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1] >= C)
					return ans;
			}

		}
	}
	return -1;
}

int minx, miny, maxx, maxy;

bool ok(int len){
	for (int i = 0; i < lx;++i)
	for (int j = 0; j < ly; ++j){
		int x1 = hash_X[x[i]];
		int y1 = hash_Y[y[j]];
		int p = x[i] + len;
		if (p > mmaxx)
			p = mmaxx;
		int x2 = hash_X[p];
		p = y[j] + len;
		if (p > mmaxy)
			p = mmaxy;
		int y2 = hash_Y[p];
		if (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1] >= C)
			return 1;

	}
	return 0;
}

int main(){
	ifstream in("C:\\input.txt");
	
	cin >> C >> N;
	for (int i = 0; i < N; ++i){
	//	in >> data[i].x >> data[i].y;
		scanf("%d%d", &data[i].x, &data[i].y);
		
		x[i] = data[i].x;
		y[i] = data[i].y;
	}
	lx = ly = N;
	sort(x, x + lx);
	sort(y, y + ly);
	lx = unique(x, x + lx) - x;
	ly = unique(y, y + ly) - y;
	mmaxx = x[lx - 1];
	mmaxy = y[ly - 1];
	x[lx] = mmaxx;
	y[ly] = mmaxy;

	for (int i = 0; i < lx; ++i){
	//	hash_X[x[i]] = i + 1;
		for (int j = x[i]; j <= x[i + 1];++j)
			hash_X[j] = i + 1;
	}
	for (int i = 0; i < ly; ++i){
	//	hash_Y[y[i]] = i + 1;
		for (int j = y[i]; j <= y[i + 1]; ++j)
			hash_Y[j] = i + 1;
	}
	for (int i = 0; i < N; ++i){
		dp[hash_X[data[i].x]][hash_Y[data[i].y]]++;
	}
	for (int i = 1; i <= lx;++i)
	for (int j = 1; j <= ly; ++j){
		dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
	}


	/*for (int i = 0; i < ly;++i)
	for (int j = i; j < ly; ++j){
		vy[y[j] - y[i]].push_back(Line(y[i], y[j]));
	}
	for (int i = 0; i < lx;++i)
	for (int j = i; j < lx; ++j){
		vx[x[j] - x[i]].push_back(Line(x[i], x[j]));
	}
	int ansx = funX();
	int ansy = funY();
	if (ansx == -1)
		cout << ansy + 1 << endl;
	else if (ansy == -1)
		cout << ansx + 1 << endl;
	else
		cout << min(ansx, ansy) + 1 << endl;*/
	minx = x[0];
	miny = y[0];
	maxx = x[lx - 1];
	maxy = y[ly - 1];
	int L = 0;
	int R = max(maxx - minx, maxy - miny);
	int m, ans;
	while (L <= R){
		m = (L + R) / 2;
		if (ok(m)){
			ans = m;
			R = m - 1;;
		}
		else{
			L = m + 1;
		}
	}
	cout << ans + 1<< endl;
	return 0;
}