#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int data[1010][1010], dp[1010][1010], N, M, K;
int R1, R2, S1, S2;

int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> data[i][j];

		dp[1][1] = data[1][1];
		for (int i = 2; i <= N; ++i)
			dp[i][1] = dp[i - 1][1] + data[i][1];
		for (int j = 2; j <= M; ++j)
			dp[1][j] = dp[1][j - 1] + data[1][j];
		for (int i = 2; i <= N; ++i)
		for (int j = 2; j <= M; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + data[i][j];

		cin >> K;
		while (K--){
			cin >> R1 >> S1 >> R2 >> S2;
			printf("Absolutni hodnota pohodlnosti je %d bodu.\n", dp[R2][S2] - dp[R1 - 1][S2] - dp[R2][S1 - 1] + dp[R1 - 1][S1 - 1]);

		}
		cout << endl;
	}















	return 0;
}