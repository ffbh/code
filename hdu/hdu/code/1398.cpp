#include <iostream>
#include <fstream>
using namespace std;
int price[20];
int dp[400];

int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i <= 17; ++i)
		price[i] = i*i;
	dp[0] = 1;
	for (int i = 1; i <= 17;++i)
	for (int k = price[i]; k < 350; ++k)
		dp[k] += dp[k - price[i]];
	int N;
	while (cin >> N&&N)
		cout << dp[N] << endl;

	return 0;
}