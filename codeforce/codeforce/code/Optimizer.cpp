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
string str[1010];

string a[1010], b[1010], c[1010];
char OP[1010];
void paste(int k){
	int pos = 0;
	int pre = 0;
	int eq, op = -1;
	for (int i = 0; i < str[k].length(); ++i){
		if (str[k][i] == '='){
			eq = i;
		}
		//$, ^, # or &
		if (str[k][i] == '$' || str[k][i] == '^' || str[k][i] == '#' || str[k][i] == '&'){
			op = i;
		}
	}
	
	a[k] = str[k].substr(0, eq);
	if (op == -1){
		b[k] = str[k].substr(eq+1);
		c[k] = "";
	}
	else{
		b[k] = str[k].substr(eq+1, op - eq - 1);
		c[k] = str[k].substr(op+1);
		OP[k] = str[k][op];
	}


}

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> str[i];
}

int mark[1010];

string Get(int k){
	if (c[k] == ""){
		return a[k] + "=" + b[k];
	}
	else{
		return a[k] + "=" + b[k] + OP[k] + c[k];
	}
}

int main(){

	//str[1] = "d12=c";
	//paste(1);
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		memset(mark, -1, sizeof(mark));

		set<string> S;
		S.insert("res");
		vector<string> ans;



		for (int k = n; k >= 1; --k){
			paste(k);

			if (S.count(a[k])){
				if (c[k] == ""){
					for (int i = k + 1; i <= n; ++i){
						if (mark[i] == -1)
							continue;
						bool ok = 0;
						if (a[i] == a[k]){
							ok = 1;
							a[i] = b[k];
						}
						if (b[i] == a[k]){
							ok = 1;
							b[i] = b[k];
						}
						if (c[i] == a[k]){
							ok = 1;
							c[i] = b[k];
						}
						if (ok){
							ans[mark[i]] = Get(i);
						}
					}
				}
				else{
					mark[k] = ans.size();
					ans.push_back(str[k]);
					S.erase(a[k]);
					S.insert(b[k]);
					S.insert(c[k]);
				}
			}
		}

		cout << ans.size() << endl;
		for (int i = (int)ans.size() - 1; i >= 0; --i){
			cout << ans[i] << endl;
		}










	}


	return 0;
}





