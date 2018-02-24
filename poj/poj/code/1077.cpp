/*#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <ctime>
using namespace std;
ifstream in("C:\\input.txt");
struct StringPath{
	struct Data{
		char c;
		int pre;
	}data[1000010];
	int size;

	StringPath(){
		size = 0;
	}

	int add(int now, char c){
		size++;
		data[size].c = c;
		data[size].pre = now;
		return size;
	}

	void print(int index){
		while (index){
			putchar(data[index].c);
			index = data[index].pre;
		}
		cout << endl;
	}

};

int dirs[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
string path = "uldr";

struct EightNum{
	struct Vis{
		static const int N = 400010, M = 10;
		int vis[N][M];
		Vis(){
			memset(vis, 0, sizeof(vis));
		}
		bool test(int code){
			int mod = code%N;
			int index = 0;
			bool f = 0;
			while (vis[mod][index]){
				if (vis[mod][index] == code)
					f = 1;
				index++;
			}
			vis[mod][index] = code;
			return f;
		}
	};
	struct Data{
		int data[3][3];
		int code, x, y, index;

		int hashCode(){
			code = 0;
			for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				code = code * 9 + data[i][j];
			return code;
		}


	}start, end;
	StringPath* stringPath;
	Vis* vis;

	EightNum(){
		int t = 1;
		stringPath = new StringPath(); 
		vis = new Vis();
		for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j){
			char c;
			in >> c;
			if (c == 'x'){
				end.data[i][j] = 0;
				end.x = i;
				end.y = j;
			}
			else
				end.data[i][j] = c - '0';
			start.data[i][j] = t++;
		}
		start.data[2][2] = 0;
		start.x = 2;
		start.y = 2;
		start.index = 0;
		start.hashCode();
		end.hashCode();
	}
	bool IN(int _x, int _y){
		return _x >= 0 && _x < 3 && _y >= 0 && _y < 3;
	}

	int bfs(){
		queue<Data> qd;
		Data u, v;
		vis->test(start.code);
		qd.push(start);
		while (!qd.empty()){
			u = qd.front();
			qd.pop();
			if (u.hashCode() == end.code){
				return u.index;
			}
			for (int i = 0; i < 4; ++i){
				int nx = u.x + dirs[i][0];
				int ny = u.y + dirs[i][1];
				if (IN(nx, ny)){
					v = u;
					swap(v.data[u.x][u.y], v.data[nx][ny]);
					v.x = nx;
					v.y = ny;
					if (!vis->test(v.hashCode())){
						v.index = stringPath->add(u.index, path[i]);
						qd.push(v);
					}
				}
			}
		}
		return -1;
	}

	void slove(){
		int ans = bfs();
		if (ans == -1)
			cout << "unsolvable" << endl;
		else
			stringPath->print(ans);
	}
};



int main(){
	long time = clock();
	EightNum eightNum;
	eightNum.slove();
	cout << clock() - time << endl;

	return 0;
}*/