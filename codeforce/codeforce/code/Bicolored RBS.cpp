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
string str;
int E[200010];
int P[200010];
void input(){
	in >> n;
	in >> str;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		vector<int> V;
		for (int i = 0; i < str.length(); ++i){
			if (i == 3){
				int t = 0;
			}
			if (str[i] == '('){
				V.push_back(i);
			}
			else{
				E[i] = V.back();
				P[V.back()] = i;
				V.pop_back();
			}
		}

		assert(V.empty());

		int r, b;
		r = b = 0;
		string ans = "";
		for (int i = 0; i < str.length(); ++i){
			if (i == 2){
				int t = 0;
			}
			if (str[i] == '('){
				if (r <= b){
					r++;
					ans += '0';
				}
				else{
					b++;
					ans += '1';
				}
			}
			else{
				char c = ans[E[i]];
				if (c == '0'){
					r--;
				}
				else{
					b--;
				}
				ans += c;
			}
		}


		cout << ans << endl;






	}


	return 0;
}





