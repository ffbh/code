#include <iostream>
//#include <fstream>
、、

//题目有问题，结束条件不是N==-1，而是N>=0
using namespace std;
int value[55];
int num[55];
int dp[250005];
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N>=-1){
		int sum = 0;
		memset(dp, -1, sizeof(dp));
		memset(value, 0, sizeof(value));
		memset(num, 0, sizeof(num));
		dp[0] = 1;
		for (int i = 0; i < N; ++i){
		//	in >> value[i] >> num[i];
			scanf("%d%d", &value[i], &num[i]);
			sum += value[i] * num[i];
		}
		int ssum = sum;
		sum /= 2;
		for (int i = 0; i < N; ++i){
			int v = num[i] * value[i];
			if (v >= sum){
				for (int j = value[i]; j <= sum;++j)
				if (dp[j] == -1 && dp[j - value[i]] != -1)
					dp[j] = 1;
				//if (dp[j] < dp[j - value[i]] + value[i])
				//	dp[j] = dp[j - value[i]] + value[i];
			}
			else{
				int k = 1;
				while (k < num[i]){
					int vv = k*value[i];
					for (int j = sum; j >= vv; --j)
					if (dp[j] == -1 && dp[j - vv] != -1)
						dp[j] = 1;
					//if (dp[j] < dp[j - vv] + vv)
						//dp[j] = dp[j - vv] + vv;
					num[i] -= k;
					k *= 2;
				}
				if (num[i]>0){
					int vv = num[i] * value[i];
					for (int j = sum; j >= vv; --j)
					if (dp[j] == -1 && dp[j - vv] != -1)
						dp[j] = 1;
				//	if (dp[j] < dp[j - vv] + vv)
						//dp[j] = dp[j - vv] + vv;
				}
			}
		}
		while (dp[sum] == -1)sum--;
		printf("%d %d\n", ssum - sum, sum);
	
	}

	return 0;
}