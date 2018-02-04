#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[60010];

int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i <= 60000; ++i)
		dp[i] = 99999;
	for (int i = 1; i*i <= 60000; ++i){
		int tmp = i*i;
		for (int j = tmp; j <= 60000;++j)
		if (dp[j] > dp[j - tmp] + 1)
			dp[j] = dp[j - tmp] + 1;
	}
	int N;
	while (cin >> N)
		cout << dp[N] << endl;





	return 0;
}