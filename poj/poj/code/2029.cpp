#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int map[110][110];
int sum[110][110];
int W, H, S, T;

int getsum(int x,int y){
	int res = 0;
	for (int i = x; i < x + S; ++i)
		res += sum[i][y + T - 1] - sum[i][y - 1];
	return res;

}



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		cin >> H >> W;
		memset(map, 0 , sizeof(map));
		while (N--){
			int x, y;
			cin >> y >> x;
			map[x][y] = 1;
		}
		cin >> T >> S;
		for (int i = 1; i <= W;++i)
		for (int j = 1; j <= H; ++j)
			sum[i][j] = sum[i][j - 1] + map[i][j];
		int mmax = 0;
		for (int i = 1; i + S-1 <= W;++i)
		for (int j = 1; j + T-1 <= H; ++j){
			int tmp = getsum(i, j);
			if (mmax < tmp)
				mmax = tmp;
		}
		cout << mmax << endl;
	}
	return 0;
}