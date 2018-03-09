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


string s;
int num[200010];
void input(){
	in >> s;


}

bool judge(){
	if (s[0] != '1')
		return 0;
	if (s.back() != '0' && s.back() != '1')
		return 0;

	for (int i = 1; i < s.length() - 1; ++i){
		if (s[i] != '0')
			return 0;
	}
	return 1;
}

int vis[110][1025][2];
int pace[200010];
int MARK = 0;
bool dfs(int pos,int mask,int flag){//pos--
	int realpos = s.length() - pos;
	if (realpos == s.length())
		return mask == 0 && flag == 1;
	if (vis[pos][mask][flag] == MARK)
		return 0;
	vis[pos][mask][flag] = MARK;
	if (flag == 0){
		pace[realpos] = num[realpos];
		if (dfs(pos - 1, mask ^ (1 << num[realpos]), 0))
			return 1;
		for (int i = num[realpos] - 1; i >= 0; --i){
			pace[realpos] = i;
			if (dfs(pos - 1, mask ^ (1 << i), 1))
				return 1;
		}
		
	}
	else{
		for (int i = 9; i >= 0; --i){
			pace[realpos] = i;
			if (dfs(pos - 1, mask ^ (1 << i), 1))
				return 1;
		}
	}
	return 0;
}

int main(){
	MARK = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		
		if (judge()){
			for (int i = 0; i < s.length() - 2; ++i)
				putchar('9');
			cout << endl;
		}
		else{
			for (int i = 0; i < s.length(); ++i){
				num[i] = s[i] - '0';
				pace[i] = num[i];
			}
			int mask = 0;
			for (int i = 0; i < s.length(); ++i)
				mask ^= (1 << num[i]);
			int len = s.length();
			int now_mask = mask;
			bool ok = 0;
			for (int k = len - 1; k >= 0; --k){
				
				int sufflen = len - k;
				MARK++;
				now_mask ^= (1 << num[k]);
				if (dfs(sufflen, now_mask,0)){
					ok = 1;
					break;
				}
			}
			assert(ok);
			for (int i = 0; i < len; ++i)
				printf("%d", pace[i]);
			cout << endl;
		}


	}
	return 0;
}





