#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
bool dp[2001];
int fun(int n){
	int res = 0;
	for (int i = 1; i <= sqrt(n);++i)
	if (n%i == 0)
		res += i;
	return res;
}
int main(){
//	ifstream in("C:\\temp.txt");
	for (int i = 2; i <= 1000; ++i)
		dp[fun(i)] = 1;
	int T, N;
	cin >> T;
	while (T--){
		cin >> N;
		if (dp[N])
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}