#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int father[250];
int N, M;
struct Line{
	int a, b;
	int v;
	bool operator<(const Line& l)const{
		return v < l.v;
	}
};
Line line[1010];
int find(int x){
	return x == father[x] ? x : father[x] = find(father[x]);
}

int main(){
//	ifstream in("C:\\temp.txt");
	int a, b;
	int K;
	while (cin >> N >> M){
		for (int i = 0; i < M; ++i)
			//	in >> line[i].a >> line[i].b >> line[i].v;
			scanf("%d%d%d", &line[i].a, &line[i].b, &line[i].v);
		sort(line, line + M);
		cin >> K;
		while (K--){
		//	in >> a >> b;
			scanf("%d%d", &a, &b);
			int ans=INT_MAX;
			for (int i = 0; i < M; ++i){
				for (int k = 0; k <= N; ++k)
					father[k] = k;
				for (int j = i; j < M; ++j){
					int fa = find(line[j].a);
					int fb = find(line[j].b);
					if (fa != fb)
						father[fa] = fb;
					if (find(a) == find(b)){
						ans = min(ans,line[j].v - line[i].v);
						break;
					}
				}
			}
			if (ans!=INT_MAX)
				cout << ans << endl;
			else cout << -1 << endl;
				
		}
	}
	return 0;
}