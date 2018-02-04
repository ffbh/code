#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int N, M;
double data[10001];
const double PI = acos(-1.0);
bool judge(double x){
	int num = 0;
	for (int i = 0; i < N; ++i)
		num += int(data[i] / x);
	return num>M;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		double sum = 0;
		for (int i = 0; i < N; ++i){
			cin >> data[i];
			data[i] = data[i] * data[i] * PI;
			sum += data[i];
		}
		double l = 0;
		double r = sum / (M + 1);
		while (r - l>1e-6){
			double m = (l + r) / 2;
			if (judge(m))
				l = m;
			else
				r = m;
		}
		printf("%.4f\n", (l + r) / 2);
	}
	return 0;
}