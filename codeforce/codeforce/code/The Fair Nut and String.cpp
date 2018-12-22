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

LL mod = 1e9 + 7;


void input(){
	in >> s;



}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		vector<LL> vi;

		int num = 0;
		for (char c : s){
			if (c == 'a'){
				num++;
			}
			else if (c == 'b'){
				if (num){
					vi.push_back(num);
					num = 0;
				}
			}
			else{

			}
		}
		if (num){
			vi.push_back(num);
			num = 0;
		}
		
		if (vi.empty()){
			cout << 0 << endl;
		}
		else{
			LL ans = 1;
			for (LL k : vi){
				ans = ans * (k + 1) % mod;
			}
			ans = (ans + mod - 1) % mod;
			cout << ans << endl;
		}











	}


	return 0;
}





