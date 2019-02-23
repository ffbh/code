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

int n;
int cnt[1024*1024+10];
int v[300010];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		in >> v[i];
	}
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		LL ans = 0;
		memset(cnt, 0, sizeof(cnt));
		cnt[0] = 1;
		int now = 0;
		int st = 0;
		for (int i = 1; st + i * 2 <= n; ++i){
			now ^= (v[st + i * 2] ^ v[st + i * 2 - 1]);
			ans += cnt[now];
			cnt[now]++;
		}

		memset(cnt, 0, sizeof(cnt));
		cnt[0] = 1;
		now = 0;
		st = 1;
		for (int i = 1; st + i * 2 <= n; ++i){
			now ^= (v[st + i * 2] ^ v[st + i * 2 - 1]);
			ans += cnt[now];
			cnt[now]++;
		}

		cout << ans << endl;












	}


	return 0;
}





