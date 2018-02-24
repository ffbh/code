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
int N;
#define INF (1<<28)
struct Node{
	int to, d;
	Node(int a, int b){
		to = a;
		d = b;
	}
};
vector<Node> vi[40][40];
int dp[40][40];

void Init(){
	for (int i = 0; i < 40;++i)
	for (int j = 0; j < 40; ++j){
		vi[i][j].clear();
		dp[i][j] = INF;
	}
	dp[0][1] = 0;

}

int main(){
	//ifstream in("C:\\input.txt");
	while (cin >> N){
		Init();
		for (int i = 1; i <= N; ++i){
			int num;
			char c;
			cin >> num;
			for (int j = 1; j <= num; ++j){
				int v, cost;
				while (cin >> v&&v){
					cin >> cost;
					vi[i - 1][v].push_back(Node(j, cost));
				}
			}
			cin >> c;
		}
		for (int i = 0; i <= N;++i)
		for (int j = 1; j < 40; ++j){
			if (dp[i][j] == INF)
				continue;
			for (int k = 0; k < vi[i][j].size(); ++k){
				int v = vi[i][j][k].to;
				int d = vi[i][j][k].d;
				if (dp[i + 1][v] > dp[i][j] + d){
					dp[i + 1][v] = dp[i][j] + d;
				}
			}
		}
		int ans = INF;
		for (int i = 0; i < 40;++i)
		if (ans > dp[N][i])
			ans = dp[N][i];
		cout << ans << endl;


	}
















	return 0;
}