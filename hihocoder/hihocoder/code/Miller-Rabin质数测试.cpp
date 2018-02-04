#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
using namespace std;
#define ll long long 
int T;

ll quickmod(ll a, ll p, ll m){
	ll ret = 1;
	while (p){
		if (p & 1)
			ret = (ret * a) % m;
		a = (a*a) % m;
		p /= 2;
	}
	return ret;

}

bool Ftest(ll a,ll p){
	return quickmod(a, p - 1, p) == 1;
}

bool Rtest(ll a,ll p){
	ll u = p - 1;
	ll pre = 1;
	while (u % 2 == 0){
		u /= 2;
		ll ret = quickmod(a, u, p);
		if (pre == 1 && ret != 1 && ret != p - 1)
			return 0;
		pre = ret;
		
	}
	return 1;
}




bool test(ll d){
	if (d == 2)
		return 1;
	srand(time(0));
	for (int i = 0; i < 100; ++i){
		ll k = abs(rand()) % (d-2) + 2;
		if (!Ftest(k, d))
			return 0;
		if (!Rtest(k, d))
			return 0;
	}
	return 1;
}

int main(){

	ifstream in("C:\\input.txt");
	in >> T;
	while (T--){
		ll d;
		in >> d;
		if (!test(d))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;


	}

	return 0;
}