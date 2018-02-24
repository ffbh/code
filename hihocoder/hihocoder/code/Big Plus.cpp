#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
char map[510][510];
int N;
int l[510][510], r[510][510], u[510][510], d[510][510];
int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> map[i] + 1;
	int p;
	for (int i = 1; i <= N; ++i){
		p = -1;
		for (int j = 1; j <= N; ++j){
			if (p == -1 && map[i][j] == '1')
				p = j;
			if (map[i][j] == '0'){
				p = -1;
			}
			if (p == -1)
				l[i][j] = j;
			else
				l[i][j] = p;
		}
	}

	for (int i = 1; i <= N; ++i){
		p = -1;
		for (int j = N; j >= 1; --j){
			if (p == -1 && map[i][j] == '1')
				p = j;
			if (map[i][j] == '0'){
				p = -1;
			}
			if (p == -1)
				r[i][j] = j;
			else
				r[i][j] = p;
		}
	}

	for (int i = 1; i <= N; ++i){
		p = -1;
		for (int j = 1; j <= N; ++j){
			if (p == -1 && map[j][i] == '1')
				p = j;
			if (map[j][i] == '0'){
				p = -1;
			}
			if (p == -1)
				u[j][i] = j;
			else
				u[j][i] = p;

		}
	}


	for (int i = 1; i <= N; ++i){
		p = -1;
		for (int j = N; j >= 1; --j){
			if (p == -1 && map[j][i] == '1')
				p = j;
			if (map[j][i] == '0'){
				p = -1;
			}
			if (p == -1)
				d[j][i] = j;
			else
				d[j][i] = p;
		}
	}


	int ans = 0;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j)
	if (map[i][j] == '1'){
		int mmin = min(min(j - l[i][j], r[i][j] - j), min(i - u[i][j], d[i][j] - i));
		ans = max(ans, mmin);
	}
	cout << ans << endl;








	return 0;
}