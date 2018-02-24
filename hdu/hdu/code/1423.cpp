#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int M1, M2;
int dp[510];
int A[510], B[510];
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int ok = 0;
	while (T--){
		if (ok)cout << endl;
		ok = 1;
		cin >> M1;
		for (int i = 1; i <= M1; ++i)
			cin >> A[i];
		cin >> M2;
		for (int i = 1; i <= M2; ++i)
			cin >> B[i];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= M1; ++i){
			int mmax = 0;
			for (int j = 1; j <= M2; ++j){
				if (A[i] > B[j-1] && mmax < dp[j-1])
					mmax = dp[j-1];
				if (A[i] == B[j])
					dp[j] = mmax + 1;
			}
		}
		int mmax = 0;
		for (int i = 1; i <= M2;++i)
		if (mmax < dp[i])
			mmax = dp[i];
		cout << mmax << endl;
	}
	return 0;
}