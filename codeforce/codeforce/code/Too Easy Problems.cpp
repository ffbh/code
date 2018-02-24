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

LL n, T;
vector<pair<int, pii> > all;


void input(){
	in >> n >> T;
	for (int i = 1; i <= n; ++i){
		int a, b;
		in >> a >> b;
		all.pb(mp(b, mp(a, i)));
	}
}

bool ok(int m){
	LL sum = 0;
	LL num = 0;
	for (pair<int, pii> p : all){
		if (p.second.first >= m){
			sum += p.first;
			num++;
			if (sum > T){
				return 0;
			}
			if (num >= m){
				return 1;
			}
		}
		
	}
	return 0;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(all.begin(), all.end());
		int L = 0, R = n + 1, ans = 0;
		while (L <= R){
			int mid = (L + R) / 2;
			if (ok(mid)){
				ans = mid;
				L = mid + 1;
			}
			else{
				R = mid - 1;
			}
		}

		printf("%d\n", ans);
		printf("%d\n", ans);
		int num = ans;
		for (pair<int, pii> p : all){
			if (num <= 0){
				break;
			}
			if (p.second.first >= ans){
				printf("%d ", p.second.second);
				num--;

			}

		}

		cout << endl;






	}


	return 0;
}





