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


int N, S;
int a[100010];
unordered_map<int, int> M;
void input(){
	in >> N >> S;
	for (int i = 1; i <= N; ++i)
		in >> a[i];


}


int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();
		int ans = 0;
		for (int i = 1; i <= N; ++i){
			M.clear();
			int tmp = 0;
			for (int j = i; j <= N; ++j){
				if (i == 2 && j == 4){
					int t = 0;
				}
				if (M[a[j]] == S){
					tmp -= M[a[j]];
				}
				else if(M[a[j]] > S){

				}
				else{
					tmp++;
				}
				M[a[j]]++;
				ans = max(ans, tmp);
			}
		}

		printf("Case #%d: %d\n",CPP++, ans);












	}


	return 0;
}





