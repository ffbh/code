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
using namespace std;
int N;
vector<int> X, Y, SX, SY;
stringstream ss;
int x_h[10010], y_h[10010];
int mmp[110][110];
int dp[110][110];

int cale(int a,int b,int c,int d){
	return dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1];
}


class EnclosingRectangle {
	public:
		int smallestArea(vector <string> a, vector <string> b) {
			X.clear();
			Y.clear();
			SX.clear();
			SY.clear();
			X.push_back(-1);
			Y.push_back(-1);
			memset(mmp, 0, sizeof(mmp));
			memset(dp, 0, sizeof(dp));
			string xstr = "";
			string ystr = "";
			for (int i = 0; i < a.size(); ++i){
				xstr += a[i];
			}
			ss.clear();
			ss.str(xstr);
			int tmp;
			while (ss >> tmp){
				X.push_back(tmp);
			}

			for (int i = 0; i < b.size(); ++i){
				ystr += b[i];

			}
			ss.clear();
			ss.str(ystr);
			while (ss >> tmp){
				Y.push_back(tmp);
			}
			SX = X;
			SY = Y;
			N = X.size() - 1;
			sort(X.begin(), X.end());
			sort(Y.begin(), Y.end());
			X.erase(unique(X.begin(), X.end()), X.end());
			Y.erase(unique(Y.begin(), Y.end()), Y.end());


			for (int i = 1; i < X.size(); ++i){
				x_h[X[i]] = i;
			}
			for (int i = 1; i < Y.size(); ++i){
				y_h[Y[i]] = i;
			}
			for (int i = 1; i <= N; ++i){
				mmp[x_h[SX[i]]][y_h[SY[i]]] = 1;
			}

			for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mmp[i][j];
			}
			int K = N / 2;
			long long ans = (long long)1e18;
			for (int i = 1; i < Y.size(); ++i)
			for (int j = i; j < Y.size(); ++j){
				int epos = 1;
				for (int spos = 1; spos < X.size(); ++spos){
					epos = max(epos, spos);
					while (epos < X.size()){


						int ret = cale(spos, i, epos, j);
						if (ret >= K){
							break;
						}
						epos++;
					}
					if (epos < X.size()){
						long long area = (X[epos] - X[spos] + 2)*(Y[j] - Y[i] + 2);

						ans = min(ans, area);
					}
				}


			}
			return (int)ans;
		}
};


/*int main(){
	vector<string> x({ "100 200" }), y({ "100 200" });
	EnclosingRectangle so;
	cout<<so.smallestArea(x,y)<<endl;
















	return 0;
}
*/




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
