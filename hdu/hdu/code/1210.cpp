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
			if (k <= n)k = 2 * k;//k���е����,kΪ��k*2��(�������),(k�����е�)
			else k = 2*(k-n)-1;//k���е��ұ�,kΪ��k*2��(���ұ�����)
			time++;
		}
		cout << time << endl;
	
	
	}


}