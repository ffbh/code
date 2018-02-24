#include <iostream>
using namespace std;

int main(){
	int n, u, d;
	int time;
	int m;
	while (cin >> n >> u >> d&&n){
		time = 0;
		m = 0;
		while (1){
			m += u;
			time++;
			if (m >= n)
				break;
			m -= d;
			time++;
		}
		cout << time << endl;



	}







	return 0;
}