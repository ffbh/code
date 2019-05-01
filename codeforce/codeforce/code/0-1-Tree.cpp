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

inline pair<pii, pii> add_edge(pair<pii, pii> v ,int edge){ //01,10
	if (edge == 0){
		return mp(mp(0, 0), mp(v.second.first + v.first.second, v.second.second + 1));
	}
	else{
		return mp(mp(v.first.first + v.second.second, v.first.second + 1), mp(0, 0));
	}
}

pair<pii, pii> dfs(int p, pair<pii, pii> v, int f,int edge){

	pair<pii, pii> RET = mp(mp(0,0), mp(0, 0));
	for (pii son : V[p]){
		if (son.first == f){
			continue;
		}
		pair<pii, pii> ret;
		pair<pii, pii> vv = add_edge(v, son.second);
		if (son.second == 0){
			ans += 2;
			ans += v.second.second * 2;
			ans += v.second.first;
			ans += v.first.second;
			ret = dfs(son.first, vv, p, 0);
		}
		else{
			ans += 2;
			ans += v.first.second * 2;
			ans += v.first.first;
			ans += v.second.second;
			ret = dfs(son.first, vv, p, 1);
		}
		v.first.first += ret.first.first;
		v.first.second += ret.first.second;
		v.second.first += ret.second.first;
		v.second.second += ret.second.second;

		RET.first.first += ret.first.first;
		RET.first.second += ret.first.second;
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
		dfs(1, mp(mp(0,0),mp(0,0)), -1,0);

		cout << ans << endl;

	}


	return 0;
}





