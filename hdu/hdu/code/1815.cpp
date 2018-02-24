#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point{
	int x, y;
};
int dist[510][2];
Point S1, S2;
int f[510], e[510];
bool vis[510];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
void Union(int a, int b){
	f[find(a)] = find(b);
}


int main(){
	ifstream in("C:\\temp.txt");
	int N, M1, M2;
	while (in >> N >> M1 >> M2){
		memset(vis, 0, sizeof(vis));
		in >> S1.x >> S1.y >> S2.x >> S2.y;
		for (int i = 1; i <= N; ++i){
			int x, y;
			in >> x >> y;
			dist[i][0] = abs(x - S1.x) + abs(y - S1.y);
			dist[i][1] = abs(x - S2.x) + abs(y - S2.y);
			f[i] = i;
			e[i] = -1;
		}
		while(M1--){
			int a, b;
			in >> a >> b;
			if (e[a] != -1)
				Union(e[a], b);
			else
				e[a] = b;
			if (e[b] != -1)
				Union(e[b], a);
			else
				e[b] = a;
		}
		while (M2--){
			int a, b;
			in >> a >> b;
			Union(a, b);
		}
		int sum = 0;
		for (int i = 1; i <= N; ++i)
		if (!vis[i]&&f[i] == i){
			vis[i] = 1;
			int sum1, sum2;
			if (e[i] == -1){
				sum1 = sum2 = 0;
				for (int j = 1; j <= N;++j)
				if (f[j] == i){
					sum1 += dist[j][0];
					sum2 += dist[j][1];
				}
				sum += min(sum1, sum2);
			}
			else{
				if (vis[e[i]]){
					sum = -1;
					break;
				}
				vis[e[i]] = 1;
				sum1 = sum2 = 0;
				for (int j = 1; j <= N;++j)
				if (f[j] == i){
					sum1 += dist[j][0];
					sum2 += dist[j][1];
				}
				else if (f[j] == e[i]){
					sum1 += dist[j][1];
					sum2 += dist[j][0];
				}
				sum += min(sum1, sum2);
			}
		}
		cout << sum << endl;
	}
	return 0;
}