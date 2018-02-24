#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	int N,M;
	int O, P;
	cin >> N;
	while (N--){
		cin >> M;
		for (int i = 0;; ++i){
			int j = pow(2, i);
			double tt = double(M) / j;
			int ttt = int(tt);
			if (tt == ttt&&ttt % 2 == 1){
				P = i;
				O = ttt;
				break;
			}
		}
		printf("%d %d\n", O, P);
	}

	return 0;
}