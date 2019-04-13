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
int mark[300010];
vector<int> vi[300010];
int num[300010];
int K;

int dfs(int p, int l, int r){
	if (vi[p].size() == 0){
		assert(l == r);
		return l;
	}
	int ans = l;
	for (int son : vi[p]){
		int ret;
		if (mark[p] == 0){
			ret = dfs(son, l, l + num[son] - 1);
			ans = max(ans, ret);
		}
		else{
			ret = dfs(son, r - num[son] + 1, r);
			ans = max(ans, ret);
		}


	}
	return ans;

}

int pre_dfs(int p){
	if (vi[p].empty()){
		K++;
		num[p] = 1;
		return num[p];
	}
	num[p] = 0;
	for (int son : vi[p]){
		num[p] += pre_dfs(son);
	}
	return num[p];
}

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> mark[i];
	for (int i = 2; i <= n; ++i){
		int p;
		in >> p;
		vi[p].push_back(i);
	}
}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		K = 0;
		pre_dfs(1);


		cout << dfs(1, 1, num[1]) << endl;










	}


	return 0;
}





