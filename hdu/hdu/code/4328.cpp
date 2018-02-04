#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
bool map[1010][1010];
int l[1010][1010], r[1010][1010], h[1010][1010];
int DP(bool c){
	int ans = 0, temp;
	for (int i = 0; i < N; ++i){
		int t = -1;
		for (int j = 0; j < M; ++j){
			if (map[i][j] != c)
				t = j;
			l[i][j] = t;
		}
		t = M;
		for (int j = M - 1; j >= 0; --j){
			if (map[i][j] != c)
				t = j;
			r[i][j] = t;
		}
	}
	for (int j = 0; j < M;++j)
	if (map[0][j] == c){
		h[0][j] = 1;
		temp = (1 + r[0][j] - l[0][j] - 1) * 2;
		if (ans < temp)
			ans = temp;
	}
	for (int i = 1; i < N;++i)
	for (int j = 0; j < M;++j)
	if (map[i - 1][j] == c){
		h[i][j] = h[i - 1][j] + 1;
		l[i][j] = max(l[i][j], l[i - 1][j]);
		r[i][j] = min(r[i][j], r[i - 1][j]);
		temp = (h[i][j] + r[i][j] - l[i][j] - 1) * 2;
		if (ans < temp)
			ans = temp;
	}
	else{
		h[i][j] = 1;
		temp = (h[i][j] + r[i][j] - l[i][j] - 1) * 2;
		if (ans < temp)
			ans = temp;
	}
	return ans;
}




int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		cin >> N >> M;
		int a, b, c, d;
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M; ++j)
				map[i][j] = (s[j] == 'B');
		}
		a = DP(0);
		b = DP(1);
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		if ((i + j) % 2)
			map[i][j] ^= 1;
		c = DP(0);
		d = DP(1);
		printf("Case #%d: %d\n", CASE++, max(max(a,b),max(c,d)));
	}
	return 0;
}