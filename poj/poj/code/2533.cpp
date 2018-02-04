#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[1010], cnt;

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		cnt = 0;
		cin >> dp[cnt++];
		while (--N){
			int t;
			cin >> t;
			if (dp[cnt - 1] < t)
				dp[cnt++] = t;
			else
				*lower_bound(dp, dp + cnt, t) = t;
		}
		cout << cnt << endl;
	}



	return 0;
}