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


int n, a[200010];
string str;


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	in >> str;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		str = '-' + str;
		int st = 1;
		while (st < str.length()){
			if (str[st] == '0'){
				st++;
				continue;
			}

			int en = st;
			while (en < str.length() && str[en] == '1'){
				en++;
			}
			sort(a + st, a + en + 1);
			st = en;
		}

		for (int i = 1; i <= n; ++i){
			if (a[i] != i){
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;










	}


	return 0;
}





