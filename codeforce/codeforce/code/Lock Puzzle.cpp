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



int n;
string s, t;
void input(){
	in >> n >> s >> t;


}

bool permu(){
	map<char, int> mci;
	for (char c : s){
		mci[c]++;
	}
	for (char c : t){
		mci[c]--;
	}
	for (pair<char, int> p : mci){
		if (p.second != 0)
			return 0;
	}
	return 1;
}

int search(string& S,char c,int L){
	for (int i = L; i < n; ++i){
		if (S[i] == c)
			return i;
	}
	assert(0);
	return -1;
}

vector<int> ans;

void shift(string& str,int x){
	string A = str.substr(0, str.length() - x);
	string B = str.substr(str.length() - x);
	reverse(B.begin(), B.end());
	str = B + A;

	ans.push_back(x);

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (permu()){
			vector<char> vc;
			int ml, mr;
			if (t.length() % 2 == 0){
				ml = t.length() / 2 - 1;
				mr = t.length() / 2;
				vc.push_back(t[ml]);
				vc.push_back(t[mr]);
			}
			else{
				ml = mr = t.length() / 2;
				vc.push_back(t[ml]);
			}
			ml--;
			mr++;
			while (ml >= 0){
				vc.push_back(t[ml--]);
				vc.push_back(t[mr++]);
			}
			string now = s;
			int R = 0;
			for (char c : vc){
				int idx = search(now, c, R);
				int x = now.length() - idx;
				shift(now, x);
	//			cout << now << endl;
				if (now == "acbabb"){
					int t = 0;
				}
				int rest = now.length() - x - R;
				if (rest > 0){
					shift(now, rest);
		//			cout << now << endl;
				}
				R++;
				shift(now, R);
	//			cout << now << endl;
			}
			if (now != t){
				shift(now,now.length());
			}
			assert(now == t);

			printf("%d\n", ans.size());
			for (int k : ans){
				printf("%d ", k);
			}
			cout << endl;

		}
		else{
			cout << -1 << endl;
		}


	}


	return 0;
}





