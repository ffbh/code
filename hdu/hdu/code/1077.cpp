#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int N;
#define exp (0.0001)
struct Node{
	double x, y;
}data[310],center;
double getDist(Node& a, Node& b){
	return sqrt((a.x - b.x)*(a.x - b.x) +
		(a.y - b.y)*(a.y - b.y));
}

void getCenter(int a, int b){
	double midx, midy;
	midx = (data[a].x + data[b].x) / 2;
	midy = (data[a].y + data[b].y) / 2;
	double d1 = getDist(Node{ midx, midy }, data[a]);
	double d2 = sqrt(1.0 - d1*d1);
	/*if (fabs(data[a].y - data[b].y) < exp){
		center.x = midx;
		center.y = midy + d2;
	}
	else{
		double k = (data[a].y - data[b].y) / (data[a].x - data[b].x);
		k = atan(-1.0 / k);
		center.x = midx + cos(k)*d2;
		center.y = midy + sin(k)*d2;
	}*/
	if (fabs(data[a].x - data[b].x) < exp){
		center.x = midx + d2;
		center.y = midy;
	}
	else{
		double ang = atan((data[a].y - data[b].y) / (data[a].x - data[b].x));
		center.x = midx + sin(ang)*d2;
		center.y = midy - cos(ang)*d2;
	}
}






int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		int ans = 1;
		for (int i = 0; i < N; ++i)
			cin >> data[i].x >> data[i].y;
		for (int i = 0; i < N;++i)
		for (int j = i+1; j < N; ++j){///////////
			if ((getDist(data[i], data[j]) - 2.0)>exp)
				continue;
			getCenter(i, j);
			int num = 0;
			for (int k = 0; k < N;++k)
			if (getDist(data[k], center) <=1+ exp)
				num++;
			if (num>ans)
				ans = num;
		}
		cout << ans << endl;
	}
	return 0;
}