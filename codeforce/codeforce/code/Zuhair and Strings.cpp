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

string s;
int n, k;


void input(){
	in >> n >> k;
	in >> s;

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int ans = 0;
		for (char p = 'a'; p <= 'z'; ++p){
			int x = 0;
			int num = 0;
			for (char c : s){
				if (c == p){
					num++;
				}
				else{
					num = 0;
				}
				if (num == k){
					x++;
					num = 0;
				}

			}
			ans = max(ans, x);
		}

		cout << ans << endl;













	}


	return 0;
}





