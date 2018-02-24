#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
#define Exp (1e-7)
bool G(double x, double y){
	return x - y > Exp;
}

int main(){
	ifstream in("C:\\input.txt");
	double x, y, r, x1, y1, x2, y2, mx, my, rectD;
	int T;
	cin >> T;
	while (T--){
		cin >> x >> y >> r >> x1 >> y1 >> x2 >> y2;
		mx = (x1 + x2) / 2.0;
		my = (y1 + y2) / 2.0;
		rectD = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) / 2.0;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);

		double dis = sqrt((x - mx)*(x - mx) + (y - my)*(y - my));
		if (G(dis, rectD + r) || G(r,dis+rectD)){
			cout << "NO" << endl;
		}
		else{
			double dx = min(fabs(x - x1), fabs(x - x2));
			double dy = min(fabs(y - y1), fabs(y - y2));
			if (G(dx, r) && G(dy, r))
				cout << "NO" << endl;
			else
				cout << "YES" << endl;



		}

	}

	return 0;
}