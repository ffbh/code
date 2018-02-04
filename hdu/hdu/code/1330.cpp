#include <iostream>
#include <string>
#include <fstream>
using namespace std;
double dp[100100];
int main(){
	ifstream in("C:\\temp.txt");
	printf("# Cards  Overhang\n");
	int N;
	dp[1] = 0.5;
	for (int i = 2; i < 100000; ++i)
		dp[i] = dp[i - 1] + double(1) / (2 * i);
	while (cin >> N)
		printf("%5d%10.3f\n", N, dp[N]);
		
	
	

	return 0;
}