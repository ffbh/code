#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool map[110][110];

int main(){
//	ifstream in("C:\\temp.txt");
	int N, M, R, C;
	while (cin >> N >> M >> R >> C&&N + M + R + C){
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M;++j)
			if (s[j] == '0')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
		
		int step = 0;
		bool flag = 1;
		for (int i = 0; i < N - R + 1&&flag; ++i){
			for (int j = 0; j < M - C + 1; ++j)
			if (map[i][j]){
				step++;
				for (int ti = i; ti < i + R; ++ti)
				for (int tj = j; tj < j + C; ++tj)
					map[ti][tj] ^= 1;
			}
			for (int k = M - C + 1; k < M;++k)
			if (map[i][k]){
				step = -1;
				flag = 0;
				break;
			}
		}
		for (int i = N - R + 1; i < N&&flag;++i)
		for (int j = 0; j < M;++j)
		if (map[i][j]){
			step = -1;
			flag = 0;
			break;
		}
		cout << step << endl;
	}
	return 0;
}