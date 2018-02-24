#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF (1e33)

int L, N, C, T, VR, VT1, VT2;
double data[110];
double dp[110];



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> L){
		cin >> N >> C >> T >>  VR >> VT1 >>  VT2;
		for (int i = 1; i <= N; ++i){
			cin >> data[i];
		}
		double t = double(L) / VR;
		data[0] = 0;
		data[N + 1] = L;
		dp[0] = 0;
		for (int i = 1; i <= N + 1; ++i){
			dp[i] = INF;
			for (int j = 0; j < i; ++j){
				double time = dp[j] + ((j==0)?0:T);
				if (data[i] - data[j] <= C)
					time += (data[i] - data[j]) / VT1;
				else
					time += (data[i] - data[j] - C) / VT2 + double(C) / VT1;
				if (dp[i]>time)
					dp[i] = time;
			}
		}
		int a;
		if (dp[N + 1] > t)
			cout << "Good job,rabbit!" << endl;
		else
			cout << "What a pity rabbit!" << endl;

		


	}







	return 0;
}