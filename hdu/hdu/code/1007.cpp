#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Point{
	double x, y;
};
Point data[100010];
Point temp[200];

bool cmpX(const Point& p1, const Point& p2){
	if (p1.x != p2.x)
		return p1.x < p2.x;
	return p1.y < p2.y;
}

bool cmpY(const Point& p1, const Point& p2){
	if (p1.y != p2.y)
		return p1.y < p2.y;
	return p1.x < p2.x;

}

double getNum(int a, int b){
	return sqrt((data[a].x - data[b].x)*(data[a].x - data[b].x)
		+ (data[a].y - data[b].y)*(data[a].y - data[b].y));
}

double getTNum(int a, int b){
	return sqrt((temp[a].x - temp[b].x)*(temp[a].x - temp[b].x)
		+ (temp[a].y - temp[b].y)*(temp[a].y - temp[b].y));
}


double Close_pair(int l, int r){
	double res ;
	if (r - l + 1 <= 3){
		res = DBL_MAX;
		for (int i = l; i <= r;++i)
		for (int j = i + 1; j <= r; ++j){
			double ret = getNum(i, j);
			if (ret < res)
				res = ret;
		}
		return res;
	}
	int mid = (l + r)/2;
	double r1 = Close_pair(l, mid);
	double r2 = Close_pair(mid + 1, r);
	res = min(r1, r2);
	int size = 0;
	for (int i = l; i <= r; ++i)
	if (res >= fabs(data[i].x - data[mid].x))
		temp[size++] = data[i];
	sort(temp, temp + size, cmpY);
	for (int i = 0; i < size;++i)
	for (int j = i+1; j < size&&res>fabs(temp[i].y-temp[j].y); ++j){
		double ret = getTNum(i, j);
		if (ret < res)
			res = ret;
	}
	return res;
}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			// in >> data[i].x >> data[i].y;
			scanf("%lf%lf", &data[i].y, &data[i].x);//倒过来读取，x当作y
		sort(data, data + N, cmpX);
		printf("%.2f\n", Close_pair(0, N - 1)/2);
	}
	return 0; 
}