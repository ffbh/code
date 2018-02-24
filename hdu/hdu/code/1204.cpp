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
#include <cassert>
using namespace std;

ifstream in("C:\\input.txt");
//istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  

double dp[110][110];
bool vis[110][110];


int N, M;
double p, q;
double win, deal, fail;
double dfs(int a,int b){
	if (vis[a][b])
		return dp[a][b];
	vis[a][b] = 1;
	if (a == 0)
		return dp[a][b] = 0;

	if (b == 0){
		return dp[a][b] = 1;
	}
	if (fabs(deal - 1) < 1e-7){
		return dp[a][b] = 0;
	}

	double A = win*dfs(a+1 , b - 1) + fail*dfs(a - 1, b +1);
	return dp[a][b] = A / (1.0 - deal);
}

int main(){
	while (in >> N >> M >> p >> q){
		memset(vis, 0, sizeof(vis));
		win = p * (1 - q);
		fail = (1 - p)*q;
		deal = 1 - win - fail;

		printf("%.2f\n", dfs(N, M));
	}
	


	return 0;
}





