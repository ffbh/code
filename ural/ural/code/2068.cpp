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
	int N;
	while (cin >> N){
		int sum = 0;
		for (int i = 1; i <= N; ++i){
			int t;
			cin >> t;
			sum = (sum + t / 2) % 2;
		}
		if (sum == 0){
			cout << "Stannis" << endl;

		}
		else{
			cout << "Daenerys" << endl;
		}

	}
















	return 0;
}