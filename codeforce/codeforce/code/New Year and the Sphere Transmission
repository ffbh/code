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


LL n;

void input(){
	in >> n;


}
set<LL> ans;
void fun(int k){
	LL sum = 0;
	int id = 1 + k;
	while (id != 1){
		sum += id;
		id += k;
		if (id > n){
			id -= n;
		}
	}
	sum += id;
	ans.insert(sum);

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		ans.clear();
		ans.insert(1);
		ans.insert((1 + n)*n / 2);
		for (int k = 2; k <= sqrt(n); ++k){
			if (n % k == 0){
				LL num = n / k;
				LL vv = num + (num)*(num - 1) / 2 * k;
				ans.insert(vv);


				fun(n / k);
			}
		}

		for (LL v : ans){
			printf("%lld ", v);
		}
		cout << endl;










	}


	return 0;
}





