#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
bool dp[2001];
#define MMAX 1000010
int F[MMAX];

int main(){
//	ifstream in("C:\\temp.txt");
	
	for (int i = 1; i < MMAX; ++i){
		if (F[i] < 1100){
			dp[F[i]] = 1;
		}
		for (int j = i + i; j < MMAX; j += i)
			F[j] += i;
		
	}

	int T, N;
//	cin >> T;
	scanf("%d", &T);
	while (T--){
	//	cin >> N;
		scanf("%d", &N);
		if (dp[N])
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}