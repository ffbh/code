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

int n, m;
int val[100010];
vector<int> vi[100010];

void input(){
	in >> n >> m;
	for (int i = 1; i <= n; ++i)
		in >> val[i];

	for (int i = 1; i <= m; ++i){
		int a, b;
		in >> a >> b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}


}
bool vis[100010];

/*LL dfs(int p){
	if (vis[p])
		return (1e9)+1;
	vis[p] = 1;
	int ret = val[p];
	for (int k : vi[p]){
		int r = dfs(k);
		ret = min(ret, r);
	}
	return ret;
}*/

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL ans = 0;
		for (int i = 1; i <= n; ++i){
			if (vis[i])
				continue;

			queue<int> qi;
			qi.push(i);
			int tmp = val[i];
			while (!qi.empty()){
				int u = qi.front();
				qi.pop();
				for (int v : vi[u]){
					if (!vis[v]){
						vis[v] = 1;
						if (tmp > val[v]){
							tmp = val[v];
						}
						qi.push(v);
					}
				}
			}
			ans += tmp;
		}
		cout << ans << endl;








	}


	return 0;
}





