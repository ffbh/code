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
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int d[4];
int N, M;
string mmp[60];
int sx, sy, ex, ey;
string code;
void find(char c,int& x,int& y){
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M;++j)
	if (mmp[i][j] == c){
		x = i;
		y = j;
	}

}


void input(){
	in >> N >> M;
	for (int i = 0; i < N; ++i)
		in >> mmp[i];
	in >> code;

}

bool IN(int x,int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int judge(){
	int x = sx;
	int y = sy;
	for (char c : code){
		int p = d[c - '0'];
		x += dirs[p][0];
		y += dirs[p][1];
		if (IN(x, y)){
			if (mmp[x][y] == 'E')
				return 1;
			if (mmp[x][y] == '#')
				return 0;

		}
		else
			return 0;
	}
	return 0;

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		find('S', sx, sy);
		find('E', ex, ey);

		for (int i = 0; i < 4; ++i){
			d[i] = i;
		}

		int ans = judge();
		while (next_permutation(d, d + 4)){
			ans += judge();

		}
		cout << ans <<  endl;















	}


	return 0;
}





