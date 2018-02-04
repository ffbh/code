#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
struct Point{
	double x, y;
};
double distance1(const Point& a, const Point& b){
	return sqrt(pow(a.x - b.x, 2)+ pow(a.y - b.y, 2));
}
Point p[110];
double dp[110];
bool vis[110];
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i)
			scanf("%lf%lf", &p[i].x, &p[i].y);
			//in >> p[i].x >> p[i].y;
		for (int i = 1; i < N; ++i)
			dp[i] = distance1(p[0], p[i]);
		vis[0] = 1;
		double sum = 0;
		for (int i = 1; i < N; ++i){
			double mmin = 99999999.0;
			int u;
			for (int j = 0; j < N; ++j)
			if (mmin>dp[j] && !vis[j]){
				mmin = dp[j];
				u = j;
			}
			sum += dp[u];
			vis[u] = 1;
			double t;
			for (int k = 0; k < N; ++k)
			if (!vis[k] && dp[k]>(t = distance1(p[u], p[k])))
				dp[k] = t;
		}
		printf("%.2f\n", sum);

	}

	return 0;
}