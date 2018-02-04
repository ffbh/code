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


LL n, k;
LL mod = (LL)1e9 + 7;
LL qm(LL a,LL p){
	LL ans = 1;
	while (p){
		if (p & 1){
			ans = ans * a %mod;
		}
		a = a*a%mod;
		p /= 2;
	}
	return ans;
}
LL pw[2000010], sum[2000010], res[2000010];
bool mark[2000010];
void add(LL& a,LL b){
	a %= mod;
	b %= mod;
	a += b;
	a %= mod;
	if (a < 0)
		a += mod;
}

void input(){
	in >> n >> k;
}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= k; ++i){
			pw[i] = qm(i, n);
		
		}

	

		LL ans = 0;
		LL all = 0;
		res[1] = 1;
		for (int i = 2; i <= k; ++i){
			add(sum[i], 1);
			add(all, sum[i]);
			res[i] = pw[i];
			add(res[i], -all);
			
		//	cout << all << endl;
			add(ans, res[i]^i);
			for (int j = 2; i*j <= k; j++){
				add(sum[i*j], res[i] - res[i - 1]);
			}
		}
		cout << ans << endl;









	}


	return 0;
}





