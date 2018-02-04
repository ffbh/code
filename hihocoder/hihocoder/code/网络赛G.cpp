#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <ctime>
using namespace std;
int N;
int f[10];
bool vis[900000];
int ans[8][900000];
struct Node{
	int m[7];
	int step;
	int hashcode(){
		int code = 0;
		for (int i = N-1; i >= 0; --i)
			code += f[i] * m[i];
		return code;
	}
	int getslotTop(int index){
		for (int i = 0; i < N;++i)
		if (m[i] == index)
			return i;
		return 99999;
	}
	void show(){
		for (int i = 0; i < 7; ++i)
			cout << m[i] << " ";
		cout << endl;
	}
}start;



void bfs(int num){
	N = num;
	queue<Node> qn;
	memset(ans[num], -1, sizeof(ans[num]));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 7; ++i)
		start.m[i] = i;
	start.step = 0;
	int code = start.hashcode();
	vis[code] = 1;
	ans[num][code] = start.step;
	qn.push(start);
	while(!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		for (int i = 0; i < num; ++i){
			int top = u.getslotTop(i);
			if (i - 1 >= 0 && top < u.getslotTop(i-1)){
				for (int j = 0; j < num; ++j)
					v.m[j] = u.m[j];
				v.m[top] = i - 1;
				v.step = u.step + 1;
				code = v.hashcode();
				if (!vis[code]){
					vis[code] = 1;
					ans[num][code] = v.step;
					qn.push(v);
				}
			}
			if (i + 1 < num && top < u.getslotTop(i+1)){
				for (int j = 0; j < num; ++j)
					v.m[j] = u.m[j];
				v.m[top] = i + 1;
				v.step = u.step + 1;
				code = v.hashcode();
				if (!vis[code]){
					vis[code] = 1;
					ans[num][code] = v.step;
					qn.push(v);
				}
			}
		}
	}
}




int main(){
	ifstream in("C:\\input.txt");
	f[0] = 1;
	for (int i = 1; i < 10; ++i)
		f[i] = f[i - 1] * 7;
	int T;
	cin >> T;
//	scanf("%d", &T);
	for (int i = 1; i <= 7;++i)
		bfs(i);
	map<int, int> mii;
	while(T--){
		mii.clear();
		cin >> N;
		int d = 0;

	//	scanf("%d", &N);
		for (int i = 0; i < N; ++i){
			int t;
			cin >> t;
			//scanf("%d", &t);
			mii[t] = d++;
		}
		map<int, int>::iterator it = mii.begin();
		for (int i = 0; i < N; ++i){
			start.m[i] = it->second;
			it++;
		}
	//	start.show();
		cout << ans[N][start.hashcode()] << endl;
	}
	return 0;
}