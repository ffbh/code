#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int h, w;
	int k;
	bool operator<(const Node& p)const{
		return h*w < p.h*p.w;
	}
};
Node num[100];
int cnt;
int dp[100];
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	int CASE = 1;
	int a, b, c;
	while (cin >> N&&N){
		cnt = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; ++i){
		//	in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			num[cnt].h = max(a,b);
			num[cnt].w = min(a, b);
			num[cnt].k = c;
			cnt++;
			num[cnt].h = max(a, c);
			num[cnt].w = min(a, c);
			num[cnt].k = b;
			cnt++;
			num[cnt].h = max(c, b);
			num[cnt].w = min(c, b);
			num[cnt].k = a;
			cnt++;
		}
		sort(num, num + cnt);
		dp[0] = num[0].k;
		for (int i = 1; i < cnt; ++i){
			dp[i] = num[i].k;
			for (int j = i - 1; j >= 0; --j)
			if (num[i].h>num[j].h&&num[i].w > num[j].w&&dp[i] < num[i].k + dp[j])
				dp[i] = num[i].k + dp[j];
		}
		int mmax = 0;
		for (int i = 0; i < cnt;++i)
		if (mmax < dp[i])
			mmax = dp[i];
		printf("Case %d: maximum height = %d\n",CASE++,mmax);
	
	
	
	
	
	}

	return 0;
}