#include <iostream>
using namespace std;

int fun(int n){
	int sum = 1;
	for (int i = 1; i <= n; i++)
		sum *= i;
	return sum;
}
int main(){
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	cout << 0 << " " << 1 << endl;
	cout << 1 << " " << 2 << endl;
	cout << 2 << " " << 2.5 << endl;
	double old = 2.5;
	for (int i = 3; i < 10; ++i){
		double d = 1.0 / fun(i);
		old += d;
		printf("%d %.9f\n",i, old);
	}



	return 0;
}