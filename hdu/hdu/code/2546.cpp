#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
bool dp[1100];
int data[1010];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N&&N){
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		cin >> M;
		dp[0] = 1;
		sort(data, data + N);
		for (int i = 0; i < N;++i)
		for (int j = M - 5+data[i]; j >= data[i];--j)
		if (dp[j - data[i]])
			dp[j] = 1;
		for (int i = 1100; i >= 0;--i)
		if (dp[i]){
			cout << M - i << endl;
			break;

		}
	}
	return 0;
}