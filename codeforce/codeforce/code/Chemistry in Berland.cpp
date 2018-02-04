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

#define MMAX (int(1e5)+10)
int n;
LL a[MMAX], b[MMAX];
vector<pll> V[MMAX];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> b[i];
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	for (int i = 2; i <= n; ++i){
		LL x, k;
		in >> x >> k;
		V[x].push_back(make_pair(i, k));
	}
}


bool AAA;
pair<LL,bool> dfs(LL p,LL v){
	LL val = b[p] - a[p];
	for (pll son : V[p]){
		pair<LL, bool> ret = dfs(son.first, son.second);
		if (ret.second){
			val += ret.first;
		}
		else{
			val -= ret.first;
		}

		if (log10(abs(val)) > 17){
			if (val > 0){

			}
			else{
				AAA = 0;
			}
		}

	}

	if (val >= 0){
		return make_pair(val, 1);
	}
	else{
		if (log10(v) + log10(-val) > 17){
			AAA = 0;
		}

		return make_pair(-v*val, 0);
	}

}

int main(){



	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		AAA = 1;
		pair<LL, bool> ans = dfs(1,1);
		if (ans.second && AAA){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}





	}


	return 0;
}





