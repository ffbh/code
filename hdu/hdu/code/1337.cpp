#include <iostream>
#include <fstream>
using namespace std;
int num[110];
int dp[110];
int main(){
	//ifstream in("C:\\temp.txt");
	num[1] = 1;
	int k;
	for (int i = 2; i <= 100; ++i){
		k = 0;
		for (int j = 1; j <= i;++j)
		if (i%j == 0)k++;
		num[i] = k;
	}
	dp[1] = 1;
	for (int i = 2; i <= 100;++i)
	if (num[i] % 2 == 1)
		dp[i] = dp[i - 1] + 1;
	else
		dp[i] = dp[i - 1];
	int N,M;
	cin >> N;
	while (N--){
		cin >> M;
		cout << dp[M] << endl;
	}
		
	
	
	

	return 0;
}