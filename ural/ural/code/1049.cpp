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
#define MMAX (10010)
bool vis[MMAX];
int num[1500];
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



int main(){
	ifstream in("C:\\input.txt");
	Init();
	for (int i = 0; i < 10; ++i){
		int digit;
		cin >> digit;
		for (int k = 0; k < prime.size() && prime[k] <= digit; ++k){
			while (digit % prime[k] == 0){
				digit /= prime[k];
				num[k]++;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < 1500; ++i)
		ans = (ans*(num[i] + 1)) % 10;
	cout << ans << endl;
	return 0;
}