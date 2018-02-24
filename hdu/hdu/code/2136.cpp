#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int prime[1000000];
void Init(){
	int sum = 0;
	for (int i = 2; i < 1000000; ++i)
	if (!prime[i]){
		sum++;
		prime[i] = sum;
		for (int j = 1; i*j < 1000000; ++j)
			prime[i*j] = sum;
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	Init();
	while (~scanf("%d", &N)){
		printf("%d\n", prime[N]);
	}




	return 0;
}