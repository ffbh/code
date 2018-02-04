#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
#define MMAX (32010)

vector<int> prime;
bool vis[MMAX];
void Init(){
	for (int i = 2; i < MMAX;++i)
	if (!vis[i]){
		prime.push_back(i);
		for (int j = i + i; j < MMAX; j += i)
			vis[j] = 1;
	}

}



int quick_mod(int a,int p,int m){
	int ret = 1;
	while (p){
		if (p & 1)
			ret = a*ret%m;
		a = a*a%m;
		p /= 2;
	}
	return ret;

}



void ex_gcd(int a,int b,int& x,int& y){
	if (b == 0){
		x = 1;
		y = 0;
	}
	else{
		ex_gcd(b, a%b, x, y);
		int tmp = x;
		x = y;
		y = tmp - a / b*y;
	}
}


int main(){
	ifstream in("C:\\input.txt");
	Init();



	int T, e, n, c, inve, t, pq, q;
	cin >> T;
	while (T-- > 0){
		cin >> e >> n >> c;
		for (int i = 1; i < prime.size(); ++i){
			if (n%prime[i] == 0){
		//		q = prime[i];
				pq = (prime[i] - 1)*(n / prime[i] - 1);
				break;
			}
		}
		ex_gcd(e, pq, inve, t);
		inve %= pq;
		inve += pq;
		inve %= pq;
		printf("%d\n", quick_mod(c, inve, n));

	}



	return 0;
}