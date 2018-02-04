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


int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
string bfs(){
	string ans = "";
	memset(mark, 1, sizeof(mark));
	for (int i = 0; i < R; ++i)
	for (int j = 0; j < C; ++j)
		mark[i][j] = 0;
	Node now, next;
	now.x = now.y = 0;
	now.dir = 0;
	int M = s.length() / 5;
	while(M--){
		int temp = 0;
		for (int i = 0; i < 5; ++i){
			temp = temp*2+data[now.x][now.y];
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
		if (temp == 0)
			ans += ' ';
		else
			ans += char('A' - 1 + temp);
	}
	int k = ans.length() - 1;
	while (ans[k] == ' ')k--;
	return ans.substr(0, k+1);
}




int main(){
//	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		printf("%d ", CASE++);
		cin >> R >> C;
		cin.get();
		getline(cin, s);
		int p = 0;
		for (int i = 0; i < R;++i)
		for (int j = 0; j < C; ++j)
			data[i][j] = s[p++] - '0';
		cout << bfs() << endl;
	}
	return 0;
}