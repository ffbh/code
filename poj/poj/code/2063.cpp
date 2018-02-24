#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int a,b;
}data[11];
int dp[501000];
int M;
int  K, N;
int main(){
	//ifstream in("C:\\temp.txt");
	int T;
//	in >> T;
	scanf("%d", &T);
	while (T--){
	//	in >> M >> K >> N;
		memset(dp, 0, sizeof(dp));
		scanf("%d%d%d", &M, &K, &N);
		for (int i = 0; i < N; ++i){
		//		in >> data[i].a >> data[i].b;
			scanf("%d%d", &data[i].a, &data[i].b);
			data[i].a /= 1000;
		}
		for (int i = 0; i < N; ++i)
		for (int j = data[i].a; j <= int( M/20); ++j)
		if (dp[j] < dp[j - data[i].a] + data[i].b)
			dp[j] = dp[j - data[i].a] + data[i].b;
		while (K--){
			M += dp[M/1000] ;
		}
		printf("%d\n", M);
	}
	return 0;
}