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
LL a[1000010];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
	//	in >> a[i];
		scanf("%d", &a[i]);
	}
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int ans = 0;
		for (int i = 1; i <= n; ++i){
			a[i] = i - a[i];
		}
		LL low = 1e18;
		for (int i = n; i >= 1; --i){
			if (i < low){
				ans++;
			}
			low = min(low, a[i]);
		}
		cout << ans << endl;












	}


	return 0;
}





