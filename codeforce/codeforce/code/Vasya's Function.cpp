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
using namespace std;
vector<int> prime;
#define MMAX ((int)1e6+10)
bool vis[MMAX];
void Init(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j += i)
				vis[j] = 1;
		}
	}
}

long long gcd(long long a,long long b){
	if (b == 0)
		return a;
	else{
		return gcd(b, a%b);
	}
}

void factor(long long p){
	cout << p << ":     ";
	for (int i = 0; i < prime.size(); ++i){
		while (p && p%prime[i] == 0){
			cout << prime[i] << "*";
			p /= prime[i];
		}
	}
	cout << p << endl;
}
void cale(long long x,long long y){
	for (int i = 0; i < 100 && y; ++i){
		factor(y);
		long long g = gcd(x, y);
		cout << x << " " << y << " " << g << endl;
		y -= g;
	}
}

vector<pair<long long, long long> > X;

void fac(long long p){
	//X.push_back(make_pair(1,1));
	for (int i = 0; i < prime.size() && p!=1; ++i){
		int num = 0;
		while (p%prime[i] == 0){
			num++;
			p /= prime[i];
		}
		if (num){
			X.push_back(make_pair(prime[i], num));
		}
	}
	if (p != 1){
		X.push_back(make_pair(p, 1));
	}
	
}



int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	Init();
	long long x, y;
	in >> x >> y;
//	cale(x, y);
//	cale(4, 182);
	fac(x);


	long long ans = 0;
	while (y){
		long long g = gcd(x, y);
		if (g == x){
			ans += y / g;
			break;
		}
		long long resty = y / g;
		long long add = (long long)1e18;
		for (pair<long long, long long> p : X){
			if (resty % p.first != 0){
				add = min(add, resty%p.first);
			}
		}
		y -= g*add;
		ans += add;

	}
	cout << ans << endl;


	return 0;
}





