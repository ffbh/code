#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	double x1, y1, x2, y2;
};
Node data[100010];
bool vis[100010];
bool _cross(int i, int j){
	double k1 = (data[j].y1 - data[i].y1)*(data[i].x2 - data[i].x1)
		- (data[j].x1 - data[i].x1)*(data[i].y2-data[i].y1);
	double k2 = (data[j].y2 - data[i].y1)*(data[i].x2 - data[i].x1)
		- (data[j].x2 - data[i].x1)*(data[i].y2 - data[i].y1);
	return k1*k2 < 0;
}

bool cross(int i, int j){
	return _cross(i, j) && _cross(j, i);
}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			//cin >> data[i].x1 >> data[i].y1 >> data[i].x2 >> data[i].y2;
			scanf("%lf%lf%lf%lf", &data[i].x1, &data[i].y1, &data[i].x2, &data[i].y2);
		}
		for (int i = 0; i < N;++i)
		for (int j = i + 1; j < N;++j)
		if (cross(i, j)){
			vis[i] = 1;
			break;
		}
		printf("Top sticks:");
		bool sign = 1;
		for (int i = 0; i < N; ++i){
			if (!vis[i]){
				if (sign){
					sign = 0;
					printf(" %d", i+1);
				}
				else
					printf(", %d", i+1);
			}
		}
		printf(".\n");
	}
	return 0;
}