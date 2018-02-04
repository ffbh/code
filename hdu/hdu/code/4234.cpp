#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct Node{
	double x, y, d, s;
}data[20];
int N, C;




int main(){
	ifstream in("C:\\input.txt");
	while (in >> N >> C&&N+C){
		for (int i = 0; i < N; ++i)
			in >> data[i].x >> data[i].y >> data[i].d >> data[i].s;

	}
















	return 0;
}