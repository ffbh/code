#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int data[200][200];
int sum[200][200];
int N;

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	while (in >> N){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
			in >> data[i][j];

		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
			sum[i][j] = sum[i][j - 1] + data[i][j];

		int ans = -999999;
		for (int i = 1; i <= N;++i)
		for (int j = i; j <= N; ++j){
			int all = -999999;
			for (int k = 1; k <= N; ++k){
				all = max(sum[k][j] - sum[k][i - 1], all + sum[k][j] - sum[k][i - 1]);
				ans = max(ans, all);
			}
		}
		cout << ans << endl;
	}
















	return 0;
}