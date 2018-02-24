#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Point{
	int x, y;
};
Point num[1100];
bool map[110][110];
int N, M,K;
int cnt;
int ID[110][110];
bool match[110][110];
int dirs[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
bool cmp(const Point& p1, const Point& p2){
	if (p1.x != p2.x)
		return p1.x < p2.x;
	return p1.y < p2.y;
}

bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}
int link[1100];
bool vis[1100];

bool dfs(int n){
	for (int i = 0; i < cnt; ++i)
	if (!vis[i]&&match[n][i]){
		vis[i] = 1;
		if (link[i] == -1 ||dfs(link[i])){
			link[i] = n;
			return 1;
		}
	}
	return 0;
}


int MaxMatch(){
	int res = 0;
	for (int i = 0; i < cnt; ++i){
		memset(vis, 0, sizeof(vis));
		if (dfs(i))
			res++;
	}
	return res;
}

void Print(int n){
	Point dd[2];
	dd[0] = num[n];
	dd[1] = num[link[n]];
	sort(dd, dd + 2,cmp);
	printf("(%d,%d)--(%d,%d)\n", dd[0].x+1, dd[0].y+1, dd[1].x+1, dd[1].y+1);
}
int main(){
	ifstream in("C:\\temp.txt");
	int a, b;
	Point t;

	while (cin >> N >> M&&N + M){

		memset(map, 0, sizeof(map));
		memset(match, 0, sizeof(match));
		memset(link, -1, sizeof(link));
		cin >> K;
		cnt = 0;
		for (int i = 0; i < K; ++i){
			//in >> a >> b;
			scanf("%d%d", &a, &b);
			map[a-1][b-1] = 1;
		}
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M;++j)
		if (map[i][j] == 0){
			ID[i][j] = cnt;
			t.x = i;
			t.y = j;
			num[cnt++] = t;
		}
		
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M;++j)
		if (map[i][j] == 0&&(i+j)%2==1){
			int ti, tj;
			for (int k = 0; k < 4; ++k){
				ti = i + dirs[k][0];
				tj = j + dirs[k][1];
				if (IN(ti, tj) && map[ti][tj] == 0){
					match[ID[ti][tj]][ID[i][j]] = 1;
					//match[ID[i][j]][ID[ti][tj]] = 1;
				}
			}
		}
		int ans = MaxMatch();
		cout << ans << endl;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < cnt;++i)
	if (link[i] >= 0){
			vis[i] = 1;
			vis[link[i]] = 1;
			Print(i);
		}
		cout << endl;
		
	}
	return 0;
}