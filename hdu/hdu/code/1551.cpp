#include <iostream>
#include <string>
#include <fstream>
using namespace std;
double data[10001];
int N, K;
bool ok(double x){
	int sum = 0;
	for (int i = 0; i < N; ++i)
		sum += int(data[i] / x);
	return sum >= K;
}

int main(){
	ifstream in("C:\\temp.txt");
	
	while (cin >> N >> K&&N+K){
		double sum = 0;
		for (int i = 0; i < N; ++i){
			cin >> data[i];
			sum += data[i];
		}
		double l = 0;
		double r = sum / 11.0;
		double m;
		while (r - l>1e-8){
			m = (l + r) / 2;
			if (ok(m))
				l = m;
			else
				r = m;
		}
		if (l < 1.0)
			cout << "0.00" << endl;
		else
			printf("%.2f\n", m);
	}
	return 0;
}