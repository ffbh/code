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
#define MMAX (int(1e6)+10)
vector<int> prime;
bool vis[MMAX];

void Init(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j+=i)
				vis[j] = 1;
		}
	}
}
struct Node{
	long long p, num;
}tmp;
vector<Node> A, B;
long long N, M;


long long gcd(long long a, long b){
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	long long a, b;
	long long ansA, ansB;
	while (cin >> N >> M){
		A.clear();
		B.clear();
		for (int i = 0; i < prime.size() && N != 1; ++i){
			tmp.num = 0;
			tmp.p = prime[i];
			while (N % prime[i] == 0){
				N /= prime[i];
				tmp.num++;
			}
			if (tmp.num != 0){
				A.push_back(tmp);
			}
		}
		if (N != 1){
			tmp.num = 1;
			tmp.p = N;
			A.push_back(tmp);
		}

		for (int i = 0; i < prime.size() && M != 1; ++i){
			tmp.num = 0;
			tmp.p = prime[i];
			while (M % prime[i] == 0){
				M /= prime[i];
				tmp.num++;
			}
			if (tmp.num != 0){
				B.push_back(tmp);
			}
		}
		if (M != 1){
			tmp.num = 1;
			tmp.p = M;
			B.push_back(tmp);
		}

		a = b = 1;
		for (int i = 0; i < A.size(); ++i){
			a *= (A[i].num + 1);
		}
	
		for (int i = 0; i < B.size(); ++i){
			b *= (B[i].num + 1);
		}
		ansA = a*b;
		ansB = 1;
		int apos = 0, bpos = 0;
		while (apos < A.size() && bpos < B.size()){
			if (A[apos].p == B[bpos].p){
				ansB *= (min(A[apos].num, B[bpos].num)+1);
				apos++;
				bpos++;
			}
			else if (A[apos].p > B[bpos].p){
				bpos++;
			}
			else{
				apos++;
			}
		}

		long long g = gcd(ansA, ansB);
		cout << ansA / g << " " << ansB / g << endl;
	}

	
	return 0;
}