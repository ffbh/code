#include <iostream>
using namespace std;

int main(){
	int N;
	int a, b;
	cin >> N;
	while (N--){
		cin >> a >> b;
		int c = a - b;
		if (a < b || (a - b) % 2)
			cout << "impossible" << endl;
		else printf("%d %d\n", a- c / 2,  c / 2);
	}


	return 0;
}