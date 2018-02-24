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
using namespace std;
int N, P;
vector<int> vi[60];
int mark[60];

void Init(){
	for (int i = 0; i < 60; ++i){
		mark[i] = -1;
		vi[i].clear();
	}

}

bool bfs(int s,int next){
	queue<int> qi;
	qi.push(s);
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i];
			if (mark[v] == -1){
				mark[v] = mark[u] + next;
				qi.push(v);
			}
			else{
				if (abs(mark[v] - mark[u]) % 2 == 0)
					return 0;
			}
		}
	}
	return 1;
}

int ansP, ansMark[60];

void update(){
	int mmax = -1;
	int mmin = 111;
	for (int i = 1; i <= P; ++i){
		mmax = max(mmax, mark[i]);
		mmin = min(mmin, mark[i]);
	}
	if (mmax - mmin > ansP){
		ansP = mmax - mmin;
		memcpy(ansMark, mark, sizeof(ansMark));
	}
}
int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N >> P){
		Init();
		for (int i = 1; i <= N; ++i){
			int a, b;
			cin >> a >> b;
			vi[a].push_back(b);
			vi[b].push_back(a);
		}
		bool ok = 1;
		int num = 0;
		for (int i = 1; i <= P; ++i){
			if (mark[i] == -1){
				num++;
				if (num % 2 == 1){
					mark[i] = 1;
					if (!bfs(i,1)){
						ok = 0;
						break;
					}
				}
				else{
					mark[i] = 50;
					if (!bfs(i, -1)){
						ok = 0;
						break;
					}
				}
			}
		}

		if (ok){
			if (num > 1){
				int mmax = -1;
				int mmin = 111;
				for (int i = 1; i <= P; ++i){
					mmax = max(mmax, mark[i]);
					mmin = min(mmin, mark[i]);
				}
				cout << mmax - mmin << endl;
				for (int i = 1; i <= P; ++i){
					cout << mark[i] << " ";
				}
				cout << endl;
			}
			else{
				ansP = -1;
				for (int i = 1; i <= P; ++i){
					memset(mark, -1, sizeof(mark));
					mark[i] = 1;
					bfs(i, 1);
					update();
				}
				cout << ansP << endl;
				for (int i = 1; i <= P; ++i){
					cout << ansMark[i] << " ";
				}
				cout << endl;
			}
		}
		else
			cout << -1 << endl;
	}


	return 0;
}