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

int D[1000010];

LL a[300010], c[300010];
int n, m;

int lowbit(int x){
	return x&(-x);
}

void add(int pos,LL v){
	while (pos <= n){
		c[pos] += v;
		pos += lowbit(pos);
	}
}

LL qr(int pos){
	LL sum = 0;
	while (pos > 0){
		sum += c[pos];
		pos -= lowbit(pos);
	}

	return sum;
}

int f[300010];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}


void input(){
	in >> n >> m;
	for (int i = 1; i <= n; ++i)
		//	in >> a[i];
		scanf("%lld", &a[i]);

}


void REPLACE(int l,int r){
	while (l <= r){
		int na = D[a[l]];
		if (na != a[l]){
			add(l, na - a[l]);
			a[l] = na;
			l = find(l + 1);
		}
		else{
			f[l] = find(l + 1);
			l = find(l + 1);
		}
	}
}




int main(){

	for (int i = 1; i<1000010;++i)
	for (int j = i; j<1000010; j += i)
		D[j]++;

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i < n+10; ++i)
			f[i] = i;

		for (int i = 1; i <= n; ++i)
			add(i, a[i]);

		for (int i = 1; i <= m; ++i){
			int t, l, r;
		//	in >> t >> l >> r;
			scanf("%d%d%d", &t, &l, &r);
			if (t == 1){
				REPLACE(l, r);
			}
			else{
				printf("%lld\n", qr(r) - qr(l - 1));

			}


		}










	}


	return 0;
}





