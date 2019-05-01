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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

void _init(){



}

int n;
vector<pii> V[200010];

void input(){
	in >> n;
	for (int i = 1; i < n; ++i){
		int a, b, c;
		in >> a >> b >> c;
		V[a].push_back(mp(b, c));
		V[b].push_back(mp(a, c));
	}
}

LL ans;

inline pair<int, pii> add_edge(pair<int, pii> v ,int edge){
	if (edge == 0){
		return mp(v.first + 1, mp(0, 0));
	}
	else{
		return mp(0, mp(v.first + v.second.first, v.second.second + 1));
	}
}

pair<int, pii> dfs(int p, pair<int, pii> v, int f,int edge){

	pair<int, pii> RET = mp(0, mp(0, 0));
	for (pii son : V[p]){
		if (son.first == f){
			continue;
		}
		pair<int, pii> ret;
		pair<int, pii> vv = add_edge(v, son.second);
		if (son.second == 0){
			ans += v.second.second;
			ans += (LL)2 * v.first;
			ans += 2;
			ret = dfs(son.first, vv, p, 0);
		}
		else{
			ans += v.first;
			ans += v.second.first;
			ans += (LL)2 * v.second.second;
			ans += 2;
			ret = dfs(son.first, vv, p, 1);
		}
		v.first += ret.first;
		v.second.first += ret.second.first;
		v.second.second += ret.second.second;

		RET.first += ret.first;
		RET.second.first += ret.second.first;
		RET.second.second += ret.second.second;
	}
	
	if (edge == 0){
		return add_edge(RET, 0);
	}
	else{
		return add_edge(RET, 1);
	}

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		ans = 0;
		dfs(1, mp(0,mp(0,0)), -1,0);

		cout << ans << endl;

	}


	return 0;
}





