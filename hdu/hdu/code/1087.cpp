#include <iostream>
#include <fstream>
using namespace std;
struct node{
	int v;
	_int64 max;
};
node dp[1010];
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	while (cin>>N && N){
		for (int i = 1; i <= N; ++i)
			scanf("%d", &dp[i].v);

		for (int i = 1; i <= N; ++i){
			dp[i].max = dp[i].v;
			for (int j = 1; j < i;++j)
			if (dp[j].v<dp[i].v&&dp[j].max + dp[i].v>dp[i].max)
				dp[i].max = dp[i].v + dp[j].max;
		}
		_int64 mmax = 0;
		for (int i = 1; i <= N;++i)
		if (mmax < dp[i].max)
			mmax = dp[i].max;
		cout << mmax << endl;




	}

	return 0;
}


