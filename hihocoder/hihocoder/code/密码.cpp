#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int data[1010], N;


int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> data[i];
	if (N == 1){
		cout << data[1] << endl;
	}
	else{
		int pos = N;
		while (pos > 2 && data[pos] > data[pos - 1])
			pos--;
		for (int i = 1; i < pos; ++i)
			cout << data[i] << " ";
		cout << endl;
	}















	return 0;
}