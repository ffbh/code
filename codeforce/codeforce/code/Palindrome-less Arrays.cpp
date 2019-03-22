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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


LL n, k;
LL a[200010];
LL mod = 998244353;

void input(){
	in >> n >> k;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
	}
}

bool judge(vector<int> A){
	for (int i = 0; i < A.size() - 1; ++i){
		if (A[i] != -1 && A[i] != -1 && A[i] == A[i + 1]){
			return 0;
		}
	}
	return 1;

}

void add(LL& a,LL b){
	a %= mod;
	b %= mod;
	a += b;
	a %= mod;
	if (a < 0){
		a += mod;
	}
}

LL dp[200010][2];
LL g(int S,int E,int len){
	//cout << S << " " << E << " " << len << endl;
	assert(len >= 1);
	LL ans = 1;
	if (S == -1 && E == -1){
		ans = k;
		for (int i = 2; i <= len; ++i){
			ans = ans * (k - 1) % mod;
		}
	}
	else if (S == -1 || E == -1){
		ans = k - 1;
		for (int i = 2; i <= len; ++i){
			ans = ans * (k - 1) % mod;
		}
	}
	else{
		for (int i = 0; i <= len; ++i){
			dp[i][0] = dp[i][1] = 0;
		}
		if (S == E){
			dp[0][1] = 1;
		}
		else{
			dp[0][0] = 1;
		}


		for (int i = 1; i <= len; ++i){
			add(dp[i][0], dp[i - 1][1] * (k - 1) % mod + dp[i - 1][0] * (k - 2) % mod);
			add(dp[i][1], dp[i - 1][0]);
		}
		ans = dp[len][0];
	}


	
	return ans;

}


LL cale(vector<int> A){
	LL ans = 1;
	int pos = -1;
	int size = A.size();
	while (pos + 1< size){
		pos++;
		while (pos < size && A[pos] != -1){
			pos++;
		}
		int st = pos;
		if (st >= size){
			break;
		}
		while (pos < size && A[pos] == -1){
			pos++;
		}
		pos--;
		int en = pos;
		int num = en - st + 1;
		int S = -1, E = -1;
		if (st > 0){
			S = A[st - 1];
		}
		if (en < size - 1){
			E = A[en + 1];
		}
		ans = ans * g(S, E, num) % mod;
	}
	return ans;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		vector<int> odd, even;
		for (int i = 1; i <= n; ++i){
			if (i % 2 == 0){
				even.push_back(a[i]);
			}
			else{
				odd.push_back(a[i]);
			}
		}

		
		LL ans = 1;
		if (!judge(odd) || !judge(even)){
			ans = 0;
		}
		else{
			ans = ans * cale(odd) % mod;
			ans = ans * cale(even) % mod;
		}
		cout << ans << endl;








	}


	return 0;
}





