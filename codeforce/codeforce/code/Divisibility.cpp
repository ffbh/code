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
#define lson (root<<1)  
#define rson (root<<1|1)  


int n, k;

void input(){
	in >> n >> k;


}

int num[10010];
int E;
set<int> si;
int g[100010];
int tar, min_tar;
vector<int> ans;
bool ch(vector<int>& a,vector<int>& b){
	if (a.size() == 0 || a.back() > b.back())
		return 1;
	if (a.back()<b.back())
		return 0;
	if (a.size() > b.size())
		return 1;
	if (a.size() < b.size())
		return 0;
	for (int i = 0; i<a.size();++i)
	if (a[i] != b[i])
		return a[i]>b[i];
	return 0;
}
void dfs(int pos,int sum){
	if (pos > E){
		if (sum == tar){
			int gg = 0;
			vector<int> now;
			for (int i = 1; i <= E;++i)
			if (g[i])
				now.push_back(i);
			if (ch(ans,now)){
				ans.clear();
				ans = now;
			}
		

		}
		return;
	}
	for (int i = 2; i*pos <= E; ++i){
		num[i*pos]++;
	}
	g[pos] = 1;
	dfs(pos + 1, sum + num[pos]);

	g[pos] = 0;
	for (int i = 2; i*pos <= E; ++i){
		num[i*pos]--;
	}

	dfs(pos + 1, sum);

}


int D[300010], S[300010], di[300010];
bool vis[300010];

vector<int> V[1010];


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		/*E = 15;
		for (int i = 1; i <= 30; ++i){
			memset(g, 0, sizeof(g));
			memset(num, 0, sizeof(num));
			ans.clear();
			tar = i;
			cout << tar << ":   ";
			dfs(1, 0);
			for (int k : ans){
				cout << k << " ";
			}
			cout << endl;
		}*/
		
		S[0] = 0;
		for (int i = 1; i < 300010; ++i){
			for (int j = i + i; j < 300010; j += i){
				D[j]++;
				if (i != 1){
					di[j] = max(di[j], i);
					di[j] = max(di[j], j / i);
				}
			}
			S[i] = S[i - 1] + D[i];
		}

		if (S[n] < k){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
			int p = lower_bound(S + 1, S + n + 1, k) - S;
			
			for (int i = 1; i <= p; ++i)
				vis[i] = 1;
			int need = S[p] - k;
			int limit = p / 2 + 1;
			for (int k = limit; k < p; ++k)
				V[D[k]].push_back(k);
			while (need>0){
				for (int i = need; i >= 1; --i){
					if (!V[i].empty()){
						vis[V[i].back()] = 0;
						V[i].pop_back();
						need -= i;
						break;
					}
				}
			}


			int num = 0;
			for (int i = 1; i <= n;++i)
			if (vis[i])
				num++;
			printf("%d\n", num);
			for (int i = 1; i <= n; ++i)
			if (vis[i])
				printf("%d ", i);
			cout << endl;
		}












	}


	return 0;
}





