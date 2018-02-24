#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
bool map[2010][2010];
int dp[2010][2010];



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		string s;
		for (int i = 1; i <= N; ++i){
			cin >> s;
			for (int j = 0; j < N;++j)
			if (s[j] == '0')
				map[i][j + 1] = 0;
			else
				map[i][j + 1] = 1;
		}
		int mmax=0;
		int num = 0;;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j){
			if (map[i][j] == map[i - 1][j - 1] && map[i - 1][j] == map[i][j - 1]
				&& map[i][j] != map[i][j - 1])
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])+1;
			else
				dp[i][j] = 1;
			if (dp[i][j] > mmax&&map[i][j]){
				mmax = dp[i][j];
				num = 1;
			}
			else if (dp[i][j] == mmax&&map[i][j]){
				num++;
			}
		}
		cout << mmax << " " << num << endl;
	}
	return 0;
}