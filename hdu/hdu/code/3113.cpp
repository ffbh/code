#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node{
	int x, y;
	bool ok;
}data[1000010];
int main(){
	ifstream in("C:\\temp.txt");
	for (int i = -1000; i <= 1000;++i)
	for (int j = max(0,i); j <= 1000; ++j){
		int temp = i*i*i + j*j*j;
		if (temp >= 0 && temp <= 1000000){
			if (!data[temp].ok){
				data[temp].ok = 1;
				data[temp].x = i;
				data[temp].y = j;
			}
		}

	}
	int N;
	while (cin >> N&&N){
		if (!data[N].ok)
			printf("Impossible\n");
		else
			printf("%d %d\n", data[N].x, data[N].y);



	}
	return 0;
}