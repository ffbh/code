#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[22][22];/////
bool mark[22][22];
struct Node{
	int x, y;
	int dir;
};
int R, C;
string s;
int mm[27][5] = {
	0, 0, 0, 0, 0
};
void Init(){
	for (int i = 1; i < 27; ++i){
		int flag = 1;
		for (int j = 4; j >= 0; --j)
		if (mm[i - 1][j] && flag){
			mm[i][j] = 0;
		}
		else{
			mm[i][j] = max(mm[i - 1][j],flag);
			flag = 0;
		}
	}
}

int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
void bfs(){
	memset(data, 0, sizeof(data));
	memset(mark, 1, sizeof(mark));
	for (int i = 0; i < R;++i)
	for (int j = 0; j < C; ++j)
		mark[i][j] = 0;
	Node now, next;
	now.x = now.y = 0;
	now.dir = 0;
	for (int k = 0; k < s.length(); ++k){
		int index;
		if (s[k] == ' ')
			index = 0;
		else
			index = s[k] - 'A' + 1;
		for (int i = 0; i < 5; ++i){
			data[now.x][now.y] = mm[index][i];
			mark[now.x][now.y] = 1;
			next.x = now.x + dirs[now.dir][0];
			next.y = now.y + dirs[now.dir][1];
			if (mark[next.x][next.y]){
				now.dir++;
				now.dir %= 4;
				next.x = now.x + dirs[now.dir][0];
				next.y = now.y + dirs[now.dir][1];
			}
			now.x = next.x;
			now.y = next.y;
		}

	}
}




int main(){
	//ifstream in("C:\\temp.txt");
	Init();
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		printf("%d ", CASE++);
		cin >> R >> C;
		cin.get();
		getline(cin, s);
		bfs();
		for (int i = 0; i < R;++i)
		for (int j = 0; j < C; ++j)
			cout << data[i][j];
		cout << endl;
	}
	return 0;
}