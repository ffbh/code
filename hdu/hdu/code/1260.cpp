#include <iostream>
//#include <fstream>
using namespace std;
int Si[2010];
int Di[2010];
int dp[2010];

void Print(int t){
	int h = t / 3600;
	h += 8;
	t %= 3600;
	int m = t / 60;
	t %= 60;
	int s = t;
	printf("%02d:%02d:%02d am\n", h, m, s);



}
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	int k;
	while (N--){
		memset(dp, 0, sizeof(dp));
		cin >> k;
		for (int i = 1; i <= k; ++i)
			//	in >> Si[i];
			scanf("%d", &Si[i]);
		for (int i = 2; i <= k; ++i)
			//	in >> Di[i];
			scanf("%d", &Di[i]);
		dp[1] = Si[1];
		for (int i = 2; i <= k; ++i){
			dp[i] = dp[i - 1] + Si[i];
			if (Di[i] + dp[i - 2] < dp[i])
				dp[i] = Di[i] + dp[i - 2];
		}
		Print(dp[k]);
	}

	return 0;
}