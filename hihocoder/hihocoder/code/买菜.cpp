
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;

int data[30], N, X, dp[210], sum;

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> X;
	sum = 0;
	for (int i = 1; i <= N; ++i){
		cin >> data[i];
		sum += data[i];
	}
	if (sum < X)
		cout << -1 << endl;
	else{
		dp[0] = 1;
		for (int i = 1; i <= N;++i)
		for (int j = 210; j >=data[i]; --j)
		if (dp[j - data[i]])
			dp[j] = 1;
		for (int i = X;;++i)
		if (dp[i]){
			cout << i << endl;
			break;
		}
	}














	return 0;
}