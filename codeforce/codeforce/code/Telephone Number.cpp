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

void _init(){



}

int n;
string s;

void input(){
	in >> n;
	in >> s;


}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();
		bool ok = 0;

		if (s.length() >= 11){
			for (int i = 0; i < s.length() - 10; ++i){
				if (s[i] == '8'){
					ok = 1;
					break;
				}
			}
		}

		if (ok){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}

		













	}


	return 0;
}





