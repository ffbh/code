#include <iostream>
//#include <fstream>
#include <cmath>
using namespace std;
int dp[100010][15];
int MaxT;
bool bok(int ceng, int i){
	if (ceng >= 5)return 1;
	else return abs(i - 5) <= ceng;
}
int Max(int a, int b){
	return a > b ? a : b;

}
int MMax(int a, int b, int c){
	return Max(a, Max(b, c));
}
int main(){
	//ifstream in("C:\\temp.txt");
	int N;

	while (cin >> N&&N){
		memset(dp, 0, sizeof(dp));
		MaxT = 0;
		int x, T;
		for (int i = 0; i < N; ++i){
			//in >> x >> T;
			scanf("%d%d", &x, &T);
			dp[T][x]++;
			if (T>MaxT)MaxT = T;
		}
		for (int ceng = MaxT-1; ceng >=0; --ceng)
			for (int i = 0; i <= 10; ++i){
				if (bok(ceng, i)){
					if (i>0)
						if (i<10)
						dp[ceng][i] += MMax(dp[ceng + 1][i - 1], dp[ceng + 1][i], dp[ceng + 1][i + 1]);
						else
							dp[ceng][i] += Max(dp[ceng + 1][i - 1], dp[ceng + 1][i]);
					else 
						dp[ceng][i] += Max( dp[ceng + 1][i], dp[ceng + 1][i + 1]);
				}
			
			}
		//	int mmax = INT_MIN;
			//for (int i = 0; i <= 10;++i)
		//	if (mmax < dp[MaxT][i])mmax = dp[MaxT][i];
			cout << dp[0][5] << endl;
		

	}



	return 0;
}