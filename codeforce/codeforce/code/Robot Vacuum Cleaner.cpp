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

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  
LL ans;

pii ch(string& s){
	pii p = mp(0, 0);
	for (char c : s){
		if (c == 's'){
			p.first++;
		}
		else{
			ans += p.first;
			p.second++;
		}
	}
	return p;
}
int n;
vector<pii> all;

bool cmp(pii& a,pii& b){
	LL lf = (LL)a.first*b.second;
	LL rg = (LL)a.second*b.first;
	return lf > rg;
}

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		string s;
		in >> s;
		all.push_back(ch(s));
	}


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		LL sum = 0;
		sort(all.begin(), all.end(), cmp);
		for (pii p : all){
			ans += sum * p.second;
			sum += p.first;
		}
		cout << ans << endl;












	}


	return 0;
}





