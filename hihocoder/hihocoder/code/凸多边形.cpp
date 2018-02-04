#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N, M;
double x, y;
struct Point{
	double x, y;
}data[110];

double area[110][110];
double dp[110][110][110];

double getArea(int i,int j){
	double a, b, c, p;
	a = sqrt((data[i].x - x)*(data[i].x - x) + (data[i].y - y) *(data[i].y - y));
	b = sqrt((data[j].x - x)*(data[j].x - x) + (data[j].y - y) *(data[j].y - y));
	c = sqrt((data[j].x - data[i].x)*(data[j].x - data[i].x) + (data[j].y - data[i].y) *(data[j].y - data[i].y));
	p = (a + b + c) / 2.0;
	return sqrt(p *(p - a)*(p - b)*(p - c));
}






int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	x = y = 0;
	for (int i = 0; i < N; ++i){
		cin >> data[i].x >> data[i].y;
		x += data[i].x;
		y += data[i].y;
	}
	x /= N;
	y /= N;
	double sum = 0;
	for (int i = 0; i < N; ++i)
		sum += getArea(i, (i + 1) % N);





	return 0;
}