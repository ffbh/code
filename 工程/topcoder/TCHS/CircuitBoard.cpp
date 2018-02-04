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
using namespace std;
#define DEBUG (0)


bool vis[60][60];
int N, M;
class CircuitBoard {
public:
	bool dfs(int row, int col){
		if (row == N)
			return 1;
		if (col < 0 || col >= M)
			return 0;
		if (vis[row][col])
			return 0;
		vis[row][col] = 1;

		bool ok = 0;
		for (int i = -1; i <= 1; ++i){
			if (dfs(row + 1, col + i)){
				ok = 1;
				break;
			}
		}

		return ok;
	}


	int maxDataLines(vector <string> layout) {
		N = layout.size();
		M = layout[0].size();
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			vis[i][j] = (layout[i][j] == 'o');

		int ans = 0;
		for (int i = 0; i < M; ++i){
			if (dfs(0, i))
				ans++;
		}
		return ans;
	}
};



#if DEBUG
int main(){

	CircuitBoard so;
	cout << so.maxDataLines() << endl;
















	return 0;
}
#endif

