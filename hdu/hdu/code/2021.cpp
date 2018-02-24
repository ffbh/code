#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	int N;
	int data[6] = { 100, 50, 10, 5, 2, 1 };
	while (cin >> N&&N){
		int sum = 0;
		while (N--){
			int t;
			cin >> t;
			for (int i = 0; i < 6; ++i){
				sum += t/data[i];
				t %= data[i];
			}
		}
		cout << sum << endl;
	}
	return 0;
}