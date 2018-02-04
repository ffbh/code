#include <iostream>
#include <fstream>
using namespace std;
int num[10010];
struct node{
	int i, j;
	int mmax;
};
node dp[10010];
int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	int maxindex;
	int mmax;
	while (cin >> N&&N){
		memset(num, 0, sizeof(num));
		memset(dp, 0, sizeof(dp));
		maxindex = 0;
		for (int i = 0; i < N; ++i)
			//in >> num[i];
			scanf("%d", &num[i]);
		dp[0].mmax = num[0];
		dp[0].i = dp[0].j = 0;
		mmax = num[0];
		for (int i = 1; i < N; ++i){
			if (num[i] + dp[i - 1].mmax>num[i]){
				dp[i].i = dp[i - 1].i;
				dp[i].j = i;
				dp[i].mmax = num[i] + dp[i - 1].mmax;
			}
			else{
				dp[i].i = dp[i].j = i;
				dp[i].mmax = num[i];
			}
			if (mmax < dp[i].mmax){
				mmax = dp[i].mmax;
				maxindex = i;
			}
		}
		int ans = dp[maxindex].i;
		if (ans>0&&num[ans - 1] == 0)ans--;
		if (mmax>=0)
		printf("%d %d %d\n", mmax, num[ans], num[dp[maxindex].j]);
		else
			printf("%d %d %d\n", 0, num[0], num[N-1]);
	}
	return 0;
}