#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
using namespace std;
#define MMAX (1000010)
int data[5];
bool dp[MMAX];
int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		int N = 4;
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		sort(data, data + N);
		N = unique(data, data + N) - data;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int k = 0; k < N; ++k){
			int val = data[k];
			int mmax = MMAX - val;
			for (int i = 0; i < mmax;++i)
			if (dp[i])
				dp[i + val] = 1;
		}
		int Frobenius = 0;
		int sum = 0;
		bool flag = 0;
		for (int i = 1000000; i > 0; --i){
			if (!dp[i]){
				sum++;
				if (!flag){
					flag = 1;
					if (1000000 - i >= data[0])
						Frobenius = i;
					else
						Frobenius = -1;
				}
			}
		}
		cout << sum << endl;
		cout << Frobenius << endl;
	}















	return 0;
}