#include<iostream>
using namespace std;

int main(){
	int a, b;
	while (cin>>a>>b){
		int m1 = a > b ? a : b;
		int m2 = a < b ? a : b;
		int t;
		while (m1%m2){
			t = m1%m2;
			m1 = m2;
			m2 = t;
		}
		cout << a/m2*b << endl;
	}


	return 0;
}
