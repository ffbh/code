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

string str;

void input(){
	in >> str;


}

int num[30];


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		memset(num, 0, sizeof(num));

		for (char c : str){
			num[c - 'a']++;
		}

		vector<int> S;
		for (int i = 0; i < 30; ++i){
			if (num[i]){
				S.push_back(i);
			}
		}
		
		string str = "";
		for (int i = 1; i < S.size(); i += 2){
			int v = S[i];
			for (int j = 1; j <= num[v]; ++j){
				str += ('a' + v);
			}
		}
		for (int i = 0; i < S.size(); i += 2){
			int v = S[i];
			for (int j = 1; j <= num[v]; ++j){
				str += ('a' + v);
			}
		}
		bool ok = 1;
		char pre = 0;
		for (char c : str){
			if (abs(c - pre) == 1){
				ok = 0;
				break;
			}
			pre = c;
		}

		if (ok){
			cout << str << endl;

		}
		else{
			cout << "No answer" << endl;
		}







	}


	return 0;
}





