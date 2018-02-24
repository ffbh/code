#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
#define EXP 1e-10

int n;
int x[2510], y[2510];
double dp[2][2510][2510];
bool vis[2][2510][2510];
double d[2510][2510];
double getdist(int i, int j){
	if (d[i][j] < EXP ){
		return d[j][i] = d[i][j] = sqrt((double(x[i] - x[j]))*(x[i] - x[j]) + (double(y[i] - y[j]))*(y[i] - y[j]));
	}
	else
		return d[i][j] ;
}

double dfs(int dir,int a, int b){
	if (vis[dir][a][b]){
		return dp[dir][a][b];
	}
	vis[dir][a][b] = 1;
	double& ref = dp[dir][a][b], di, tmp, l, r;
	ref = 0;
	if (dir == 0){
		if ((a + 1) % n == b)
			return 0;

		int k1 = (a + 1) % n;
		int k2 = (b - 1 + n) % n;

		if (k1 != b){
			di = getdist(a, k1);
			l = dfs(0, k1, b);
			r = dfs(1, k1, a);
			tmp = max(l, r) + di;
			if (ref < tmp)
				ref = tmp;
		}

		if (k2 != a){
			di = getdist(a, k2);
			l = dfs(0, k2, b);
			r = dfs(1, k2, a);
			tmp = max(l, r) + di;
			if (ref < tmp)
				ref = tmp;
		}
	}
	else{
		if ((a - 1 + n)% n == b)
			return 0;
		int k1 = (a - 1 + n) % n;
		int k2 = (b + 1) % n;
		if (k1 != b){
			di = getdist(a, k1);
			l = dfs(1, k1, b);
			r = dfs(0, k1, a);
			tmp = max(l, r) + di;
			if (ref < tmp)
				ref = tmp;
		}

		if (k2 != a){
			di = getdist(a, k2);
			l = dfs(1, k2, b);
			r = dfs(0, k2, a);
			tmp = max(l, r) + di;
			if (ref < tmp)
				ref = tmp;
		}






	}


	return ref;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n;
	for (int i = 0; i < n; ++i){
	//	in >> x[i] >> y[i];
		scanf("%d%d", &x[i], &y[i]);
		
	}


	double ans = 0;
	for (int i = 0; i < n; ++i){
		double ret = dfs(0,i, i);
		ans = max(ans, ret);
	}
	printf("%.10f\n", ans);














	return 0;
}


