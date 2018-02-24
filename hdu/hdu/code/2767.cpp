#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int data[10];


int main(){
	ifstream in("C:\\input.txt");
	for (int i = 0; i < 9; ++i)
		data[i] = i;
	int num = 0;
	while (next_permutation(data, data + 9)){
		cout << num++ << "      ";
		for (int i = 0; i < 9; ++i)
			cout << data[i];
		cout << endl;
	}















	return 0;
}