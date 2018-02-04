#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int fun(int x){
	int res = x;
	res = (res * x) % 10000;
	res = (res * x) % 10000;
	return res;

}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin>>N){
		N %= 10000;
		N = (N*(N + 1) / 2) % 10000;
		N = (N*N) % 10000;
		printf("%04d\n", N);
	}
	return 0;
}