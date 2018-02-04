#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	double X, Y, x, y;
	while (cin >> T&&T){
		while (T--){
			X = Y = 0;
			int M = 3;
			while (M--){
				cin >> x >> y;
				X += x;
				Y += y;
			}
			printf("%.1f %.1f\n", X / 3, Y / 3);
		}
	}





	return 0;
}