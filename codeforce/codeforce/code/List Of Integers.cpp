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


vector<int> V[1000010];

int x, p, k;


void input(){
	in >> x >> p >> k;


}

LL ret;

void dfs(vector<int>& P, int pos, LL pre, LL X,int f){
	if (pre > X)
		return;


	if (pos == P.size()){
		ret += f * X / pre;
	}
	else{
		dfs(P, pos + 1, pre, X, f);
		dfs(P, pos + 1, pre *P[pos], X, -f);
	}
}


int cale(vector<int> P,int X){
	ret = X;
	dfs(P, 0, 1, X, -1);
	return ret;
}


bool judge(int N,vector<int> v){
	for (int ss : v){
		if (N % ss == 0)
			return 0;
	}
	return 1;

}

//#define MMAX (100)
#define MMAX (1000010)
//////// xiugggggggggg

int main(){
	for (int i = 2; i<MMAX; ++i){
		if (V[i].empty()){
			for (int j = i; j < MMAX; j += i)
				V[j].push_back(i);
		}
	}
	

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int L = x + 1, R = 1e7, ans = -1;
		int PN = cale(V[p], x);

	

		while (L <= R){
			int mid = (L + R) / 2;
			int PPN = cale(V[p], mid);
			int nowk = mid - x - (PPN - PN);
			if (nowk <= k){
				L = mid + 1;
				ans = mid;
			}
			else{
				R = mid - 1;
			}
		}

		while (!judge(ans, V[p]))
			ans--;

		printf("%d\n", ans);

	}


	return 0;
}





