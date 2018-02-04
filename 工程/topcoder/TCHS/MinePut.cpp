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



int N, M;
int dirs[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
inline bool IN(int x,int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}
class MinePut {
public:
	int mmp[25][25], table[25][25];
	vector<pair<int, int> > V;
	int cale(int p){
		int num = 0;
		for (int i = 0; i < V.size(); ++i){
			if (p & (1 << i)){
				num++;
				for (int k = 0; k < 8; ++k){
					int x = V[i].first + dirs[k][0];
					int y = V[i].second + dirs[k][1];
					if (IN(x, y)){
						mmp[x][y]++;
					}
				}
			}
		}
		return num;
	}

	bool judge(){
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M;++j)
		if (table[i][j] < mmp[i][j]){
			return 0;
		}
		return 1;
	}
	int getMines(vector <string> partialBoard) {
		V.clear();
		N = partialBoard.size();
		M = partialBoard[0].size();
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
			if (!isdigit(partialBoard[i][j])){
				V.push_back(make_pair(i, j));
				table[i][j] = 9;
			}
			else{
				table[i][j] = partialBoard[i][j] - '0';
			}
		}
		int ans = 0;
		for (int i = 1; i < (1 << V.size()); ++i){
			memset(mmp, 0, sizeof(mmp));
			int tmp = cale(i);
			if (judge()){
				ans = max(ans, tmp);
			}
		}

		return ans;


	}
};



#if DEBUG
int main(){
	
	MinePut so;
	cout<<so.getMines()<<endl;
















	return 0;
}
#endif

