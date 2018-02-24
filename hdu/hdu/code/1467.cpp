#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
int data[110];
bool map[110][220];
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < 2*N-1&&map[x][y];
}
int MAXLEN;
void dfs(int x, int y, int len,int dir){
	for (int i = 0; i < len; ++i){
		int y1, y2;
		y1 = y + i;
		y2 = y - i;
		if (!IN(x, y1)||!IN(x, y2))
			return ;
	}
	if (len>MAXLEN)
		MAXLEN = len;
	x += dir;
	if (IN(x, y))
		dfs(x, y, len + 1,dir);
}


int main(){
	ifstream in("C:\\temp.txt");
	data[0] = 0;
	data[1] = 1;
	int num = 3;
	for (int i = 2; i < 110; ++i){
		data[i] = data[i - 1] + num;
		num += 2;
	}
	int CASE = 1;
	while (cin >> N&&N){
		MAXLEN = 0;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; ++i){
			string temp;
			cin >> temp;
			for (int j = 0; j < temp.length();++j)
			if (temp[j] == '-')
				map[i][j+i] = 1;
		}
		for (int i = 0; i < N;++i)
		for (int j = 0; j < 2*N-1; ++j)
		if (map[i][j]){
			if ((i+j)%2==1)
				dfs(i, j, 1, 1);
			else
				dfs(i, j, 1, -1);
		}
		printf("Triangle #%d\n", CASE++);
		printf("The largest triangle area is %d.\n", data[MAXLEN]);
		cout << endl;
	}
	return 0;
}