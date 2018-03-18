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


char str[2000010];
int n;
void input(){
	in >> str;
	n = strlen(str);

}


int ans[2000010];

void Init(){
	for (int i = 0; i <= n; ++i)
		ans[i] = 0;
}


bool judge(char* s,int len){
	if (len == 1)
		return 1;
	if (s[0] == s[len-1])
		return 0;
	for (int i = 0; i < len - 1;++i)
	if (s[i] == s[i + 1])
		return 0;
	return 1;
}

int Next[2000010];
void kmp(char * s,int len){
	int i, j;
	i = 0;
	j = -1;
	Next[i] = j;
	while (i < len){
		if (j == -1 || s[i] == s[j]){
			i++;
			j++;
			Next[i] = j;
		}
		else{
			j = Next[j];
		}
	}

	for (int i = 1; i <= len; ++i)
		ans[i]++;

	

	int all = len;
	int sub = len - Next[len];
	if (all % sub == 0 && all / sub > 1){
		for (int k = 1 + sub; k <= len; k += sub)
			ans[k]--;
	}
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		Init();

		

		if (judge(str,n)){
			kmp(str, n);
		}
		else{
			for (int i = n; i < n + n; ++i)
				str[i] = str[i - n];
			str[n + n] = 0;
	//		cout << strlen(str) << endl;
			int apos = 0;
			while (apos < n + n){
				int bpos = apos + 1;
				while (bpos < n + n && str[bpos] != str[bpos - 1]){
					bpos++;
				}
				if (str[bpos - 1] == str[apos] && bpos - 1 != apos){
					bpos--;
				}

				kmp(str + apos, bpos - apos);
				apos = bpos;
			}
		}

		for (int i = 0; i < n; ++i){
			printf("%d", ans[n - i]>0 ? 1 : 0);
		}
		printf("\n");

	}


	return 0;
}





