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
#define lson (root<<1)  
#define rson (root<<1|1)  


LL N;
unordered_map<LL, LL> M;
int ans[10] = { 0, 0, 0, 0, 1, 1, 1, 1, 2, 3 };
LL dfs(LL p){
	if (M.count(p))
		return M[p];
	if (p < 10){
		return M[p] = ans[p];
	}
	LL ret = 0;
	for (int i = 2; i < 63; ++i){
		LL s = pow(p, 1.0 / i);
		ret += s - 1;
		ret -= dfs(s);
	}
	return ret;
}

int main(){

	while (in >> N){

		printf("%lld\n", dfs(N) + 1);
	}


	return 0;
}





