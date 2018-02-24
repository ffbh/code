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


string a, b;
LL x;


void input(){
	in >> a >> b >> x;
}

vector<pll> Get(string& s){ // f:zhishu  s:xishu
	LL xishu, zhishu;
	int pos = 0;
	vector<pll> ans;

	while (pos < s.length()){
		LL flag = 1;
		xishu = 1;
		zhishu = 0;
		if (s[pos] == '-'){
			flag = -1;
			pos++;
		}
		else if (s[pos] == '+'){
			pos++;
		}

		if (isdigit(s[pos])){
			xishu = s[pos] - '0';
			pos++;
		}
		
		
		if (s[pos] == 'x'){
			pos++;
			zhishu = 1;
			if (s[pos] == '^'){
				pos++;
				zhishu = s[pos] - '0';
				pos++;
			}
		}
		if (xishu != 0){
			ans.push_back(mp(zhishu, xishu*flag));
		}
	}
	return ans;
}

LL gcd(LL a,LL b){
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);
}

LL mypow(LL a,LL b){
	LL ans = 1;
	for (int i = 1; i <= b; ++i)
		ans *= a;
	return ans;
}

LL cale(const vector<pll>& all){
	LL ans = 0;
	for (pll p : all){
		ans += p.second * mypow(x, p.first);
	}
	return ans;
}

vector<pll> daoshu(vector<pll> all){
	vector<pll> ans;
	for (pll p : all){
		if (p.first != 0){
			ans.push_back(mp(p.first - 1, p.second * p.first));
		}

	}
	return ans;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		


		vector<pll> A = Get(a);
		vector<pll> B = Get(b);

		if (B.size() == 0){
			cout << "INF" << endl;
			continue;
		}


		while (cale(B) == 0 && cale(A) == 0){
			
			A = daoshu(A);
			B = daoshu(B);
		}

		if (cale(B) == 0){
			cout << "INF" << endl;
			continue;
		}

		LL fenzi = cale(A);
		LL fenmu = cale(B);
		LL g = gcd(abs(fenzi), abs(fenmu));
		fenzi /= g;
		fenmu /= g;

		if (fenmu < 0){
			fenzi *= -1;
			fenmu *= -1;
		}

		if (fenzi == 0){
			cout << 0 << endl;
		}
		else if (fenmu == 1){
			cout << fenzi << endl;
		}
		else{
			cout << fenzi << "/" << fenmu << endl;
		}










	}


	return 0;
}





