#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
unsigned int data[250010];


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> data[i];
	sort(data, data + N);
	if (N % 2 == 1){
		printf("%.1f\n", 1.0*data[N / 2]);
	}
	else{
		
		printf("%.1f\n", (data[N / 2-1]+data[N/2])/2.0);
	}

	return 0;
}