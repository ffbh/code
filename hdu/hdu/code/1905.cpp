#include <iostream>
#include <string>
#include <fstream>
using namespace std;

_int64 QuockMod(_int64 A, _int64 P, _int64 N){
	_int64 res = 1;
	while (P > 0){
		if (P%2)
			res = res*A%N;
		A = A*A%N;
		P /= 2;
	}
	return res;
}

bool prime(_int64 n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)
		return 0;
	return 1;
}


int main(){
	//ifstream in("C:\\temp.txt");
	_int64 P, A;
	while (cin >> P >> A&&P + A){
		if (!prime(P)&&QuockMod(A, P, P) == A)
			cout << "yes" << endl;
		else
			cout << "no" << endl;


	}





	return 0;
}