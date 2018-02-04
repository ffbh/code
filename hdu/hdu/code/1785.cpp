#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	double x, y;
	bool operator<(const Node& p)const{
		return x / y>p.x / p.y;
	}
};
Node num[110];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N > 0){
		for (int i = 0; i < N; ++i)
			cin >> num[i].x >> num[i].y;
		//	in >> num[i].x >> num[i].y;
		sort(num, num + N);
		for (int i = 0; i < N - 1; ++i)
			printf("%.1f %.1f ", num[i].x, num[i].y);
		printf("%.1f %.1f\n", num[N-1].x, num[N-1].y);
	}
	return 0;
}