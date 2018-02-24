#include <iostream>
//#include <fstream>
using namespace std;
int num[3];
int z[3] = { 1, 2, 5 };
int dp[10000];
int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> num[0] >> num[1] >> num[2]){
		if (num[0] == 0 && num[1] == 0 && num[2]==0)
			break;
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < 3; ++i){
			int tk = num[i];
			int k = 1;
			while (k < tk){
				for (int j = 8100; j >= k*z[i]; --j)
					if (dp[j - k*z[i]] >= 0)
						dp[j] = 1;
					tk -= k;
					k*= 2;
			}
			for (int j = 8100; j >= tk*z[i]; --j)
			if (dp[j - tk*z[i]] >= 0)
				dp[j] = 1;
		}
		int ans;
		for (int i = 1; i < 8800;++i)
		if (dp[i] < 0){
			ans = i;
			break;
		}
		cout << ans << endl;

	
	}

	return 0;
}