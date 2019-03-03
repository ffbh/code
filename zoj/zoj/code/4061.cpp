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

int n, m;
string str;
int s1[200010], s2[200010];
int len;
void input(){
	in >> n >> m;
	in >> str;

}


inline int get(int& pos,int k){
	if (pos >= len){
		return -1;
	}
	int aim = str[pos] - '0';
	if (k == 0){
		if (aim == k){
			pos++;
			return 0;
		}
	}
	else if (aim % k == 0){
		pos++;
		return aim / k;
	}
	else if (pos + 1 < len){
		pos++;
		int new_aim = aim * 10 + str[pos] - '0';
		if (new_aim % k == 0 && new_aim / k < 10){
			pos++;
			return new_aim / k;
		}
	}
	return -1;
}

int get_m(int k){
	s1[1] = k;
	int pos = 0;
	for (int i = 1; i <= m; ++i){
		if (pos >= len){
			return -1;
		}
		s2[i] = get(pos, k);
		if (s2[i] == -1){
			return -1;
		}
	}
	return pos;
}




bool get_n(int pos){
	for (int i = 2; i <= n; ++i){
		s1[i] = get(pos, s2[1]);
		if (s1[i] == -1){
			return 0;
		}
		for (int j = 2; j <= m; ++j){
			int val = get(pos, s2[j]);
			if (val == s1[i] || s2[j] == 0 && val == 0){
			
			}
			else{
				return 0;
			}
		}
	}
	return pos == len;
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		len = str.length();
		bool ok = 0;
		for (int k = 1; k <= 9; ++k){
			int pos = get_m(k);
			if (pos != -1){
				if (get_n(pos)){
					ok = 1;
					break;
				}
			}
		}

		if (ok){
			for (int i = 1; i <= n; ++i)
				printf("%d", s1[i]);
			printf(" ");
			for (int i = 1; i <= m; ++i)
				printf("%d", s2[i]);
			printf("\n");
		}
		else{
			printf("Impossible\n");
		}
















	}


	return 0;
}





