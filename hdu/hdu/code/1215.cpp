#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 500000;
_int64 dp[MAXN + 10] = { 0 };
int main(){
	int N;
	cin >> N;
	int n;
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 1;i<=MAXN/2;++i)
	for (int j = i+i; j <=MAXN; j+=i)
		dp[j] += i;
	while (cin >> n)
		cout << dp[n] << endl;

	return 0;
}