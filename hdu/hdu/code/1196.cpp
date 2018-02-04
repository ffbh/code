#include<iostream>
using namespace std;

int main(){
	int n;
	while (cin >> n&&n){
		for (int i = 1; i < 100;i*=2)
		if (n&i){
			cout << i << endl;
			break;
		}
	
	}

	
}