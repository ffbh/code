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
#define MMAX ((int)1e7+10)
bool vis[MMAX];
vector<int> prime;

void Init(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j += i)
				vis[j] = 1;
		}

	}

}

int getDigit(long long num){
	int dig = 0;
	while (num){
		dig++;
		num /= 10;
	}
	return dig;
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	long long N;
	while (cin >> N){
		int sum = 0;
		for (int i = 0; i < prime.size() && sum <= 20 && prime[i] <= N; ++i){
			while (N%prime[i] == 0){
				sum++;
				N /= prime[i];
			}
		}
		if (N==1&&sum == 20)
			cout << "Yes" << endl;
		else if (sum == 19 && getDigit(N) >= 6){
			bool f = 1;
			for (int i = prime.back() + 1; i <= sqrt(N); ++i){
				if (N%i == 0){
					f = 0;
					break;
				}
			}
			if (f)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;

		}
		else
			cout << "No" << endl;
	}
	return 0;
}