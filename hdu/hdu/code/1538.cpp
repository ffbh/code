#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
	ifstream in("C:\\input.txt");
	int T, n, m, p;
	cin >> T;
	while (T-- > 0){
		cin >> n >> m >> p;

		if (n <= 2 * m){
			if (n == p){
				cout << m - (n - 1) / 2 << endl;
			}
			else{
				if (p % 2 == n % 2)
					cout << 1 << endl;
				else
					cout << 0 << endl;
			}
		}
		else if (n == m * 2 + 1){
			if (p <= 2 * m){
				cout << p % 2 << endl;
			}
			else{
				cout << 0 << endl;
			}
		}
		else if (n == m * 2 + 2){
			if (p <= 2 * m){
				cout << 1 - p % 2 << endl;
			}
			else{
				cout << 0 << endl;
			}
		}
		else if(n == m*2+3){
			if (n == p){
				cout << "Thrown" << endl;
			}
			else{
				if (p <= 2 * m){
					cout << 1 - p % 2 << endl;
				}
				else{
					cout << 0 << endl;
				}
			}
		}
		else if (n == 2 * m + 4){
			cout << 0 << endl;
		}
		else{
			if (p > 2 * m + 4)
				cout << "Thrown" << endl;
			else
				cout << 0 << endl;
		}
	}


	return 0;
}