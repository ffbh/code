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

int n, m;



void input(){
	in >> n >> m;


}

struct Node{
	Node(){
		clear();
	}
	int f[(1 << 14) + 10], size;
	int find(int x){
		return x == f[x] ? x : f[x] = find(f[x]);
	}
	void clear(){
		size = 1;
	}
	int add(){
		f[size] = size;
		return size++;
	}
	void Union(int fa, int son){
		f[son] = fa;
	}
	

}BCJ;

int h[256];
char s[(1 << 14) + 10];
bool mark[(1 << 14) + 10], now[(1 << 14) + 10];
int SS[(1 << 14) + 10];
int mmp[(1 << 14) + 10], tmp[(1 << 14) + 10];
int YS[(1 << 14) + 10];


void ch(){
	for (int i = 0; i < m/4; ++i){
		int st = i * 4;
		int en = (i + 1) * 4 - 1;
		int key = h[s[i]];
		for (int j = en; j >= st; --j){
			now[j] = key % 2;
			key /= 2;
		}
	}
}

void SU(vector<int>& all){
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
}

int main(){
	for (char c = '0'; c <= '9'; ++c){
		h[c] = c - '0';
	}
	for (char c = 'A'; c <= 'F'; ++c)
		h[c] = c - 'A' + 10;
	int TEST_CASE = 1;
	//in >> TEST_CASE;

	while (TEST_CASE-- > 0){
		input();
		int ans = 0;


		
		for (int i = 1; i <= n; ++i){
			scanf("%s", s);
			//in >> s;
			ch();
			vector<int> all;

			BCJ.clear();

			memset(YS, -1, sizeof(YS));


			int pos = 0;
			while (pos < m){
				while (pos < m &&!now[pos]){
					pos++;
				}
				if (pos == m)
					break;


				all.clear();
				int top = BCJ.add();
				ans++;
				while (pos < m&&now[pos]){
					if (mark[pos]){
						all.push_back(mmp[pos]);
					}
					tmp[pos] = top;
					pos++;
				}

				SU(all);
				int D = top;
				for (int p : all){
					if (YS[p] != -1){
						D = YS[p];
						break;
					}
				}
				
				vector<int> TT;
				for (int p : all){
					if (YS[p] == -1){
						YS[p] = D;
						ans--;
					}
					else{
						int downid = BCJ.find(YS[p]);
						if (SS[downid] != i){
							SS[downid] = i;
							TT.push_back(downid);
							ans--;
						}
					}
				}
				
		

				for (int p : TT){
					if (p != top){
						BCJ.Union(top, p);
					}
				}



			}
			
			for (int k = 0; k < m; ++k){
				mark[k] = now[k];
				if (!now[k])
					continue;
				mmp[k] = BCJ.find(tmp[k]);
			}

		
			
	

		}

		cout << ans << endl;
	}


	return 0;
}





