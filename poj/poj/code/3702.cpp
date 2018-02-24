#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
int dirs[6][4] = { { 1, -1, 1, -1 }, { -1, 1, -1, 1 }, { -1, -1, 1, 0 }, { 0, -1, -1, 1 }, { 1, 0, -1, -1 }, { -1, 1, 0, -1 } };


bool vis[840000];
struct Node{
	int val[4];
	Node(string& s){
		memset(val, 0, sizeof(val));

		for (int i = 0; i < s.length(); ++i){
			if (s[i] == '*'){
				val[i % 4]++;
			}
		}
	}

	Node(){}
	int getSum(){
		return val[0] + val[1] + val[2] + val[3];
	}

	int gethash(){
		int hash = 0;
		for (int i = 0; i < 4; ++i){
			hash = hash * 31 + val[i];
		}
		return hash;
	}

	
};

bool bfs(string& s,string& e){
	Node start(s), End(e);
	int aim = End.gethash();
	int aim_sum = End.getSum();
	memset(vis, 0, sizeof(vis));
	queue<Node> qi;
	qi.push(start);
	vis[start.gethash()] = 1;
	while (!qi.empty()){
		Node u = qi.front(), v;
		qi.pop();
		if (u.gethash() == aim)
			return 1;
		if (u.getSum() < aim_sum)
			continue;
		for (int i = 0; i < 6; ++i){
			bool ok = 1;
			for (int j = 0; j < 4; ++j){
				v.val[j] = u.val[j] + dirs[i][j];
				if (v.val[j] < 0){
					ok = 0;
					break;
				}
			}
			if (ok){
				int h = v.gethash();
				if (!vis[h]){
					vis[h] = 1;
					qi.push(v);
				}

			}
		}
	}
	return 0;
}

int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		string s, e;
		cin >> s >> e;
		if (bfs(s, e)){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

	}















	return 0;
}