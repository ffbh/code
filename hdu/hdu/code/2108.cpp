#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Point{
	int x, y;
};
Point data[10001];
bool OK(Point& a, Point& b, Point& c){
	return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y)>0;
} 


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i].x >> data[i].y;
		bool flag = 1;
		for (int i = 0; i < N; ++i)
		if (!OK(data[i], data[(i + 1) % N], data[(i + 2) % N])){
			flag = 0;
			break;
		}
		if (flag)
			cout << "convex" << endl;
		else
			cout << "concave" << endl;
	}
	return 0;
}