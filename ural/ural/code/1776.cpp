#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
double dp[510];
void Init(){
	dp[0] = 0;
	dp[1] = 10;
	for (int i = 2; i < 510; ++i){
		double p = 1.0 / i;
		dp[i] = 0;
		for (int j = 1; j <= i; ++j){
			dp[i] += (10.0 + max(dp[j - 1], dp[i - j]));
		}
		dp[i] *= p;
	}

}


int main(){
	ifstream in("C:\\input.txt");
	Init();

	int N;
	while (cin >> N){
		printf("%.10lf\n", dp[N-2]);
	}


	return 0;
}