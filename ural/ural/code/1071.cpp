#include <iostream>
#include <string>
#include <fstream>
using namespace std;
long long fib[100];
int dp[50][2];
int main(){
	ifstream in("C:\\temp.txt");
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 3;
	for (int i = 3; i < 100; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= 45;++i)







	return 0;
}