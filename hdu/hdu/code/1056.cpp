#include<iostream>
using namespace std;
int main(){
	double n;
	while (cin >> n&&n){
		double sum = 0;
		int i;
		for (i = 2; sum < n; ++i)
			sum += 1.0 / i;
		printf("%d card(s)\n", i - 2);
	}
	return 0;
}