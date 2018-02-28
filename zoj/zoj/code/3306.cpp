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


int N;
int col[30], tmp[30];
int cnt[1024 * 1024 + 100];

void Init(){
	for (int i = 0; i < 30; ++i)
		col[i] = 0;


}

int COUNT(int p){
	int ret = 0;
	for (int i = 0; i < 25; ++i){
		if (p & (1 << i))
			ret++;
	}
	return ret;
}

int main(){
	cnt[0] = 0;
	for (int i = 1; i < 1024 * 1024 + 100; ++i)
		cnt[i] = cnt[i/2]  + i % 2;


	while (in >> N){
		if (N == 0)
			break;
		Init();
		for (int i = 0; i < 20; ++i){
			string s;
			in >> s;
			for (int j = 0; j < 20; ++j){
				int k = s[j] == '#' ? 1 : 0;
				col[j] = col[j] * 2 + k;
			}
		}
		int ans = 0;
		for (int i = 0; i < (1 << 20); ++i){
			int m = cnt[i];
			if (m >= N)
				continue;
			
			vector<int> all;
			for (int j = 0; j < 20; ++j){
				all.push_back(cnt[col[j] & i]);
			}
			sort(all.begin(), all.end(), greater<int>());
			int t = 0;
			
			for (int k = 0; k < N - m && k < all.size(); ++k)
				t += all[k];
			ans = max(ans, t);


		}
		printf("%d\n", ans);





	}




	return 0;
}





