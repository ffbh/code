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



int n, a[200010];
long long mod = (long long)1e9 + 7;
long long  fac[1000010];
long long cnt[1000010];
int  num[1000010];
long long ans;
long long cale_num[1000010];

long long cale(int p){
	if (p <= 0)
		return 0;
	return fac[p - 1] * p % mod;
}

bool rek[1000010];
pair<long long, int> D[1000010];
pair<long long, int> dfs(long long p){
	if (rek[p])
		return D[p];
	rek[p] = 1;
	if (p == 2){
		int t = 0;
	}

	pair<long long, int> ret;
	ret.first = 0;
	for (int i = 2; i < 1000010; ++i){
		long long v = p * i;
		if (v <= 1000000){
			//st[v] = i;
			pair<long long, int> tmp = dfs(v);

			ret.first = ((ret.first - tmp.first) % mod + mod) % mod;
		}
		else
			break;
	}
	if (p == 2){
		int t = 0;
	}
	if (cnt[p] > 0){
		//		long long d = cale(ret.second);
		ret.first = (ret.first + cale(cnt[p])) % mod;
	}





	if (p != 1)
		ans = (ans + ret.first * p%mod) % mod;
	//ret.first = cale(ret.second);
	return D[p] = ret;
}


void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
		if (a[i] != 1)
			num[a[i]]++;
	}
}


int main(){
	input();
	fac[0] = 1;
	for (int i = 1; i < 1000010; ++i){
		fac[i] = (fac[i - 1] * 2) % mod;
	}
	for (int i = 1; i < 1000010; ++i)
		cale_num[i] = cale(i);
	for (int i = 2; i < 1000010;++i)
	for (int j = i; j < 1000010; j += i){
		if (num[j])
			cnt[i] += num[j];
	}

	ans = 0;
	dfs(1);

	cout << ans << endl;















	return 0;
}
