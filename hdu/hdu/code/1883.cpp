#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
#define exp (0.001)
struct Node{
	float x, y;
}data[2010], center1,center2;
double getDist(Node& a,Node& b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));

}
int N;
float D;

void getCenter(int a,int b){
	float midx, midy;
	midx = (data[a].x + data[b].x) / 2;
	midy = (data[a].y + data[b].y) / 2;
	float d = getDist(data[a], data[b]) / 2;
	d = sqrt(D*D - d*d);
	if (fabs(data[a].y - data[b].y) <= exp){
		center1.x = midx;
		center1.y = midy + d;
		center2.x = midx;
		center2.y = midy - d;
	}
	else{
		float k = (data[a].y - data[b].y) / (data[a].x);
		k = atan(-1.0 / k);
		center1.x = midx + cos(k)*d;
		center1.y = midy + sin(k)*d;
		center2.x = midx - cos(k)*d;
		center2.y = midy - sin(k)*d;
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N >> D&&N+D){
		for (int i = 0; i < N; ++i)
			in >> data[i].x >> data[i].y;
			//scanf("%f%f", &data[i].x, &data[i].y);
		int ans = 1;
		for (int i = 0; i < N;++i)
		for (int j = i+1; j < N; ++j){///////////
			if (fabs(getDist(data[i], data[j])) > D*2+exp)
				continue;
			getCenter(i, j);
			int num1 = 0, num2 = 0;
			for (int k = 0; k < N; ++k){
				if (fabs(getDist(center1, data[k])) <= D + exp)
					num1++;
				if (fabs(getDist(center2, data[k])) <= D + exp)
					num2++;
			}
			if (ans < num1)
				ans = num1;
			if (ans < num2)
				ans = num2;
		}
		printf("It is possible to cover %d points.\n", ans);
	}
	return 0;
}