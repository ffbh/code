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
#define pcc pair<char,char>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  

bool mmp[30][30];
bool src[30][30];
bool des[30][30];
int n;
string s1, s2;
void input(){
	in >> n;
	in >> s1 >> s2;
}

bool mark[30], vis[30];
int f[30], deg[30];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

bool stack[30], vvv[30];
bool cycle(int p){
	if (stack[p])
		return 1;
	if (vis[p])
		return 0;
	vis[p] = 1;
	stack[p] = 1;
	for (int i = 0; i < 30;++i)
	if (i!=p&&mmp[p][i]){
		if (cycle(i))
			return 1;
	}
	stack[p] = 0;
	return 0;
}

vector<pcc> temp;
bool vvvv[30];
void dfs(int p){
	if (vvvv[p])
		return;
	vvvv[p] = 1;
	for (int i = 0; i < 30;++i)
	if (i!=p&&mmp[p][i]){
		dfs(i);
		bool ok = 1;
		for (int j = 0; j < 30; ++j){
			if (j!=i&&mmp[p][j]&&mmp[j][i]){
				ok = 0;
				break;
			}
		}
		if (ok){
			temp.push_back(mp('a' + p, 'a' + i));
		}
	}

}

vector<pcc> cale(int p){
	vector<int> v, root;
	for (int i = 0; i < 30; ++i){
		if (find(i) == p){
			if (deg[i] == 0){
				root.push_back(i);
			}
			v.push_back(i);
		}
	}
	assert(v.size()>1);
	vector<pcc> all;
	if (root.size() == 0){
		for (int i = 0; i < v.size()-1; ++i){
			all.push_back(mp('a' + v[i], 'a' + v[(i + 1) % v.size()]));
		}
	}

	else{
		bool kkk = 0;
		for (int p : root){
			memset(stack, 0, sizeof(stack));
			if (cycle(p)){
				kkk = 1;
				for (int i = 0; i < v.size()-1; ++i){
					all.push_back(mp('a' + v[i], 'a' + v[(i + 1) % v.size()]));
				}
				break;
			}
		}	
		memset(vvvv, 0, sizeof(vvvv));
		if (kkk == 0){
			for (int p : root){
				temp.clear();
			
				dfs(p);
				for (pcc kk : temp)
					all.push_back(kk);

			}

		}


	}
	assert(all.size() <= v.size());
	return all;


}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		memset(mmp, 0, sizeof(mmp));
		for (int i = 0; i < n; ++i){
			int a = s1[i] - 'a';
			int b = s2[i] - 'a';
		
			if (a != b){
				mmp[a][b] = 1;
				mark[a] = mark[b] = 1;
			}
		}

		for (int i = 0; i < 30; ++i)
			mmp[i][i] = 0;
		
		for (int k = 0; k < 30;++k)
		for (int i = 0; i < 30;++i)
		for (int j = 0; j < 30;++j)
		if (i != k&&i != j&&j != k&&mmp[i][k] && mmp[k][j])
			mmp[i][j] = 1;

		for (int i = 0; i < 30; ++i)
			mmp[i][i] = 0;

		for (int i = 0; i < 30;++i)
		for (int j = 0; j < 30; ++j){
			if (i != j&&mmp[i][j]){
				deg[j]++;
			}
		}

		for (int i = 0; i < 30; ++i)
			f[i] = i;

		for (int i = 0; i < 30;++i)
		for (int j = 0; j < 30; ++j){
			if (i!=j&&mmp[i][j]){
				int fa = find(i);
				int fb = find(j);
				if (fa != fb)
					f[max(fa, fb)] = min(fa, fb);
			}
		}
		
		//mark
		vector<pcc> ans;
		for (int i = 0; i < 30; ++i){
			if (mark[i] && find(i) == i){
				vector<pcc> nn = cale(i);
				for (pcc p : nn)
					ans.push_back(p);
			}

		}

		cout << ans.size() << endl;
		for (pcc p : ans)
			cout << p.first << " " << p.second << endl;

	}


	return 0;
}





