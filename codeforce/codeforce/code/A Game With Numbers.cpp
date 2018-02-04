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





void input(){


}




int encode(int p[5]){
	int code = 0;
	for (int i = 1; i < 5; ++i)
		code = code * 9 + p[i];
	return code;
}

bool decode(int code, int p[5]){
	p[0] = 0;
	for (int i = 4; i > 0; --i){
		p[i] = code % 9;
		code /= 9;
	}
	return p[1] + p[2] + p[3] + p[4] <= 8 && code == 0;
}
//int dfs(int A,int B){
//	
//
//	if (dp[A][B] != -1){
//		return dp[A][B];
//	}
//	if (A == 0){
//		return dp[A][B] = 2;
//	}
//	if (B == 0){
//		return dp[A][B] = 0;
//	}
//	dp[A][B] = 1;
//	int ans = 0;
//
//	int a[5], b[5];
//	decode(A, a);
//	decode(B, b);
//	vector<int> all;
//	for (int i = 1; i <= 4; ++i){
//		if (a[i] == 0)
//			continue;
//		for (int j = 1; j <= 4; ++j){
//			if (b[j] == 0)
//				continue;
//			a[i]--;
//			a[(i + j) % 5]++;
//			all.push_back(encode(a));
//			a[(i + j) % 5]--;
//			a[i]++;
//		}
//	}
//	if (A == 1467 && B == 1){
//		int t = 0;
//	}
//
////	sort(all.begin(), all.end());
//	for (int son : all){
//		int ret = 2 - dfs(B, son);
//		ans = max(ans, ret);
//		
//	}
//	return dp[A][B] = ans;
//}

int h[6666];
int dp[600][600];
vector<pii> V[600][600];
int deg[600][600];
int ok[600][600][2];
int vis[600][600];
void Init(){
	memset(dp, -1, sizeof(dp));
	int p[5];
	vector<int> state;
	for (int i = 0; i < 6666; ++i){
		if (!decode(i, p))
			continue;

		h[i] = state.size();
		state.push_back(i);


	}

	int a[5], b[5];
	for (int A : state)
	for (int B : state){
		if (A == 0 || B == 0){
			continue;
		}
		decode(A, a);
		decode(B, b);


		for (int i = 1; i <= 4; ++i){
			if (a[i] == 0)
				continue;
			for (int j = 1; j <= 4; ++j){
				if (b[j] == 0)
					continue;
				a[i]--;
				a[(i + j) % 5]++;


				V[h[B]][h[encode(a)]].push_back(mp(A, B));
				deg[h[A]][h[B]]++;

				a[(i + j) % 5]--;
				a[i]++;
			}
		}
	}

	for (int A : state){
		if (A != 0){
			ok[0][h[A]][1] = 1;
			ok[h[A]][0][0] = 1;
		}
	}

	queue<pii> Q;
	for (int A : state)
	for (int B : state){
		if (A + B != 0){
			if (deg[h[A]][h[B]] == 0){
				Q.push(mp(A, B));
			}
		}
	}


	while (!Q.empty()){
	
		pii u = Q.front();
		Q.pop();

		if (ok[h[u.first]][h[u.second]][1]){
			dp[h[u.first]][h[u.second]] = 1;
		}
		else{
			dp[h[u.first]][h[u.second]] = 0;
		}
		for (pii son : V[h[u.first]][h[u.second]]){
			if (dp[h[u.first]][h[u.second]] == 0){
				ok[h[son.first]][h[son.second]][1 - dp[h[u.first]][h[u.second]]]++;
				if (deg[h[son.first]][h[son.second]] > 0){
					deg[h[son.first]][h[son.second]] = 0;
					Q.push(son);
				}
			}
			else{
			
				ok[h[son.first]][h[son.second]][1 - dp[h[u.first]][h[u.second]]]++;
				if (--deg[h[son.first]][h[son.second]] == 0){
					Q.push(son);
				}
			}
		}
	}
	

}


int main(){




	Init();

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int f;
		int a[5], b[5];

		in >> f;
		for (int i = 0; i < 5; ++i)
			a[i] = b[i] = 0;
		for (int i = 0; i < 8; ++i){
			int t;
			in >> t;
			a[t]++;
		}
		for (int i = 0; i < 8; ++i){
			int t;
			in >> t;
			b[t]++;
		}

		int A = encode(a);
		int B = encode(b);
		if (f == 0){
			int ret = dp[h[A]][h[B]];
			if (ret == 1){
				cout << "Alice" << endl;
			}
			else if (ret == 0){
				cout << "Bob" << endl;
			}
			else{
				cout << "Deal" << endl;
			}

		}
		else{
			int ret = dp[h[B]][h[A]];
			if (ret == 1){
				cout << "Bob" << endl;
			}
			else if (ret == 0){
				cout << "Alice" << endl;
			}
			else{
				cout << "Deal" << endl;
			}

		}











	}


	return 0;
}

