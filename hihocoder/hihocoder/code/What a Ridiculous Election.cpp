#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int num[5];
	int step;
	int optwo, opthree;
	int value(){
		int val = 0;
		for (int i = 0; i < 5; ++i)
			val = val * 10 + num[i];
		return val;
	}
};
int ans[100000];
bool vis[100000][4][3];
void bfs(){
	memset(ans, -1, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	queue<Node> qn;
	Node start;
	for (int i = 0; i < 5; ++i)
		start.num[i] = i + 1;
	start.step = 0;
	start.optwo = 3;
	start.opthree = 2;
	qn.push(start);
	ans[12345] = 0;
	vis[12345][3][2] = 1;
	while (!qn.empty()){
		Node u = qn.front();
		qn.pop();
		u.step++;
		for (int i = 0; i < 4;++i){
			swap(u.num[i], u.num[i+1]);
			int val = u.value();
			if (!vis[val][u.optwo][u.opthree]){
				vis[val][u.optwo][u.opthree] = 1;
				if (ans[val] == -1 || ans[val] > u.step)
					ans[val] = u.step;
				qn.push(u);
			}
			swap(u.num[i], u.num[i+1]);
		}
		if (u.optwo){
			Node v = u;
			v.optwo--;
			for (int i = 0; i < 5; ++i){
				v.num[i]++;
				v.num[i] %= 10;

				int val = v.value();
				if (!vis[val][v.optwo][v.opthree]){
					vis[val][v.optwo][v.opthree] = 1;
					if (ans[val] == -1 || ans[val] > v.step)
						ans[val] = v.step;
					qn.push(v);
					
				}

				v.num[i] = (v.num[i] + 9) % 10;

			}
		}

		if (u.opthree){
			for (int i = 0; i < 5; ++i){
				Node v = u;
				v.opthree--;
				v.num[i] = (v.num[i] * 2) % 10;

				int val = v.value();
				if (!vis[val][v.optwo][v.opthree]){
					vis[val][v.optwo][v.opthree] = 1;
					if (ans[val] == -1 || ans[val] > v.step)
						ans[val] = v.step;
					qn.push(v);
				}
			}
		}


	}
}






int main(){
	ifstream in("C:\\input.txt");
	bfs();
	int N;
	while (cin >> N){
		cout << ans[N] << endl;
	}

	return 0;
}