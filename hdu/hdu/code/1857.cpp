#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
#define MAXSIZE 26
struct Point{
	int x, y;
}ans[10010];
int N, M;
char map[510][510];
struct Node{
	int next[MAXSIZE];
	int index;
}data[220000];
int size, root;
int MALLOC(){
	data[size].index = -1;
	for (int i = 0; i < MAXSIZE; ++i)
		data[size].next[i] = -1;
	return size++;
}


void Insert(char* s, int index){
	int len = strlen(s);
	int p = root;
	for (int i = 0; i < len; ++i){
		if (data[p].next[s[i] - 'A'] == -1)
			data[p].next[s[i] - 'A'] = MALLOC();
		p = data[p].next[s[i] - 'A'];
	}
	data[p].index = index;
}


int dirs[3][2] = { 0, 1, 1, 0, 1, 1 };

void query(int x, int y){
	int p;
	p = root;
	for (int i = x; i < N; ++i){
		p = data[p].next[map[i][y] - 'A'];
		if (p == -1)
			break;
		if (data[p].index != -1 && ans[data[p].index].x == -1){
			ans[data[p].index].x = x;
			ans[data[p].index].y = y;
		}
	}
	p = root;
	for (int i = y; i < M; ++i){
		p = data[p].next[map[x][i] - 'A'];
		if (p == -1)
			break;
		if (data[p].index != -1 && ans[data[p].index].x == -1){
			ans[data[p].index].x = x;
			ans[data[p].index].y = y;
		}
	}
	p = root;
	for (int i = x, j = y; i < N&&j < M; i++, j++){
		p = data[p].next[map[i][j] - 'A'];
		if (p == -1)
			break;
		if (data[p].index != -1 && ans[data[p].index].x == -1){
			ans[data[p].index].x = x;
			ans[data[p].index].y = y;
		}
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	cin >> N >> M;
	size = 0;
	root = MALLOC();
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < N; ++i)
		cin >> map[i];
	char t[30];
	int num = 0;
	while (cin >> t && t[0] != '-'){
		Insert(t, num++);
	}
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j){
		query(i, j);
	}
	for (int i = 0; i < num; ++i)
		printf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}