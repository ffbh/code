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
	int T;
	while (cin >> T){
		int num = 0;
		while (T--){
			int n;
			scanf("%d", &n);
			if (Isprime(n))
			num++;
		}
		cout << num << endl;


	}





	return 0;
}