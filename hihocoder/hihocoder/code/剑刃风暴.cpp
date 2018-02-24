#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
#define exp (0.000001)
int N;
double R;
double x[2010], y[2010];
double center_x, center_y;
double get_dist(int a,int b){
	return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}

double get_dist(double x1,double y1,double x2,double y2){
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void get_center(int a,int b){
	double mid_x = (x[a] + x[b]) / 2.0;
	double mid_y = (y[a] + y[b]) / 2.0;
	double r = get_dist(mid_x, mid_y, x[a], y[a]);
	double pr = sqrt((R*R) - (r*r));
	double angle = atan2( x[a] - x[b],y[b] - y[a]);
	
//	center_x = mid_x + sin(angle)*pr;
	//center_y = mid_y - cos(angle)*pr;
	if (fabs(x[a] - x[b]) < exp){
		center_x = mid_x + pr;
		center_y = mid_y;
	}
	else{
		double ang = atan((y[a] - y[b]) / (x[a] - x[b]));
		center_x = mid_x + sin(ang)*pr;
		center_y = mid_y - cos(ang)*pr;
	}
}

int main(){
	ifstream in("C:\\input.txt");

	cin >> N >> R;
	for (int i = 1; i <= N; ++i)
		cin >> x[i] >> y[i];
	int ans = 1;

	for (int i = 1; i <= N;++i)
	for (int j = i + 1; j <= N; ++j){
		if (get_dist(i, j) >= 2 * R){
			continue;
		}
		get_center(i, j);
		int num = 0;
		for (int i = 1; i <= N; ++i){
			if (get_dist(center_x, center_y, x[i], y[i]) <= R + exp){
				num++;
			}
		}
		ans = max(num, ans);

	}

	cout << ans << endl;


	return 0;
}