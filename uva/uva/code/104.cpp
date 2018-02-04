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
struct Node{
	int now, dept;
	Node(){}
	Node(int a, int b){
		now = a;
		dept = b;
	}
};

int N;
double rate[40][40];
double p[40][40];
bool vis[40][40];
int pace[40][40];

void Init(){
	for (int i = 0; i < 40;++i)
	for (int j = 0; j < 40; ++j){
		vis[i][j] = 0;
		p[i][j] = 0;
	}
}

int ans;
vector<int> vi;

void dfs(int now,int dept){
	if (dept == -1){
		return;
	}
	dfs(pace[now][dept], dept - 1);
	vi.push_back(now);
}

void spfa(int start){
	Init();
	queue<Node> qi;
	p[start][0] = 1.0;
	qi.push(Node(start, 0));
	vis[start][0] = 1;
	while (!qi.empty()){
		Node u = qi.front(), v;
		qi.pop();
		vis[u.now][u.dept] = 0;
		if (u.dept > 33)
			continue;
		
		for (int i = 1; i <= N; ++i){
			if (i == u.now){
				continue;
			}
				
			v.now = i;
			v.dept = u.dept + 1;
			double vp = p[u.now][u.dept] * rate[u.now][v.now];
			if (vp - p[v.now][v.dept] > 1e-7){
				p[v.now][v.dept] = vp;
				pace[v.now][v.dept] = u.now;
				if (!vis[v.now][v.dept]){
					vis[v.now][v.dept] = 1;
					qi.push(v);
				}
			}
		}
	}
	
	for (int i = 1; i < 40; ++i){
		if (p[start][i] - 1.01 > 1e-7 ){
			if (ans > i){
				ans = i;
				vi.clear();
				dfs(start, i);
			}
			break;
		}

	}


}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	while (in >> N){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j){
			if (i == j)
				continue;
			in >> rate[i][j];
		}
		ans = 9999;
		for (int i = 1; i <= N; ++i){
			if (i == 5){
				int t = 0;
			}
			spfa(i);
		}
		if (ans == 9999 || vi.size() -1 > N)
			cout << "no arbitrage sequence exists" << endl;
		else{
			for (int i = 0; i < vi.size()-1 ; ++i)
				cout << vi[i] << " ";
			cout <<vi.back()<< endl;
		

		}

	}



	return 0;
}