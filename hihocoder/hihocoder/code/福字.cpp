#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int N;
int data[1010][1010];
bool ok[1010][1010];
int r[1010][1010], d[1010][1010];

int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j){
		cin >> data[i][j];
	}

	for (int i = 1; i <= N; ++i){
		int rr = N,j;
		r[i][N] = N;
		for (j = N - 1; j >= 1; --j){
			if (data[i][j] + 1 != data[i][j + 1])
				rr = j;
			r[i][j] = rr;
		}
	}

	for (int j = 1; j <= N; ++j){
		int dd = N, i;
		d[N][j] = N;
		for (i = N - 1; i >= 1; --i){
			if (data[i][j] + 1 != data[i+1][j])
				dd = i;
			d[i][j] = dd;
		}

	}
	
	int ans = 0;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j){
		int rr = r[i][j] - j + 1;
		int dd = d[i][j] - i + 1;
		int tmp = min(rr, dd);
		for (int k = 0; k < tmp&&tmp > ans; ++k){
			tmp = min(tmp, r[i + k][j] - j + 1);
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}