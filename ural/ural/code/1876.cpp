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
	int a, b;
	while (cin >> a >> b){
		int left = 40 + 39 * 2 + (a - 40) * 2 + 1;
		int right = 39 + 40 * 2 + (b - 40) * 2 + 1;
		cout << max(left, right) << endl;
	}


	return 0;
}