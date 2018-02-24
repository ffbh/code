#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
bool dp[50010];
vector<int> vi[12];

int main(){
	ifstream in("C:\\temp.txt");
	map<string, int> msi;
	int N, M;
	while (cin >> N >> M&&N+M){
		msi.clear();
		for (int i = 1; i <= N; ++i){
			string s;
			cin >> s;
			msi[s] = i;
			vi[i].clear();
		}
		while (M--){
			int a;
			string s;
			cin >> a >> s;
			vi[msi[s]].push_back(a);
		}
		int ans = 0, sum;
		for (int i = 1; i <= N; ++i)
		if (!vi[i].empty()){
			sum = 0;
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for (int j = 0; j < vi[i].size(); ++j)
				sum += vi[i][j];
			for (int j = 0; j < vi[i].size();++j)
			for (int k = sum / 2; k >= vi[i][j];--k)
			if (dp[k - vi[i][j]])
				dp[k] = 1;
			for (int j = sum / 2; j >= 0;--j)
			if (dp[j]){
				ans += sum - j;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}