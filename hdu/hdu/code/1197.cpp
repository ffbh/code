#include <iostream>
using namespace std;
int getNum(int n,int dex){
	int sum = 0;
	for (int i = 0; i < 4; ++i){
		sum += n % dex;
		n /= dex;
	}
	return sum;
}


int main(){
	for (int i = 2992; i <= 9999; ++i){
		int Ten = getNum(i, 10);
		if (Ten == getNum(i, 12) && Ten == getNum(i, 16))
			cout << i << endl;
	}
	


	
}