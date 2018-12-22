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

int n;
LL V[300010];
vector<pll> vi[300010];

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> V[i];
	for (int i = 1; i < n; ++i){
		LL a, b, c;
		in >> a >> b >> c;
		vi[a].push_back(mp(b, c));
		vi[b].push_back(mp(a, c));
	}
}

LL ans;

LL dfs(int p,int f){
	ans = max(ans, V[p]);


	LL ret = 0;
	for (pii son : vi[p]){
		if (son.first == f)
			continue;
		LL r = dfs(son.first,p) - son.second;
		LL path = ret + r + V[p];
	    ans = max(ans, path);
		ret = max(ret, r);
	}
	ans = max(ans, ret + V[p]);
	return ret + V[p];
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		ans = 0;

		dfs(1,-1);
		cout << ans << endl;















	}


	return 0;
}





