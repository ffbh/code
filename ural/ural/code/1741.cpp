#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
#define INF (88888888888888)
int N, M;
struct Node{
	long long x, y, f;
	int flag;
	bool operator<(const Node& p)const{
		return x < p.x;
	}
}data[10010];
long long dp[10010][2];


int main(){
	map<string, int> msi;
	msi["Licensed"] = 0;
	msi["Pirated"] = 1;
	msi["Cracked"] = 2;
	ifstream in("C:\\temp.txt");
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		cin >> data[i].x >> data[i].y >> data[i].f;
		string s;
		cin >> s;
		data[i].flag = msi[s];
	}
	sort(data, data + M);
	for (int i = 1; i <= N; ++i)
		dp[i][0] = dp[i][1] = INF;
	dp[1][0] = 0;
	for (int i = 0; i < M; ++i){
		long s = data[i].x;
		long t = data[i].y;
		long f = data[i].f;
		if (data[i].flag == 0){
			if (dp[t][0] > dp[s][0] + f)
				dp[t][0] = dp[s][0] + f;
		}
		else if (data[i].flag == 1){
			dp[t][1] = min(dp[t][1],min(dp[s][0], dp[s][1]) + f);
		}
		else{
			dp[t][1] = min(dp[t][1], dp[s][1] + f);
			dp[t][0] = min(dp[t][0], dp[s][0] + f);
		}
	}
	if (dp[N][0]>=INF && dp[N][1]>=INF)
		cout << "Offline" << endl;
	else{
		cout << "Online" << endl;
		cout << min(dp[N][0], dp[N][1]) << endl;
	}
	return 0;
}