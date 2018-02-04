#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int s, t;
	const double H = 4.5;
	while (cin >> N&&N){
		double ans = DBL_MAX;
		while (N--){
			cin >> s >> t;
			if (t < 0)
				continue;
			double mm = (H / s) * 3600 + t;
			if (mm < ans)
				ans = mm;
		}
		printf("%d\n", int(ans+0.99999));

	}






	return 0;
}