#include <iostream>
//#include <fstream>
using namespace std;

double dp[10020];
int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	int a;
	double b;
	while (cin >> N >> M){
		if (N == 0 && M == 0)break;
		for (int i = 0; i < 10020; ++i)
			dp[i] = 1.0;
		for (int i = 0; i < M; ++i){
			scanf("%d%lf", &a, &b);
		//	in >> a >> b;
			b = 1 - b;
			for (int k = N; k >= a; --k){
				if (dp[k] > dp[k - a] * b)
					dp[k] = dp[k - a] * b;
			}
		}
		printf("%.1f%%\n", (1-dp[N])*100);
	}


	
}