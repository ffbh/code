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
long long data[300][300];
long long sum[300][300];
int N, M;
long long K;
int ans;

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M >> K;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M; ++j)
		cin >> data[i][j];
	ans = 0;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M; ++j){
		sum[i][j] = sum[i][j - 1] + data[i][j];
	}

	for (int i = 1; i <= N;++i)
	for (int j = i; j <= N; ++j){
		if (i == 1 && j == 2){
			int t = 0;
		}
		long long now = 0;
		int a = 1, b = 1;
		while (a <= M){
			while (a <= M &&now <= K){
				now += sum[a][j] - sum[a][i - 1];
				a++;
				if (now <= K){
					ans = max(ans, (j-i+1)*(a-b));
				}
				
			}
			while (now > K){
				now -= sum[b][j] - sum[b][i - 1];
				b++;
			}
			if (now <= K){
				ans = max(ans, (j - i+1)*(a - b));
			}
		}
	}
	cout << ans << endl;















	return 0;
}