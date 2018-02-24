#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[1000010];
void Init(){
	dp[0] = 1;
	for (int i = 1; i <= 1000000; i *= 2)
	for (int j = i; j <= 1000000; ++j){
		dp[j] = (dp[j] + dp[j - i]);
		while (dp[j] >= 1000000000)
			dp[j] -= 1000000000;
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	Init();
	while (~scanf("%d", &N))
		printf("%d\n", dp[N]);



	return 0;
}