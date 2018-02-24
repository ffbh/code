#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 dp[100001];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	dp[1] = 1;
	for (_int64 i = 2; i < 100001;++i)
	if (i % 3 == 0)
		dp[i] = dp[i - 1] + i*i*i;
	else
		dp[i] = dp[i - 1] + i;
	while (cin >> N&&N >= 0){
		cout << dp[N] << endl;
	
	}





	return 0;
}