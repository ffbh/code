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


int n;
char c[5010];
LL dp[5010][5010];
LL mod = 1e9 + 7;

vector<int> all;
void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> c[i];


}

void add(LL& a, LL p){
	a %= mod;
	p %= mod;
	a += p;
	a %= mod;
	if (a < 0)
		a += mod;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int pos = 1;
		while (pos <= n){
			int num = 0;
			while (pos <= n && c[pos] == 'f'){
				num++;
				pos++;
			}
			all.push_back(num);
			pos++;
		}
		dp[0][0] = 1;
		n = all.size();
		for (int i = 0; i < n; ++i){
			int v = all[i];
		
			LL sum = 0;
			for (int j = 5009 - v; j >= 0; --j){
				add(sum, dp[i][j]);
				
				add(dp[i + 1][j + v], sum);
			}
		}

		LL sum = 0;
		for (int j = 0; j < 5010; ++j)
			add(sum, dp[n][j]);

		cout << sum << endl;









	}


	return 0;
}





