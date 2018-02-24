#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, K;
bool map[1010][6];
bool block[6][2][2] = {
	{1,1,0,0},
	{1,0,1,0},
	{1,1,1,0},
	{1,1,0,1},
	{1,0,1,1},
	{0,1,1,1}
};
int size[6] = { 2, 2, 3, 3, 3, 3 };

bool OK(int x, int y, int k){
	for (int i = x; i < x + 2;++i)
	for (int j = y; j < y + 2;++j)
	if (map[i][j] && block[k][i - x][j - y])
		return 0;
	return 1;
}

void place(int x, int y, int k){
	for (int i = 0; i < 2;++i)
	for (int j = 0; j < 2;++j)
	if (block[k][i][j])
		map[i + x][j + y] = 1;
}
void move(int x, int y, int k){
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j)
	if (block[k][i][j])
		map[i + x][j + y] = 0;
}


bool dfs(int x,int left){
	if (left <= K)
		return 1;
	for (int i = x; i < N;++i)
	for (int j = 0; j < 5; ++j)
	for (int k = 0; k < 6; ++k)
	if (OK(i, j, k)){
		place(i, j, k);
		if (dfs(i, left - size[k]))
			return 1;
		move(i, j, k);
	}
	return 0;
}




int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> K){
		int num = 0;
		for (int i = 0; i <= N; ++i)
			map[i][5] = 1;
		for (int i = 0; i < 5; ++i)
			map[N][i] = 1;
		for (int i = 0; i < N; ++i){
			string temp;
			cin >> temp;
			for (int j = 0; j < 5; ++j){
				map[i][j] = temp[j] - '0';
				if (!map[i][j])
					num++;
			}
		}
		if (dfs(0, num))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


	}



	return 0;
}