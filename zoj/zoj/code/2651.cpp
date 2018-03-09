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

int N, A, B;

LL x[20010];
LL L[20010], R[20010];
LL mod[20010];
bool vis[20010];
#define INF ((LL)1e8)
bool cale(){
	if (A < B){
		for (int i = 0; i <= N; ++i){
			if (vis[i%A]){
				L[i] = mod[i%A];
				mod[i%A] -= INF;
			}
			x[i] = (L[i] + R[i]) / 2;
			if (i + A <= N)
				R[i + A] = x[i] - 1;
			if (i + B <= N){
				if (vis[(i + B) % A])
					return 0;
				vis[(i + B) % A] = 1;
				L[i + B] = x[i] + 1;
				LL limit = (i + B) / A;
				mod[(i + B) % A] = x[i] + (limit + 1) * INF;
			}
		}
	}
	else{
		for (int i = 0; i <= N; ++i){
			if (vis[i%B]){
				R[i] = mod[i%B];
				mod[i%B] += INF;
			}
			
			x[i] = (L[i] + R[i]) / 2;
			if (i + B <= N)
				L[i + B] = x[i] + 1;
			if (i + A <= N){
				if (vis[(i + A) % B])
					return 0;
				vis[(i + A) % B] = 1;
				R[i + A] = x[i] - 1;
				LL limit = (i + A) / B;
				mod[(i + A) % B] = x[i] - (limit + 1) * INF;
			}
		}
	}
	return 1;
}

int main(){


	while (in >> N >> A >> B){
		if (A%B == 0 || B%A == 0){
			printf("No\n");
		}
		else{
			for (int i = 0; i <= N; ++i){
				L[i] = -(int)1e9;
				R[i] = (int)1e9;
				vis[i] = 0;
			}
			
			if (cale()){
				printf("Yes\n");
				for (int i = 0; i < N; ++i){
					if (x[i] == x[i + 1]){
						printf("Stay\n");
					}
					else if (x[i] < x[i + 1]){
						printf("Right %lld\n", x[i + 1] - x[i]);
					}
					else{
						printf("Left %lld\n", x[i] - x[i + 1]);
					}
				}



			}
			else{
				printf("No\n");
			}

		}

	}


	return 0;
}





