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

int n, m;
LL a[100010];
LL c[100010];
deque<pair<pll, int> > order;


void input(){
	in >> n >> m;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	for (int i = 1; i <= n; ++i)
		in >> c[i];
	

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= n; ++i){
			order.push_back(mp(mp(c[i], a[i]), i));
		}
		sort(order.begin(), order.end());

		while (m-- > 0){
			LL kind, num;
			in >> kind >> num;
			LL ans = 0;
			ans += min(num, a[kind]) * c[kind];
			if (a[kind] >= num){
				a[kind] -= num;
				num = 0;
			}
			else{
				num -= a[kind];
				a[kind] = 0;
				while (num > 0 && !order.empty()){
					kind = order.front().second;
					ans += min(num, a[kind]) * c[kind];
					if (a[kind] >= num){
						a[kind] -= num;
						num = 0;
					}
					else{
						num -= a[kind];
						a[kind] = 0;
					}
					if (a[kind] == 0){
						order.pop_front();
					}
				}
			}
			if (num != 0){
				ans = 0;
			}
			printf("%lld\n", ans);

		}











	}


	return 0;
}





