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

#define MMAX (100010)
bool vis[MMAX];
vector<int> prime;
LL p, y;
void Init(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j += i)
				vis[j] = 1;
		}
	}
}

void input(){
	in >> p >> y;


}

bool ok(int h){
	for (int i = 0; i < prime.size() && prime[i] <= p; ++i){
		if (h % prime[i] == 0)
			return 0;
	}
	return 1;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		Init();
		input();

		unordered_set<int> S;
		LL low = 1e12;
		for (int i = 0; i < prime.size() && prime[i]<=p; ++i){
			LL k = y / prime[i] * prime[i];
			low = min(low, k);
			S.insert((int)k);
		}
		while (y > p){
			if (ok(y)){
				cout << y << endl;
				return 0;
			}
			y--;

		}

		cout << -1 << endl;










	}


	return 0;
}





