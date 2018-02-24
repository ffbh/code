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

LL n, a, b;



void input(){
	in >> n >> a >> b;


}


LL gcd(LL a, LL b){
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);

}

void ex_gcd(LL a, LL b, LL& x, LL& y,const LL k){
	if (b == 0){
		x = k;
		y = 0;
	}
	else{
		ex_gcd(b, a%b, x, y,k);
		LL tmp = y;
		y = x - a / b*y;
		x = tmp;
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL g = gcd(a, b);
		if (n%g == 0){
		
			a /= g;
			b /= g;
			n /= g;
			LL x, y;
			ex_gcd(a, b, x, y,n);
			bool ex = 0;

			if (y < 0){
				ex = 1;
				swap(a, b);
				swap(x, y);
			}

			if (x < 0){
				LL div = abs(x) / b;
				if (abs(x) % b != 0){
					div++;
				}
				x += b*div;
				y -= a*div;
			}

			if (y < 0 || x < 0){
				cout << "NO" << endl;
			}
			else{
				cout << "YES" << endl;
				if (ex)
					swap(x, y);

				cout << x << " " << y << endl;

			}
		}
		else{
			cout << "NO" << endl;
		}













	}


	return 0;
}





