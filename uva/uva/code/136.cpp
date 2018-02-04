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
int data[1600];
int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	int p1, p2, p3;
	data[1] = 1;
	p1 = p2 = p3 = 1;
	int size = 2;
	while (size < 1550){
		int pp1 = data[p1] * 2;
		int pp2 = data[p2] * 3;
		int pp3 = data[p3] * 5;
		data[size] = min(min(pp1, pp2), pp3);
		if (data[size] == data[p1] * 2)
			p1++;
		if (data[size] == data[p2] * 3)
			p2++;
		if (data[size] == data[p3] * 5)
			p3++;
		size++;
	}
	printf("The 1500'th ugly number is %d.\n", data[1500]);














	return 0;
}