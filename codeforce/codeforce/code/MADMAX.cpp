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

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pic pair<int,char>
#define mp make_pair
#define pb push_back

int dp[110][110][30];

int n, m;
vector<pic> V[110];

void Init(){
	memset(dp, -1, sizeof(dp));


}

int dfs(int a,int b,char c){
	int& ref = dp[a][b][c - 'a'];
	if (ref != -1)
		return ref;
	ref = 0;
	for (pic p : V[a]){
		if (p.second >= c){
			if (dfs(b, p.first, p.second) == 0){
				ref = 1;
				break;
			}
		}
	}
	return ref;
}

void input(){
	in >> n >> m;
	for (int i = 1; i <= m; ++i){
		int u, v;
		char c;
		in >> u >> v >> c;
		V[u].push_back(mp(v, c));
	}
}


int main(){

	Init();
	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (dfs(i, j, 'a') == 1){
					putchar('A');
				}
				else{
					putchar('B');
				}
			}
			cout << endl;
		}











	}


	return 0;
}





