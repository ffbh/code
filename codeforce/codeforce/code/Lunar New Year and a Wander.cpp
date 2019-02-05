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

int n, m;
vector<int> vi[100010];

void input(){
	in >> n >> m;
	for (int i = 1; i <= m; ++i){
		int a, b;
		in >> a >> b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}

}

bool vis[100010];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		set<int> S;
		S.insert(1);
		vis[1] = 1;
		while (!S.empty()){
			int u = *S.begin();
			S.erase(S.begin());
			printf("%d ", u);
			for (int v : vi[u]){
				if (!vis[v]){
					vis[v] = 1;
					S.insert(v);
				}
			}
		}

	}


	return 0;
}





