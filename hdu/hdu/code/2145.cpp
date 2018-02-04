#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 99999999
int N, M, K;
struct Node{
	int to;
	int v;
};
vector<Node> vn[302];
int S;
int NumCity[302];
int Speed[302];
int dist[302];
void spfa(){
	queue<int> qi;
	bool vis[301] = { 0 };
	fill(dist, dist + 301, INF);
	vis[S] = 1;
	qi.push(S);
	dist[S] = 0;
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		vis[temp] = 0;
		for (int i = 0; i < vn[temp].size(); ++i){
			int son = vn[temp][i].to;
			int v = vn[temp][i].v;
			if (dist[son]>dist[temp] + v){
				dist[son] = dist[temp] + v;
				if (!vis[son]){
					vis[son] = 1;
					qi.push(son);
				}
			}
		}
	}
}



int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M >> K){
		for (int i = 0; i < 301; ++i)
			vn[i].clear();
		while (K--){
			int a, b, c;
		//	cin >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			vn[b].push_back(Node{ a, c });
		}
		cin >> S;
		for (int i = 1; i <= M; ++i)
			//cin >> NumCity[i];
			scanf("%d", &NumCity[i]);
		for (int i = 1; i <= M; ++i)
			//cin >> Speed[i];
			scanf("%d", &Speed[i]);
		spfa();
		double mmin = DBL_MAX;
		int ans = 0;
		for (int i = 1; i <= M;++i)
		if (dist[NumCity[i]] != INF){
			if (double(dist[NumCity[i]]) / Speed[i] < mmin){
				mmin = double(dist[NumCity[i]]) / Speed[i];
				ans = i;
			}
			else if (double(dist[NumCity[i]]) / Speed[i] == mmin&&dist[NumCity[i]]>dist[NumCity[ans]])
				ans = i;
			else if (double(dist[NumCity[i]]) / Speed[i] == mmin&&dist[NumCity[i]] == dist[NumCity[ans]])
				ans = i;
		}
		if (mmin != DBL_MAX)
			cout << ans << endl;
		else
			cout << "No one" << endl;
	}
	return 0;
}