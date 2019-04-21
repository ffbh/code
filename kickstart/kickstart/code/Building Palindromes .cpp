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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

void _init(){



}


string str;
int N, Q;
int num[100010][30];

void input(){
	in >> N >> Q;
	in >> str;


}


int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();


		str = '-' + str;
		for (int i = 1; i <= N; ++i){
			for (int j = 0; j < 30; ++j)
				num[i][j] = num[i - 1][j];
			num[i][str[i] - 'A']++;
		}
		int ans = 0;
		while (Q-->0){
			int l, r;
			in >> l >> r;
			int v = 0;
			if (l == 2 && r == 5){
				int t = 0;
			}
			for (int i = 0; i < 30; ++i){
				if ((num[r][i] - num[l - 1][i]) % 2 == 1){
					v++;
				}
			}
			if (v > 1){

			}
			else{
				ans++;
			}
		}

		printf("Case #%d: %d\n", CPP++, ans);










	}


	return 0;
}





