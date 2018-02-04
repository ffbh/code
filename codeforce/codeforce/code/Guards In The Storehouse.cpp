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
#define pii pair<int,int>
#define mp make_pair

const long long mod = 1e9 + 7;

int n, m;
char mmp[310][310];
long long dp[2][2][(1<<16)+10];

void rarote(){
	if (n > m)
		return;
	char tmp[310][310];
	for (int i = 0; i < n;++i)
	for (int j = 0; j < m; ++j)
		tmp[j][i] = mmp[i][j];
	swap(n, m);
	for (int i = 0; i < n;++i)
	for (int j = 0; j < m; ++j)
		mmp[i][j] = tmp[i][j];

}



void input(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	in >> n >> m;
	for (int i = 0; i < n; ++i)
		in >> mmp[i];

}



void add(long long& a,long long b){
	a %= mod;
	b %= mod;
	a = (a + b) % mod;
}

int test(int pos,int key){
	int empty = 0;
	for (int i = 0; i < m; ++i){
		if (mmp[pos][i] == 'x'){
			if (key & (1 << i))
				return 99999;
		}
		else{
			if (!(key & (1 << i))){
				empty++;
			}

		}
	}
	return empty;
}

int main(){
	input();
	rarote();

	int MAXN = (1 << m);
	for (int i = 0; i < MAXN; ++i){
		int num = test(0, i);
		if (num >= 2){
			continue;
		}
		dp[0][num][i] = 1;
	}

	for (int i = 1; i < n; ++i){
		int cur = i % 2;
		int pre = 1 - cur;
		memset(dp[cur], 0, sizeof(dp[cur]));





	}




	return 0;
}





