#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct DP{
	int ans, suff;
}dp[2200][2200];
int la, lb;
char A[2200], B[2200];
int MMAX(int a, int b, int c){
	return max( max(a, b), c);
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> A+1 >> B+1;
	la = strlen(A + 1);
	lb = strlen(B + 1);
	for (int i = 1; i <= la;++i)
	for (int j = 1; j <= lb; ++j){
		dp[i][j].ans = max(dp[i - 1][j].ans, dp[i][j - 1].ans);
		if (A[i] == B[j]){
			dp[i][j].suff = dp[i - 1][j - 1].suff + 1;
			int suff = dp[i][j].suff;
			for (int k = 3; k <= suff;++k)
				dp[i][j].ans = max(dp[i][j].ans, dp[i - k][j - k].ans + k);
			
		}
	}
	cout << dp[la][lb].ans << endl;


	return 0;
}