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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;


LL n, a[200010];

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		priority_queue<LL,vector<LL>,greater<LL>> Q;
		for (int i = 1; i <= n; ++i){
			Q.push(a[i]);
		}
		LL ans = 0;
		while (Q.size() != 1 ){
			if (Q.size() % 2 == 0){
				LL tmp = 0;
				for (int i = 0; i < 2 && !Q.empty(); ++i){
					tmp += Q.top();
					Q.pop();
				}
				ans += tmp;
				Q.push(tmp);

			}
			else{
				LL tmp = 0;
				for (int i = 0; i < 3 && !Q.empty(); ++i){
					tmp += Q.top();
					Q.pop();
				}
				ans += tmp;
				Q.push(tmp);
			}
			
		}
		cout << ans << endl;
		
		










	}


	return 0;
}





