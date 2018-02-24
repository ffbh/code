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


typedef unsigned long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair



int n, p;
LL V;
LL x[1010], y[1010];

void input(){
	in >> n >> V >> p;
	for (int i = 1; i <= n; ++i)
		in >> x[i];
	for (int i = 1; i <= n; ++i)
		in >> y[i];

}


LL cale(LL v){
	if (p == 1){
		return v;
	}
	else if (p == 2){
		return v*v;
	}
	else{
		if (v > 1e6){
			return LL(1e18) + 1;
		}
		else
			return v*v*v;
	}

}


LL calu(int a,int b){
	int pa = a;
	int pb = b;
	LL sum = 0;
	LL ans = 0;
	while (pa <= n && pb <= n){
		if (x[pa] > y[pb]){
			sum += cale(x[pa]-y[pb]);
		}
		else{
			sum += cale(y[pb] - x[pa]);
		}
		
		while (sum > V){
			if (x[a] > y[b]){
				sum -= cale(x[a] - y[b]);
			}
			else{
				sum -= cale(y[b] - x[a]);
			}
			a++;
			b++;

		}
		pa++;
		pb++;
		ans += pa - a;
	}
	return ans;
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL ans = calu(1, 1);
		for (int i = 2; i <= n; ++i){
			ans += calu(1, i);
			ans += calu(i, 1);

		}

		cout << ans << endl;











	}


	return 0;
}





