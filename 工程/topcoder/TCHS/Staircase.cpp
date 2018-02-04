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
#define DEBUG (0)
struct Node{
	int cur, down, step;
	Node(int a, int b,int c){
		cur = a;
		down = b;
		step = c;
	}
	Node(){}
};

bool vis[60][60];
vector<int> sta;

int pw(int p){
	int ret = 1;
	for (int i = 0; i < p; ++i){
		ret *= 2;
		if (ret>(1e9)){
			return ret;
		}
	}
	return ret;
}

class Staircase {
public:
	int bfs(){
		memset(vis, 0, sizeof(vis));
		vis[0][0] = 1;
		queue<Node> qn;
		qn.push(Node(0, 0,0));
		while (!qn.empty()){
			Node u = qn.front(), v;
			qn.pop();
			if (u.cur == sta.size() - 1){
				return u.step;
			}


			if (u.cur == 0 && u.down == 1 && u.step == 2){
	//			int t = 0;
			}

			if (u.down == 0 ){
				if (sta[u.cur] + 1 == sta[u.cur + 1]){
					v.cur = u.cur + 1;
					v.step = u.step + 1;
					v.down = 0;
					if (!vis[v.cur][v.down]){
						vis[v.cur][v.down] = 1;
						qn.push(v);
					}
				}
			}
			else{
				int en = pw(u.down) + sta[u.cur];
				int pos = 0;
				while (pos < sta.size() && en >= sta[pos])
					pos++;
				pos--;
				v.cur = pos;
				v.down = 0;
				v.step = u.step + 1;
				if (!vis[v.cur][v.down]){
					vis[v.cur][v.down] = 1;
					qn.push(v);
				}
			}
			
			if (u.cur > 0){
				v.cur = u.cur - 1;
				v.down = u.down + 1;
				v.step = u.step + 1;
				if (!vis[v.cur][v.down]){
					vis[v.cur][v.down] = 1;
					qn.push(v);
				}
			}
			
		}
		return -1;
	}

	int minimalSteps(vector <int> stairs) {
		sta = stairs;
		return bfs();
	}
};



#if 0
int main(){
	vector<int> p({ 0, 1, 2, 3, 6 });
	Staircase so;
	cout<<so.minimalSteps(p)<<endl;
















	return 0;
}
#endif

