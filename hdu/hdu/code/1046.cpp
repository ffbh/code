#include <iostream>
using namespace std;

int main(){
	int n;
	double a, b;
	cin >> n;
	int c = 1;
	while (n-- > 0){
		cin >> a >> b;
		if (int(a) % 2 == 0 || int(b) % 2 == 0)
			printf("Scenario #%d:\n%.2f\n", c++, 1.0*a*b);
		else
			printf("Scenario #%d:\n%.2f\n", c++, 1.0*a*b - 1.0 + 1.41);
		cout << endl;
	}



	return 0;
}