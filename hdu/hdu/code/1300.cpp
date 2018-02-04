#include <iostream>
//#include <fstream>
using namespace std;
struct Good{
	int num;
	int v;
};
Good good[110];
int dp[110];
int main(){
//	ifstream in("C:\\temp.txt");
	int N,K;
	cin >> N;
	int num;
	while (N--){
		//in >> K;
		scanf("%d", &K);
		for (int i = 0; i < 110; ++i)
			dp[i]= INT_MAX;
		dp[0] = 0;
		for (int i = 1; i <= K; ++i)
			//in >> good[i].num >> good[i].v;
			scanf("%d%d", &good[i].num, &good[i].v);
		for (int i = 1; i <= K; ++i){
			num = 10;
			for (int j = i; j >= 1; --j){
				num += good[j].num;
				if (dp[i]>dp[j-1] + num*good[i].v)
					dp[i] = dp[j-1] + num*good[i].v;
			}
		}
		cout << dp[K] << endl;
	}

	return 0;
}