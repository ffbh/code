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
long long n, a[310];
long long fac[310], rev[310];
bool mmp[310][310];
long long mod = (long long)1e9 + 7;

long long qmod(long long a,long long p){
	long long ret = 1;
	while (p){
		if (p & 1)
			ret = (ret*a) % mod;
		a = (a*a) % mod;
		p /= 2;
	}
	return ret;
}


void Init(){
	fac[0] = 1;
	for (int i = 1; i < 310; ++i)
		fac[i] = fac[i - 1] * i;

	rev[0] = 1;
	for (int i = 1; i < 310; ++i)
		rev[i] = qmod(fac[i], mod - 2);


}

long long C(int n, int m){
	return fac[n] * rev[m] % mod*rev[n - m] % mod;

}


bool isSqure(long long q){
	long long sq = (long long)sqrt(q);
	return sq*sq == q;

}



void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];



}
bool vis[310];
int dfs(int p){
	if (vis[p])
		return 0;
	vis[p] = 1;
	int ret = 1;
	for (int i = 1; i <= n; ++i){
		if (mmp[p][i]){
			ret += dfs(i);
		}
	}
	return ret;
}

int num[310];
long long dp[310][310][310];
bool END[310];
void add(long long& a, long long b){
	a %= mod;
	b %= mod;
	a = (a + b) % mod;
}

int main(){
	input();
	Init();

	for (int i = 1; i <= n; ++i)
	for (int j = i + 1; j <= n; ++j){
		if (isSqure(a[i] * a[j])){
			mmp[i][j] = mmp[j][i] = 1;
		}
	}

	vector<int> block;

	for (int i = 1; i <= n; ++i){
		int ret = dfs(i);
		if (ret)
			block.push_back(ret);

	}

	sort(block.begin(), block.end());
	reverse(block.begin(), block.end());
	int sum = 0;
	for (int p : block){
		for (int i = 1; i <= p; ++i)
			num[sum + i] = i;
		sum += p;
		END[sum] = 1;
	}


	dp[0][0][0] = 1;
	for (int i = 1; i <= n;++i)
	for (int j = 0; j <= n+1; ++j)
	for (int k = 0; k <= n+1; ++k){
		long long& ref = dp[i - 1][j][k];
		if (dp[i-1][j][k] == 0)
			continue;
		int allslot = i;
		int prewa = j - k;
		int nowwa = k;
		int nookwaslot = (num[i]-1)*2 -2* nowwa;
		
		int okslot = allslot - j - nookwaslot;
		
		
		

		if (!END[i]){
			if (j > 0)
				add(dp[i][j - 1][k], dp[i - 1][j][k] * prewa);
			add(dp[i][j + 1][k + 1], dp[i - 1][j][k] * nowwa);
			add(dp[i][j][k], dp[i - 1][j][k] * okslot);
			add(dp[i][j + 1][k + 1], dp[i - 1][j][k] * nookwaslot);
		}
		else{
			if (j > 0)
				add(dp[i][j - 1][0], dp[i - 1][j][k] * prewa);
			add(dp[i][j + 1][0], dp[i - 1][j][k] * nowwa);
			add(dp[i][j][0], dp[i - 1][j][k] * okslot);
			add(dp[i][j + 1][0], dp[i - 1][j][k] * nookwaslot);

		}
	}


	cout << dp[n][0][0] << endl;



	return 0;
}





