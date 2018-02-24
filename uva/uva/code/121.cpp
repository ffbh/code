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

long long cale_grid(double n,double m){
		long long grid_n = floor(n);
		long long grid_m = floor(m);
		return grid_n*grid_m;
}

long long cale_skew(double n, double m){
	double p = sqrt(3.0) / 2.0;
	if (n < 1 || m < 1)
		return 0;
	int h = floor((n - 1.0) / p) + 1;
	int w = floor(m);
	double rest = m - w;
	if (rest >= 0.5){
		return h*w;
	}
	else{
		if (h % 2 == 1)
			return h / 2 * (2 * w - 1) + w;
		else{
			return h / 2 * (2 * w - 1); 
		}
	}


}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	double N, M;
	while (cin >> N >> M){
		
		long long grid = cale_grid(N, M);

		long long skew = max(cale_skew(N, M), cale_skew(M, N));
		if (grid >= skew){
			cout << grid << " grid" << endl;
		}
		else{
			cout << skew << " skew" << endl;
		}
	}



	return 0;
}