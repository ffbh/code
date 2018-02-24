#include <iostream>
using namespace std;
struct Node{
	Node(int a, int b) :f(a), l(b){}
	Node(){}
	int f, l;
	bool vis;
};
Node dp[110][110];
int N, M;
int data[110][110];
struct Point{
	Point(int a, int b) :x(a), y(b){}
	Point(){}
	int x, y;
};
bool IN(const Point& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}
Node dfs(const Point& p){
	if (IN(p)){
		Point temp;
		if (data[p.x][p.y] > N + M - p.x - p.y - 2)
			return Node(0, 1);
		else if (data[p.x][p.y] == N + M - p.x - p.y - 2)
			return Node(1, 1);
		if (data[p.x][p.y] == 0)
			return Node(-1, 0);
		if (dp[p.x][p.y].vis)
			return dp[p.x][p.y];
		Node ans(-1, 0);
		ans.vis = 1;
		for (int i = 0; i <= data[p.x][p.y]; ++i){
			temp.x = p.x + i;
			temp.y = p.y + data[p.x][p.y] - i;
			Node tt = dfs(temp);
			if (ans.f < tt.f)
				ans = tt;
			else if (ans.f == tt.f)
				ans.l += tt.l;
		}
		ans.f++;
		return dp[p.x][p.y] = ans;
	}
	else
		return Node(-1, 0);
}
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &data[i][j]);
		Node ans = dfs(Point(0, 0));
		if (ans.f < 0)
			ans.f = 0;
		cout << ans.f << " " << ans.l << endl;
	}
	return 0;
}