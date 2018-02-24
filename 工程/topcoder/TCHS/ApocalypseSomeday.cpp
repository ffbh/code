#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

bool ok(int n){
	int num = 0;
	while (n){
		int p = n % 10;
		n /= 10;
		if (p == 6){
			num++;
			if (num == 3){
				return 1;
			}
		}
		else{
			num = 0;
		}
	}
	return 0;
}

class ApocalypseSomeday {
public:
	int getNth(int n) {
		int num = 0;
		for (int i = 1; i < 1e7; ++i){
			if (ok(i)){
				num++;
			}
			if (num == n)
				return i;
		}
		return -1;
	}
};




int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

	
















	return 0;
}





