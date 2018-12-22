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


LL n, k;
string SS, TT;

LL num[500010];

void input(){
	in >> n >> k;
	in >> SS >> TT;


}

void modify(LL& a){
	a = min(a, (LL)1e9);
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

	
		int pos = 1;
		while (pos <= n && SS[pos-1] == TT[pos-1]){
			num[pos] = 1;
			pos++;
		}

		LL crazy = 0;
		for (int i = pos; i <= n; ++i){
			char s = SS[i - 1];
			char t = TT[i - 1];
			if (i == pos){
				num[i] = 2;
			}
			else{
				crazy *= 2;
				if (s == 'a'){
					crazy++;
				}
				if (t == 'b'){
					crazy++;
				}
				num[i] = crazy + 2;
				modify(crazy);
				modify(num[i]);
			}
		}

		LL ans = 0;
		for (int i = 1; i <= n; ++i){
			ans += min(num[i], k);
		}
		cout << ans << endl;













	}


	return 0;
}





