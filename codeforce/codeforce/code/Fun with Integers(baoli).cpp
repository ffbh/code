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



set<pii> sp;

void input(){



}

bool judge(int a,int b){
	pii k1 = mp(a, b);
	pii k2 = mp(b, a);
	a = abs(a);
	b = abs(b);
	if (a > b){
		swap(a, b);
	}

	return b % a == 0 && b / a > 1 && !sp.count(k1) && !sp.count(k2);
}

int get(int a, int b){
	a = abs(a);
	b = abs(b);
	if (a > b){
		swap(a, b);
	}
	return b / a;
}

vector<int> pace;
vector<int> ans;
int mmax = 0;
vector<int> kkk = { 2, 4,8};
void dfs(int p,int val){
	if (val > mmax){
		mmax = val;
		ans = pace;
	}

	for (int k : kkk){
		if (judge(p, k)){
			sp.insert(mp(p, k));
			sp.insert(mp(k, p));
			pace.push_back(k);
			dfs(k, val + get(p, k));
			pace.pop_back();
			sp.erase(mp(p, k));
			sp.erase(mp(k, p));
		}
		if (judge(p, -k)){
			sp.insert(mp(p, -k));
			sp.insert(mp(-k, p));
			pace.push_back(-k);
			dfs(-k, val + get(p, -k));
			pace.pop_back();
			sp.erase(mp(p, -k));
			sp.erase(mp(-k, p));
		}
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		for (int i = 2; i <= 2; ++i){
			pace.push_back(i);
			dfs(i, 0);
			pace.pop_back();
		}
		for (int p : ans){
			cout << p << " ";
		}
		cout << endl;
		cout << mmax << endl;











	}


	return 0;
}





