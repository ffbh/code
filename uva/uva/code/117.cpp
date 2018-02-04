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
	int to, d;
	Node(int a,int b){
		to = a;
		d = b;
	}
};
int deg[30], a, b;
vector<Node> vi[30];
vector<int> odd;

void Init(){
	for (int i = 0; i < 30; ++i){
		vi[i].clear();
		deg[i] = 0;
	}
	odd.clear();
}
int dist[30];

bool vis[30];

int spfa(int st,int en){
	queue<int> qi;
	for (int i = 0; i < 30; ++i){
		vis[i] = 0;
		dist[i] = (1 << 29);
	}
	dist[st] = 0;
	vis[st] = 1;
	qi.push(st);
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		vis[u] = 0;
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i].to;
			int d = vi[u][i].d;
			if (dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				if (!vis[v]){
					vis[v] = 1;
					qi.push(v);
				}
			}
		}

	}
	return dist[en];
}


int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;

	string s;
	
	while (in >> s){
		Init();
		int ans = 0;
		ans += s.length();
		a = s[0] - 'a';
		b = s.back() - 'a';
		deg[a]++;
		deg[b]++;
		vi[a].push_back(Node(b, s.length()));
		vi[b].push_back(Node(a, s.length()));
		while (in >> s && s != "deadend"){
			ans += s.length();
			a = s[0] - 'a';
			b = s.back() - 'a';
			deg[a]++;
			deg[b]++;
			vi[a].push_back(Node(b, s.length()));
			vi[b].push_back(Node(a, s.length()));
		}
		for (char c = 'a'; c <= 'z'; ++c){
			if (deg[c - 'a'] % 2 == 1){
				odd.push_back(c - 'a');
			}
		}
		if (odd.empty()){
			cout << ans << endl;
		}
		else{
			cout << ans + spfa(odd[0], odd[1]) << endl;

		}
	}






	return 0;
}