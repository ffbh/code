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

int mmp[50][50];

class Subgraphs{
public :

	bool vis[25][255];
	int pace[25][255];
	vector<int> dp(int num,int val,int M){
		memset(vis, 0, sizeof(vis));
		pace[0][0] = -1;
		vis[0][0] = 1;
		for (int i = 0; i <= num;++i)
		for (int j = 0; j <= val; ++j){
			if (vis[i][j]){
				for (int k = 0; k <= M; ++k){
					if (j + k <= val){
						vis[i + 1][j + k] = 1;
						pace[i + 1][j + k] = k;
					}
				}
			}
		}
		
		vector<int> ans;
		int a = num, b = val;
		while (a > 0){
			ans.push_back(pace[a][b]);
			
			b -= pace[a][b];
			a--;
		}
		return ans;
	}

	bool L[30], R[30];

	int cale(int p,int K){
		int ans = 0;
		for (int i = 0; i <= K;++i)
		if (i*(i - 1) / 2 <= p)
			ans = i;
		return ans;
	}

	vector<string> findGroups(int K){
		memset(mmp, 0, sizeof(mmp));
		for (int i = 0; i < K; ++i){
			for (int j = 0; j < K; ++j)
				mmp[i][j] = 1;
		}
		for (int i = 0; i < K; ++i){
			for (int j = 0; j <= i; ++j)
				mmp[i][j + K] = mmp[j + K][i] = 1;
		}

		for (int i = 0; i < 2 * K; ++i)
			mmp[i][i] = 0;

		vector<string> ans;
		for (int i = 0; i < 2 * K; ++i){
			string s = "";
			for (int j = 0; j < 2 * K; ++j)
				s += mmp[i][j] + '0';
			ans.push_back(s);
		}


		for (int k = 0; k <= K*(K - 1) / 2; ++k){
			
		
			int left = cale(k,K);
			if (left * (left-1)/2 == k){
				string s = "";
				for (int i = 0; i < K; ++i){
					if (i < left){
						s += 'Y';
					}
					else{
						s += 'N';
					}
				}

				for (int i = 0; i < K; ++i){
					if (i < left){
						s += 'N';
					}
					else{
						s += 'Y';
					}
				}
				ans.push_back(s);
			}
			else{
				int need = k - left * (left-1)/2;
				vector<int> p = dp(K - left, need, left);
				sort(p.begin(), p.end(),greater<int>());
				memset(L, 0, sizeof(L));
				memset(R, 0, sizeof(R));
				int a = left;
				int alen = 0, blen = 0;
				for (int i = 0; i < p.size(); ++i){
					int nnn = p[i];
					if (a == nnn){
						R[blen] = 1;
						alen++;
						blen++;
					}
					else{
						while (a != nnn){
							L[alen] = 1;
							alen++;
							blen++;
							a--;
						}
						R[blen] = 1;
						alen++;
						blen++;
					}
				}
				while (a > 0){
					L[alen++] = 1;
					a--;
				}
				string s = "";
				for (int i = 0; i < K;++i)
				if (L[i]){
					s += 'Y';
				}
				else{
					s += 'N';
				}
				for (int i = 0; i < K; ++i)
				if (R[i]){
					s += 'Y';
				}
				else{
					s += 'N';
				}
				
				ans.push_back(s);
			
			}


		}




		return ans;
	}



};

//
//int main(){
//	Subgraphs sh;
//	vector<string> ans = sh.findGroups(4);
//	for (string s : ans){
//		cout << s << endl;
//	}
//	
//
//
//	return 0;
//}
//
//
//
//
//
