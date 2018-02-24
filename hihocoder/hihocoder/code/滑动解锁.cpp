#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
ofstream out("C:\\out.txt");
struct Node{
	int x, y;
	Node(int _x, int _y){
		x = _x;
		y = _y;
	}
};
bool mark[400000][10][10];
vector<Node> input;
int size;
char vt[11];
bool ok[10][10];
bool vis[10];
void dfs(int dept){
	if (dept >= 4){
		for (int i = 0; i < dept - 1; ++i){
			mark[size][vt[i]][vt[i + 1]] = 1;
			mark[size][vt[i + 1]][vt[i]] = 1;
		}
		size++;
	}
	if (dept == 9)
		return;
	for (int i = 1; i <= 9; ++i){
		if (vis[i])
			continue;
		if (dept != 0 && ok[vt[dept - 1]][i] && !vis[(vt[dept - 1] + i) / 2])
			continue;
		vt[dept] = i;// no clear
		vis[i] = 1;
		dfs(dept + 1);
		vis[i] = 0;
	}
}

void Init(){
	ok[1][3] = ok[3][1] = 1;
	ok[2][8] = ok[8][2] = 1;
	ok[4][6] = ok[6][4] = 1;
	ok[1][7] = ok[7][1] = 1;
	ok[1][9] = ok[9][1] = 1;
	ok[3][7] = ok[7][3] = 1;
	ok[3][9] = ok[9][3] = 1;
	ok[7][9] = ok[9][7] = 1;
	dfs(0);

}

int Cale(){
	int ans = 0;
	for (int i = 0; i < size; ++i){
		bool f = 1;
		for (int j = 0; j < input.size(); ++j)
		if (!mark[i][input[j].x][input[j].y]){
			f = 0;
			break;
		}
		if (f)
			ans++;
	}
	return ans;
}


int main(){
	ifstream in("C:\\input.txt");
	Init();
	int T, K;
	cin >> T;
	while (T--){
		input.clear();
		cin >> K;
		while (K--){
			int x, y;
			cin >> x >> y;
			input.push_back(Node(x, y));
		}
		cout << Cale() << endl;
	}
	return 0;
}