#include <iostream>

using namespace std;

int main(){

	int n;
	int sum;
	while (cin >> n){
		sum = 0;
		for (int i = 1; i <= n; ++i)
			sum += i;
		cout << sum << endl;
		cout << endl;


	}



	return 0;
}