#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node{
	int x, y;
}data[5010];
int dp[1000010];

int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= N; ++i)
			cin >> data[i].x >> data[i].y;
		dp[data[1].x] = 0;
		int H = data[1].y;
		for (int k = 2; k <= N; ++k){
			int d = (int)sqrt(data[k].y*data[k].y - (data[k].y - H)*(data[k].y - H));
			int s = data[k].x - d;
			int e = data[k].x + d;
			if (s < data[1].x){
				e -= data[1].x - s;
				s = data[1].x;
			}
			if (e>data[N].x){
				s += e - data[N].x;
				e = data[N].x;
			}
			for (; s <= data[k].x; ++s,e--){
				if (dp[s] == -1)
					continue;
				if (dp[e] == -1)
					dp[e] = dp[s] + 1;
				else
					dp[e] = min(dp[e], dp[s] + 1);
			}
		}
		int D = (int)sqrt(data[N].y*data[N].y - (data[N].y - H)*(data[N].y - H));
		int mmin = 9999;
		for (int i =(data[N].x - D)<data[1].x?data[1].x:(data[N].x-D); i <= data[N].x;++i)
		if (dp[i] < mmin&&dp[i]!=-1)
			mmin = dp[i];
		mmin = mmin == 9999 ? -1 : mmin+1;
		cout << mmin << endl;
	}
	return 0;
}