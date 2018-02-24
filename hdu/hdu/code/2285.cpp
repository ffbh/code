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
#define lson (root<<1)  
#define rson (root<<1|1)  


int N, M;
LL h[110];

void add(LL v){
	for (int i = 60; i >= 0; --i){
		if (v & ((LL)1) << i){
			if (h[i] == -1){
				h[i] = v;
				break;
			}
			else{
				v ^= h[i];
			}
		}
	}
}

LL input(){
	string str;
	in >> str;
	LL v = 0;
	for (char c : str){
		v = v * 2 + c - '0';
	}
	return v;
}


bool judge(LL p){
	for (int i = 60; i >= 0; --i){
		if (p & ((LL)1) << i){
			if (h[i] == -1){
				return 0;
			}
			p ^= h[i];
		}
	}
	return 1;
}
int main(){
	while (in >> N >> M){
		memset(h, -1, sizeof(h));
		for (int i = 1; i <= M; ++i){
			
			LL v = input();
			
			add(v);
		}

		int Q;
		in >> Q;
		while (Q-- > 0){
			LL a = input();
			LL b = input();
			b ^= a;
			
			if (judge(b)){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}

		}



	}



	return 0;
}





