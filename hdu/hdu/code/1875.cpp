#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int N;
struct Point{
	int x, y;
};
Point data[110];
double map[110][110];
bool vis[110];
double dist[110];



void  Init(){
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			map[i][j] = map[j][i] = sqrt(fabs(double(data[i].x - data[j].x))*fabs(double(data[i].x - data[j].x))
				+ fabs(double(data[i].y - data[j].y))*fabs(double(data[i].y - data[j].y)));
	
}


int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0; i < N; ++i)
			//in >> data[i].x >> data[i].y;
			scanf("%d%d", &data[i].x, &data[i].y);
		Init();
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i)
			dist[i] = 99999;
		for (int i = 1; i < N; ++i)
		if (map[0][i] >= 10 && map[0][i] <= 1000)
			dist[i] = map[0][i];
		vis[0] = 1;
		double ans = 0;
		for (int i = 0; i < N - 1; ++i){
			int u = -1;
			double mmin = 99999;
			for (int j = 0; j < N; ++j)
			if (!vis[j] && dist[j] < mmin){
				u = j;
				mmin = dist[j];
			}
			if (u < 0){
				ans = -1;
				break;
			}
			vis[u] = 1;
			ans += dist[u];
			for (int k = 0; k < N; ++k)
			if (map[u][k] < dist[k]&&map[u][k]>=10&&map[u][k]<=1000)
				dist[k] = map[u][k];
		}
		if (ans >= 0)
			printf("%.1f\n", ans * 100);
		else
			cout << "oh!" << endl;

	}
	return 0;
}