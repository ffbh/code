#include <iostream>
//#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
struct time{
	int h, m;
	double angle;
};
time num[10];
double getA(int h, int m){
	double a, b;
	b = 6.0 * m;
	if (h >= 12) h -= 12;
	a = double(h*30.0) + b / 12;
	if (abs(b - a) > 180)return 360.0 - abs(b - a);
	return abs(b - a);

}
bool cmp(const time& a, const time& b){
	if (a.angle!=b.angle)
	return a.angle < b.angle;
	return a.h < b.h;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	int h,m;
	double ang;
	while (N--){
		memset(num, 0, sizeof(num));
		for (int i = 0; i < 5; ++i){
			//in >> h >> m;
			scanf("%d:%d", &h, &m);
			num[i].h = h;
			num[i].m = m;
			num[i].angle = getA(h, m);
		}
		sort(num, num + 5, cmp);
		printf("%02d:%02d\n", num[2].h, num[2].m);
	
	
	}




	return 0;
}