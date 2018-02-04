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


LL a, b, p, x;

LL qm(LL A,LL B){
	LL ret = 1;
	while (B){
		if (B & 1){
			ret = (ret * A) % p;
		}
		A = (A*A) % p;
		B /= 2;
	}
	return ret;
}

int K[1000010];


void input(){
	in >> a >> b >> p >> x;


}

int baoli(){
	int ans = 0;
	for (int i = 1; i <= x; ++i){
		LL l = i%p;
		LL r = qm(a, i);
		if (l * r % p == b){
			ans++;
	//		cout << i << endl;
		}
	}
	return ans;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (x <= p){
			cout << baoli() << endl;
			return 0;
		}

		memset(K, -1, sizeof(K));
		LL A = 1, B = 0;
		while (K[A] == -1){
		
			K[A] = B;
			A = A * a%p;
			B++;
		}
		
		

		LL ans = 0;
		for (int m = 1; m < p; ++m){
			LL num = (x - m) / (p);
			LL base = qm(a, m) * m %p;
			if (num == 0){
				if (base == b)
					ans++;
			}
			else{
				LL aim = b * qm(base, p - 2) % p;
				LL k = K[aim];
				if (num >= k && k != -1){
					ans++;
					num -= k;
					ans += num / (B);
				}

			}
		}

		cout << ans << endl;














	}


	return 0;
}





