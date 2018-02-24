#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;
int prime[7000];
bool Isprime(int n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)return 0;
	return 1;
}
int main(){
	ifstream in("C:\\temp.txt");
	map<int, int> mii;
	int cnt = 0;
	for (int i = 2; i <= 65536;++i)
	if (Isprime(i))prime[cnt++] = i;
	int N;
	int CASE = 1;
	int ok = 0;
	while (cin >> N&&N > 0){
		if (ok)cout << endl;
		ok = 1;
		mii.clear();
		for (int i = 0; prime[i] <= N; ++i)
		while(N%prime[i] == 0){
			mii[prime[i]]++;
			N /= prime[i];
		}
		if (N > 1)
			mii[N]++;
		map<int, int>::iterator it = mii.begin();
		int size = mii.size();
		printf("Case %d.\n", CASE++);
		for (int i = 0; i < size ; ++i,it++)
			printf("%d %d ", it->first, it->second);
		printf("\n");
	
	
	
	}

	return 0;
}