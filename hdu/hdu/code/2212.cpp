#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int fun(int n){
	int ans = 1;
	while (n){
		ans *= n;
		n--;
	}
	return ans;
}

int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i <= 40585; ++i){
		int ans = 0;
		int temp = i;
		while (temp){
			ans += fun(temp % 10);
			temp /= 10;
		}
		if (ans == i)
			cout << i << endl;
	}
	return 0;
}