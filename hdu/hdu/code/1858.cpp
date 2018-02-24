#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAXN = 1000010;
struct Node{
	int l, r;
	_int64 sum;
};
int data[MAXN];
Node dp[MAXN];

int main(){
	//ifstream in("C:\\temp.txt");
	int T ,N;
	cin >> T;
	while (T--){
		dp[0].sum = INT_MIN;
		data[0] = INT_MIN;
		cin >> N;
		for (int i = 1; i <= N; ++i)
			//in >> data[i];
			scanf("%d", &data[i]);
		dp[1].sum = data[1];
		dp[1].l = dp[1].r = 1;
		for (int i = 2; i <= N; ++i){
			if (dp[i - 1].sum>= 0){
				dp[i].sum = dp[i - 1].sum + data[i];
				dp[i].l = dp[i - 1].l;
				dp[i].r = i;
			}
			else{
				dp[i].sum = data[i];
				dp[i].l = dp[i].r = i;
			}
		}
		int u = 1;
		_int64 MMAX = dp[1].sum;
		for (int i = 1; i <= N; ++i)
		if (MMAX < dp[i].sum){
			u = i;
			MMAX = dp[i].sum;
		}
		while (data[dp[u].l-1] == 0)
			dp[u].l--;
		while (data[dp[u].r-1] == 0)
			dp[u].r--;
		cout << dp[u].sum << " " << dp[u].l << " " << dp[u].r << endl;
	}
	return 0;
}