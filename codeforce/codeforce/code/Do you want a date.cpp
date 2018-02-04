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

LL mod = 1e9 + 7;

int n;
LL a[300010];
LL p[300010];

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(a + 1, a + n + 1);

		p[0] = 1;
		for (int i = 1; i < 300010; ++i)
			p[i] = p[i - 1] * 2 % mod;

		LL ans = 0;
		for (int i = 1; i <= n; ++i){
			LL sub = ((p[n - i] - 1 + mod) % mod*a[i] % mod + mod) % mod;
			LL add = ((p[i - 1] - 1 + mod) % mod*a[i] % mod + mod) % mod;
			ans = ((ans + add - sub) % mod + mod) % mod;
		}

		cout << ans << endl;










	}


	return 0;
}





