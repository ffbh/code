#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int dp[2100][2100];
bool vis[2100][2100];
int N, M;
struct Node{
	int v, s;
	vector<int> vi;
}data[1010];

void Init(){
	memset(dp, 0, sizeof(dp));

	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 1010; ++i)
		data[i].vi.clear();
}

int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T-- > 0){
		Init();
		cin >> N >> M;
		for (int i = 1; i <= N; ++i){
			cin >> data[i].v >> data[i].s;
			for (int j = 0; j < data[i].s; ++j){
				int t;
				cin >> t;
				data[i].vi.push_back(t);
			}
		}
		vis[0][0] = 1;
		int aim = (1 << M) - 1;
		for (int i = 1; i <= N; ++i){
			for (int j = 0; j <= aim; ++j){
				if (!vis[i - 1][j])
					continue;
				vis[i][j] = 1;
				dp[i][j] = max(dp[i - 1][j], dp[i][j]);
				int state = j;
				for (int k = 0; k < data[i].vi.size(); ++k){
					int p = 1 << (data[i].vi[k] - 1);
					state ^= p;
				}
				vis[i][state] = 1;
				dp[i][state] = max(dp[i - 1][j] + data[i].v, dp[i][state]);
			}
		}
		cout << dp[N][aim] << endl;

	}
	return 0;
}