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

int n, s, f;
LL a[200010];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	in >> s >> f;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int len = f - s;
		for (int i = n + 1; i <= 2 * n; ++i)
			a[i] = a[i - n];
		LL sum = 0;
		for (int i = 1; i <= len; ++i)
			sum += a[i];
		LL ans = sum; 
		vector<int> V;
		V.push_back(1);
		for (int i = 2; i <= n; ++i){
			sum -= a[i - 1];
			sum += a[i + len - 1];
			if (sum > ans){
				ans = sum;
				V.clear();
				V.push_back(i);
			}
			else if (sum == ans){
				V.push_back(i);
			}
		}

		int ret = n;
		for (int p : V){
			int t;
			if (s >= p){
				t = s - p;
			}
			else{
				t = n - p + s;
			}
			ret = min(ret, t);
		}
		cout << ret + 1 << endl;










	}


	return 0;
}





