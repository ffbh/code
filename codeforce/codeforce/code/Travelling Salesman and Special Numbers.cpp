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
#define mp make_pair
#define pb push_back

string B;
int k;

int P[1010];


int cale(int p){
	int ret = 0;
	for (int i = 0; i < 30; ++i){
		if (p&(1 << i))
			ret++;
	}
	return ret;
}

void Init(){
	P[0] = -9999;
	P[1] = 0;
	for (int i = 2; i < 1010; ++i){
		P[i] = P[cale(i)] + 1;
	}
}


void input(){
	in >> B >> k;


}

LL mod = 1e9 + 7;
LL dp[1010][1010][2];

LL dfs(int pos,int num,int f){
	LL& ref = dp[pos][num][f];
	if (ref != -1)
		return ref;
	if (pos == B.length()){
		return P[num] == k - 1;
	}
	ref = 0;
	if (f == 0){
		int M = B[pos] - '0';
		if (M == 0){
			ref += dfs(pos + 1, num, f);
			ref %= mod;
		}
		else{
			ref += dfs(pos + 1, num, 1);
			ref %= mod;
			ref += dfs(pos + 1, num + 1, 0);
			ref %= mod;
		}
	}
	else{
		ref += dfs(pos + 1, num, 1);
		ref %= mod;
		ref += dfs(pos + 1, num + 1, 1);
		ref %= mod;
	}
	return ref%mod;

}


int main(){
	Init();
	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		

		memset(dp, -1, sizeof(dp));

		LL ans = dfs(0, 0, 0);
		if (k == 0){
			cout << 1 << endl;
		}
		else if (k == 1){
			cout << (ans + mod - 1)%mod << endl;
		}
		else{
			cout << ans << endl;
		}











	}


	return 0;
}





