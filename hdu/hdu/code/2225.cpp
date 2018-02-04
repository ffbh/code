#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int gcd(int n, int m){
	if (m == 0)
		return n;
	else
		return gcd(m, n%m);
}

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		int fenzi, fenmu;
		double mmin = DBL_MAX;
		for (int i = 1; i <= M; ++i){
			int k1, k2, k3, k4;
			k1 = int(sqrt(N)*M);
			k2 = i;
			k3 = k1 + 1;
			k4 = i;
			int g = gcd(k1, k2);
			k1 /= g;
			k2 /= g;
			double d = fabs(sqrt(N) - double(k1) / k2);
			if (d < mmin){
				mmin = d;
				fenzi = k1;
				fenmu = k2;
			}
			k1 = k3;
			k2 = k4;
			d = fabs(sqrt(N) - double(k1) / k2);
			if (d < mmin){
				mmin = d;
				fenzi = k1;
				fenmu = k2;
			}
		}
		printf("%d/%d\n", fenzi, fenmu);
	}
	return 0;
}