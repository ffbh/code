#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;



int main(){
	//ifstream in("C:\\temp.txt");
	double k;
	int y1, y2;
	int ansX1, ansX2;
	int N;
	while (cin >> N){
		cin >> y1 >> y2;
		ansX1 = 1;
		ansX2 = 2;
		k = abs(y1-y2);
		for (int i = 3; i <= N; ++i){
			y1 = y2;
			//in >> y2;
			scanf("%d", &y2);
			if (k < abs(y1 - y2)){
				k = abs(y1 - y2);
				ansX1 = i - 1;
				ansX2 = i;
			}
		}
		printf("%d %d\n", ansX1, ansX2);
	}
	return 0;
}