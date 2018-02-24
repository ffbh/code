#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[110][110];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		memset(data, 0, sizeof(data));
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			cin >> data[1][i];
		for (int i = 2; i <= N;++i)
		for (int j = 1; j <= N - i + 1; ++j)
			data[i][j] = data[i - 1][j + 1] - data[i - 1][j];
		data[N + 1][1] = 0;
		for (int j = 1; j <= M; ++j){
			int k = j+1;
			for (int i = N; i >= 1; --i){
				data[i][k] = data[i][k - 1] + data[i + 1][k - 1];
				k++;
			}
		}
		bool sign = 1;
		for (int i = N + 1; i <= N + M; ++i){
			if (sign){
				sign = 0;
				printf("%d", data[1][i]);
			}
			else
				printf(" %d", data[1][i]);
		}
		cout << endl;
	}





	return 0;
}