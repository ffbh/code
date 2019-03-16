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


string str;
LL now;
void input(){
	in >> str;

}


LL get(int pos){
	LL ans = 0;
	for (int i = pos; i < str.length(); ++i){
		ans = ans * 10 + str[i] - '0';
	}
	return ans;
}

LL get_modify(int pos ,char c1,int change){
	LL ans = 0;
	for (int i = 0; i < str.length(); ++i){
		char c = str[i] - '0';
		if (i < pos){

		}
		else if (i == pos){
			c = c1-'0';
		}
		else{
			c = change;
		}
//		cout << (int)c;
		ans = ans * 10 + c;
	}
	return ans;
	
}


LL get_8(int pos){
	assert(str[pos] == '1');
	LL ans = 0;
	for (int i = 0; i < str.length(); ++i){
		char c = str[i]-'0';
		if (i < pos){

		}
		else if (i == pos){
			c = 0;
		}
		else{
			c = 8;
		}
		ans = ans * 10 + c;
	}
	return ans;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	int CCC = 1;
	while (TEST_CASE-- > 0){
		input();

		while (str[0] == '0'){
			str = str.substr(1);
		}
		now = get(0);
		LL ans = 0;
		for (int k = 0; k < str.length(); ++k){
			char c = str[k] - '0';

			if (c == 1){
		//		cout << "1111" << endl;
				LL k1 = get_modify(k, c + '0' + 1,0);
				LL k2 = get_8(k);
				ans = min(abs(now - k1), abs(now - k2));
				break;

			}

			if (c == 9){
			//	cout << "1222" << endl;
				LL k2 = get_modify(k, c + '0' - 1,8);
				ans = abs(now - k2);
				break;
			}

			if (c % 2 == 1){
			//	cout << "13333" << endl;
				LL k1 = get_modify(k, c + '0' + 1,0);
				LL k2 = get_modify(k, c + '0' - 1,8);
				ans = min(abs(now - k1), abs(now - k2));
				break;
			}
		}

	//	cout << ans << endl;
		printf("Case #%d: %lld\n",CCC++, ans);










	}


	return 0;
}





