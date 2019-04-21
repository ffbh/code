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



int N;
vector<pair<int, pii> > V,tmp;


void input(){
	in >> N;
	for (int i = 1; i <= N; ++i){
		pair<int, pii> D;
		in >> D.second.first >> D.second.second >> D.first;
		V.push_back(D);
	}
}
int dp[10010];
void _init(){

	V.clear();
	tmp.clear();
	memset(dp, 0, sizeof(dp));
}

int Lose(pair<int, pii> p1, pair<int, pii> p2){
	int lose = p2.second.first * p1.first;
	return min(lose, p1.second.second);
}

bool cmp(pair<int, pii> p1 , pair<int, pii> p2){
	int lose1 = Lose(p1, p2);
	int lose2 = Lose(p2, p1);
	return lose1 > lose2;
	/*if (lose1 < lose2)
		return 1;
	else if (lose1 == lose2){
		if (p1.first < p2.first){
			return 1;
		}
		else if (p1.first == p2.first){
			return p1.second.first < p2.second.first;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}*/
}




int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();
		int ans = 0;
		sort(V.begin(), V.end(), cmp);
		for (auto p : V){
			for (int k = 10009; k >= p.second.first; --k){
				int time = k - p.second.first;
				int v = p.second.second - time * p.first;
				if (v < 0)
					v = 0;
				dp[k] = max(dp[k], dp[time] + v);
				ans = max(ans, dp[k]);
			}
		}
		
		for (auto p : V){
			for (int k = 10009; k >= p.second.first; --k){
				int time = k - p.second.first;
				int v = p.second.second - time * p.first;
				if (v < 0)
					v = 0;
				dp[k] = max(dp[k], dp[time] + v);
				ans = max(ans, dp[k]);
			}
		}

		printf("Case #%d: %d\n",CPP++, ans);


	}


	return 0;
}





