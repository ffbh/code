#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
#define exp (1e-6)
#define getDist(a,b) (sqrt((data[a].x - data[b].x)*(data[a].x - data[b].x) +\
		(data[a].y - data[b].y)*(data[a].y - data[b].y)))
struct Point{
	double x, y;
	double dist;
	bool operator<(const Point& p)const{
		return dist < p.dist;
	}
}data[210]; 
double map[210][210];
int N;

bool slove(){
	for (int i = 1; i <= N; ++i){
		bool flag = 0;
		for (int j = 1; j <= N; ++j){
			if (i == j)
				continue;
			if (map[i][j] / 2.0 - data[i].dist < exp){
				flag = 1;
				break;
			}
		}
		if (!flag){
			printf("%.6f\n", 2.0*data[i].dist);
			return 1;
		}
	}
	return 0;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		data[0].x = data[0].y = 0;
		cin >> N;
		for (int i = 1; i <= N; ++i){
			cin >> data[i].x >> data[i].y;
			data[i].dist = getDist(0, i);
		}
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N;++j)
			map[i][j] = getDist(i, j);
		sort(data + 1, data + N + 1);
		if (!slove())
			printf("-1.0\n");
	}
	return 0;
}