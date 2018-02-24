#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
int A[100010], B[100010], N, M, tree[100010], ansB;
bool vis[100010];
int slove(int X, int Y){
	int num = 1;
	memset(vis, 0, sizeof(vis[0])*(N + 5));
	tree[X] = num++;
	vis[X] = 1;
	while (A[X]){
		X = A[X];
		tree[X] = num++;
		vis[X] = 1;
	}
	ansB = 1;
	while (!vis[Y]){
		ansB++;
		Y = B[Y];
	}
	return Y;
}

int main(){
	//ifstream in("C:\\input.txt");
//	ios::sync_with_stdio(true);
	int ans, x, y;
	while (cin >> N >> M){
		ans = 0;
		A[1] = B[1] = 0;
		for (int i = 2; i <= N; ++i)
		//	in >> A[i];
			scanf("%d", &A[i]);
		for (int i = 2; i <= N; ++i)
		//	in >> B[i];
			scanf("%d", &B[i]);
		while (M--){
		//	in >> x >> y;
			scanf("%d%d", &x, &y);
			ans = slove((x + ans) % N + 1, (y + ans) % N + 1);
			printf("%d %d %d\n", ans, tree[ans], ansB);
		}
	}
	return 0;
}