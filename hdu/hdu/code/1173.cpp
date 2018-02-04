#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	double x, y;
	int N;
	while (cin >> N&&N){
		x = y = 0;
		double dx, dy;
		for (int i = 0; i < N; ++i){
			scanf("%lf%lf", &dx, &dy);
			x += dx;
			y += dy;
		}
		printf("%.2f %.2f\n", x / N, y / N);

	}
	return 0;
}