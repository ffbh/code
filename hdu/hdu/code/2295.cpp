#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int N, M, K;
struct City{
	double x, y;
}city[60];
double map[60][60];




int main(){
	ifstream in("C:\\temp.txt");
	int T;
	in >> T;
	while (T--){
		in >> N >> M >> K;
		for (int i = 1; i <= N; ++i)
			in >> city[i].x >> city[i].y;
		for (int i = 1; i <= M; ++i){
			double x, y;
			in >> x >> y;
			for (int j = 1; j <= N; ++j)
				map[i][j] = sqrt(pow(x - city[i].x, 2) + pow(y - city[i].y, 2));


		}

	}



	return 0;
}