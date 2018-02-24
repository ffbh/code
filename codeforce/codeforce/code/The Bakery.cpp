#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
int N, K;
int data[35010], h[35010];
int dp[60][35010];

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> N >> K;
	for (int i = 1; i <= N; ++i)
		in >> data[i];
	int L, R;
	for (int k = 1; k <= K; ++k){
		L = 0;
		int diff = 0, mmax = 0;
		memset(h, 0, sizeof(h));
		for (int R = 1; R <= N; ++R){
			if (h[data[R]] == 0){
				diff++;
			}
			h[data[R]]++;
			mmax = max(mmax,dp[k - 1][L] + diff);
			while (L + 1 < R){
				if (h[data[L + 1]] == 1){
					if (diff - 1 + dp[k - 1][L + 1] < mmax)
						break;
					mmax = max(mmax, diff - 1 + dp[k - 1][L + 1]);
				}
				else{
					if (diff + dp[k - 1][L + 1] <  mmax)
						break;
					mmax = max(mmax, diff + dp[k - 1][L + 1]);
				}
				L++;
				h[data[L]]--;
				if (h[data[L]] == 0)
					diff--;
			}
			dp[k][R] = mmax;
		}
	}


	cout << dp[K][N] << endl;












	return 0;
}





