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

char mmp[12][12];
bool vis[11][11][4];
int dirs[4][2] = { 1, 0, 0, 1, 1, 1, 1, -1 };
bool IN(int x,int y){
	return x >= 0 && x < 10 && y >= 0 && y < 10;
}
bool judge(){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 10;++i)
	for (int j = 0; j < 10; ++j){
		if (mmp[i][j] != 'X')
			continue;

		for (int k = 0; k < 4; ++k){
			int num = 0;
			int x = i;
			int y = j;
			while (IN(x, y) && !vis[x][y][k] && mmp[x][y] == 'X'){
				num++;
				vis[x][y][k] = 1;
				x += dirs[k][0];
				y += dirs[k][1];
			}
			if (num >= 5)
				return 1;
		}
	}
	return 0;
}

void work(){
	for (int i = 0; i < 10; ++i)
	for (int j = 0; j < 10; ++j){
		if (mmp[i][j] == '.'){
			mmp[i][j] = 'X';
			if (judge()){
				cout << "YES" << endl;
				return;
			}
			mmp[i][j] = '.';
		}
	}
	cout << "NO" << endl;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	for (int i = 0; i < 10; ++i)
		in >> mmp[i];

	

	work();













	return 0;
}





