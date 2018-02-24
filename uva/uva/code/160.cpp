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
vector<int> prime;
int num[30];
bool isprime(int n){
	for (int i = 2; i <= sqrt(n); ++i){
		if (n%i == 0)
			return 0;
	}
	return 1;
}



int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	for (int i = 2; i <= 100;++i)
	if (isprime(i))
		prime.push_back(i);



	int N;
	while (in >> N&&N){
		for (int i = 0; i < 30; ++i)
			num[i] = 0;
		for (int k = 1; k <= N; ++k){
			int now = k;
			for (int i = 0; i < prime.size() && now != 1; ++i){
				while (now%prime[i] == 0){
					num[i]++;
					now /= prime[i];
				}
			}
		}

		int pos = 29;
		while (num[pos] == 0)
			pos--;

		printf("%3d! =", N);
		for (int i = 0; i <= pos; ++i){
			printf("%3d", num[i]);
			if ((i + 1) % 15 == 0 && i + 1 <= pos)
				printf("\n      ");
		}
		cout << endl;
	}


	return 0;
}