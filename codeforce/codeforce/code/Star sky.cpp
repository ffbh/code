#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
int n, q, c;
int num[11][11][110][110];

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> q >> c;
	c++;
	for (int i = 1; i <= n; ++i){
		int x, y, s;
		in >> x >> y >> s;
		for (int k = 0; k < c; ++k){
			num[k][(k+s)%c][x][y]++;
		}
	}


	for (int i = 0; i < c;++i)
	for (int j = 0; j < c; ++j){
		for (int a = 1; a < 110;++a)
		for (int b = 1; b < 110; ++b)
			num[i][j][a][b] += num[i][j][a - 1][b] + num[i][j][a][b - 1] - num[i][j][a - 1][b - 1];
	}

	while (q-->0){
		int t, x1, y1, x2, y2;
		in >> t >> x1 >> y1 >> x2 >> y2;
		t %= c;
		int ans = 0;
		for (int i = 1; i < c; ++i){
			ans += i * (num[t][i][x2][y2] - num[t][i][x1 - 1][y2] - num[t][i][x2][y1 - 1] + num[t][i][x1 - 1][y1 - 1]);

		}
		cout << ans << endl;
	}












	return 0;
}





