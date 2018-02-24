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
using namespace std;
#define pii pair<int,int>
int st;
int vis[1000010];
void input(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> st;

}

bool judge(int p){
	int l, r;
	l = r = 0;
	for (int i = 0; i < 3; ++i){
		l += p % 10;
		p /= 10;
	}
	for (int i = 0; i < 3; ++i){
		r += p % 10;
		p /= 10;
	}
	return l == r;
}

int ppp[6] = { 100000, 10000, 1000, 100, 10, 1 };

int bfs(){
	queue<int> qi;
	qi.push(st);
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		if (judge(u)){
			return vis[u];
		}

		int digit[6], tmp = u;
		for (int i = 5; i >= 0; --i){
			digit[i] = tmp % 10;
			tmp /= 10;
		}

		for (int i = 0; i < 6;++i)
		for (int j = 0; j < 10; ++j){
			if (digit[i] == j)
				continue;
			int v = u + (j- digit[i]) * ppp[i];
			if (!vis[v]){
				vis[v] = vis[u] + 1;
				qi.push(v);
			}

		}
	}



}


int main(){
	input();

	cout << bfs() << endl;
















	return 0;
}





