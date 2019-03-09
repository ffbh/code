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


int n, k;


void input(){
	in >> n >> k;


}

void PF(){
	printf("2");
	for (int i = 2; i <= n; ++i){
		if (i % 2 == 0){
			printf(" %d", i - 1);
		}
		else{
			printf(" %d", i + 1);
		}
	}
	printf("\n");
}

bool vis[1010][1010];

int f[1010];

void  clear(){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			vis[i][j] = 0;
		}
	}
}

inline int getLow(int a){
	if (a % 2 == 1){
		return a;
	}
	return a - 1;
}

int ans[1010];
int mark[1010];

int final_ans[1010][1010];

void put(int a,int b){
	ans[a] = b;
	ans[b] = a;
	vis[a][b] = vis[b][a] = 1;
	mark[a] = 1;
	mark[b] = 1;
}


inline int get_no_use(int p){
	for (int k = p + 2; k <= n; k++){
		if (!mark[k] && !vis[p][k]){
			return k;
		}
	}
	return -1;
}

bool cale(int one){
	for (int i = 1; i <= n; i ++){
		mark[i] = 0;
	}
	put(1, one);
	put(f[1], f[one]);



	for (int i = 1; i <= n; i += 2){
		if (mark[i])
			continue;
		int dr = get_no_use(i);
		if (dr == -1){
			return 0;
		}
		put(i, dr);
		put(f[i], f[dr]);
	}


	for (int i = 1; i <= n; ++i)
		final_ans[one-1][i] = ans[i];

	return 1;
	

}


inline void print(int p){
	printf("%d",final_ans[p][1]);
	for (int i = 2; i <= n; ++i){
		printf(" %d", final_ans[p][i]);
	}
	printf("\n");
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		clear();

		for (int i = 1; i <= n; ++i){
			if (i % 2 == 0){
				f[i] = i - 1;
				
			}
			else{
				f[i] = i + 1;
				vis[i][i + 1] = vis[i + 1][i] = 1;
			}
		}

		if (n % 2 != 0){
			printf("Impossible\n");
		}
		else if(n % 4 != 0){
			if (k == 1){
				PF();
			}
			else{
				printf("Impossible\n");
			}
		}
		else{
			int num = 1;
			int st = 3;
			while (cale(st)){
				st++;
				num++;
			}
			if (k > num){
				printf("Impossible\n");
			}
			else{
				PF();
				for (int i = 2; i <= k; ++i)
					print(i);

			}




		}














	}


	return 0;
}




