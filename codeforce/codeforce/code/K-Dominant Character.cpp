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


string s;


void input(){
	in >> s;


}


int cale(char c){
	int ans = -1;
	int pre = -1;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == c){
			ans = max(ans, i - pre);
			pre = i;
		}
	}

	ans = max(ans, (int)s.length() - pre);
	return ans;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int ans = s.length();
		for (char c = 'a'; c <= 'z'; ++c){
			ans = min(ans, cale(c));


		}




		cout << ans << endl;









	}


	return 0;
}





