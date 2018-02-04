#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
#define PI  3.1415926535897932384626433832795
#define S1  (PI*r*r)
#define S2 (PI*R*R)
#define y  (r + M*(R - r) / H)
#define S3 (PI*y*y)
#define tV (M / 3.0 * (S1 + S3 + sqrt(S1*S3)))
int main(){
	ifstream in("C:\\temp.txt");
	double r, R, H, V;
	int T;
	in >> T;
	while (T--){
		in >> r >> R >> H >> V;
		//double MAXV = H / 3.0 * (S1 + S2 + sqrt(S1*S2));
	//	if (V >= MAXV)
	//		printf("%.6f\n", H);
	//	else if (V == 0)
	//		printf("%.6f\n", 0);
	//	else{
			double L, R;
			L = 0.0;
			R = H;
			while (R - L > 1e-10){
				double M = (L + R) / 2.0;
				if (tV <= V)
					L = M+1e-10;
				else
					R = M-1e-10;
			}
			printf("%.6lf\n", (L + R) / 2.0);
	//	}
	}
	return 0;
}

