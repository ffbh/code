#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node{
	double x, y;
}data[10100];

double getArea(Node& a, Node& b, Node& c){
	double k = (b.x - a.x)*(c.y - a.y) -
		(b.y - a.y)*(c.x - a.x);
	return fabs(k) / 2.0;


}


int main(){
	ifstream in("C:\\input.txt");
	int N;
	double len;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i].x >> data[i].y;
		cin >> len;
		double sum = 0;
		for (int i = 1; i < N - 1; ++i)
			sum += getArea(data[0], data[i], data[i + 1]);
		printf("BAR LENGTH: %.2f\n", len/sum );
	}
	return 0;
}