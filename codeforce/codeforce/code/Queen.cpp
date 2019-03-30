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
vector<int> vi[100010];
int root;
int c[100010];
void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		int p;
		in >> p >> c[i];
		if (p == -1){
			root = i;
		}
		else{
			vi[p].push_back(i);
		}
	}
}


set<int> S;

bool dfs(int p){
	if (vi[p].size() == 0){
		if (c[p]){
			S.insert(p);
		}
		return c[p];
	}

	bool ok = c[p];
	for (int son : vi[p]){
		bool s = dfs(son);
		if (!s)
			ok = 0;
	}
	if (ok){
		S.insert(p);
	}
	return c[p];

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		dfs(root);

		for (int k : S){
			cout << k << " ";
		}
		if (S.empty()){
			cout << "-1";
		}
		cout << endl;











	}


	return 0;
}





