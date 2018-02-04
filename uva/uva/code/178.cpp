#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <deque>
using namespace std;
struct Node{
	int x, y;
	bool check;
	Node(int a, int b,bool c=0){
		x = a;
		y = b;
		check = c;
	}
	bool operator==(const Node& p)const{
		return x == p.x&&y == p.y;
	}
	bool operator<(const Node& p)const{
		return x < p.x || x == p.x&&y < p.y;
	}
};
int pile[5][5];
int num[5][5];
deque<Node> dn;
vector<Node> que;
int h[266];
void Init(){
	dn.clear();
	que.clear();
	for (int i = 1; i < 5; ++i)
	for (int j = 1; j < 5; ++j){
		num[i][j] = 0;
		pile[i][j] = -1;
		dn.push_back(Node(i, j,1));
	}
}

int getValue(string& s){
	return h[s[0]];
}

bool IN(int x, int y){
	return x >= 1 && x <= 4 && y >= 1 && y <= 4;
}

void del(Node k){
	int pos = -1;
	for (int i = 0; i < que.size(); ++i){
		if (que[i] == k){
			pos = i;
			break;
		}
	}
	if (pos == -1){
		cout << "WAAAAAAAAAAA";
	}
	else{
		for (int i = pos + 1; i < que.size(); ++i){
			que[i - 1] = que[i];
		}
		que.pop_back();
	}

}

bool judgepair(int idx){
	int x = que[idx].x;
	int y = que[idx].y;
	if (pile[x][y]>10)
		return 0;
	int val = pile[x][y];
	for (int i = idx + 1; i < que.size(); ++i){
		int nx = que[i].x;
		int ny = que[i].y;
		int v = pile[nx][ny];
		if (val + v == 11){
			pile[x][y] = pile[nx][ny] = -1;
			
		//	if (Node(nx, ny) < Node(x, y)){
		//		dn.push_front(Node(x, y, 1));
		//		dn.push_front(Node(nx, ny, 0));
		//	}
		//	else{
				dn.push_front(Node(nx, ny, 1));
				dn.push_front(Node(x, y, 0));
		//	}
			del(Node(x, y));
			del(Node(nx, ny));
			return 1;
		}
	}
	return 0;
}

bool judgetriple(int idx){
	int x = que[idx].x;
	int y = que[idx].y;
	if (pile[x][y]<=10)
		return 0;
	int mark[3];
	for (int i = 0; i < 3; ++i)
		mark[i] = 0;
	mark[pile[x][y] - 11] = 1;
	vector<Node> V;
	V.push_back(Node(x, y));
	for (int i = idx + 1; i < que.size(); ++i){
		int val = pile[que[i].x][que[i].y];
		if (val >= 11){
			val -= 11;
			if (!mark[val]){
				mark[val] = 1;
				V.push_back(Node(que[i].x, que[i].y));
			}
		}
	}
	if (V.size() == 3){
	//	sort(V.begin(), V.end());
		for (int i = 0; i < V.size(); ++i)
			V[i].check = 0;
		V.back().check = 1;
		for (int i = 2; i >= 0; --i){
			pile[V[i].x][V[i].y] = -1;
			dn.push_front(V[i]);
			del(V[i]);
		}
		return 1;
	}

	return 0;
}
void check(){
	sort(que.begin(), que.end());
	for (int i = 0; i < que.size(); ++i){
		if (judgepair(i) || judgetriple(i)){
			break;
		}
	}


}


bool put_to_pile(string& s){
	int val = getValue(s);
	if (dn.size() == 0){
		return 0;
	}
	Node tmp = dn.front();
	dn.pop_front();
	num[tmp.x][tmp.y]++;
	pile[tmp.x][tmp.y] = val;
	que.push_back(tmp);
	if (tmp.check){
		check();
	}
	return 1;
}
string str[60];

void show(){
	for (int i = 1; i <= 4; ++i){
		for (int j = 1; j <= 4; ++j){
			cout << pile[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
ofstream ou("C:\\input2.txt");
void getInput(){
	for (int i = 1; i <= 52; ++i){
		if (i % 2){
			ou << "7H" << " ";
		}
		else{
			ou << "4H " ;
		}
		if (i % 13==0){
			ou << endl;
		}
	}
}


int main(){
	//getInput();

	//ifstream in("C:\\input.txt");
	istream& in = cin;

	h['A'] = 1;
	for (char c = '2'; c <= '9'; ++c)
		h[c] = c - '0';
	h['T'] = 10;
	h['J'] = 11;
	h['Q'] = 12;
	h['K'] = 13;
	int CASE = 1;
	string card;
	while (in >> card&&card != "#"){
		Init();
		put_to_pile(card);
		for (int i = 2; i <= 52; ++i)
			in >> str[i];
		int flag = -1;
		for (int i = 2; i <= 52; ++i){
			
			if (!put_to_pile(str[i])){
				flag = i;
				break;
			}
	//		show();
		}
		printf("%3d:", CASE++);
		if (flag == -1){
			for (int i = 1; i <= 4;++i)
			for (int j = 1; j <= 4; ++j){
				if (num[i][j] != 0){
					printf("%3d", num[i][j]);
				}

			}
			cout << endl;
		}
		else{
			printf(" Overflowed on card no%3d\n", flag);
		}

	}
	return 0;
}