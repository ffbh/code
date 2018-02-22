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
int n;

void input(){
	in >> n >> s;



}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int x, y, ans = 0;
		int v = 0;
		x = y = 0;
		int pre = 0;
		for (char c : s){
			if (c == 'U'){
				x++;
				v++;
			}
			else{
				y++;
				v--;
			}
			if (v*pre != 0){
				if (v*pre < 0){
					ans++;
					pre = v;
				}
			}
			else{
				if (pre == 0)
					pre = v;
				else{

				}
			}
		}
		cout << ans << endl;












	}


	return 0;
}





