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

struct Node{
	int x, y;
	int step;
	Node(int a, int b, int c){
		x = a;
		y = b;
		step = c;
	}



	Node(){}
};
vector<string> mmp;
bool vis[110][110];
bool IN(Node& p){
	if (p.x >= 0 && p.x < mmp.size()){
		return p.y >= 0 && p.y < mmp[p.x].size();
	}
	else{
		return 0;
	}

}

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool lf[110][110];
Node pace[110][110];



void dfs(int x, int y){
	if (pace[x][y].x == -1){
		cout << x << " " << y << endl;
	}
	else{
		dfs(pace[x][y].x, pace[x][y].y);
		cout << x << " " << y << endl;
	}
}

void push(Node& u, Node& v, queue<Node>& qn){
	if (IN(v) && !vis[v.x][v.y]){
		vis[v.x][v.y] = 1;
		pace[v.x][v.y] = u;
		qn.push(v);
	}
}



bool LineEnd(Node& p){
	return mmp[p.x].size() - 1 == p.y;
}

void goleft(int x, int& y){
	y--;
	while (y >= 0 && !lf[x][y]){
		y--;
	}
}
void goright(int x, int& y){
	y++;
	while (y < mmp[x].size() && !lf[x][y]){
		y++;
	}
}


int bfs(int sx, int sy, int ex, int ey){
	memset(vis, 0, sizeof(vis));
	queue<Node> qn;
	qn.push(Node(sx, sy, 0));
	vis[sx][sy] = 1;
	pace[sx][sy].x = -1;
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		if (u.x == ex&&u.y == ey){
			return u.step;
		}

		for (int i = 0; i < 4; ++i){
			v.x = u.x + dirs[i][0];
			v.y = u.y + dirs[i][1];
			v.step = u.step + 1;
			push(u, v, qn);
		}

		if (LineEnd(u)){
			v.x = (u.x + 1) % mmp.size();
			v.y = 0;
			v.step = u.step + 1;
			push(u, v, qn);
		}

		v.x = u.x;
		v.y = 0;
		v.step = u.step + 1;
		push(u, v, qn);

		v.x = u.x;
		v.y = mmp[v.x].size() - 1;
		v.step = u.step + 1;
		push(u, v, qn);

		v.x = 0;
		v.y = u.y;
		v.step = u.step + 1;
		push(u, v, qn);

		v.x = mmp.size() - 1;
		v.y = u.y;
		v.step = u.step + 1;
		push(u, v, qn);

		v.x = u.x;
		v.y = u.y;
		v.step = u.step + 1;
		goleft(v.x, v.y);
		push(u, v, qn);

		v.x = u.x;
		v.y = u.y;
		v.step = u.step + 1;
		goright(v.x, v.y);
		push(u, v, qn);

	}

	return -1;

}


class TextEditorNavigation {
public:
	int keystrokes(vector <string> source, vector <int> start, vector <int> finish) {
		mmp = source;
		memset(lf, 0, sizeof(lf));
		for (int i = 0; i < source.size(); ++i){
			int pos = 0;
			while (pos < source[i].size()){
				while (pos < source[i].size() && source[i][pos] == ' ')
					pos++;
				if (pos == source[i].size())
					break;
				lf[i][pos] = 1;

				while (pos < source[i].size() && source[i][pos] != ' ')
					pos++;
			}
		}

		int ans = bfs(start[0], start[1], finish[0], finish[1]);
		//	dfs(finish[0], finish[1]);

		return ans;
	}
};



/*int main(){
vector<string> vs({"AAAAAA  AA"});

vector<int> st({ 0, 2 }), en({ 0, 8 });

TextEditorNavigation so;
cout<<so.keystrokes(vs,st,en)<<endl;














return 0;
}

*/


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
