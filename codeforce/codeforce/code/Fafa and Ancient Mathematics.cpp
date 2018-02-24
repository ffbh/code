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


string str;
int P, M;
void input(){
	in >> str;
	in >> P >> M;

}

int E[10010];
int op[10010];

pii dp[10010][110];
bool vis[10010][110];
int DDD(int p){
	if (str[p] == '('){
		int r = E[p];
		int L = p + 1;

		int LR = L;
		if (str[L] == '(')
			LR = E[L];
		int R = LR + 2;
		return op[p] = DDD(L) + DDD(R) + 1;
	}
	else{
		return op[p] = 0;
	}




}

pii dfs(int lf,int k){
	if (str[lf] == '?'){
		int t = 0;
	}
	if (vis[lf][k])
		return dp[lf][k];
	vis[lf][k] = 1;
	int addop, subop;
	bool add = 0;
	if (P <= 100){
		addop = k;
		subop = op[lf] - addop;
		add = 1;
	}
	else{
		subop = k;
		addop = op[lf] - subop;
	}

	if (op[lf] == 0){
		if (subop == 0){
			dp[lf][k] = mp((int)(str[lf] - '0'), (int)(str[lf] - '0'));
			return dp[lf][k];
		}
		else{
			return dp[lf][k] = mp((int)-1e7, (int)1e7);
		}
	}
	else{
		int r = E[lf];
		int L = lf + 1;
		int LR = L;
		if (str[L] == '(')
			LR = E[L];
		int R = LR + 2;

		if (str[L] == '?' || str[R] == '?'){
			int t = 0;
		}

		dp[lf][k] = mp((int)-1e7, (int)1e7);
		for (int i = 0; i <= k; ++i){
			if (addop > 0){
				if (add){
					if (k - i - 1 >= 0){
						pii ls = dfs(L, i);
						pii rs = dfs(R, k - i - 1);
						dp[lf][k].first = max(dp[lf][k].first, ls.first + rs.first);
						dp[lf][k].second = min(dp[lf][k].second, ls.second + rs.second);
					}
				}
				else{
					
					pii ls = dfs(L, i);
					pii rs = dfs(R, k - i);
					dp[lf][k].first = max(dp[lf][k].first, ls.first + rs.first);
					dp[lf][k].second = min(dp[lf][k].second, ls.second + rs.second);
	//				dp[lf][k].first = max(dp[lf][k].first, ls.first - rs.second);
	//				dp[lf][k].second = min(dp[lf][k].second, ls.second - rs.first);
				}
			}
			if (subop > 0){
				if (lf == 3 && k == 0){
					int t = 0;
				}

				if (add){
					pii ls = dfs(L, i);
					pii rs = dfs(R, k - i);
					dp[lf][k].first = max(dp[lf][k].first, ls.first - rs.second);
					dp[lf][k].second = min(dp[lf][k].second, ls.second - rs.first);

				}
				else{
					if (k - i - 1 >= 0){
						pii ls = dfs(L, i);
						pii rs = dfs(R, k - i - 1);
						dp[lf][k].first = max(dp[lf][k].first, ls.first - rs.second);
						dp[lf][k].second = min(dp[lf][k].second, ls.second - rs.first);
					}
				}

			}

		}

	}
	return dp[lf][k];


	
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		vector<int> S;
		for (int i = 0; i < str.length(); ++i){
			if (str[i] == '('){
				S.push_back(i);
			}
			else if(str[i]==')'){
				E[S.back()] = i;
				S.pop_back();
			}
			
		}

		DDD(0);
		if (P <= 100){
			cout << dfs(0, P).first << endl;
		}
		else{
			cout << dfs(0, M).first << endl;
		}



		int d = 0;
		d++;




	}


	return 0;
}





