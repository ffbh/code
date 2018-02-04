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

long long dp[6010];
int price[11] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5 };
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	double p;
	dp[0] = 1;
	for (int i = 0; i < 11; ++i){
		int k = price[i] / 5;
		for (int j = k; j < 6010; ++j)
			dp[j] += dp[j - k];
	}
	while (in >> p){
		int N = round((p * 100));
		if (N == 0)
			break;
		printf("%6.2f%17lld\n",p, dp[N/5]);
	}


	return 0;
}