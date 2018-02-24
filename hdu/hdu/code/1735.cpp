#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
bool map[10010][110];
int N, M, L;

int main(){
//	ifstream in("C:\\temp.txt");
	while (cin >> N >> M >> L){
		priority_queue<int> pi;
		int sum = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
		//	in >> map[i][j];
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				sum++;
		}
		L--;
		sum -= 2;
		int tsum;
		for (int i = 1; i < N;++i)
		if (map[i][0] == 0 && map[i][1] == 0){
			tsum = 2;
			for (int k = M - 1; map[i - 1][k] == 0; --k)
				tsum++;
			pi.push(tsum);
		}
		for (int k = M - 1; map[N - 1][k] == 0; --k)
			sum--;

		while (!pi.empty() && L--){
			sum -= pi.top();
			pi.pop();
		}
		cout << sum << endl;
	}
	return 0;
}