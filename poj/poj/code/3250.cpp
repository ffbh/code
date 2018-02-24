#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[80010];
int dp[80010];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		for (int i = 1; i <= N; ++i)
		//	in >> data[i];
			scanf("%d", &data[i]);
		data[N + 1] = INT_MAX;
		long long int sum = 0;
		for (int i = N; i >= 1; --i){
			dp[i] = i + 1;
			while (data[i]> data[dp[i]])
				dp[i] = dp[dp[i]]+1;	
			dp[i]--;
			sum += dp[i] - i;
		}
		cout << sum << endl;
	}
	return 0;
}