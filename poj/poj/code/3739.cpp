#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
const int MMAX = 2100;
int y[MMAX];
int x[MMAX];
bool point[MMAX][MMAX];
int dp[MMAX][MMAX];
struct Line{
	int y1, y2;
	Line(int a, int b){
		y1 = a;
		y2 = b;
	}
};
vector<Line> vl[MMAX];

int main(){
	//ifstream in("C:\\input.txt");
	int Y, X, N;
	cin >> Y >> X >> N;
	for (int i = 0; i < Y; ++i){
		cin >> y[i];
		y[i]++;
	}
	sort(y, y + Y);
	for (int i = 0; i < X; ++i){
		cin >> x[i];
		x[i]++;
	}
	sort(x, x + X);
	while (N--){
		int a, b;
		cin >> a >> b;
		point[a+1][b+1] = 1;
	}
	int maxX = x[X - 1];
	int maxY = y[Y - 1];
	for (int i = 1;i <= maxX;++i)
	for (int j = 1; j <= maxY; ++j){
		dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + point[i][j];
	}
	for (int i = 0; i < Y;++i)
	for (int j = i + 1; j < Y; ++j){
		vl[y[j] - y[i]].push_back(Line(y[i], y[j]));
	}
	int ans = 0;
	for (int i = 0; i < X;++i)
	for (int j = 0; j < X; ++j){
		int x1 = x[i];
		int x2 = x[j];
		int len = x2 - x1;
		for (int k = 0; k < vl[len].size(); ++k){
			int y1 = vl[len][k].y1;
			int y2 = vl[len][k].y2;
			if (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1])
				ans++;
		}
	}
	cout << ans << endl;













	return 0;
}