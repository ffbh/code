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

int v[10] = { 1, 0, 0, 0, 1, 0, 1, 0, 2, 1 };

int x, k;

void input(){
	in >> x >> k;


}


int f(int p){
	int ans = 0;
	while (p){
	//	printf("cale %d\n", p % 10);
		ans += v[p % 10];
		p /= 10;
	}
	return ans;
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		
		for (int i = 1; i <= k; ++i){
			if (x <= 1){
				int t = k - i + 1;
				t %= 2;
				if (t){
					x = 1 - x;
				}
				break;
			}
			else{
				x = f(x);
			}
		}

		printf("%d\n", x);

	}


	return 0;
}





