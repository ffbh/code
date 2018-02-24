#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MMAX 120
vector<int> vi[MMAX];
int dist[MMAX];
bool vis[MMAX];
string s;
int spfa(){
	queue<int> qi;
	memset(vis, 0, sizeof(vis));
	fill(dist, dist + MMAX, 9999);
	qi.push(0);
	vis[0] = 1;
	dist[0] = 0;
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		vis[temp] = 0;
		for (int i = 0; i < vi[temp].size(); ++i){
			int son = vi[temp][i];
			if (dist[son]>dist[temp] + 1){
				dist[son] = dist[temp] + 1;
				if (!vis[son]){
					vis[son] = 1;
					qi.push(son);
				}
			}
		}
	}
	return dist[s.length()];
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> s){
		for (int i = 0; i < MMAX; ++i)
			vi[i].clear();
		int l, r;
		for (int i = 0; i < s.length(); ++i){
			l = i - 1;
			r = i + 1;
			while (l >= 0 && r<s.length()&&s[l] == s[r]){
				vi[l].push_back(r+1);
				l--;
				r++;
				
			}
			l = i;
			r = i + 1;
			while (l >= 0 && r<s.length()&&s[l] == s[r]){
				vi[l].push_back(r+1);
				l--;
				r++;
			}
		}
		for (int i = 0; i < s.length(); ++i)
			vi[i].push_back(i + 1);
		cout << spfa()-1 << endl;
	}
	return 0;
}