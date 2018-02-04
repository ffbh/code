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


int n, q;


void input(){
	in >> n >> q;


}

map<int, int> mii;

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int ans = n;
		int l, r, k;
		int L, R;
		while (q-- > 0){
		//	in >> l >> r >> k;
			scanf("%d%d%d", &l,&r,&k);
			L = l;
			R = r;
			if (k == 1){
				if (mii.empty()){
					ans -= r - l + 1;
					mii[l] = r;
				}
				else{
					int temp = 0;
					map<int, int>::iterator p = mii.upper_bound(l);
					if (p != mii.begin()){
						p--;
						if (p->second >= l){
							L = min(L, p->first);
							R = max(R, p->second);
							temp += p->second - p->first + 1;
							p = mii.erase(p);
						}
						else{
							p++;
						}
					}
					while (p != mii.end()){
						if (p->first > R){
							break;
						}
						R = max(R, p->second);
						temp += p->second - p->first + 1;
						p = mii.erase(p);
					}
					mii[L] = R;
					ans -= R - L + 1;
					ans += temp;
				}
			}
			else{
				if (mii.empty()){
					

				}
				else{
					int temp = 0;
					map<int, int>::iterator p = mii.upper_bound(l);
					int l1, r1, l2, r2;
					l1 = l2 = -1;
					if (p != mii.begin()){
						p--;
						if (l > p->second){
							p++;
						}
						else if (l == p->first){
							
						}

						else if (p->second <= r){
							l1 = p->first;
							r1 = l - 1;
							ans += p->second - l + 1;
							p = mii.erase(p);
						}
						else{
							l1 = p->first;
							r1 = l - 1;
							l2 = r + 1;
							r2 = p->second;
							ans += r - l + 1;
							p = mii.erase(p);
						}
					}

					while (p != mii.end()){
						if (r < p->first){
							break;
						}
						if (r >= p->second){
							ans += p->second - p->first + 1;
						}
						else{
						
							l2 = r + 1;
							r2 = p->second;
							ans += r - p->first + 1;
						}
						p = mii.erase(p);
					}

					if (l1 != -1){
						mii[l1] = r1;
					}
					if (l2 != -1){
						mii[l2] = r2;
					}


				}


			}
			printf("%d\n", ans);





		}












	}


	return 0;
}





