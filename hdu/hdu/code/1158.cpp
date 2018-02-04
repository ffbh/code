#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define INF (INT_MAX)
int day[20];
int dp[20][50000];
int H, S, F, N, mmax;
void DP(){
	int temp;
	for (int i = day[1]; i <= mmax; ++i)
		dp[1][i] = (H + S)*i;
	for (int k = 2; k <= N; ++k)
	for (int i = day[k]; i <= mmax; ++i){
		dp[k][i] = INF;
		int j;
		for (j = day[k - 1]; j <= i; ++j){
			temp = dp[k - 1][j] + S*i + H*(i - j);
			if (dp[k][i] > temp)
				dp[k][i] = temp;
		}
		for (; j <= mmax; ++j){
			temp = dp[k - 1][j] + S*i + F*(j-i);
			if (dp[k][i] > temp)
				dp[k][i] = temp;
		}
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		cin >> H >> S >> F;
		mmax = 0;
		for (int i = 1; i <= N; ++i){
			cin >> day[i];
			if (mmax < day[i])
				mmax = day[i];
		}
		DP();
		int mmin = INF;
		for (int i = day[N]; i <= mmax;++i)
		if (mmin>dp[N][i])
			mmin = dp[N][i];
		cout << mmin << endl;



	}



	return 0;
}