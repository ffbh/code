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

void input(){

	in >> n;

}

vector<int> vi[100010];
vector<int> vb[100010];
bool vis[100010];

int main(){


	

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		for (int i = 2; i<=n; ++i){
			for (int j = i+i; j<=n; j += i){
				vi[i].push_back(j);
				vi[j].push_back(i);
				vb[i].push_back(j);
			}
		}
		queue<int> Q;
		Q.push(2);
		vis[2] = 1;
		while (!Q.empty()){
			int u = Q.front();
			Q.pop();
			for (int v : vi[u]){
				if (!vis[v]){
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
		LL ans = 0;
		for (int k = 2; k <= n; ++k){
			if (vis[k]){
				for (int v : vb[k]){
					ans += v / k * 4L;
				}
			}
		}

		cout << ans << endl;












	}


	return 0;
}





