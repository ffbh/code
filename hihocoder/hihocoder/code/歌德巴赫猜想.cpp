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
			for (int j = i + i; j < MMAX; j += i)
				vis[j] = 1;
		}
	}

}

int main(){
	ifstream in("C:\\input.txt");
	Init();

	int N;
	while (cin >> N){
		int ansA, ansB;
		for (int i = 0; i < prime.size(); ++i){
			int d1 = prime[i];
			int d2 = N - prime[i];
			if (!vis[d2]){
				ansA = min(d1, d2);
				ansB = max(d1, d2);
				break;
			}
		}
		cout << ansA << " " << ansB << endl;


	}















	return 0;
}