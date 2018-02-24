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
#define MMAX (100010)

vector<int> prime;
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


int main(){
	ifstream in("C:\\input.txt");
	Init();
	int T, N, p, q;
	in >> T;
	while (T-- > 0){
		in >> N;
		for (int i = 0; i < prime.size(); ++i){
			if (N%prime[i]==0){
				p = prime[i];
				q = N / prime[i];
				break;
			}
		}
		cout << p << " " << q << endl;
		if (303395437 % p == 0 && 606790875 % q == 0)
			cout << 303395437 / p << " " << 606790875 / q << endl;
		else if (303395437 % q == 0 && 606790875 % p == 0){
			cout << 606790875 / p << " " <<303395437 / q  << endl;
		}
		else
			cout << "NO" << endl;
		cout << endl;




	}


















	return 0;
}