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




int F;

void input(){



}



unordered_map<char, int> M;
char Q[1010];
void _init(){
	memset(Q, 0, sizeof(Q));


}
string temp;
void Get(){
	temp = "";
	string str = "ABCDE";
	temp += str;
	while (next_permutation(str.begin(),str.end())){
		temp += str;
	}
}

char query(int p){
	///*if (p<1 || p>595){
	//	cout << p << endl;
	//}*/
	//assert(p >= 1 && p <= 595);
	//return temp[p - 1];

		FFLUAHALL;
		cout << p << endl;
		FFLUAHALL;
		char c;
		in >> c;
		return c;
}


int main(){


	//string str = "ABCDE";
	/*while (next_permutation(str.begin(), str.end())){
		cout << str << endl;
	}*/
	//Get();


	int TEST_CASE = 1;
	in >> TEST_CASE >> F;
	while (TEST_CASE-- > 0){
		_init();
		input();

		int aim;
		string ans = "";

		M.clear();
		aim = 24;
		for (int i = 1; i <= 119; ++i){
			if (i == 2){
				int t = 0;
			}
			int pp = (i - 1) * 5 + 1;
			Q[pp] = query(pp);
			M[Q[pp]]++;
		}
		for (auto p : M){
			if (p.second != aim){
				ans += p.first;
				break;
			}
		}
		//1

		M.clear();
		aim = 6;
		for (int i = 1; i <= 119; ++i){
			int pp = (i - 1) * 5 + 1 + 1;
			if (Q[pp - 1] == ans.back()){
				Q[pp] = query(pp);
				M[Q[pp]]++;
			}
		}
		for (auto p : M){
			if (p.second != aim){
				ans += p.first;
				break;
			}
		}
		//2

		M.clear();
		aim = 2;
		for (int i = 1; i <= 119; ++i){
			int pp = (i - 1) * 5 + 1 + 2;
			if (Q[pp - 1] == ans.back()){
				Q[pp] = query(pp);
				M[Q[pp]]++;
			}
		}
		for (auto p : M){
			if (p.second != aim){
				ans += p.first;
				break;
			}
		}
		//3

		M.clear();
		aim = 1;
		for (int i = 1; i <= 119; ++i){
			int pp = (i - 1) * 5 + 1 + 3;
			if (Q[pp - 1] == ans.back()){
				Q[pp] = query(pp);
				M[Q[pp]]++;
			}
		}

		set<char> SSSS;
		for (char c : ans){
			SSSS.insert(c);
		}

		for (auto p : M){
			if (p.second == aim){
				SSSS.insert(p.first);
			}
		}
		//4
		for (char c = 'A'; c <= 'E'; ++c){
			if (!SSSS.count(c)){
				ans += c;
				break;
			}
		}

		M.clear();
		for (char c : ans){
			M[c] = 1;
		}

		for (char c = 'A'; c <= 'E'; ++c){
			if (!M.count(c)){
				ans += c;
				break;
			}
		}


		cout << ans << endl;

		FFLUAHALL;
		char t;
		in >> t;
		assert(t == 'Y');










	}


	return 0;
}





