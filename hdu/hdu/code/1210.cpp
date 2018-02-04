#include <iostream>
#include <cmath>
using namespace std;


int main(){
	int n;
	while (cin >> n){
		int m = 2 * n;
		int k = 1;
		int time = 1;
		while (k != n + 1){
			if (k <= n)k = 2 * k;//k在中点左边,k为第k*2个(从左边数),(k包括中点)
			else k = 2*(k-n)-1;//k在中点右边,k为第k*2个(从右边数起)
			time++;
		}
		cout << time << endl;
	
	
	}


}