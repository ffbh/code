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

char mmp[15][15][15];
int N;
long long MAX_VAL = 1000000001;
long long dp[15][15][15][50];
int dirs[3][3] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
bool IN(int x, int y, int z){
	return x >= 0 && x < N&&y >= 0 && y < N&&z >= 0 && z < N;
}

class BracketMaze {
	public:
	int properPaths(vector <string> maze, int n) {
		N = n;
		string str = "";
		for (int i = 0; i < maze.size(); ++i){
			str += maze[i];
		}
		int size = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N;++j)
		for (int k = 0; k < N; ++k){
			mmp[i][j][k] = str[size++];
		}
		if (mmp[0][0][0] == ')'){
			return 0;
		}
		memset(dp, 0, sizeof(dp));
		if (mmp[0][0][0] == '.'){
			dp[0][0][0][0] = 1;
		}
		else{
			dp[0][0][0][1] = 1;
		}
	
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N;++j)
		for (int k = 0; k < N; ++k)
		for (int d = 0; d < 50; ++d){
			long long& ref = dp[i][j][k][d];
			if (ref > 0){
				for (int p = 0; p < 3; ++p){
					int nx = i + dirs[p][0];
					int ny = j + dirs[p][1];
					int nz = k + dirs[p][2];
					if (IN(nx, ny, nz)){
						int nd = d;
						if (mmp[nx][ny][nz] == '('){
							nd++;
						}
						else if (mmp[nx][ny][nz] == ')'){
							nd--;
						}

						if (nd >= 0){
							dp[nx][ny][nz][nd] += ref;
							if (dp[nx][ny][nz][nd] > MAX_VAL)
								dp[nx][ny][nz][nd] = MAX_VAL;
						}
					}
				}
			}
		}

		long long ans = dp[N - 1][N - 1][N - 1][0];
		if (ans == MAX_VAL)
			ans = -1;
		return ans;
	}
};



/*int main(){
	
	BracketMaze so;
	//cout<<so.properPaths()<<endl;
















	return 0;
}

*/
