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


int R, C;

void input(){
	in >> R >> C;


}

inline int Get(int p, int m){
	p %= m;
	if (p == 0)
		p += m;
	return p;
}

vector<pii> cale(int row,int col,int st,int st_col){
	vector<pii> V;
	if (row == 2){
		if (col > 4){
			for (int i = 0; i<col; ++i){
				V.push_back(mp(st_col, Get(st + i,col)));
				V.push_back(mp(st_col + 1, Get(st + i + 2, col )));
			}
		}
	}
	else{//row=3
		if (col > 3){
			for (int i = 0; i<col; ++i){
				V.push_back(mp(st_col, Get(st + i, col)));
				V.push_back(mp(st_col + 2, Get(st + i + 1, col)));
				V.push_back(mp(st_col + 1, Get(st + i + 3, col)));
			}
		}

	}

	return V;

}

bool judge(int x1,int y1,int x2,int y2){
	return x1 != x2&&y1 != y2&&x1 + y1 != x2 + y2&&x1 - y1 != x2 - y2;

}
bool change = 0;
vector<pii> ans;
void ppp(pii p){
	if (change){
		swap(p.first, p.second);
	}
	ans.push_back(p);


}


bool test(){
	for (int i = 1; i < ans.size(); ++i){
		if (!judge(ans[i-1].first,ans[i-1].second,ans[i].first,ans[i].second)){
	//		cout << "swap " << i << endl;
			swap(ans[i], ans[i+1]);
			i--;
		}

	}
	return 1;
}

bool test2(){
	for (int i = 1; i < ans.size(); ++i){
		if (!judge(ans[i - 1].first, ans[i - 1].second, ans[i].first, ans[i].second)){
				//	cout << "wa " << i-1 << endl;
		//	swap(ans[i], ans[i + 1]);
		//	i--;
			return 0;
		}

	}
	return 1;
}
int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		/*for (int i = 2; i <=5;++i)
		for (int j = 2; j <=5; ++j){
			R = i;
			C = j;*/

			change = 0;
			if (R > C){
				swap(R, C);
				change = 1;
			}



			ans.clear();
			bool ok = 1;
			if (R == 2 && C <= 4 || R==3&&C==3){
				ok = 0;
			}
			int ST[50];
			int now = 1;
			if (R == 2){
				ST[1] = 1;
				ppp(mp(1, ST[1]));
				ST[2] = 4;
				ppp(mp(2, ST[2]));
			//	for (int i = 1; i <= R; ++i){
					/*if (i != 1){
						now = Get(now + 2, C);
						for (int k = 1; k <= C; ++k){
							now = Get(now + 1, C);
							ST[i] = now;
							if (judge(i - 1, ST[i - 1], i, ST[i])){
								break;
							}
						}
					}
					ST[i] = now;
					if (!judge(i - 1, ST[i - 1], i, ST[i])){
						ok = 0;
						break;
					}*/
				
				//}
			}
			else{
				for (int i = 1; i <= R; ++i){
					if (i % 2 == 1){
						ST[i] = 1;
					}
					else{
						ST[i] = 3;
					}
					ppp(mp(i, ST[i]));
				}


			}
		/*	if (R == 2 && C == 4){
				ok = 1;
				ST[1] = 3;
				ST[2] = 1;
				ans.clear();
				ans.push_back(mp(1, 3));
				ans.push_back(mp(2, 1));
			}
*/
			if (ok){
				for (int i = 1; i < C; ++i){
					for (int j = 1; j <= R; ++j){
						ppp(mp(j, Get(ST[j] + i, C)));
					}
				}
			}

		/*	if (R == 2 && C == 4){
				ok = 1;
				ans.clear();
				ans.push_back(mp(1, 3));
				ans.push_back(mp(2, 1));
			}*/

			if (ok){
				test();
				/*if (!test2()){
					cout << "WAAAAA" << R << " " << C << endl;
				}*/
				
				printf("Case #%d: POSSIBLE\n", CPP++);
				for (pii p : ans){
					printf("%d %d\n", p.first, p.second);
				}

			}
			else{
				printf("Case #%d: IMPOSSIBLE\n", CPP++);
				/*if (change){
					swap(R, C);
				}
				cout << R << " " << C << endl;*/
			}


	//	}
		

	}


	return 0;
}





