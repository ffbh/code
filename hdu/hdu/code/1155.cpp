#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	double g = 9.81;
	double k, l, s, w;
	while (cin >> k >> l >> s >> w&&k+l+s+w){
		double F, G, V;
		G = w*g*s;
		if (l >= s)
			F = 0;
		else
			F = pow((s - l),2) / 2 * k;
		V = sqrt((G - F) * 2 / w);
		if (V > 10.0)
			printf("Killed by the impact.\n");
		else
		if (V >= 0)
			printf("James Bond survives.\n");
		else
			printf("Stuck in the air.\n");
	}
	return 0;
}