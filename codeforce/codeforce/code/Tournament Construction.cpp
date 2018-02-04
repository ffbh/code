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

int n, a[50];


void input(){
	in >> n;
	for (int i = 0; i < n; ++i)
		in >> a[i];

}
#define MAXN (70)
int ansnum;

vector<int> ans;


int dp[MAXN][MAXN][MAXN*MAXN], pace[MAXN][MAXN][MAXN*MAXN];

int  dfs(int pos, int num, int sum){
	if (sum > ansnum*(ansnum - 1) / 2)
		return 0;
	int& ref = dp[pos][num][sum];
	if (ref != -1)
		return ref;
	ref = 0;
	if (pos==n || num==ansnum){
		return ref = (sum == ansnum*(ansnum - 1) / 2 && pos == n &&num == ansnum);
	}
	

	for (int k = 1;k<=ansnum-num; ++k){
		if (sum + k * a[pos] >= (num + k)*(num + k - 1) / 2){
			pace[pos][num][sum] = k;
			if (dfs(pos + 1, num + k, sum + k*a[pos])){
				ref = 1;
				break;
			}
		}
		else
			break;
	}
	return ref;
}

bool cale(){
	

	for (ansnum = n; ansnum < MAXN; ++ansnum){


		memset(dp, -1, sizeof(dp));
		if (ansnum == 4){
			int t = 0;
		}

		if (dfs(0,0,0)){
			ans.clear();
			int p1, p2, p3;
			p1 = p2 = p3 = 0;
			while (p1 != n){
				int num = pace[p1][p2][p3];
				for (int k = 1; k <= num;++k){
					ans.push_back(a[p1]);
				}
			
				p2 += num;
				p3 += num*a[p1];
				p1++;
			}
			return 1;
		}

		
	}
	return 0;
}

int g[MAXN][MAXN];

bool cmp(pii a,pii b){
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second < b.second;
}

bool vis[70];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(a, a + n);

		if (cale()){
			memset(g, -1, sizeof(g));
			vector<pii > V, P;
			for (int i = 1; i <= ansnum; ++i)
				g[i][i] = 0;

			assert(ansnum == ans.size());

			for (int i = 0; i < ansnum; ++i){
				V.push_back(mp(ansnum - 1 - ans[i], i + 1));
				P.push_back(mp(ans[i], i + 1));
			}
			
			while(!P.empty()){
				sort(P.begin(), P.end(),cmp);
				pii top = P.back();
				P.pop_back();
				sort(V.begin(), V.end());
				for (int i = (int)V.size() - 1; i >= 0 && top.first > 0; --i){
					int p1 = top.second;
					int p2 = V[i].second;
					if (g[top.second][V[i].second] != -1 || vis[V[i].second])
						continue;
					g[top.second][V[i].second] = 1;
					g[V[i].second][top.second] = 0;
					V[i].first--;
					top.first--;
				}
				for (int i = 1; i <= ansnum; ++i){
					if (g[top.second][i] == -1){
						g[top.second][i] = 0;
						g[i][top.second] = 1;
						for (pii & p : P){
							if (p.second == i){
								p.first--;
								break;
							}
						}
					}

				}

				vis[top.second] = 1;

				/*		cout << endl;
				for (int i = 1; i <= ansnum; ++i){
				for (int j = 1; j <= ansnum; ++j){
				printf("%d", g[i][j]);
				}
				putchar('\n');
				}
				cout << endl;*/

			}

			cout << ansnum << endl;
			for (int i = 1; i <= ansnum; ++i){
				for (int j = 1; j <= ansnum; ++j){
					printf("%d", g[i][j]);
				}
				putchar('\n');
			}


		}
		else{
			cout << "=(" << endl;
		}











	}


	return 0;
}
