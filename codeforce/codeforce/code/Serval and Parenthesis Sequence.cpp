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

void input(){
	in >> n;
	in >> str;


}
bool ok;
string change(string s){
	string ret = "";
	int a, b, c;
	a = b = c = 0;
	for (char C : s){
		if (C == '('){
			a++;
		}
		else if (C == ')'){
			b++;
		}
		else{
			c++;
		}
	}
	int C = b - a + c;
	if (C < 0 || C % 2 != 0){
		ok = 0;
	}
	int c2 = C / 2;
	int v = 0;
	for (int i = 0; i < s.length(); ++i){
		if (str[i] == '?'){
			if (c2>0){
				c2--;
				ret += '(';
				v++;
			}
			else{
				ret += ')';
				v--;
			}
		}
		else if(str[i] == '('){
			ret += str[i];
			v++;
		}
		else{
			ret += str[i];
			v--;
		}
		
		if (v < 0){
			ok = 0;
		}

	}
	return ret;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		int v = 0;
		ok = 1;
		for (char c : str){
			if (c == '('){
				v++;
			}
			else if (c == ')'){
				v--;
			}
			else{
				v++;
			}
			if (v < 0){
				ok = 0;
			}
		}
		if (n % 2 == 1 || str.back() == '('){
			ok = 0;
		}

		string ans;
		if (ok){
			str = str.substr(1, n - 2);
			ans = change(str);
			ans = "(" + ans + ")";
		}



		if (ok){
			cout << ans << endl;
		}
		else{
			cout << ":(" << endl;
		}










	}


	return 0;
}





