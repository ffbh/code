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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;
#define INF ((int)1e9+10)
int n, m;
vector<pii> vi[110];
pii ans;


void update(pii tmp){
	if (ans.first < tmp.first){
		ans = tmp;
	}
	else if (ans.first == tmp.first)
		ans.second += tmp.second;
}

void Init(){
	for (int i = 0; i < 110; ++i)
		vi[i].clear();
	ans.first = ans.second = 0;

}


void input(){
	
}

pii d[110];
bool vis[110];
pii spfa(int s){
	for (int i = 0; i < 110; ++i){
		d[i].first = INF;
		d[i].second = 0;
	}
	memset(vis, 0, sizeof(vis));
	d[s].first = 0;
	d[s].second = 1;
	for (int k = 1; k < n; ++k){
		int pos = -1, mmin = INF;
		for (int i = 1; i <= n; ++i){
			if (vis[i])
				continue;

			if (d[i].first < mmin){
				mmin = d[i].first;
				pos = i;
			}

		}
		vis[pos] = 1;
		for (pii & p : vi[pos]){
			if (d[p.first].first > d[pos].first + p.second){
				d[p.first].first = d[pos].first + p.second;
				d[p.first].second = d[pos].second;
			}
			else if (d[p.first].first == d[pos].first + p.second){
				d[p.first].second += d[pos].second;
			}
		}

		

	}

	

	pii ret(0, 0);
	for (int i = 1; i <= n; ++i){
		if (d[i].first < ret.first){

		}
		else if (d[i].first == ret.first){
			ret.second += d[i].second;
		}
		else{
			ret.first = d[i].first;
			ret.second = d[i].second;
		}


	}
	return ret;

}

int main(){
	

	while (in >> n >> m){
		Init();
		while (m-->0){
			int a, b, c;
		//	in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			vi[a].pb(mp(b, c));
			vi[b].pb(mp(a, c));
		}

		for (int i = 1; i <= n; ++i){
			update(spfa(i));
		}


	//	cout << ans.first << " " << ans.second / 2 << endl;
		printf("%d %d\n", ans.first, ans.second / 2);
	}

	


	return 0;
}





