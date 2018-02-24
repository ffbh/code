#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
bool prime[11000];

int main(){
//	ifstream in("C:\\temp.txt");
	multiset<int> si;
	for (int i = 2; i <= 10100; ++i)
		if (prime[i] == 0){
			si.insert(i);
			for (int j = i; j*i <= 10100; ++j)
				prime[j*i] = 1;
		}
	int Q, N;
	scanf("%d", &Q);
	while (Q--){
		//cin >> N;
		scanf("%d", &N);
		printf("%d\n" ,*si.upper_bound(N));
	}
	return 0;
}