#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
const double esp = 1e-10;


int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		double x;
		cin >> x;
		if (fabs(x) < esp){
			printf("-1\n");
			continue;
		}
		int num = 0;
		double l, r;
		l = 0.0;
		r = 0.5;
		while (1){
			num += 4;
			double mid = (l + r) / 2.0;
			if (fabs(mid - x) < esp){
				num = -1;
				break;
			}
			else if (x > mid){
				l = mid;
			}
			else{
				break;
			}
		}
		printf("%d\n", num);
	}
















	return 0;
}