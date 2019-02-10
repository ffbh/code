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


bool vis[50];
bool mmp[50][50];
unordered_map<string, int> M;
int n, m, size = 1;



int getID(string s){
	if (M.count(s)){
		return M[s];
	}
	else{
		M[s] = size++;
		return size - 1;
	}
}


void input(){
	in >> n >> m;


}

int ans;
int mark[50];

void dfs(int p,int val){

	ans = max(ans, val);



	if (p > m || m - p + 1 + val <= ans){
		return;
	}
	if (mark[p]){
		dfs(p + 1,val);
	}
	else{
		for (int k = p + 1; k <= m; ++k){
			if (mmp[p][k]){
				mark[k]++;
			}
		}

		dfs(p + 1, val + 1);

		for (int k = p + 1; k <= m; ++k){
			if (mmp[p][k]){
				mark[k]--;
			}
		}

		dfs(p + 1, val);
	}

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		while (n-- > 0){
			int type;
			in >> type;
			if (type == 1){
				vector<int> V;
				for (int i = 1; i <= m; ++i){
					if (vis[i])
						V.push_back(i);
				}
				for (int a : V){
					for (int b : V){
						if (a != b){
							mmp[a][b] = 1;
						}
					}
				}
				memset(vis, 0, sizeof(vis));
			}
			else{
				string ss;
				in >> ss;
				int id = getID(ss);
				vis[id] = 1;
			}
		}
		vector<int> V;
		for (int i = 1; i <= m; ++i){
			if (vis[i])
				V.push_back(i);
		}
		for (int a : V){
			for (int b : V){
				if (a != b){
					mmp[a][b] = 1;
				}
			}
		}
		memset(vis, 0, sizeof(vis));

		dfs(1, 0);
		cout << ans << endl;

			

	}


	return 0;
}





