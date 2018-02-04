#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
long long A[1010][1010];
int N, M;
long long cale(int x,int y){
	long long sum = 0;
	for (int i = x; i < x + N;++i)
	for (int j = y; j < y + M; ++j)
		sum += A[i][j];
	return sum;
}

int main(){
	ifstream in("C:\\input.txt");
	for (int i = 1; i < 1010;++i)
	for (int j = 1; j < 1010; ++j)
		A[i][j] = min(i, j);

	N = 5;
	M = 4;
	cout << cale(1, 1) << endl;
	cout << cale(2, 1) << endl;
	cout << cale(1, 2) << endl;
	cout << cale(2, 2) << endl;
	cout << endl;

	N = 4;
	M = 5;
	cout << cale(1, 1) << endl;
	cout << cale(2, 1) << endl;
	cout << cale(1, 2) << endl;
	cout << cale(2, 2) << endl;
	cout << endl;








	return 0;
}