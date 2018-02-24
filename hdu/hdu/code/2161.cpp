#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
bool Isprime(int n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)
		return 0;
	return 1;

}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int CASE = 1;
	while (cin >> N&&N>0){
		printf("%d: ", CASE++);
		if (N == 1 || N == 2)
			cout << "no" << endl;
		else{
			if (Isprime(N))
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
	return 0;
}