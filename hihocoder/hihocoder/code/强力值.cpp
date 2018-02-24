#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M;
double A[11], B[11];
int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
		cin >> A[i];
	double sum = 0;
	for (int i = 1; i <= M; ++i){
		cin >> B[i];
		sum += 1.0 / B[i];
	}
	double ans = 1.0;
	for (int i = 1; i <= M; ++i){
		ans *= pow(A[i] + double(N) / (sum * B[i]), 1.0 / B[i]);
	}
	printf("%.3f\n", ans);
	return 0;
}