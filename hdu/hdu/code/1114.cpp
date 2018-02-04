#include <iostream>
#include <algorithm>
//#include <fstream>
using namespace std;
int W;
int dp[10010];
void CompletePack(int value, int weight){
	for (int i = weight; i<=W; ++i)
	if (dp[i - weight] >=0){
		if (dp[i]<0)
			dp[i] = dp[i - weight] + value;
		else
			dp[i] = min(dp[i], dp[i - weight] + value);
	}
}
int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	int w1, w2;
	cin >> N;
	int value, weight;
	while (N--){
		memset(dp, -1, sizeof(dp));
		//for (int i = 0; i < 10010; ++i)
		//	dp[i] = INT_MIN;
		dp[0] = 0;
		cin >> w1 >> w2;
		W = w2 - w1;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i){
			cin >> value >> weight;
			CompletePack(value, weight);
		}
		if (dp[W] == -1)
			cout << "This is impossible." << endl;
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[W]);
	}


	return 0;
}