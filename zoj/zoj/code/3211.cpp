#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	long long  now, grow;
	bool operator<(const Node& p)const{
		if (grow!=p.grow)
			return grow < p.grow;
		return now < p.now;
	}
}data[300];
long long  dp[300][300];
int N, K;

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> K;
		memset(dp, 0, sizeof(dp)); 
		for (int i = 1; i <= N; ++i)
			cin >> data[i].now;
		for (int i = 1; i <= N; ++i)
			cin >> data[i].grow;
		sort(data + 1, data + N + 1);
		long long mmax;
		for (int i = 1; i <= K; ++i){
			mmax = 0;
			for (int j = 1; j <= N; ++j){
				if (dp[i][j] < mmax + data[j].now + data[j].grow*(i - 1))
					dp[i][j] = mmax + data[j].now + data[j].grow*(i - 1);
				if (mmax<dp[i - 1][j])
					mmax = dp[i - 1][j];
			}
		}
		mmax = 0;
		for (int i = 1; i <= N;++i)
		if (dp[K][i]>mmax)
			mmax = dp[K][i];
		cout << mmax << endl;
	}
	return 0;
}