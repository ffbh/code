#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[40001];


int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	int t;
	int count;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		count = 0;
		cin >> dp[count++];
		while (--N){
		//	in >> t;
			scanf("%d", &t);
			if (dp[count - 1] < t)
				dp[count++] = t;
			else
				*lower_bound(dp, dp + count,t) = t;
		}
		cout << count << endl;
	}
	return 0;
}