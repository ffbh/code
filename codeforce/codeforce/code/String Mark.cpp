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

string a, b;


int all[30];
void input(){
	in >> a >> b;


}



LL fac[1000010];
LL inv[1000010];
LL mod = 1e9 + 7;

LL qm(LL a, LL p){
	LL ret = 1;
	while (p){
		if (p % 2)
			ret = (ret*a) % mod;
		a = (a*a) % mod;
		p /= 2;
	}
	return ret;
}

void Init(){
	fac[0] = 1;
	for (int i = 1; i < 1000010; ++i)
		fac[i] = fac[i - 1] * i%mod;

	inv[1000009] = qm(fac[1000009], mod - 2);
	for (int i = 1000008; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}


LL tmp[30];
LL src, d_num;
void oop(LL idx, LL op){
	src = src * fac[d_num + op] % mod;
	src = src * inv[d_num] % mod;
	src = src * fac[tmp[idx]] % mod;
	src = src * inv[tmp[idx] + op] % mod;
	tmp[idx] += op;
	d_num += op;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		Init();

		int pos = 0;
		while (a[pos] == b[pos])
			pos++;
		a = a.substr(pos);
		b = b.substr(pos);
		for (int i = 0; i < a.length(); ++i)
			a[i] -= ('a' - 1);
		for (int i = 0; i < b.length(); ++i)
			b[i] -= ('a' - 1);

		for (char c : a){
			all[c]++;
		}

		

		LL ans = 0;

		d_num = a.length();
		src = fac[d_num];
		for (int i = 0; i < 30; ++i){
			src = src * inv[all[i]] % mod;
			tmp[i] = all[i];
		}


		
		for (int i = 0; i < a.length() - 1 ; ++i){
		
			if (i == 0){
				for (char c = a[i] + 1; c < b[i]; ++c){
					if (tmp[c] > 0){
						oop(c, -1);
						ans = (ans + src) % mod;
						oop(c, 1);
					}
				}
			}
			else{
				for (char c = a[i] + 1; c < 30; ++c){
					if (tmp[c] > 0){
						oop(c, -1);
						ans = (ans + src) % mod;
						oop(c, 1);
					}
				}

			}
			oop(a[i], -1);
		}


		d_num = a.length();
		src = fac[d_num];
		for (int i = 0; i < 30; ++i){
			src = src * inv[all[i]] % mod;
			tmp[i] = all[i];
		}
	
		for (int i = 0; i < b.length() - 1; ++i){
			if (i == 0){
				
			}
			else{
				for (char c = 0; c < b[i]; ++c){
					if (tmp[c] > 0){
						oop(c, -1);
						ans = (ans + src) % mod;
						oop(c, 1);
					}
				}

			}

			oop(b[i], -1);
			if (tmp[b[i]] < 0)
				break;
		}


		cout << ans << endl;



	}


	return 0;
}
