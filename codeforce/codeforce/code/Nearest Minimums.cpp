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


int n;
vector<pii> all;

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		int a;
		in >> a;
		all.push_back(mp(a, i));
	}


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(all.begin(), all.end());
		int M = all[0].first;
		int pre = -1;
		int ans = n + 1;
		for (pii p : all){
			if (p.first != M)
				break;
			if (pre == -1){
				pre = p.second;
			}
			else{
				ans = min(ans, p.second - pre);
				pre = p.second;
			}


		}

		cout << ans << endl;











	}


	return 0;
}





