#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
bool ok[151];
vector<int> prime;
_int64 dp[151];
void Init(){
	for (int i = 2; i < 151;++i)
	if (!ok[i]){
		prime.push_back(i);
		for (int j = 1; i*j < 151; ++j)
			ok[i*j] = 1;
	}
}




int main(){
	//ifstream in("C:\\temp.txt");
	Init();
	dp[0] = 1;
	for (int i = 0; i < prime.size();++i)
	for (int j = prime[i]; j < 151; ++j)
		dp[j] += dp[j - prime[i]];
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		cout << dp[N] << endl;

	}




	return 0;
}