#include <iostream>
#include <string>
#include <fstream>
#include<cmath>
using namespace std;
int sum[1010];

int main(){
	ifstream in("C:\\temp.txt");
	int T, N;
	cin >> T;
	int CASE = 1;
	while (T--){
		sum[0] = 0;
		cin >> N;
		for (int i = 1; i <= N; ++i){
			int t;
			cin >> t;
			sum[i] = sum[i - 1] + t;
		}
		int mmin = (1 << 20);
		for (int i = 1; i <= N;++i)
		for (int j = i; j <= N; ++j){
			int temp = abs(sum[j] - sum[i-1]);
			if (temp < mmin)
				mmin = temp;
		}
		printf("Case %d: %d\n", CASE++, mmin);
	}
	return 0;
}