#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF (-1<<29)
int N;
double D;
struct Node{
	double x, y;
	bool operator<(const Node& p)const{
	//	if (y != p.y)
			return y < p.y;
	//	return x>p.x;
	}
}data1[1010], data[1010];
int main(){
	ifstream in("C:\\temp.txt");
	int CASE = 1;
	while (cin >> N >> D&&N+D){
		printf("Case %d: ", CASE++);
		for (int i = 0; i < N; ++i)
			cin >> data1[i].x >> data1[i].y;
		bool flag = 0;
		for (int i = 0; i < N; ++i){
			if (fabs(data1[i].y)>D){
				flag = 1;
				break;
			}
			double d = sqrt(D*D - data1[i].y*data1[i].y);
			data[i].x = data1[i].x - d;
			data[i].y = data1[i].x + d;
		}
		if (flag){
			cout << -1 << endl;
			continue;
		}
		sort(data, data + N);
		double end = INF;
		int ans = 0;
		for (int i = 0; i < N; ++i){
			if (end < data[i].x){
				end = data[i].y;
				ans++;
			}
		}
		cout << ans << endl;

	}



	return 0;
}